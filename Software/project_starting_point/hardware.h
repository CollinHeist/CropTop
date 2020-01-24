/** 
 *	@file 	hardware.h
 *	@brief	Shared hardware header file. Gives useful macros for error-handling, switch operation,
 *			LED toggling, and system timings.
 *	@author	Collin Heist
 **/

#define _SUPPRESS_PLIB_WARNING

#ifndef __HARDWARE_H__
	#define __HARDWARE_H__

	// Macros for error-detection
	#define NO_ERROR                (0)
	#define ERROR                   (1)

	// Hardware macros
	#define SWITCH_2				(BIT_7)		// SW2 is Pin 92, RA7
	#define SWITCH_3				(BIT_6)		// SW3 is Pin 91, RA6
	#define SWITCH_4				(BIT_0)		// SW4 is Pin 90, RG0
	#define READ_SWITCH_2()			(PORTA & SWITCH_2)
	#define READ_SWITCH_3()			(PORTB & SWITCH_3)
	#define READ_SWITCH_4()			(PORTG & SWITCH_4)
	#define LED_A					(BIT_1)		// LEDA (D22) is Pin 89, RG1
	#define LED_B					(BIT_1)		// LEDB (D23) is Pin 88, RF1
	#define LED_C					(BIT_0)		// LEDC (D24) is Pin 87, RF0
	#define ALL_LEDS_OFF()			{LATGCLR = LED_A; LATFCLR = LED_B | LED_C;}

	// System timing definitions
	#define GetSystemClock()		(80000000ul)
	#define GetInstructionClock()	(GetSystemClock()/2)	
	#define GetPeripheralClock()	(GetSystemClock()/1)	
	#define CORE_MS_TICK_RATE		(GetInstructionClock()/1000)
#endif