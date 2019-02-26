/* **************************************************************************
 * File name:   I2CLib.c
 * Association: University of Idaho
 * Author:      Ryan Donahue
 * Dates:       Created 2/13/2018
 * Summary:     
 * Notes:       HW: Get rid of accelerometer in lieu of a gyroscope  
 * **************************************************************************/
#define _SUPPRESS_PLIB_WARNING
#include <plib.h>
#include "crop_top.h"
#include "I2CLib.h"

void I2CLib_Init()
{
    I2CConfigure(I2C1,0);
    I2CSetFrequency(I2C1, GetPeripheralClock(), I2C_CLOCK_FREQ);
    I2CEnable(I2C1, TRUE);
}

char BusyI2C1() //returns non-zero value if I2C1 is busy, 1-busy, 0-not busy
{
    return(I2C1CONbits.SEN || I2C1CONbits.PEN || I2C1CONbits.RSEN ||
            I2C1CONbits.RCEN || I2C1CONbits.ACKEN || I2C1STATbits.TRSTAT);
}

char I2C_Read(char slave_addr, char *read_string, int len)
{
    char error = 0;
    StartI2C1();
    IdleI2C1();
    error |= MasterWriteI2C1((slave_addr<<1)|1);
    while(1)
    {
        len--;
        *read_string = MasterReadI2C1();
        if(len == 0)
        {
            return;
        }
        AckI2C1();
        IdleI2C1();
        read_string++;
    }
    NotAckI2C1();
    IdleI2C1();
    StopI2C1();
    IdleI2C1();
    return error;
}

//terminated by null terminated string or after len message bytes are sent 
char I2C_Write(char slave_addr, char *write_string, int len)
{
    char error = 0;
    StartI2C1();
    IdleI2C1();
    error |= MasterWriteI2C1(slave_addr<<1|0);
    while((write_string!= NULL)&&(len!=0))
    {
        error |= MasterWriteI2C1(*write_string);
        write_string++;
        len--;
    }
    StopI2C1();
    IdleI2C1(); 
    return error; //returns non-zero if there was a write error
}

char I2C_WriteRead(char slave_addr, char *write_string, char *read_string, int write_len, int read_len)
{
    char error = 0;
    StartI2C1();
    IdleI2C1();
    error |= MasterWriteI2C1(slave_addr<<1|0);
    while((write_string!= NULL)&&(write_len!=0))
    {
        error |= MasterWriteI2C1(*write_string);
        write_string++;
        write_len--;
    }
    RestartI2C1();
    IdleI2C1();
    error |= MasterWriteI2C1((slave_addr<<1)|1);
    while(1)
    {
        *read_string = MasterReadI2C1();
        read_len--;
        if(read_len == 0)
        {
            return;
        }
        AckI2C1();
        IdleI2C1();
        read_string++;
    }
    NotAckI2C1();
    IdleI2C1();
    StopI2C1();
    IdleI2C1();
    return error; //returns non-zero if there was a write error
}

BOOL I2C_WaitForSlaveAck(char slave_addr)
{
    int i = 0;
    StartI2C1();
    IdleI2C1();
    while((MasterWriteI2C1(slave_addr<<1|0)) && (i++<5000))
    {
        RestartI2C1();
        IdleI2C1();
    };
    StopI2C1();
    IdleI2C1(); 
    return 1;
}