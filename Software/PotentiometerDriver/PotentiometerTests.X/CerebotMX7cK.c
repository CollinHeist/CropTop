/* **************************************************************************
 * File name:   CerebotMx7cK.c
 * Association: University of Idaho
 * Author:      Ryan Donahue
 * Dates:       Created 1/11/2018
 * 
 * Summary:     This file intializes buttons and LEDs on the cerebot for use.
 * 
 * Notes:       Software things:
 *
 *              Hardware things:
 *              
 * *************************************************************************/

#define _SUPPRESS_PLIB_WARNING
#include <plib.h>
#include "CerebotMX7cK.h"

void Cerebot_mx7cK_setup(void)
{
    SYSTEMConfig(SYS_FREQ, SYS_CFG_WAIT_STATES | SYS_CFG_PCACHE);
    //statement is required to use Pin RA0 as IO
    DDPCONbits.JTAGEN = 0;
    //set BTN3 as input
    PORTSetPinsDigitalIn(IOPORT_A, BTN3);
    //set BTN1 and BTN2 as inputs
    PORTSetPinsDigitalIn(IOPORT_G, BTN1 | BTN2);
    //set BRD LEDs as outputs
    PORTSetPinsDigitalOut(IOPORT_G, BRD_LEDS);
    LATGCLR = BRD_LEDS;
}