/* **************************************************************************
 * File name:   main.c
 * Association: University of Idaho
 * Author:      Ryan Donahue
 * Dates:       Created 1/10/2018
 * 
 * Summary:     This file contains a main loop and several functions to test
 *              the MotorLib.c library functionality.
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
#define BTN_A   (0x01 << 14)    //port C
#define BTN_B   (0x01 << 13)    //port C

int main()
{
    //local variables
    
    //setup
    PORTSetPinsDigitalIn(IOPORT_C, BTN_A | BTN_B);
    
    while(1)
    {
        ForwardBackwardTest(50);
    }
    
}

void ForwardBackwardTest(unsigned int speed)
{
    //local variables
    int ButtonA, ButtonB;
    //configure IO
    ButtonA = PORTReadBits(IOPORT_C, BTN_A);
    ButtonB = PORTReadBits(IOPORT_C, BTN_B);
    if((ButtonA == 1) && (ButtonB ==0))
    {
        MotorLib_Forward(speed);
    }
    else if((ButtonA == 0) && (ButtonB == 1))
    {
        MotorLib_Reverse(speed);
    }
    else
    {
        MotorLib_Brake();
    }
}