/**
 *	File
 *		hardware.h
 *	Summary
 *		Shared hardware header file. Gives useful macros for error-handling, switch operation,
 *      LED toggling, and system timings.
 *	Author(s)
 *		Collin Heist
 */

#define _SUPPRESS_PLIB_WARNING

#ifndef __HARDWARE_H__
	#define __HARDWARE_H__

	// Macros for error-detection
	#define NO_ERROR                (0)
	#define ERROR                   (1)
    #define TRUE                    (1)
    #define FALSE                   (0)

    // Shared Pin Configurations
    #define DEBUG_BTN_2_PIN         (BIT_7)     // DEBUG_BTN_1 is Pin 92, RA7
    #define DEBUG_BTN_2_PORT        (IOPORT_A)
    #define DEBUG_BTN_3_PIN         (BIT_6)     // DEBUG_BTN_2 is Pin 91, RA6
    #define DEBUG_BTN_3_PORT        (IOPORT_A)
    #define DEBUG_BTN_4_PIN         (BIT_0)     // DEBUG_BTN_3 is Pin 90, RG0
    #define DEBUG_BTN_4_PORT        (IOPORT_G)
    #define DEBUG_LED_1_PIN         (BIT_1)     // DEBUG_LED_1 is Pin 89, RG1
    #define DEBUG_LED_1_PORT        (IOPORT_G)
    #define DEBUG_LED_2_PIN         (BIT_1)     // DEBUG_LED_2 is Pin 91, RA6
    #define DEBUG_LED_2_PORT        (IOPORT_F)
    #define DEBUG_LED_3_PIN         (BIT_0)     // DEBUG_LED_3 is Pin 90, RG0
    #define DEBUG_LED_3_PORT        (IOPORT_F)
    #define TOTAL_NUMBER_PINS       (100)

	// System timing definitions
	#define GetSystemClock()		(80000000ul)
	#define GetInstructionClock()	(GetSystemClock()/2)	
	#define GetPeripheralClock()	(GetSystemClock()/1)	
	#define CORE_MS_TICK_RATE		(GetInstructionClock()/1000)

    // Function Prototypes
    unsigned int initialize_shared_hardware(void);
    inline void software_delay_ms(unsigned int milliseconds);
    inline unsigned int read_button2(void);
    inline unsigned int read_button3(void);
    inline unsigned int read_button4(void);
    inline unsigned int read_button2(void);
    inline void toggle_LED1(void);
    inline void toggle_LED2(void);
    inline void toggle_LED3(void);
#endif