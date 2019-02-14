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
    while(1)
    {
        // do some shit
    }
}
void initialize_system()
{
    PORTSetPinsDigitalIn(IOPORT_C, BUTTONS);
    PORTSetPinsDigitalOut(IOPORT_C, LEDS);
}