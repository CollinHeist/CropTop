/**
 *	File
 *		main.h
 *	Summary
 *		Main program header file. Provides basic configurations for system interfaces.
 *	Author(s)
 *		Collin Heist
 */

#ifndef __MAIN_H__
	#define __MAIN_H__

	// Operational Configurations
	#define POTENTIOMETER_SAMPLE_FREQ_HZ	(500)				// How fast (in Hz) to sample the potentiometer inputs	
	#define I2C1_GNSS_FREQ_HZ				(100000)			// 100kB clock line for GNSS Reciever module
	#define TEMPERATURE_MODE				(FAHRENHEIT_MODE)	// What result temperature values are returned in
	#define SCREEN_UART_BAUD				(9600)				// Startup UART baud rate to the Nextion device
																// I would not change this at boot, but once communication
																// has been established, this can be changed freely.

	// Function Prototypes
	static unsigned int initialize_system(void);
#endif