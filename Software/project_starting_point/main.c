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
<<<<<<< HEAD
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
=======
#include "MotorLib.h"
#include "PotLib.h"
#include "I2CLib.h"
#include "Si7006.h"
#include "AccelLib.h"
#include "GPSLib.h"
#include "Expo.h"
>>>>>>> master

int main()
{
    initialize_system();
<<<<<<< HEAD
    MCU_Init();
    APP_Init();
    
//    APP_Calibrate();
    
    uint8_t x = 7;
    char buf[50];
    
    while (1)
    {
        API_LIB_BeginCoProList();
        API_CMD_DLSTART();
        
        API_CLEAR_COLOR_RGB(0, 0, 0);
        API_CLEAR(1,1,1);
        
        API_COLOR_RGB(0xFF, 0xFF, 0xFF);
        
        x *= 43;
        sprintf(buf, "Here's some nonsense %d", x);
        API_CMD_TEXT(10, 10, 30, 0, buf);
        
        x *= 23;
        sprintf(buf, "Here's some more nonsense %d", x);
        API_CMD_TEXT(10, 50, 22, 0, buf);
        
        x *= 723;
        sprintf(buf, "[%d] is in brackets", x);
        API_CMD_TEXT(10, 80, 18, 0, buf);
        
        x *= 901;
        sprintf(buf, "heres sum %d", x);
        API_CMD_TEXT(10, 110, 16, 0, buf);
        
        API_DISPLAY();
        API_CMD_SWAP();

        API_LIB_EndCoProList();
        API_LIB_AwaitCoProEmpty();
            
        MCU_Delay_ms(250);
    }
    
=======
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
>>>>>>> master
}
void initialize_system()
{
	SYSTEMConfig(GetSystemClock(), SYS_CFG_WAIT_STATES | SYS_CFG_PCACHE);
    DDPCONbits.JTAGEN = 0;
    PORTSetPinsDigitalIn(IOPORT_C, BUTTONS);
    PORTSetPinsDigitalOut(IOPORT_C, LEDS);
//    MCU_Init();
    LATCCLR = LED_A;
    PotLib_Init();
    MotorLib_Init();
    I2CLib_Init();
    AccelLib_Init();
    INTEnableSystemMultiVectoredInt();
}
