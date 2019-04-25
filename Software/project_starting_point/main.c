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
//#include "MotorLib.h"
//#include "PotLib.h"
#include "FT8xx.h"
#include <stdio.h>
#include "DisplayLib.h"

/*
 *
 *  The graphics engine interprets commands from the MPU host via a 4 Kbyte 
 * FIFO in the FT81x memory at RAM_CMD. 
 * 
 * The MPU/MCU writes commands into the FIFO, and the graphics engine  reads 
 *  and  executes  the  commands. 
 * 
 * The MPU/MCU  updates the register REG_CMD_WRITE to indicate  that  there 
 *  are  new  commands  in  the  FIFO, and  the  graphics  engine 
 *  updates REG_CMD_READ after commands have been executed
 
 */

int main()
{
    initialize_system();
    MCU_Init();
    APP_Init();
    
    APP_Calibrate();
    
    APP_SliderandButton();
    
    while (1)
    {           
        Nop();
    }
    
}
void initialize_system()
{
	SYSTEMConfig(GetSystemClock(), SYS_CFG_WAIT_STATES | SYS_CFG_PCACHE);
    DDPCONbits.JTAGEN = 0;
    PORTSetPinsDigitalIn(IOPORT_C, BUTTONS);
    PORTSetPinsDigitalOut(IOPORT_C, LEDS);
//    MCU_Init();//Configures FT812 SPI Bits, rename to something LCD related
    LATCCLR = LED_A;
    PotLib_Init();
    MotorLib_Init();
    INTEnableSystemMultiVectoredInt();
}
