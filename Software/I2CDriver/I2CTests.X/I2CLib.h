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

//prototypes
void I2CLib_Init();
void I2CLib_PortSetup();
void I2CLib_I2CSetup();
char I2C_Read(int slave_addr, char *i2c_string_read, int len);
int I2C_Write(int slave_addr, char *i2c_string_write, int len);
char BusyI2C2();