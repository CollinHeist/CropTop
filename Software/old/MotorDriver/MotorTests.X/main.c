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
 *              fixed the PWM duty cycle in this version
 *              need to workout the fault indication
 * 
 *              Hardware things:
 *              
 * *************************************************************************/
#define _SUPPRESS_PLIB_WARNING
#include <plib.h>
#include "config_bits.h"
#include "crop_top.h"
#include "MotorLib.h"

int main()
{
    //local variables
    initialize_system();
    while(1)
    {
        MotorLib_ForwardBackwardTest(60);
//        MotorLib_Coast();
    }
}

void initialize_system()
{
    SYSTEMConfig(GetSystemClock(), SYS_CFG_WAIT_STATES | SYS_CFG_PCACHE);
    PORTSetPinsDigitalIn(IOPORT_C, BUTTONS);
    PORTSetPinsDigitalOut(IOPORT_C, LEDS);
    MotorLib_Init();	
    INTEnableSystemMultiVectoredInt();
}