/** 
 *	File
 *		temp_humidity.h
 *	Summary
 *		Temperature and humidity header file for the the IC Silicon Labs Si7006. Provides
 *		temperature mode definitions, macros for code to temperature conversion, and I2C
 *		definitions.
 *	Author(s)
 *		Collin Heist
 **/

#ifndef __TEMP_HUMIDITY_H__
	#define __TEMP_HUMIDITY_H__

	// Configuration Macros
	#define CELSIUS_MODE					(0)	 // To select which mode the temperature is returned as
	#define FAHRENHEIT_MODE					(1)
	#define DEFAULT_MODE					(FAHRENHEIT_MODE)

	// Useful Macros
	#define TEMP_CODE_TO_C(TEMP_CODE)		(((175.72 * (float) TEMP_CODE) / 65536.0) - 46.85)
	#define TEMP_CODE_TO_F(TEMP_CODE)		((TEMP_CODE_TO_C(TEMP_CODE) * 9.0 / 5.0) + 32.0)

	// I2C Macros
	#define SI7006_I2C_ADDRESS				(0x40)
	#define SI7006_TEMP_HOLD_MASTER			(0xE3)
	#define SI7006_TEMP_NO_HOLD_MASTER		(0xF3)
	#define SI7006_HUMIDITY_HOLD_MASTER		(0xE5)
	#define SI7006_HUMIDITY_NO_HOLD_MASTER	(0xF5)
	#define SI7006_RESET					(0xFE)

	// Function Prototypes
	float read_temperature(void);
	float read_humidity(void);
	inline void set_temperature_mode(unsigned int mode);
	inline char get_temperature_mode(void);
	static inline float raw_code_to_humidity(const unsigned char* i2c_code);
	static inline float raw_code_to_temperature(const unsigned char* i2c_code);
#endif

