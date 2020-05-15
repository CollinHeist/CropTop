/**
 *	File
 *		motors.h
 *	Summary
 *		Motor library header file. Provides macros for Timer 2, PWM, and pin configurations.
 *	Author(s)
 *		Collin Heist, Ryan Donahue
 */

#ifndef __MOTORS_H__
	#define __MOTORS_H__

	// Timer 2 Configurations
	#define T2_PRESCALE						(16)
	#define T2_TOGGLES_PER_SEC				(1000)
	#define PR2_VALUE						(GetPeripheralClock() / T2_PRESCALE / T2_TOGGLES_PER_SEC)

	// PWM Configurations
	#define MOTOR_DUTY_CYCLE_START_PERCENT	(0)	// Start out at 0% duty cycle
	#define MOTOR_START_PR_VALUE			(MOTOR_DUTY_CYCLE_START_PERCENT * PR2_VALUE)

	// Pin Configurations
	#define MOTOR_1_PIN						(BIT_1)		// DC_PWM_1, OC2 is Pin 76, RD1
	#define MOTOR_1_PORT					(IOPORT_D)
	#define MOTOR_2_PIN						(BIT_2)		// DC_PWM_2, OC3 is Pin 77, RD2
	#define MOTOR_2_PORT					(IOPORT_D)
	#define MOTOR_FAULT_PIN					(BIT_8)		// DC_FAULT, INT1 is Pin 18, RE8
	#define MOTOR_FAULT_PORT				(IOPORT_E)

	// Function Prototypes
	unsigned int initialize_motors(void);
	unsigned int motor_forward(const unsigned int speed);
	unsigned int motor_reverse(const unsigned int speed);
	unsigned int motor_coast(void);
	unsigned int motor_brake(void);
	unsigned int motor_test_mode(const unsigned int speed);
	static unsigned int motor_set_duty_cycle(const unsigned int oc2_cycle_percent, const unsigned int oc3_cycle_percent);
	static inline unsigned int read_motor_fault_pin(void);
#endif