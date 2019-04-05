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
#include "config_bits.h"
#include "crop_top.h"
#include "MotorLib.h"
#include "PotLib.h"

int main()
{
    initialize_system();
    unsigned int TestRead;
    while(1)
    {
//        TestRead = PotLib_SingleRead();
        LATCSET = LED_A;
    }
}
void initialize_system()
{
	SYSTEMConfig(GetSystemClock(), SYS_CFG_WAIT_STATES | SYS_CFG_PCACHE);
    PORTSetPinsDigitalIn(IOPORT_C, BUTTONS);
    PORTSetPinsDigitalOut(IOPORT_C, LEDS);
    PotLib_Init();
    MotorLib_Init();
    INTEnableSystemMultiVectoredInt();
}