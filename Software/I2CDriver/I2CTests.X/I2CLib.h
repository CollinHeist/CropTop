/* **************************************************************************
 * File name:   I2CLib.h
 * Association: University of Idaho
 * Author:      Ryan Donahue
 * Dates:       Created 2/13/2018
 * Summary:     This file contains macro definitions and prototypes for the
				I2C library.     
 * *************************************************************************/
#define _SUPPRESS_PLIB_WARNING

//pin macros
#define SDA BIT_14 //port A
#define SCL BIT_15 //port A

//I2C module macros
#define FSCK 50000 //clock frequency
#define BRG_VAL ((GetPeripheralClock()/2/FSCK)-2)    //baud rate

//Si7006 temperature and humidity sensor modules
#define Si7006_addr 0b1000000
#define Si7006_hold_master 0xE3

//prototypes
void I2CLib_Init();
char BusyI2C1();
char I2C_Read(char slave_addr, char *read_string, int len);
char I2C_Write(char slave_addr, char *write_string, int len);