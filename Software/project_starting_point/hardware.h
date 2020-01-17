#define _SUPPRESS_PLIB_WARNING
#ifndef __HARDWARE_H__
	#define __HARDWARE_H__

	//macros
	#define BUTTON_A    (BIT_14)                  //port c
	#define BUTTON_B    (BIT_13)                  //port c
	#define BUTTONS     (BUTTON_A | BUTTON_B)   //port c
	#define LED_A       (BIT_1)               //port c
	#define LED_B       (BIT_2)               //port c
	#define LEDS        (LED_A | LED_B)         //port c

	// System timing definitions
	#define GetSystemClock()		(80000000ul)
	#define GetInstructionClock()	(GetSystemClock()/2)	
	#define GetPeripheralClock()	(GetSystemClock()/1)	
	#define CORE_MS_TICK_RATE	(GetInstructionClock()/1000)

	// Function prototypes
	void initialize_system();
#endif