/** 
 *  @file	temp_humidity.c
 *  @brief	Temperature and humidity source file for the the IC Silicon Labs Si7006.
 *  @authors	Collin Heist, Ryan Donahue
 **/

/* ----------------------------------- File Inclusion ----------------------------------- */

#define _SUPPRESS_PLIB_WARNING
#include <plib.h>

#include "hardware.h"
#include "I2CLib.h"
#include "temp_humidity.h"

/* -------------------------- Global Variables and Structures --------------------------- */

/* ---------------------------------- Public Functions ---------------------------------- */

/**	
 *	@brief		Read the temperature from the SI7006 sensor.
 *	@param[in]	temp_mode: Unsigned int that is either CELSIUS_MODE or FAHRENHEIT_MODE for the format of the return.
 *	@return		float that represents the current temperature in degrees F or C.
 **/
float read_temperature(unsigned int temp_mode) {
    unsigned char write[1] = {Si7006_temp_no_hold_master};
    unsigned char read[2];
    read_write_I2C1(Si7006_addr, write, read, 1, 2);
   
    return (temp_mode == CELSIUS_MODE ? TEMP_CODE_TO_C(((read[0] << 8) | read[1])) : TEMP_CODE_TO_F(((read[0] << 8) | read[1])));
//    return (temperature_mode == CELSIUS_MODE ? (((read[0] << 8) | read[1])*175.72/65536)-46.85 : ());
}

/**	
 *	@brief		Read the humidity from the SI7006 sensor.
 *	@param		None.
 *	@return		float that represents the current humidity
 **/
float read_humidity(void) {
    unsigned char write[1] = {Si7006_humidity_no_hold_master};
    unsigned char read[2];
    
    read_write_I2C1(Si7006_addr, write, read, 1, 2);
    float humidity = RH_CODE_TO_HUMIDITY(((read[0] << 8) | read[1]));
    
    // Normalize the humidity reading [0.0, 100.0]
    humidity = (humidity > 100.0 ? 100.0 : humidity);
    humidity = (humidity < 0.0   ? 0.0   : humidity);
    
    return humidity;
}

/* --------------------------------- Private Functions ---------------------------------- */

/* ----------------------------- Interrupt Service Routines ----------------------------- */
