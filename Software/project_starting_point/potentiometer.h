/**
 *	File
 *		potentiometer.h
 *	Summary
 *		Potentiometer library header file. Provides useful macros for T3 configuration.
 *	Author(s)
 *		Collin Heist
 */

#ifndef __POTENTIOMETER_H__
	#define __POTENTIOMETER_H__

	// ADC Mode (Volts or Newtons)
	#define MODE_VOLTS			(0)
	#define MODE_NEWTONS		(1)
	#define DEFAULT_MODE		(ADC_MODE_NEWTONS)

	// Timer 3 Configurations
	#define TIMER3_BASE_FREQ	(GetPeripheralClock())	// Base (undivided) frequency of T3
	#define TIMER3_MAX_PR_VAL	(1 << 16)				// The maximum value of T3 is 2^16
	#define TIMER3_PS_ERROR		(-1.0)	

	// Function prototypes
	unsigned int initialize_potentiometer(const float sample_frequency);
	unsigned int reconfigure_timer3(const float timer3_frequency);
	unsigned int read_potentiometer(void);
	void set_potentiometer_mode(unsigned int mode);
	static unsigned int initialize_timer3(const float timer3_frequency);
#endif

