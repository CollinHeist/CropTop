/* **************************************************************************
 * File name:   GPIOLib.c
 * Association: University of Idaho
 * Author:      Ryan Donahue
 * Dates:       Created 1/29/2018
 * 
 * Summary:     This file contains a collection of functions and macros used to 
 *              enable the PIC32 GPIO.
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
#define BUTTON_A    BIT_14                  //port c
#define BUTTON_B    BIT_13                  //port c
#define BUTTONS     (BUTTON_A | BUTTON_B)   //port c
#define LED_A       BIT_1                   //port c
#define LED_B       BIT_2                   //port c
#define LEDS        (LED+A | LED_B)         //port c

void GPIO_Lib_Init()
{
    //enable GPIO
    PORTSetPinsDigitalIn(IOPORT_C, BUTTONS);
    PORTSetPinsDigitalOut(IOPORT_C, LEDS);
    //enable interrupts
    
}