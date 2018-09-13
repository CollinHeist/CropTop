// Firmware for the StalkPusher device V2
// The required hardware and wiring is the following:
//      HARDWARE:                   CONNECTION: (legend: -> from board to arduino, - from board to itself)
//      Adafruit ADS1115 (1)        SCL->A5 | SDA->A4
//      Adafruit ADS1115 (2)        SCL->A5 | SDA->A4 | SDA-ADDR
//      Adafruit LSM9DS0            SCL->A5 | SDA->A4
//      Arduino Pro Mini 5V
//      Adafruit Ultimate GPS V3    Rx->02 | Tx->03
// The schematic of this setup should (hopefully) always be available at https://github.com/tcl326/StalkPusher/tree/master/hardware/schematics
// The communication protocol between the Pi and this Arduino is detailed at
//
// 21/06/2017 by Ting-Che Lin <tcl326@nyu.edu> or <tingchel@andrew.cmu.edu>

//include the necessary libraries
#include "ADS1115.h"          //library for the Analog to Digital Converter (ADS1115). *important* this is an optimized library, much faster than the default adafruit library.
#include "SFE_LSM9DS0.h"      //library for the IMU. *important* do not replace this library with the default adafruit library. The adafruit library sometimes interferes with the parsing/messaging process of this code.
#include "Adafruit_GPS.h"     //library for the GPS
#include "Adafruit_AM2315.h"  //library for the Temperature Humidity Sensor

#include <SoftwareSerial.h>
#include <Wire.h>

//define IMU variables
#define LSM9DS0_XM  0x1D
#define LSM9DS0_G   0x6B
#define GRAVITY (9.80665F)

//define GPS variables
#define GPSECHO false

//open a software serial port to communicate with the GPS
//(software serial is used so the more reliable hardware serial can be used to communicate with the Pi)
SoftwareSerial gpsSerial(3, 2);

//instantiate the library objects
LSM9DS0 lsm(MODE_I2C, LSM9DS0_G, LSM9DS0_XM); //instantiate IMU object
Adafruit_GPS GPS(&gpsSerial);                 //instantiate GPS object with the pre-opened Software Serial port
Adafruit_AM2315 am2315;                       //instantiate the temperature and humidity sensor object
ADS1115 adsLoadXPot(0x48);                    //instantiate the ADC object for potentiometer and x-axis loadcell
ADS1115 adsLoadY(0x4A);                       //instantiate the ADC object for y-axis loadcell

//variables for temperature and humidity sensor
float temperature;
float humidity;

//variables for IMU
float AcX, AcY, AcZ, Tmp, GyX, GyY, GyZ;

//variable for GPS
boolean usingInterrupt = true;

//variables for command parsing and communicating with Pi
int dataIndex = 0;
int stringLength;
char dataInputBuffer[10];
bool start;
bool parse;
bool readCommand;
bool toStream;
bool toPerCall;
bool sendTime;
bool sendTimeStamp;
bool sendAngle;
bool sendForce;
bool sendTemp;
bool sendHumidity;
bool sendLocation;
bool sendAll;
bool liveFeed;
bool single = false; //determine if one or two axis loadcell is attached.
String command;
String value;

//declaring variables for the Kalman Filter. See the link below for more info.
//http://blog.tkjelectronics.dk/2012/09/a-practical-approach-to-kalman-filter-and-how-to-implement-it/
float QAngle  =  0.001;
float QGyro   =  0.003;
float RAngle  =  0.03;
float xBias = 0;
float P0 = 0;
float P1 = 0;
float P2 = 0;
float P3 = 0;
float y, S;
float K0, K1;
float xAngle = 0;
uint32_t timer;

//function prototype, necessary to keep Arduino IDE happy.
void reader (bool, bool, char, const char);
void parser (String, String, char, int);
void prepareData (const String&, const char[], String&, int&);
void sendData (const String&, int&);
void useInterrupt(boolean);
void getGPS(boolean GPSLocation = true, boolean GPSTime = true);
void getAM2315TempHumidity(boolean AM2315Temperature = true, boolean AM2315Humidity = true);
float kalmanCalculate(float, float, double, float);

