/* **************************************************************************
 * File name:   main.c
 * Association: University of Idaho
 * Author:      Ryan Donahue
 * Dates:       Created 1/11/2018
 * 
 * Summary:     This file contains a main loop and several functions to test
 *              the PotLib.c library functionality.
 * 
 * Notes:       Software things:
 *
 *              Hardware things:
 *              
 * *************************************************************************/

//includes and definitions
#define _SUPPRESS_PLIB_WARNING
#include <plib.h>
#include "config_bits.h"
#include "CerebotMX7cK.h"


int main()
{
    //initialize system
    Cerebot_mx7cK_setup();
    //variables
    int button1, button2;
    while(1)
    {
        button1 = PORTReadBits(IOPORT_G, BTN1);
        button2 = PORTReadBits(IOPORT_G, BTN2);
        LATGCLR = LED1|LED2;
        if(button1 == 1)
        {
            LATGSET = LED1;
        }
        if(button2 == 1)
        {
            LATGSET = LED2;
        }
    }
}