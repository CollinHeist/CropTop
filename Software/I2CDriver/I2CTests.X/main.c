/* **************************************************************************
 * File name:   main.c
 * Association: University of Idaho
 * Author:      Ryan Donahue
 * Dates:       Created 2/13/2018
 * Summary:     This file is used to test the I2C library
 * Notes:       
 * *************************************************************************/
#define _SUPPRESS_PLIB_WARNING
#include <plib.h>
#include "crop_top.h"
#include "I2CLib.h"

int main()
{
    initialize_system();
    int error = 0;
    char write_str[1] = {Si7006_hold_master};
    char read_str[2];
    while(1)
    {
        // do some shit
        error |= I2C_Write(Si7006_addr, write_str, 1);
        error |= I2C_Read(Si7006_addr, read_str, 2);
    }
}
void initialize_system()
{
    PORTSetPinsDigitalIn(IOPORT_C, BUTTONS);
    PORTSetPinsDigitalOut(IOPORT_C, LEDS);
    LATCCLR = LEDS;
    I2CLib_Init();
}