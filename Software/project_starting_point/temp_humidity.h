/** 
 *	File
 *		temp_humidity.h
 *	Summary
 *		Temperature and humidity header file for the the IC Silicon Labs Si7006.
 *	Author(s)
 *		Collin Heist, Ryan Donahue
 *	Note
 *		Data taken from following PDF: https://www.silabs.com/documents/public/data-sheets/Si7006-A20.pdf
 **/

#ifndef __TEMP_HUMIDITY_H__
	#define __TEMP_HUMIDITY_H__

	// Configuration Macros
	#define CELSIUS_MODE					(0)	// To select which mode the temperature is returned as
	#define FAHRENHEIT_MODE					(1)
	#define DEFAULT_MODE					(FAHRENHEIT_MODE)

	// Useful Macros
	#define TEMP_CODE_TO_C(TEMP_CODE)		(((175.72 * (float) TEMP_CODE) / 65536.0) - 46.85)
	#define TEMP_CODE_TO_F(TEMP_CODE)		((TEMP_CODE_TO_C(TEMP_CODE) * 9.0 / 5.0) + 32.0)

	#define Si7006_addr						(0x40)
	#define Si7006_temp_hold_master			(0xE3)
	#define Si7006_temp_no_hold_master		(0xF3)
	#define Si7006_humidity_hold_master		(0xE5)
	#define Si7006_humidity_no_hold_master	(0xF5)
	#define Si7006_reset					(0xFE)

	// Function Prototypes
	float read_temperature(void);
	float read_humidity(void);
	inline void set_temperature_mode(unsigned int mode);
	inline char get_temperature_mode(void);
	static inline float raw_code_to_humidity(unsigned char* i2c_code);
	static inline float raw_code_to_temperature(unsigned char* i2c_code);
#endif