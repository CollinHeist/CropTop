/**
 *	File
 *		main.c
 *	Summary
 *		Main program source file. Implements main operational loop.
 *	Author(s)
 *		Collin Heist, Ryan Donahue
 */

/* ----------------------------------- File Inclusion ----------------------------------- */

#include "config_bits.h"	// Do only once
#include <plib.h>
#include <stdio.h>

#include "hardware.h"
#include "main.h"
#include "FT8xx.h"
#include "display_library.h"
#include "motors.h"
#include "potentiometer.h"
#include "I2CLib.h"
#include "temp_humidity.h"
#include "accelerometer.h"
#include "GPS.h"
#include "screen.h"

/* -------------------------- Global Variables and Structures --------------------------- */

extern char screen_buffer[DMA_BUFFER_SIZE];

/* ---------------------------------- Public Functions ---------------------------------- */

int main() {
    if (initialize_system() == ERROR)
		Nop(); //return 0;		// An error occurred while running
    
	unsigned int i = 0;
	char test_string[256] = {'\0'};
	while (1) {
		sprintf(test_string, "test: %d\n\r\0", i++);
		send_string_UART2(test_string);
		software_delay_ms(500);
		send_string_UART2(screen_buffer);
		software_delay_ms(500);
	}
	return 1;
}

/* --------------------------------- Private Functions ---------------------------------- */

static unsigned int initialize_system(void) {
    // Fundamental hardware configurations
    SYSTEMConfig(GetSystemClock(), SYS_CFG_WAIT_STATES | SYS_CFG_PCACHE);
    DDPCONbits.JTAGEN = 0;
    
    // Initialize primary shared hardware
    unsigned int error_flag = NO_ERROR;
    error_flag |= initialize_shared_hardware();

    // Initialize subsystems
    error_flag |= initialize_potentiometer(POTENTIOMETER_SAMPLE_FREQ_HZ);
    error_flag |= initialize_motors();
    error_flag |= initialize_i2c(I2C1_GNSS_FREQ_HZ);
//    error_flag |= initialize_accelerometer();
    error_flag |= initialize_screen(SCREEN_UART_BAUD);

    INTEnableSystemMultiVectoredInt();

    return error_flag;
}

/* ----------------------------- Interrupt Service Routines ----------------------------- */