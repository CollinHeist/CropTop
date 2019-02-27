/* **************************************************************************
 * File name:   Si7006.h
 * Association: University of Idaho
 * Author:      Ryan Donahue
 * Dates:       Created 2/21/2018
 * Summary:     
 * *************************************************************************/
#define _SUPPRESS_PLIB_WARNING

//temperature and humidity sensor module macros
#define Si7006_addr                     (0x40)
#define Si7006_temp_hold_master         (0xE3)
#define Si7006_temp_no_hold_master      (0xF3)
#define Si7006_humidity_hold_master     (0xE5)
#define Si7006_humidity_no_hold_master  (0xF5)
#define Si7006_reset                    (0xFE)

//function prototypes
float Si7006_ReadTemp();
float Si7006_ReadHumidity();