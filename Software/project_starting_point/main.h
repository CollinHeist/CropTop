/** 
 *	@file 	main.h
 *	@brief	Main program header file. Provides basic macros for operational configurations.
 *	@author	Collin Heist
 **/

#define _SUPPRESS_PLIB_WARNING

#ifndef __MAIN_H__
	#define __MAIN_H__

	// Operational Configurations
	#define POTENTIOMETER_SAMPLE_FREQ_HZ		(500)		// How fast (in Hz) to sample the potentiometer inputs	
    #define I2C1_GNSS_FREQ_HZ                   (100000)    // 100kB clock line for GNSS Reciever module

	// Function Prototypes
	static unsigned int initialize_system(void);
#endif