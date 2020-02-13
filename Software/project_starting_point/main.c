/**
 *	File
 *		main.c
 *	Summary
 *		Main program source file. Implements main operational loop.
 *	Author(s)
 *		Collin Heist, Ryan Donahue
 */

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
#include "GPS.h"

/* -------------------------- Global Variables and Structures --------------------------- */

/* ---------------------------------- Public Functions ---------------------------------- */

int main() {
    if (initialize_system() == ERROR)
		Nop(); //return;		// An error occurred while running
    
	
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
    error_flag |= initialize_display();

    INTEnableSystemMultiVectoredInt();

    return error_flag;
}

/* ----------------------------- Interrupt Service Routines ----------------------------- */