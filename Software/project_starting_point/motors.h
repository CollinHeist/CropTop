/** 
 *	@file 	motors.h
 *	@brief	Motor library header file. Provides useful macros for timer 2, PWM, and pin configurations.
 *	@author	Collin Heist, Ryan Donahue.
 **/

#define _SUPPRESS_PLIB_WARNING

#ifndef __MOTORLIB_H__
	#define __MOTORLIB_H__

	// Timer 2 Configurations
	#define T2_PRESCALE				(16)
	#define T2_TOGGLES_PER_SEC		(1000)
	#define PR2_VALUE				(GetPeripheralClock() / T2_PRESCALE / T2_TOGGLES_PER_SEC)

	// PWM Configurations
	#define MOTOR_DUTY_CYCLE_START_PERCENT	(0)	// Start out at 0% duty cycle
	#define MOTOR_START_PR_VALUE			(MOTOR_DUTY_CYCLE_START_PERCENT * PR2_VALUE)

	// Pin Configurations
	#define MOTOR_OUT_1				(BIT_1)		// DC_PWM_1 / OC2 is Pin 76, RD1
	#define MOTOR_OUT_2				(BIT_2)		// DC_PWM_2 / OC3 is Pin 77, RD2
	#define MOTOR_FAULT_PIN			(BIT_8)		// DC_FAULT / INT1, is pin 18, RE8

	// Function Prototypes
	unsigned int initialize_motors(void);
	unsigned int motor_forward(unsigned int speed);
	unsigned int motor_reverse(unsigned int speed);
	unsigned int motor_coast(void);
	unsigned int motor_brake(void);
	void motor_test_mode(unsigned int speed);
	static unsigned int motor_set_duty_cycle(unsigned int oc2_cycle_percent, unsigned int oc3_cycle_percent);
#endif