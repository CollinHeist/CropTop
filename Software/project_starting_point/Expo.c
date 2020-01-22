/* **************************************************************************
 * File name:   Expo.c
 * Association: University of Idaho
 * Author:      Ryan Donahue
 * Dates:       Created 4/25/2019
 * Summary:     Functions to modify system_variables
 * **************************************************************************/
#include <string.h>
#include "hardware.h"
#include "motors.h"
#include "potentiometer.h"
#include "I2CLib.h"
#include "Si7006.h"
#include "AccelLib.h"
#include "GPSLib.h"
#include "Expo.h"

void system_variables_update(struct system_variables *sys_vars)
{
    //date and time
    sys_vars->year = 2019;
    sys_vars->month = 4;
    sys_vars->day = 26;
    sys_vars->hour = 9;
    sys_vars->minute = 0;
    //GPS status
    strcpy(sys_vars->latitude, "no fix");
    strcpy(sys_vars->longitude, "no fix");
    //board temperature and humidity
    sys_vars->temp_c = Si7006_ReadTemp();
    sys_vars->temp_f = (sys_vars->temp_c)*1.8+32;
    sys_vars->humidity = Si7006_ReadHumidity();
    //Tilt
    sys_vars->tilt = AccelLib_ReadTilt();
    //PIC ADC read
    sys_vars->adc_raw = read_potentiometer();
    sys_vars->adc_nominal = (sys_vars->adc_raw)*3.30/1023;
}