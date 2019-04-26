/* **************************************************************************
 * 
 * To become DisplayAPP.c, this only operates as main.c for testing purposes!
 * 
 * File name:   main.c
 * Association: University of Idaho
 * Author:      Conrad Mearns
 * Dates:       Created 3/22/2018
 * Summary:     Application level driver for 7" Touchscreen
 * Notes:       
 * *************************************************************************/
#define _SUPPRESS_PLIB_WARNING
#include <plib.h>
#include "config_bits.h"
#include "crop_top.h"
//#include "FT8xx.h"
//#include <stdio.h>
//#include "DisplayLib.h"
#include "MotorLib.h"
//#include "PotLib.h"
//#include "I2CLib.h"
//#include "Si7006.h"
//#include "AccelLib.h"
//#include "GPSLib.h"
//#include "Expo.h"

int main()
{
    initialize_system();
    int ButtonA, ButtonB;
    while (1)
    {
//        system_variables_update(&sv);
//        MotorLib_ForwardBackwardTest(50);
        ButtonA = (PORTReadBits(IOPORT_C, BUTTON_A))>>14;
        ButtonB = (PORTReadBits(IOPORT_C, BUTTON_B))>>13;
        if((ButtonA == 1) && (ButtonB ==0))
        {

            MotorLib_Forward(100);
        }
    }
}
    
void initialize_system()
{
	SYSTEMConfig(GetSystemClock(), SYS_CFG_WAIT_STATES | SYS_CFG_PCACHE);
    DDPCONbits.JTAGEN = 0;
    PORTSetPinsDigitalIn(IOPORT_C, BUTTONS);
    PORTSetPinsDigitalOut(IOPORT_C, LEDS);
    LATCCLR = LED_A;
    MotorLib_Init();
    INTEnableSystemMultiVectoredInt();
}
