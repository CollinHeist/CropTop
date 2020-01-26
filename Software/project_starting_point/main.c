/** 
 *	@file 	main.c
 *	@brief	Main program source file. Provides basic macros for operational configurations.
 *	@author	Collin Heist, Ryan Donahue
 **/

/* ----------------------------------- File Inclusion ----------------------------------- */

#define _SUPPRESS_PLIB_WARNING

#include "config_bits.h"	// Do only once
#include "main.h"
#include <plib.h>
#include <stdio.h>
#include "hardware.h"

#include "FT8xx.h"
#include "display_library.h"
#include "motors.h"
#include "potentiometer.h"
#include "I2CLib.h"
#include "temp_humidity.h"
#include "accelerometer.h"
#include "GPSLib.h"
#include "Expo.h"

/* -------------------------- Global Variables and Structures --------------------------- */

/*
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

/* ---------------------------------- Public Functions ---------------------------------- */

int main() {
	if (initialize_system() == ERROR)
		return;		// An error occurred while running
	APP_Init();
	
	//Enable Touch	
//	EVE_MemWrite8(REG_TOUCH_MODE, TOUCHMODE_FRAME);
	
//	APP_Calibrate();
	
	char buf[200];
	struct system_variables sv;
	
	float temp_c_moving = 1;
	float temp_f_moving = 1;
	float humidi_moving = 1;
	double tilt_moving = 1;
	float moving_N = 500;
	
	int first = 0;
	  
	// Sizes:   30  22  18  16
	
	EVE_MemWrite16(REG_TOUCH_CONFIG, 0x8381);
	uint16_t v = EVE_MemRead16(REG_TOUCH_CONFIG);
	
	while (1)
	{
		uint32_t xy = EVE_MemRead32(REG_TOUCH_SCREEN_XY);
//		uint32_t xy = EVE_MemRead32(REG_TOUCH_DIRECT_XY);
		
		uint32_t raw = EVE_MemRead32(REG_TOUCH_RAW_XY);
//		uint32_t raw = EVE_MemRead32(REG_TOUCH_DIRECT_Z1Z2);
		
		uint16_t rz = EVE_MemRead16(REG_TOUCH_RZ);
		
		uint16_t w = EVE_MemRead16(REG_TOUCH_CONFIG);
		
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
		
		tilt_moving -= tilt_moving / moving_N;
		tilt_moving += sv.tilt / moving_N;
	
		API_LIB_BeginCoProList();
		API_CMD_DLSTART();
		
//		API_CLEAR_COLOR_RGB(0, 0, 0);
		API_CLEAR_COLOR_RGB(0xFF, 0xFF, 0xFF);
		API_CLEAR(1,1,1);
		
//		API_COLOR_RGB(0xFF, 0xFF, 0xFF);
		API_COLOR_RGB(0, 0, 0);

		
		sprintf(buf, "Date: %02d - %02d - %d", sv.day, sv.month, sv.year);
		API_CMD_TEXT(10, 10, 22, 0, buf);
		
		sprintf(buf, "Latitude: %s  |  Longitude: %s", sv.latitude, sv.longitude);
		API_CMD_TEXT(10, 40, 22, 0, buf);
		
		sprintf(buf, "Board Temperature (C): %0.3f (%f)", temp_c_moving, sv.temp_c);
		API_CMD_TEXT(10, 70, 22, 0, buf);
		
		sprintf(buf, "Board Temperature (F): %0.3f (%f)", temp_f_moving, sv.temp_f);
		API_CMD_TEXT(10, 100, 22, 0, buf);
		
		sprintf(buf, "Humidity: %.3f (%f)", humidi_moving, sv.humidity);
		API_CMD_TEXT(10, 130, 22, 0, buf);
		
		sprintf(buf, "Tilt: %5.3lf", sv.tilt);
		API_CMD_TEXT(10, 160, 22, 0, buf);
		
		sprintf(buf, "ADC_RAW: %d  |  ADC: %f", sv.adc_raw, sv.adc_nominal);
		API_CMD_TEXT(10, 190, 22, 0, buf);
		
		
		
		///////////////////////////////////////////////////////////////////////////////
		
		
//		uint32_t xy = 0xFFFFFFFF;

		sprintf(buf, "RAW: 0x%08x  |  TOUCH: 0x%08x  |  RZ: 0x%04x", raw, xy, rz);
		API_CMD_TEXT(10, 220, 22, 0, buf);
		
		sprintf(buf, "A: 0x%08x  |  B: 0x%08x  |  C: 0x%08x", REG_TOUCH_TRANSFORM_A, REG_TOUCH_TRANSFORM_B, REG_TOUCH_TRANSFORM_C);
		API_CMD_TEXT(10, 250, 22, 0, buf);
		
		sprintf(buf, "D: 0x%08x  |  E: 0x%08x  |  F: 0x%08x", REG_TOUCH_TRANSFORM_D, REG_TOUCH_TRANSFORM_E, REG_TOUCH_TRANSFORM_F);
		API_CMD_TEXT(10, 280, 22, 0, buf);
		
		sprintf(buf, "v: 0x%04x  |  w: 0x%04x", v, w);
		API_CMD_TEXT(10, 310, 22, 0, buf);

		
		
		
		
		
		sprintf(buf, "LCD Firmware: Conrad Mearns");
		API_CMD_TEXT(10, 360, 23, 0, buf);
		
		sprintf(buf, "Backend Firmware: Ryan Donahue");
		API_CMD_TEXT(10, 400, 23, 0, buf);
		
		sprintf(buf, "Board Design: Kennedy Caisley");
		API_CMD_TEXT(10, 440, 23, 0, buf);
		
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
			
//		MCU_Delay_ms(20);
	}
}

/* --------------------------------- Private Functions ---------------------------------- */

static unsigned int initialize_system(void) {
    // Fundamental hardware configurations
    SYSTEMConfig(GetSystemClock(), SYS_CFG_WAIT_STATES | SYS_CFG_PCACHE);
    DDPCONbits.JTAGEN = 0;

    // Configure debug buttons and LEDs
    mPORTASetPinsDigitalIn(SWITCH_2 | SWITCH_3);
    mPORTGSetPinsDigitalIn(SWITCH_4);
    mPORTGSetPinsDigitalOut(LED_A);
    mPORTFSetPinsDigitalOut(LED_B | LED_C);
    ALL_LEDS_OFF();

    // Initialize subsystems
    unsigned int error_flag = NO_ERROR;
    error_flag |= initialize_potentiometer(POTENTIOMETER_SAMPLE_FREQ_HZ);
    error_flag |= initialize_motors();
    error_flag |= initialize_i2c(I2C1_GNSS_FREQ_HZ);
    error_flag |= initialize_accelerometer();
    error_flag |= initialize_display();

    INTEnableSystemMultiVectoredInt();

    return error_flag;
}

/* ----------------------------- Interrupt Service Routines ----------------------------- */

