/* **************************************************************************
 * File name:   main.c
 * Association: University of Idaho
 * Author:      Ryan Donahue
 * Dates:       Created 2/09/2018
 * 
 * Summary:     This file contains a main loop and several functions to test
 *              the GPIOLib.h library functionality.
 * 
 * Notes:       Software things:
 *
 *              Hardware things:
 *              
 * *************************************************************************/
#define _SUPPRESS_PLIB_WARNING
#include <plib.h>
#include "crop_top.h"
#include "config_bits.h"

int main()
{
    initialize_system();
    while(1)
    {
        if(PORTReadBits(IOPORT_C, BUTTON_A))
        {
            PORTSetBits(IOPORT_C, LED_A);
        }
        else
        {
            PORTClearBits(IOPORT_C, LED_A);
        }
        if(PORTReadBits(IOPORT_C, BUTTON_B))
        {
            PORTSetBits(IOPORT_C, LED_B);
        }
        else
        {
            PORTClearBits(IOPORT_C, LED_B);
        }
    }
}
void initialize_system()
{
    SYSTEMConfig(GetSystemClock(), SYS_CFG_WAIT_STATES | SYS_CFG_PCACHE);
    PORTSetPinsDigitalIn(IOPORT_C, BUTTONS);
    PORTSetPinsDigitalOut(IOPORT_C, LEDS);
}