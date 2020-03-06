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

/* ---------------------------------- Public Functions ---------------------------------- */

int main() {
	if (initialize_system() == ERROR)
		Nop();		// An error occurred while running
	
	while (1) {
		parse_screen_response();
	}
	return 1;
}

/* --------------------------------- Private Functions ---------------------------------- */

static unsigned int initialize_system(void) {
	// Initialize primary shared hardware
	unsigned int error_flag = NO_ERROR;
	error_flag |= initialize_shared_hardware();

	// Initialize subsystems
	error_flag |= initialize_potentiometer(POTENTIOMETER_SAMPLE_FREQ_HZ);
	error_flag |= initialize_motors();
	error_flag |= initialize_I2C1(I2C1_GNSS_FREQ_HZ);
//	error_flag |= initialize_accelerometer();
	error_flag |= initialize_screen(SCREEN_UART_BAUD);

	INTEnableSystemMultiVectoredInt();

	return error_flag;
}

/* ----------------------------- Interrupt Service Routines ----------------------------- */