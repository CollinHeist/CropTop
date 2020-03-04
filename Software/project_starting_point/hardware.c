/**
 *	File
 *		hardware.c
 *	Summary
 *		Shared hardware source file. Provides setup and access functions for debug hardware.
 *	Author(s)
 *		Collin Heist
 */

/* ----------------------------------- File Inclusion ----------------------------------- */

#include <plib.h>
#include "hardware.h"

/* -------------------------- Global Variables and Structures --------------------------- */

// typedef struct pin {
// 	unsigned char number;
// 	unsigned char is_available;
// 	char port; 
// 	unsigned int port_pin;
// 	char use[10];
// } pin;

// pin available_pins[TOTAL_NUMBER_PINS] = {
// 	{1, TRUE,   'G', BIT_15, ""},
// 	{2, FALSE,  '\0',  0,      "VDD"},
// 	{3, FALSE,  'E', BIT_5,  "SD_CS"},
	
// 	{11, FALSE, 'G', BIT_7,  "SD_MISO"},
// 	{12, FALSE, 'G', BIT_8,  "SD_MOSI"},
	
// 	{49, TRUE,  'F', BIT_4,  "PMOD_TX"},
// 	{50, TRUE,  'F', BIT_5,  "PMOD_RX"},
	
// 	{52, FALSE, 'F', BIT_2,  "ADI_MISO"},
// 	{53, FALSE, 'F', BIT_8,  "ADI_MOSI"}
// };

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
    // Fundamental hardware configurations
    SYSTEMConfig(GetSystemClock(), SYS_CFG_WAIT_STATES | SYS_CFG_PCACHE);
    DDPCONbits.JTAGEN = 0;
    
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
 *		Helper function to clear a given character array (set all values to '\0').
 *	Parameters
 *		buffer[in]: Character pointer to the first value in the array to be cleared.
 *      length[in]: Unsigned integer that is how many bytes to clear from the buffer.
 *	Returns
 *		None.
 */
inline void clear_buffer(char * buffer, unsigned int length) {
    unsigned int i;
    for (i = 0; i < length; i++) { buffer[i] = '\0'; }
}

/**
 *	Summary
 *		Helper function to essentially replace strcpy but does not stop at null characters.
 *	Parameters
 *		destination[out]: Character pointer to the first value in the array to be copied INTO.
 *      source[in]: Character pointer to the first value in the array to be copied FROM.
 *      length[in]: Unsigned integer that is how many bytes to copy from source -> destination.
 *	Returns
 *		None.
 *  Note
 *      This function is required because strcpy stops at '\0' by default, and will not work
 *      for event parsing the responses from the screen. This function clears the destination
 *      buffer before any copying takes place.
 */
inline void copy_buffer(char * destination, char * source, unsigned int length) {
    unsigned int i;                                                 // Indexing variable
    clear_buffer(destination, length);                              // Clear the destination
    for (i = 0; i < length; i++) { destination[i] = source[i]; }    // Copy loop
}

/**
 *	Summary
 *		Software-only blocking millisecond delay (primarily) for debugging.
 *	Parameters
 *		milliseconds[in]: Unsigned integers that is how many milliseconds to delay.
 *	Returns
 *		None.
 */
inline void software_delay_ms(unsigned int milliseconds) {
	unsigned int i, j;
	for (i = 0; i < milliseconds; i++) { for (j = 0; j < SOFTWARE_1MS_COUNT; j++) {} }
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
