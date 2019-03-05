#include <Wire.h>
#include <SPI.h>
#include <Adafruit_LSM9DS0.h>
#include <Adafruit_Sensor.h>

#define LSM9DS0_XM_CS 8
#define LSM9DS0_GYRO_CS 7

Adafruit_LSM9DS0 lsm = Adafruit_LSM9DS0();  // i2c sensor
Adafruit_LSM9DS0 lsm30 = Adafruit_LSM9DS0(LSM9DS0_XM_CS, LSM9DS0_GYRO_CS);

struct kalmanValues
{
  float P[4] = {};
  float K[2] = {};
//  float angle;
  float xBias = 0;
  float QAngle  =  0.001;
  float QGyro   =  0.003;
  float RAngle  =  0.03;
};

struct imuValues
{
  float Acc[3] = {};
  float Gyr[3] = {};
  float Mag[3] = {};
}

class KalmanFilter
{
  public:
    KalmanFilter(Adafruit_LSM9DS0 lsm);
    kalmanValues constants;
    imuValues values;
    float updateKalman();
  private:
    float _angle;
    float _newAngle;
}

void setupSensor(Adafruit_LSM9DS0 lsm)
{
  // 1.) Set the accelerometer range
  lsm.setupAccel(lsm.LSM9DS0_ACCELRANGE_2G);
  //lsm30.setupAccel(lsm30.lsm309DS0_ACCELRANGE_4G);
  //lsm30.setupAccel(lsm30.lsm309DS0_ACCELRANGE_6G);
  //lsm30.setupAccel(lsm30.lsm309DS0_ACCELRANGE_8G);
  //lsm.setupAccel(lsm.LSM9DS0_ACCELRANGE_16G);

  // 2.) Set the magnetometer sensitivity
  lsm.setupMag(lsm.LSM9DS0_MAGGAIN_2GAUSS);
  //lsm.setupMag(lsm.LSM9DS0_MAGGAIN_4GAUSS);
  //lsm.setupMag(lsm.LSM9DS0_MAGGAIN_8GAUSS);
  //lsm.setupMag(lsm.LSM9DS0_MAGGAIN_12GAUSS);

  // 3.) Setup the gyroscope
  lsm.setupGyro(lsm.LSM9DS0_GYROSCALE_245DPS);
  //lsm.setupGyro(lsm.LSM9DS0_GYROSCALE_500DPS);
  //lsm.setupGyro(lsm.LSM9DS0_GYROSCALE_2000DPS);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("LSM raw read demo");
  if (!lsm.begin())
  {
    /* There was a problem detecting the LSM9DS0 ... check your connections */
    Serial.print(F("Ooops, no LSM9DS0 detected ... Check your wiring!"));
    while (1);
  }
  if (!lsm30.begin())
  {
    /* There was a problem detecting the LSM9DS0 ... check your connections */
    Serial.print(F("Ooops, no LSM9DS0 detected ... Check your wiring!"));
    while (1);
  }
  Serial.println("Found LSM9DS0 9DOF");
  setupSensor(lsm30);
  setupSensor(lsm);
}

void loop() {
  // put your main code here, to run repeatedly:
  lsm.read();

  Serial.print("Accel X: "); Serial.print((int)lsm.accelData.x); Serial.print(" ");
  Serial.print("Y: "); Serial.print((int)lsm.accelData.y);       Serial.print(" ");
  Serial.print("Z: "); Serial.println((int)lsm.accelData.z);     Serial.print(" ");
  Serial.print("Mag X: "); Serial.print((int)lsm.magData.x);     Serial.print(" ");
  Serial.print("Y: "); Serial.print((int)lsm.magData.y);         Serial.print(" ");
  Serial.print("Z: "); Serial.println((int)lsm.magData.z);       Serial.print(" ");
  Serial.print("Gyro X: "); Serial.print((int)lsm.gyroData.x);   Serial.print(" ");
  Serial.print("Y: "); Serial.print((int)lsm.gyroData.y);        Serial.print(" ");
  Serial.print("Z: "); Serial.println((int)lsm.gyroData.z);      Serial.println(" ");
  Serial.print("Temp: "); Serial.print((int)lsm.temperature);    Serial.println(" ");
  delay(200);

  lsm30.read();

  Serial.print("Accel X: "); Serial.print((int)lsm30.accelData.x); Serial.print(" ");
  Serial.print("Y: "); Serial.print((int)lsm30.accelData.y);       Serial.print(" ");
  Serial.print("Z: "); Serial.println((int)lsm30.accelData.z);     Serial.print(" ");
  Serial.print("Mag X: "); Serial.print((int)lsm30.magData.x);     Serial.print(" ");
  Serial.print("Y: "); Serial.print((int)lsm30.magData.y);         Serial.print(" ");
  Serial.print("Z: "); Serial.println((int)lsm30.magData.z);       Serial.print(" ");
  Serial.print("Gyro X: "); Serial.print((int)lsm30.gyroData.x);   Serial.print(" ");
  Serial.print("Y: "); Serial.print((int)lsm30.gyroData.y);        Serial.print(" ");
  Serial.print("Z: "); Serial.println((int)lsm30.gyroData.z);      Serial.println(" ");
  Serial.print("Temp: "); Serial.print((int)lsm30.temperature);    Serial.println(" ");
  delay(200);
}


