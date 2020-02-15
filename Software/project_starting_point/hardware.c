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

typedef struct pin {
	unsigned char number;
	unsigned char is_available;
	char port; 
	unsigned int port_pin;
	char use[10];
} pin;

pin available_pins[TOTAL_NUMBER_PINS] = {
	{1, TRUE,   'G', BIT_15, ""},
	{2, FALSE,  '\0',  0,      "VDD"},
	{3, FALSE,  'E', BIT_5,  "SD_CS"},
	
	{11, FALSE, 'G', BIT_7,  "SD_MISO"},
	{12, FALSE, 'G', BIT_8,  "SD_MOSI"},
	
	{49, TRUE,  'F', BIT_4,  "PMOD_TX"},
	{50, TRUE,  'F', BIT_5,  "PMOD_RX"},
	
	{52, FALSE, 'F', BIT_2,  "ADI_MISO"},
	{53, FALSE, 'F', BIT_8,  "ADI_MOSI"}
};

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

inline void software_delay_ms(unsigned int milliseconds) {
	unsigned int i, j;
	for (i = 0; i < milliseconds; i++) { for (j = 0; j < 8000; j++) {} }
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
