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
#include "I2CLib.h"
#include "Si7006.h"
#include "AccelLib.h"
#include "GPSLib.h"
#include "Expo.h"

int main()
{
    initialize_system();
    int i;
    struct system_variables sys_vars;
    while(1)
    {
        i = 0;
        while(i<1000)
        {
            i++;
        }
        system_variables_update(&sys_vars);
	}
}
void initialize_system()
{
	SYSTEMConfig(GetSystemClock(), SYS_CFG_WAIT_STATES | SYS_CFG_PCACHE);
    PORTSetPinsDigitalIn(IOPORT_C, BUTTONS);
    PORTSetPinsDigitalOut(IOPORT_C, LEDS);
    PotLib_Init();
    MotorLib_Init();
    I2CLib_Init();
    AccelLib_Init();
    INTEnableSystemMultiVectoredInt();
}