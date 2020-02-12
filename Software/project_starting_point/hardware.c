/**
 *	File
 *		hardware.c
 *	Summary
 *		Shared hardware source file. Provides setup and access functions for debug hardware.
 *	Author(s)
 *		Collin Heist
 */

/* ----------------------------------- File Inclusion ----------------------------------- */

#define _SUPPRESS_PLIB_WARNING
#include <plib.h>
#include "hardware.h"

/* -------------------------- Global Variables and Structures --------------------------- */

/* ---------------------------------- Public Functions ---------------------------------- */

/**
 *	Summary
 *		Initialize all shared hardware; the debug buttons and LEDs.
 *	Parameters
 *		None.
 *	Returns
 *		Unsigned int that is ERROR or NO_ERROR if initialization was successful.
 */
unsigned int initialize_shared_hardware(void) {
    // Configure debug buttons
    PORTSetPinsDigitalIn(DEBUG_BTN_2_PORT, DEBUG_BTN_2_PIN);
    PORTSetPinsDigitalIn(DEBUG_BTN_3_PORT, DEBUG_BTN_3_PIN);
    PORTSetPinsDigitalIn(DEBUG_BTN_4_PORT, DEBUG_BTN_4_PIN);
    
    // Configure debug LEDs - initialize off
    PORTSetPinsDigitalOut(DEBUG_LED_1_PORT, DEBUG_LED_1_PIN);
    PORTClearBits(DEBUG_LED_1_PORT, DEBUG_LED_1_PIN);
    PORTSetPinsDigitalOut(DEBUG_LED_2_PORT, DEBUG_LED_3_PIN);
    PORTClearBits(DEBUG_LED_2_PORT, DEBUG_LED_2_PIN);
    PORTSetPinsDigitalOut(DEBUG_LED_3_PORT, DEBUG_LED_3_PIN);
    PORTClearBits(DEBUG_LED_3_PORT, DEBUG_LED_3_PIN);
    
    return NO_ERROR;
}

/**
 *	Summary
 *		Read the current status of SW2 / Button 2.
 *	Parameters
 *		None.
 *	Returns
 *		Unsigned int that is the current status of SW2 / Button 2.
 */
inline unsigned int read_button2(void) { 
    return PORTReadBits(DEBUG_BTN_2_PORT, DEBUG_BTN_2_PIN);
}

/**
 *	Summary
 *		Read the current status of SW3 / Button 3.
 *	Parameters
 *		None.
 *	Returns
 *		Unsigned int that is the current status of SW3 / Button 3.
 */
inline unsigned int read_button3(void) { 
    return PORTReadBits(DEBUG_BTN_3_PORT, DEBUG_BTN_3_PIN);
}

/**
 *	Summary
 *		Read the current status of SW4 / Button 4.
 *	Parameters
 *		None.
 *	Returns
 *		Unsigned int that is the current status of SW4 / Button 4.
 */
inline unsigned int read_button4(void) { 
    return PORTReadBits(DEBUG_BTN_4_PORT, DEBUG_BTN_4_PIN);
}

/**
 *	Summary
 *		Toggle debug LED1.
 *	Parameters
 *		None.
 *	Returns
 *		None.
 */
inline void toggle_LED1(void) {
    PORTToggleBits(DEBUG_LED_1_PORT, DEBUG_LED_1_PIN);
}

/**
 *	Summary
 *		Toggle debug LED1.
 *	Parameters
 *		None.
 *	Returns
 *		None.
 */
inline void toggle_LED2(void) {
    PORTToggleBits(DEBUG_LED_2_PORT, DEBUG_LED_2_PIN);
}

/**
 *	Summary
 *		Toggle debug LED1.
 *	Parameters
 *		None.
 *	Returns
 *		None.
 */
inline void toggle_LED3(void) {
    PORTToggleBits(DEBUG_LED_3_PORT, DEBUG_LED_3_PIN);
}

/* --------------------------------- Private Functions ---------------------------------- */

/* ----------------------------- Interrupt Service Routines ----------------------------- */
