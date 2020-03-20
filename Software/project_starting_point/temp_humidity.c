/** 
 *	File
 *		temp_humidity.c
 *	Summary
 *		Temperature and humidity source file for the the IC Silicon Labs Si7006.
 *	Author(s)
 *		Collin Heist, Ryan Donahue
 **/

/* ----------------------------------- File Inclusion ----------------------------------- */

#include <plib.h>

#include "hardware.h"
#include "temp_humidity.h"
#include "I2CLib.h"

/* -------------------------- Global Variables and Structures --------------------------- */

unsigned int temperature_mode = DEFAULT_MODE;

/* ---------------------------------- Public Functions ---------------------------------- */

/**
 *	Summary
 *		Read the temperature from the SI7006 sensor.
 *	Parameters
 *		temp_mode[in]: Unsigned int that is either CELSIUS_MODE or FAHRENHEIT_MODE to designate the return format.
 *	Returns
 *		Float that represents the current temperature in degrees F or C.
 */
float read_temperature(void) {
	unsigned char write[1] = {SI7006_TEMP_NO_HOLD_MASTER};
	unsigned char read[2];
	read_write_I2C1(SI7006_I2C_ADDRESS, write, read, 1, 2);

	return raw_code_to_temperature(read);
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
	unsigned char write[1] = {SI7006_TEMP_NO_HOLD_MASTER};
	unsigned char read[2];
	
	read_write_I2C1(SI7006_I2C_ADDRESS, write, read, 1, 2);
	float humidity = raw_code_to_humidity(read);
	
	// Normalize the humidity reading [0.0, 100.0]
	humidity = (humidity > 100.0 ? 100.0 : humidity);
	humidity = (humidity < 0.0   ? 0.0   : humidity);
	
	return humidity;
}

/**
 *	Summary
 *		Set the mode for returned temperature values (see header for macros).
 *	Parameters
 *		mode[in]: Unsigned integer that denotes which mode to set temperature returns in.
 *	Returns
 *		None.
 *	Note
 *		If an unknown mode is entered no error is thrown, but Fahrenheit is used by default.
 */
inline void set_temperature_mode(unsigned int mode) {
	mode = ((mode == CELSIUS_MODE) || (mode == FAHRENHEIT_MODE)) ? mode : DEFAULT_MODE;
	temperature_mode = mode;
}

/**
 *	Summary
 *		Function to get the current temperature mode (for string creation).
 *	Parameters
 *		None.
 *	Returns
 *		Character that is either 'F' or 'C' depending on the current mode.
 */
inline char get_temperature_mode(void) {
	return (temperature_mode == CELSIUS_MODE ? 'C' : 'F');
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
static inline float raw_code_to_humidity(const unsigned char* i2c_code) {
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
static inline float raw_code_to_temperature(const unsigned char* i2c_code) {
	unsigned int combined_code = (i2c_code[0] << 8) | i2c_code[1];
	float temp_celsius = (175.72 * ((float) combined_code) / 65536.0) - 46.85;
	
	return (temperature_mode == CELSIUS_MODE ? temp_celsius : (temp_celsius * 9.0 / 5.0) + 32.0);
}

/* ----------------------------- Interrupt Service Routines ----------------------------- */
