/* **************************************************************************
 * File name:   main.c
 * Association: University of Idaho
 * Author:      Ryan Donahue
 * Dates:       Created 2/09/2018
 * Summary:     This file is used to test the added drivers
 * Notes:       
 * *************************************************************************/
#define _SUPPRESS_PLIB_WARNING
#include <plib.h>
#include "crop_top.h"
#include "MotorLib.h"
#include "PotLib.h"

int main()
{
    initialize_system();
    unsigned int TestRead;
    while(1)
    {
        TestRead = PotLib_SingleRead();
    }
}
void initialize_system()
{
    PORTSetPinsDigitalIn(IOPORT_C, BUTTONS);
    PORTSetPinsDigitalOut(IOPORT_C, LEDS);
    MotorLib_Init();
    PotLib_Init();
}