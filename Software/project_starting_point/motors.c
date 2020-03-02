/**
 *	File
 *		motors.c
 *	Summary
 *		Motor library source file. Implements all basic motor functionality; such as moving
 *		forward, backwards, coasting, and braking. Also has the ISR for motor faults.
 *	Author(s)
 *		Collin Heist, Ryan Donahue
 */

/* ----------------------------------- File Inclusion ----------------------------------- */

#include <plib.h>

#include "hardware.h"
#include "motors.h"

/* -------------------------- Global Variables and Structures --------------------------- */

/* ---------------------------------- Public Functions ---------------------------------- */

/**
 *	Summary
 *		Initializes the GPIO, interrupts, and timers for motor operation.
 *	Parameters
 *		None.
 *	Returns
 *		Unsigned int that is ERROR or NO_ERROR if initialization was successful.
 */
unsigned int initialize_motors(void) {
    // Initialize the required GPIO pins for PWM outputs
    PORTSetPinsDigitalOut(MOTOR_1_PORT, MOTOR_1_PIN);
    PORTSetPinsDigitalOut(MOTOR_2_PORT, MOTOR_2_PIN);

    // Configure the interrupt for the fault detection - triggers on falling edge(?) w/ IPL1
    PORTSetPinsDigitalIn(MOTOR_FAULT_PORT, MOTOR_FAULT_PIN);
    ConfigINT1(EXT_INT_ENABLE | FALLING_EDGE_INT | EXT_INT_PRI_1);

    // Initialize timer 2 to generate level 1 interrupt every 1 millisecond
    OpenTimer2((T2_ON | T2_SOURCE_INT | T2_PS_1_16), PR2_VALUE);
    ConfigIntTimer2(T2_INT_ON | T2_INT_PRIOR_1 | T2_INT_SUB_PRIOR_0);
    mT2ClearIntFlag();
    mT2IntEnable(1);

    // Initialize output compare modules 2, 3 for their starting duty cycle
    OpenOC2(OC_ON | OC_TIMER_MODE16 | OC_TIMER2_SRC | OC_PWM_FAULT_PIN_DISABLE, MOTOR_START_PR_VALUE, MOTOR_START_PR_VALUE);
    OpenOC3(OC_ON | OC_TIMER_MODE16 | OC_TIMER2_SRC | OC_PWM_FAULT_PIN_DISABLE, MOTOR_START_PR_VALUE, MOTOR_START_PR_VALUE);

    return NO_ERROR;
}

/**
 *	Summary
 *		Sets output PWM signals to move forwards at the desired speed.
 *	Parameters
 *		speed[in]: Unsigned int that is a normalized [0-100] percentage of what speed to move at.
 *	Returns
 *		Unsigned int that is ERROR or NO_ERROR if an improper speed was entered.
 */
unsigned int motor_forward(unsigned int speed) {
    return motor_set_duty_cycle(speed, 0);
}

/**
 *	Summary
 *		Sets output PWM signals to move backwards at the desired speed.
 *	Parameters
 *		speed[in]: Unsigned int that is a normalized [0-100] percentage of what speed to move at.
 *	Returns
 *		Unsigned int that is ERROR or NO_ERROR if an improper speed was entered.
 */
unsigned int motor_reverse(unsigned int speed) {
    return motor_set_duty_cycle(0, speed);
}

/**
 *	Summary
 *		Sets output PWM signals to high-impedance states to coast the motors.
 *	Parameters
 *		None.
 *	Returns
 *		Unsigned int that is ERROR or NO_ERROR if an improper speed was entered.
 */
unsigned int motor_coast(void) {
    return motor_set_duty_cycle(0, 0);
}

/**
 *	Summary
 *		Sets output PWM signals to brake the motor through low-side decay.
 *	Parameters
 *		None.
 *	Returns
 *		Unsigned int that is ERROR or NO_ERROR if an improper speed was entered.
 */
unsigned int motor_brake(void) {
    return motor_set_duty_cycle(100, 100);
}

/**
 *	Summary
 *		Reads the status of SW2, SW3 to control the operation of the linear actuator.
 *	Parameters
 *		speed[in]: Unsigned int that is a normalized [0-100] percentage of what speed to move at.
 *	Returns
 *		Unsigned int that is ERROR or NO_ERROR if an improper speed was entered.
 */
unsigned int motor_test_mode(unsigned int speed) {
    if ((read_button2() != 0) && (read_button3() == 0))
		return motor_forward(speed);
    else if ((read_button2() == 0) && (read_button3() == 1))
		return motor_reverse(speed);
    else
		return motor_coast();
}

/* --------------------------------- Private Functions ---------------------------------- */

/**
 *	Summary
 *		Updates the PWM register values for OC2 and OC3 - the motors' registers.
 *	Parameters
 *		oc2_cycle_percent[in]: Unsigned int that is a normalized [0-100] percent to scale the OC2 register by.
 *		oc3_cycle_percent[in]: Unsigned int that is a normalized [0-100] percent to scale the OC3 register by.
 *	Returns
 *		Unsigned int that is ERROR or NO_ERROR if an improper speed was entered (<0 | >100).
 */
static unsigned int motor_set_duty_cycle(unsigned int oc2_cycle_percent, unsigned int oc3_cycle_percent) {
    if (oc2_cycle_percent > 100 || oc3_cycle_percent > 100)
		return ERROR;	// Incorrect duty cycles were entered - return an error

    // Calculate the new PWM register values
    int new_nOC2RS = (PR2_VALUE * oc2_cycle_percent / 100) - 1;
    int new_nOC3RS = (PR2_VALUE * oc3_cycle_percent / 100) - 1;

    // Update the PWM settings
    SetDCOC2PWM(new_nOC2RS);
    SetDCOC3PWM(new_nOC3RS);

    return NO_ERROR;
}

static inline unsigned int read_motor_fault_pin(void) {
	return PORTReadBits(MOTOR_FAULT_PORT, MOTOR_FAULT_PIN);
}

/* ----------------------------- Interrupt Service Routines ----------------------------- */

/**
 *	Summary
 *		ISR for INT1 - the DC_FAULT pin. Triggers on falling edge and begins coasting the motors.
 *	Parameters
 *		None.
 *	Returns
 *		None.
 */
void __ISR(_EXTERNAL_1_VECTOR, IPL1SOFT) isr_motor_fault(void) {
    // Check that it was a motor fault
    if (read_motor_fault_pin()) {
		motor_coast();	// Stop the motor
    }
	
	mINT1ClearIntFlag();
}

/**
 *	Summary
 *		ISR for Timer 2. Currently does nothing; but can have additional functionality if desired.
 *	Parameters
 *		None.
 *	Returns
 *		None.
 */
void __ISR(_TIMER_2_VECTOR, IPL1SOFT) isr_timer2(void) {
    mT2ClearIntFlag();
}