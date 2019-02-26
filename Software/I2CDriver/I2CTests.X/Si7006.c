/* **************************************************************************
 * File name:   Si7006.c
 * Association: University of Idaho
 * Author:      Ryan Donahue
 * Dates:       Created 2/21/2018
 * Summary:     
 * *************************************************************************/
#define _SUPPRESS_PLIB_WARNING
#include <plib.h>
#include "crop_top.h"
#include "I2CLib.h"
#include "Si7006.h"

float Si7006_ReadTemp()
{
    int i = 0, LSB, MSB;
    StartI2C1();
    IdleI2C1();
    MasterWriteI2C1(Si7006_addr<<1|0x00);
    MasterWriteI2C1(Si7006_temp_no_hold_master);
    RestartI2C1();
    IdleI2C1();
    while(i++<20000)
    {
        MasterWriteI2C1(Si7006_addr<<1|0x01);
        if(I2C1STATbits.ACKSTAT == 0)
        {
            break;
        }
        RestartI2C1();
        IdleI2C1();
    }
    MSB = MasterReadI2C1();
    AckI2C1();
    IdleI2C1();
    LSB = MasterReadI2C1();
    NotAckI2C1();
    IdleI2C1();
    StopI2C1();
    IdleI2C1();
    return (((MSB<<8)|LSB)*175.72/65536)-46.85;
}

float Si7006_ReadHumidity()
    {
    float humidity;
    int i = 0, LSB, MSB;
    StartI2C1();
    IdleI2C1();
    MasterWriteI2C1(Si7006_addr<<1|0x00);
    MasterWriteI2C1(Si7006_humidity_no_hold_master);
    RestartI2C1();
    IdleI2C1();
    while(i++<20000)
    {
        MasterWriteI2C1(Si7006_addr<<1|0x01);
        if(I2C1STATbits.ACKSTAT == 0)
        {
            break;
        }
        RestartI2C1();
        IdleI2C1();
    }
    MSB = MasterReadI2C1();
    AckI2C1();
    IdleI2C1();
    LSB = MasterReadI2C1();
    NotAckI2C1();
    IdleI2C1();
    StopI2C1();
    IdleI2C1();
    humidity = 125.0*((MSB<<8)|LSB)/65536-6;
    if(humidity > 100.0)
    {
        humidity = 100;
    }
    if(humidity <0.0)
    {
        humidity = 0;
    }
    return humidity;
}