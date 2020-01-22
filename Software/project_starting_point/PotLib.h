/** 
 *	@file 	PotLib.h
 *	@brief	Potentiometer library header file. Provides useful macros for T3 configuration.
 *	@author	Collin Heist
 **/

#define _SUPPRESS_PLIB_WARNING

#ifndef __POTLIB_H__
	#define __POTLIB_H__

	// Timer 3 Configurations
	#define TIMER3_BASE_FREQ	(GetPeripheralClock())	// Base (undivided) frequency of T3
	#define TIMER3_MAX_PR_VAL	(1 << 16)				// The maximum value of T3 is 2^16
	#define TIMER3_PS_ERROR		(-1.0)	

	// Function prototypes
	unsigned int initialize_potentiometer(float sample_frequency);
	unsigned int reconfigure_timer3(float timer3_frequency);
	unsigned int read_potentiometer(void);
	static unsigned int initialize_timer3(float timer3_frequency);
#endif