float updateAngleKalman() {
  double looptime = (double)(micros() - timer) / 1000000; // Calculate delta time
  timer = micros();
  getIMUReadings();
  float roll = atan2(AcZ, sign(AcY) * sqrt((AcX * AcX) + (AcY * AcY)) ) * 180 / PI;
  //  float pitch = atan2(-1 * AcX, AcZ) * 180 / PI;
  double rollRate = -1 * GyX;
  //  double pitchRate = GyY;
  xAngle = kalmanCalculate(roll, rollRate, looptime, xAngle);
}

void getIMUReadings(Adafruit_LSM9DS0 lsm) {
  //  sensors_event_t accel, mag, gyro, temp, placeholder;
  //  lsm.getEvent(&accel, &placeholder, &gyro, &placeholder);
  //
  //  //the last input variable of this function is supposed values is supposed to
  //  //be temperature, but somehow it breaks the PerCall code. So mag value is put
  //  //in as a placeholder
  //  AcX = (float)accel.acceleration.x;
  //  AcY = (float)accel.acceleration.y;
  //  AcZ = (float)accel.acceleration.z;
  //  GyX = (float)gyro.gyro.x;
  //  GyY = (float)gyro.gyro.y;
  //  GyZ = (float)gyro.gyro.z;

  lsm.readAccel();

  //  AcX = (float)lsm.accelData.x * LSM9DS0_ACCEL_MG_LSB_2G / 1000 * GRAVITY;
  //  AcY = (float)lsm.accelData.y * LSM9DS0_ACCEL_MG_LSB_2G / 1000 * GRAVITY;;
  //  AcZ = (float)lsm.accelData.z * LSM9DS0_ACCEL_MG_LSB_2G / 1000 * GRAVITY;;
  //  GyX = (float)lsm.gyroData.x * LSM9DS0_GYRO_DPS_DIGIT_245DPS;
  //  GyY = (float)lsm.gyroData.y * LSM9DS0_GYRO_DPS_DIGIT_245DPS;
  //  GyZ = (float)lsm.gyroData.z * LSM9DS0_GYRO_DPS_DIGIT_245DPS;

  AcX = (float)lsm.calcAccel(lsm.ax);
  AcY = (float)lsm.calcAccel(lsm.ay);
  AcZ = (float)lsm.calcAccel(lsm.az);
  lsm.readGyro();
  GyX = (float)lsm.calcGyro(lsm.gx);
  GyY = (float)lsm.calcGyro(lsm.gy);
  GyZ = (float)lsm.calcGyro(lsm.gz);
  //  Serial.print(AcX); Serial.print(":");
  //  Serial.print(AcY); Serial.print(":");
  //  Serial.println(AcZ);
}

//Kalman module
float kalmanCalculate(float newAngle, float newRate, double looptime, float angle)
{
  double dt = double(looptime);
  angle += dt * (newRate - xBias);
  P0 += -1 * dt * (P2 + P1) + QAngle * dt;
  P1 -= dt * P3;
  P2 -= dt * P3;
  P3 += QGyro * dt;
  y = newAngle - angle;
  S = P0 + RAngle;
  K0 = P0 / S;
  K1 = P2 / S;
  angle +=  K0 * y;
  xBias  +=  K1 * y;
  P0 -= K0 * P0;
  P1 -= K0 * P1;
  P2 -= K1 * P0;
  P3 -= K1 * P1;
  return angle;
}
