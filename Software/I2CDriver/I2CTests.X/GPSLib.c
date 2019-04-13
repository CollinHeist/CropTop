/* **************************************************************************
 * File name:   AccelLib.c
 * Association: University of Idaho
 * Author:      Ryan Donahue
 * Dates:       Created 4/12/2018
 * Summary:     
 * *************************************************************************/
#define _SUPPRESS_PLIB_WARNING
#include <plib.h>
#include "crop_top.h"
#include "I2CLib.h"
#include "AccelLib.h"
#include <stdio.h>

/* **************************************************************************
 * Function:    char GPSLib_Init()
 * Summary:     
 * Return:		0  - no I2C write errors
				!0 - an I2C write error was encountered
 * **************************************************************************/
char GPSLib_Init()
{
	//fill control registers
    int error = 0;
	error |= AccelLib_SingleWrite(CTRL_REG1,ACC_CFG_1);
    return error;
}

/* **************************************************************************
 * Function:    char GPSLib_SingleWrite(char subreg, char write_val)
 * Summary:     Write a value to a single sub register in the GPS
 * Argument:    char subreg, destination address
				char write_val, register value
 * Return:		0  - no I2C write errors
				!0 - an I2C write error was encountered
 * **************************************************************************/
char GPSLib_SingleWrite(char subreg, char write_val)
{
	char write[2] = {subreg,write_val};
	char error = I2C_Write(LIS3DHTR_ADDR, write, 2);
	return error;
}

/* **************************************************************************
 * Function:    char GPSLib_SingleRead(char subreg)
 * Summary:     Retrieve a value from a single sub register in the GPS.
 * Argument:    char subreg, destination address
 * Return:		value retrieved from subreg
 * **************************************************************************/
char GPSLib_SingleRead(char subreg)
{
    char read[1];
    char write[1] = {subreg};
    I2C_WriteRead(LIS3DHTR_ADDR, write, read, 1, 1);
    return read[0];
}

/* **************************************************************************
 * Function:    char GPSLib_ContinuousRead(char subreg, char* read, int len)
 * Summary:     Retrieve len values from the GPS and store in the array read.
				Reads begin at the sub register address and auto-increment.
 * Argument:    char subreg, starting destination address
				char* read, pointer to the array that will be filled
 * **************************************************************************/
void GPSLib_ContinuousRead(char subreg, char* read, int len)
{
    char write[1] = {subreg|AUTO_INCREMENT};
    I2C_WriteRead(LIS3DHTR_ADDR, write, read, 1, len);
}