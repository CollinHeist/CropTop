/* **************************************************************************
 * File name:   I2CLib.h
 * Association: University of Idaho
 * Author:      Ryan Donahue
 * Dates:       Created 2/13/2018
 * Summary:     This file contains macro definitions and prototypes for the
				I2C library.     
 * *************************************************************************/
#define _SUPPRESS_PLIB_WARNING

//I2C module macros
#define I2C_CLOCK_FREQ 100000                                   //clock frequency

//prototypes
void I2CLib_Init();
char BusyI2C1();
char I2C_Read(char slave_addr, char *read_string, int len);
char I2C_Write(char slave_addr, char *write_string, int len);
char I2C_WriteRead(char slave_addr, char *write_string, char *read_string, int write_len, int read_len);
BOOL I2C_SlaveAck(char slave_addr);