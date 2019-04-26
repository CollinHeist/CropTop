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
#include "FT8xx.h"
#include <stdio.h>
#include "DisplayLib.h"
#include "MotorLib.h"
#include "PotLib.h"
#include "I2CLib.h"
#include "Si7006.h"
#include "AccelLib.h"
#include "GPSLib.h"
#include "Expo.h"

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
    
//    APP_Calibrate();
    
    char buf[50];
    struct system_variables sv;
    
    float temp_c_moving = 1;
    float temp_f_moving = 1;
    float humidi_moving = 1;
    float moving_N = 200;
    
    int first = 0;
    
    // Sizes:   30  22  18  16
    
    while (1)
    {
        system_variables_update(&sv);
        
        if (0 == first)
        {
            first++;
            temp_c_moving = sv.temp_c;
            temp_f_moving = sv.temp_f;
            humidi_moving = sv.humidity;
        }
        
        temp_c_moving -= temp_c_moving / moving_N;
        temp_c_moving += sv.temp_c / moving_N;
        
        temp_f_moving -= temp_f_moving / moving_N;
        temp_f_moving += sv.temp_f / moving_N;
        
        humidi_moving -= humidi_moving / moving_N;
        humidi_moving += sv.humidity / moving_N;
    
        API_LIB_BeginCoProList();
        API_CMD_DLSTART();
        
//        API_CLEAR_COLOR_RGB(0, 0, 0);
        API_CLEAR_COLOR_RGB(0xFF, 0xFF, 0xFF);
        API_CLEAR(1,1,1);
        
//        API_COLOR_RGB(0xFF, 0xFF, 0xFF);
        API_COLOR_RGB(0, 0, 0);

        
        sprintf(buf, "Date: %02d - %02d - %d  |  Time: %d:%02d", sv.day, sv.month, sv.year, sv.hour, sv.minute);
        API_CMD_TEXT(10, 10, 22, 0, buf);
        
        sprintf(buf, "Latitude: %s  |  Longitude: %s", sv.latitude, sv.longitude);
        API_CMD_TEXT(400, 10, 22, 0, buf);
        
        sprintf(buf, "Board Temperature (C): %0.3f (%f)", temp_c_moving, sv.temp_c);
        API_CMD_TEXT(10, 40, 22, 0, buf);
        
        sprintf(buf, "Board Temperature (F): %0.3f (%f)", temp_f_moving, sv.temp_f);
        API_CMD_TEXT(10, 70, 22, 0, buf);
        
        sprintf(buf, "Humidity: %.3f (%f)", humidi_moving, sv.humidity);
        API_CMD_TEXT(10, 100, 22, 0, buf);
        
        sprintf(buf, "Tilt: %f", sv.tilt);
        API_CMD_TEXT(10, 130, 22, 0, buf);
        
        sprintf(buf, "ADC_RAW: %d  |  ADC: %f", sv.adc_raw, sv.adc_nominal);
        API_CMD_TEXT(10, 160, 22, 0, buf);
        
        
        int lx=700,ly=130,ls=16;
        
        API_BEGIN(LINES);
        API_COLOR_RGB(0, 0, 0);
        API_LINE_WIDTH(4*16);
        //Stalk
        API_VERTEX2F((lx * 16), (ly * 16));
        API_VERTEX2F((lx * 16), ((ly+220) * 16));
        //Arrow
        API_VERTEX2F((lx * 16), (ly * 16));
        API_VERTEX2F(((lx-30) * 16), ((ly-20) * 16));
        API_VERTEX2F((lx * 16), (ly * 16));
        API_VERTEX2F(((lx+30) * 16), ((ly-20) * 16));
        API_VERTEX2F((lx * 16), ((ly-70) * 16));
        API_VERTEX2F(((lx-30) * 16), ((ly-20) * 16));
        API_VERTEX2F((lx * 16), ((ly-70) * 16));
        API_VERTEX2F(((lx+30) * 16), ((ly-20) * 16));
        int yoff = 60;
        int xoff = 60;
        int yi, xi;
        for (xi = -1; xi < 2; xi+=2)
        {
            for (yi = 0; yi < 3; yi++)
            {
                API_VERTEX2F((lx * 16), (((ly+18) + yoff*yi) * 16));
                API_VERTEX2F(((lx - xoff*xi) * 16), (((ly-20) + yoff*yi) * 16));

                API_VERTEX2F((lx * 16), (((ly+58) + yoff*yi) * 16));
                API_VERTEX2F(((lx - xoff*xi) * 16), (((ly+20) + yoff*yi) * 16));

                API_VERTEX2F(((lx - xoff*xi) * 16), (((ly-20) + yoff*yi) * 16));
                API_VERTEX2F(((lx - xoff*xi) * 16), (((ly+20) + yoff*yi) * 16));
            }
        }
        API_VERTEX2F((lx * 16), ((ly+180) * 16));
        API_VERTEX2F(((lx-50) * 16), ((ly+200) * 16));
        API_VERTEX2F(((lx-50) * 16), ((ly+200) * 16));
        API_VERTEX2F(((lx-50) * 16), ((ly+250) * 16));

        API_VERTEX2F((lx * 16), ((ly+190) * 16));
        API_VERTEX2F(((lx+50) * 16), ((ly+210) * 16));
        API_VERTEX2F(((lx+50) * 16), ((ly+210) * 16));
        API_VERTEX2F(((lx+50) * 16), ((ly+270) * 16));
        API_END();

        API_BEGIN(FTPOINTS);                                       	
        API_POINT_SIZE(20*16);
        API_COLOR_RGB(0, 0, 0);                     
        API_VERTEX2F((lx*16), ((ly+220)*16));
        API_VERTEX2F(((lx-50)*16), ((ly+250)*16));
        API_VERTEX2F(((lx+50)*16), ((ly+270)*16));
        API_POINT_SIZE(12*16);
        API_COLOR_RGB(0xFF, 0xFF, 0xFF);
        API_VERTEX2F((lx*16), ((ly+220)*16));
        API_VERTEX2F(((lx-50)*16), ((ly+250)*16));
        API_VERTEX2F(((lx+50)*16), ((ly+270)*16));
        API_END();
        
        
        
        API_DISPLAY();
        API_CMD_SWAP();

        API_LIB_EndCoProList();
        API_LIB_AwaitCoProEmpty();
            
//        MCU_Delay_ms(20);
    }
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
