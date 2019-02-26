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
#include "config_bits.h"
#include "crop_top.h"
#include "I2CLib.h"
#include "Si7006.h"

int main()
{
    initialize_system();
    float temp = 0.0, humidity = 0.0;
    int i;
    while(1)
    {
        i = 0;
        while(i<5000)
        {
            i++;
        }
        // do some shit
//        temp = Si7006_ReadTemp();
        humidity = Si7006_ReadTemp();
    }
}
void initialize_system()
{
    PORTSetPinsDigitalIn(IOPORT_C, BUTTONS);
    PORTSetPinsDigitalOut(IOPORT_C, LEDS);
    LATCCLR = LEDS;
    I2CLib_Init();
}