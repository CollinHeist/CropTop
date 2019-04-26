/* **************************************************************************
 * File name:   Expo.c
 * Association: University of Idaho
 * Author:      Ryan Donahue
 * Dates:       Created 4/25/2019
 * Summary:     system_variables structure
 * **************************************************************************/
#define _SUPPRESS_PLIB_WARNING

struct system_variables
{
    //date and time
    unsigned int year;   
    unsigned int month;
    unsigned int day; 
    unsigned int hour;      //24 hour format
    unsigned int minute;
    //GPS status
    char latitude[10];
    char longitude[10];
    //Temp and humidity
    float temp_c;           //degrees Celsius
    float temp_f;           //degrees Fahrenheit
    float humidity;         //0 to 100 percent
    //Tilt
    double tilt;            //degrees
    //PIC ADC read
    unsigned int adc_raw;            //10-bit
    float adc_nominal;      //0.00 to 3.30 volts
};