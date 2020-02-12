/** 
 *	@file       temp_humidity.h
 *	@brief      Temperature and humidity header file for the the IC Silicon Labs Si7006.
 *  @note       Data taken from following PDF: https://www.silabs.com/documents/public/data-sheets/Si7006-A20.pdf
 *	@authors	Collin Heist, Ryan Donahue
 **/
#define _SUPPRESS_PLIB_WARNING

#ifndef __TEMP_HUMIDITY_H__
    #define __TEMP_HUMIDITY_H__

    // Configuration Macros
    #define CELSIUS_MODE                    (0)     // To select which mode the temperature is returned as
    #define FAHRENHEIT_MODE                 (1)

    // Useful Macros
    #define TEMP_CODE_TO_C(TEMP_CODE)       (((175.72 * (float) TEMP_CODE) / 65536.0) - 46.85)
    #define TEMP_CODE_TO_F(TEMP_CODE)       ((TEMP_CODE_TO_C(TEMP_CODE) * 9.0 / 5.0) + 32.0)
    #define RH_CODE_TO_HUMIDITY(RH_CODE)    (((125.0 * (float) RH_CODE) / 65536.0) - 6.0)
    #define Si7006_addr                     (0x40)
    #define Si7006_temp_hold_master         (0xE3)
    #define Si7006_temp_no_hold_master      (0xF3)
    #define Si7006_humidity_hold_master     (0xE5)
    #define Si7006_humidity_no_hold_master  (0xF5)
    #define Si7006_reset                    (0xFE)

    // Function Prototypes
    float read_temperature(unsigned int temp_mode);
    float read_humidity(void);
#endif

