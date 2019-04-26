/* **************************************************************************
 * File name:   Si7006.c
 * Association: University of Idaho
 * Author:      Ryan Donahue
 * Dates:       Created 2/21/2018
 * Summary:     Contains functions to operate temperature and humidity sensor 
				IC Silicon Labs Si7006.
 * *************************************************************************/
#define _SUPPRESS_PLIB_WARNING
#include <plib.h>
#include "crop_top.h"
#include "I2CLib.h"
#include "Si7006.h"

/* **************************************************************************
 * Function:    float Si7006_ReadTemp()
 * Summary:     Read the Temperature.
 * Return:		float, temperature in degrees
 * **************************************************************************/
float Si7006_ReadTemp()
{
    unsigned char write[1] = {Si7006_temp_no_hold_master};
    unsigned char read[2];
    I2C_WriteRead(Si7006_addr, write, read, 1, 2);
    return (((read[0]<<8)|read[1])*175.72/65536)-46.85;
}

/* **************************************************************************
 * Function:    float Si7006_ReadTemp()
 * Summary:     Read Humidity.
 * Return:		float, percent humidity (0-100)
 * **************************************************************************/
float Si7006_ReadHumidity()
    {
    float humidity;
    unsigned char write[1] = {Si7006_humidity_no_hold_master};
    unsigned char read[2];
    I2C_WriteRead(Si7006_addr, write, read, 1, 2);
    humidity = (125.0*((read[0]<<8)|read[1]))/65536-6;
    if(humidity > 100.0)
    {
        humidity = 100.0;
    }
    if(humidity <0.0)
    {
        humidity = 0.0;
    }
    return humidity;
}