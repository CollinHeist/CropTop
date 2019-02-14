/* **************************************************************************
 * File name:   I2CLib.c
 * Association: University of Idaho
 * Author:      Ryan Donahue
 * Dates:       Created 2/13/2018
 * Summary:     
 * Notes:       
 * **************************************************************************/
#define _SUPPRESS_PLIB_WARNING
#include <plib.h>
#include "crop_top.h"

void I2CLib_Init()
{
    I2CLib_PortSetup();
    I2CLib_I2CSetup();
}

void I2CLib_PortSetup()
{
    
}

void I2CLib_I2CSetup()
{
    
}

char I2C_Read(int slave_addr, char *i2c_string_read, int len)
{
    
}

int I2C_Write(int slave_addr, char *i2c_string_write, int len)
{
    
}

char BusyI2C2()
{
    
}