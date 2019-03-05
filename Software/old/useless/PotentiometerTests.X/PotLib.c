/* **************************************************************************
 * File name:   PotLib.c
 * Association: University of Idaho
 * Author:      Ryan Donahue
 * Dates:       Created 1/9/2018
 * 
 * Summary:     This file contains a collection of functions and macros used to 
 *              enable the PIC32 ADC peripheral. The measurements will be used
 *              to encode the position of a rotary or linear potentiometer.
 * 
 * Notes:       Software things:
 *
 *              Hardware things:
 *              
 * *************************************************************************/

//includes and definitions
#define _SUPPRESS_PLIB_WARNING
#include <plib.h>

//macros
#define AN9 (0x01<<9)   //port b

void PotLib_Init()
{
    //enable GPIO
    PORTSetPinsAnalogIn(IOPORT_B, AN9);
    //enable the peripheral
    
}