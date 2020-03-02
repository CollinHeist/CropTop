/** 
 *  @file	temp_humidity.c
 *  @brief	Temperature and humidity source file for the the IC Silicon Labs Si7006.
 *  @authors	Collin Heist, Ryan Donahue
 **/

/* ----------------------------------- File Inclusion ----------------------------------- */

#include <plib.h>

#include "hardware.h"
#include "temp_humidity.h"
#include "I2CLib.h"

/* -------------------------- Global Variables and Structures --------------------------- */

/* ---------------------------------- Public Functions ---------------------------------- */

/**
 *	Summary
 *		Read the temperature from the SI7006 sensor.
 *	Parameters
 *		temp_mode[in]: Unsigned int that is either CELSIUS_MODE or FAHRENHEIT_MODE to designate the return format.
 *	Returns
 *		Float that represents the current temperature in degrees F or C.
 */
float read_temperature(unsigned int temp_mode) {
    unsigned char write[1] = {Si7006_temp_no_hold_master};
    unsigned char read[2];
    read_write_I2C1(Si7006_addr, write, read, 1, 2);
   
    return raw_code_to_temperature(read, temp_mode);
}

/**
 *	Summary
 *		Read the humidity from the SI7006 sensor.
 *	Parameters
 *		None.
 *	Returns
 *		Float that represents the current normalized [0-100%] humidity.
 */
float read_humidity(void) {
    unsigned char write[1] = {Si7006_humidity_no_hold_master};
    unsigned char read[2];
    
    read_write_I2C1(Si7006_addr, write, read, 1, 2);
    float humidity = raw_code_to_humidity(read);
    
    // Normalize the humidity reading [0.0, 100.0]
    humidity = (humidity > 100.0 ? 100.0 : humidity);
    humidity = (humidity < 0.0   ? 0.0   : humidity);
    
    return humidity;
}

/* --------------------------------- Private Functions ---------------------------------- */

/**
 *	Summary
 *		Function to convert the I2C result code from the SI7006 sensor to a relative humidity.
 *	Parameters
 *		i2c_code[in]: Unsigned Character Pointer to the first value of a two-byte character
 *			array that was read from the sensor.
 *	Returns
 *		Float that represents the current normalized [0-100%] humidity.
 */
static inline float raw_code_to_humidity(unsigned char* i2c_code) {
	unsigned int combined_code = ((i2c_code[0] << 8) | i2c_code[1]);
	
	return (125.0 * ((float) combined_code) / 65536.0) - 6.0;
}

/**
 *	Summary
 *		Function to convert the I2C result code from the SI7006 sensor to a temperature in F or C.
 *	Parameters
 *		i2c_code[in]: Unsigned Character Pointer to the first value of a two-byte character array
 *			that was read from the sensor.
 *		temperature_mode[in]: Unsigned int that is either CELSIUS_MODE or FAHRENHEIT_MODE select
 *			what unit to return the temperature in.
 *	Returns
 *		Float that represents the current temperature of the sensor.
 */
static inline float raw_code_to_temperature(unsigned char* i2c_code, unsigned int temperature_mode) {
	unsigned int combined_code = (i2c_code[0] << 8) | i2c_code[1];
	float temp_celsius = (175.72 * ((float) combined_code) / 65536.0) - 46.85;
	
	return (temperature_mode == CELSIUS_MODE ? temp_celsius : (temp_celsius * 9.0 / 5.0) + 32.0);
}

/* ----------------------------- Interrupt Service Routines ----------------------------- */