void setup() {
  //initialize Serial Connection with Pi at 19200 baudrate
  Serial.begin(19200);

  //initialize boolean variables
  readCommand = false;
  start = false;
  parse = false;
  toStream = false;

  //initialize GPS
  GPS.begin(9600);
  GPS.sendCommand(PMTK_SET_NMEA_OUTPUT_RMCGGA);
  GPS.sendCommand(PMTK_SET_NMEA_UPDATE_1HZ);
  gpsSerial.println(PMTK_Q_RELEASE);
  useInterrupt(true);

  //initialize Temp/Hum sensor
  if (! am2315.begin()) {
    Serial.println("Temperature and Humidity Sensor not Found");
  }

  //initialize ADC for pot and x-axis
  adsLoadXPot.initialize();
  adsLoadXPot.setGain(ADS1115_PGA_6P144);
  adsLoadXPot.setRate(ADS1115_RATE_860);

  //initialize ADC for y-axis
  adsLoadY.initialize();
  adsLoadY.setGain(ADS1115_PGA_6P144);
  adsLoadY.setRate(ADS1115_RATE_860);

  //initialize IMU
  if (! lsm.begin()) {
    Serial.println("IMU not Found");
  }

  //initialize timer to measure the time passing since the program started (necessary for kalman filter)
  timer = micros();

  delay(100);
  Serial.println("%RDDYRECE$"); //Serial out message to indicate that the Arduino is ready to the Pi
}

void loop() {
  char theChar; //buffer for Serial input
  command = ""; //reset command
  value = "";   //reset value of command
  while (Serial.available()) {
    theChar = Serial.read();
    //    Serial.println("TimeStamp Receive Byte: " + String(theChar) + " at time: " + String(millis()));
    reader(start, parse, dataInputBuffer, theChar); //read the incoming Bytes and if the message matches the communication protocol, parse is made True.
    if (parse) {
      parser(command, value, dataInputBuffer, dataIndex); //parse the incoming message that matched the protocol
      parse = false;
      readCommand = true;
      //      Serial.println("TimeStamp Receive Data: " + String(millis()));
      break;
    }
  }
  if (readCommand) {
    //      Serial.println("TimeStamp PrepCommand: " + String(millis()));
    Serial.println("%" + command + "RECE" + "$"); //echo back the command to indicate that the command message has been received.
    //      Serial.println("TimeStamp Send Command: " + String(millis()));
    if (command == "PCLL") {
      if (value == "0000") {
        sendTimeStamp = true;
        sendTemp = true;
        sendLocation = true;
        sendHumidity = true;
      }
      if (value.charAt(3) == '1') {
        sendTemp = true;
      }
      if (value.charAt(2) == '1') {
        sendHumidity = true;
      }
      if (value.charAt(1) == '1') {
        sendLocation = true;
      }
      if (value.charAt(0) == '1') {
        sendTimeStamp = true;
      }
      toPerCall = true;
    }
    if (command == "LIVE") {
      liveFeed = true;
    }
    if (command == "STRM") {
      toStream = true;
      GPS.standby(); //the GPS is put into sleep during data collection as the periodic GPS request causes blemishes in the data
      if (value == "0000") {
        sendForce = true;
        sendAngle = true;
        sendTime = true;
      }
      if (value.charAt(3) == '1') {
        sendForce = true;
      }
      if (value.charAt(2) == '1') {
        sendAngle = true;
      }
      if (value.charAt(1) == '1') {
        sendTime = true;
      }
    }
    if (command == "STOP") {
      toStream = false;
      liveFeed = false;
      //        Serial.println("TimeStamp Stop Stream: " + String(millis()));
      GPS.wakeup(); //Wake the GPS up once the testing is finished.
    }
    readCommand = false;
  }
  if (toStream) {
    streaming(); //stream test data
  }
  else {

    resetStreamBool();
  }
  if (toPerCall) {
    perCall();
  }
  if (liveFeed) {
    streamFeed(); //stream live data
  }
  updateAngleKalman(); //update the angle using Kalman filter
}
