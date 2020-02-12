/** 
 *  @file 	motors.c
 *  @brief	Motor library source file. Implements all basic motor functionality.
 *  @authors	Collin Heist, Ryan Donahue.
 **/

/* ----------------------------------- File Inclusion ----------------------------------- */

#define _SUPPRESS_PLIB_WARNING
#include <plib.h>
#include "hardware.h"
#include "motors.h"

/* -------------------------- Global Variables and Structures --------------------------- */

/* ---------------------------------- Public Functions ---------------------------------- */

/**	
 *  @brief	Initializes the GPIO, interrupts, and timers for motor operation.
 *  @param	None.
 *  @return	unsigned int that is the error flag if an error occurred.
 **/
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
 *  @brief	Sets output PWM signal to move forwards.
 *  @param[in]	speed: Unsigned int the denotes at what normalized (0-100) speed to move forward at.
 *  @return	unsigned int that is the error flag if a non-normalized value was entered.
 **/
unsigned int motor_forward(unsigned int speed) {
    return motor_set_duty_cycle(speed, 0);
}

/**	
 *  @brief	Sets output PWM signal to move in reverse.
 *  @param[in]	speed: Unsigned int the denotes at what normalized (0-100) speed to move in reverse.
 *  @return	unsigned int that is the error flag if a non-normalized value was entered.
 **/
unsigned int motor_reverse(unsigned int speed) {
    return motor_set_duty_cycle(0, speed);
}

/**	
 *	@brief		Sets the output PWM signals to a high impedance state to 'coast' the motor.
 *	@param		None
 *	@return		unsigned int that is the error flag if a non-normalized value was entered.
 **/
unsigned int motor_coast(void) {
    return motor_set_duty_cycle(0, 0);
}

/**	
 *	@brief		Sets the output PWM signals to break the motor through low-side decay.
 *	@param		None
 *	@return		unsigned int that is the error flag if a non-normalized value was entered.
 **/
unsigned int motor_brake(void) {
    return motor_set_duty_cycle(100, 100);
}

/**	
 *	@brief		Reads the status of SW2, SW3 to control the operation of the linear actuator.
 *	@param[in]	speed: Unsigned int that denotes at what normalized (0-100) speed to move forward / backwards at.
 *	@return		None.
 **/
void motor_test_mode(unsigned int speed) {
    if ((read_button2() != 0) && (read_button3() == 0))
	motor_forward(speed);
    else if ((read_button2() == 0) && (read_button3() == 1))
	motor_reverse(speed);
    else
	motor_coast();
}

/* --------------------------------- Private Functions ---------------------------------- */

/**	
 *	@brief		Updates the PWM register values for OC2 and OC3
 *	@param[in]	speed: Unsigned int the denotes at what normalized (0-100) duty cycle value to move at. 
 *	@return		unsigned int that is the error flag if a non-normalized value was entered.
 **/
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

/* ----------------------------- Interrupt Service Routines ----------------------------- */

/**	
 *	@brief		ISR for INT1 - the DC_FAULT pin. Triggers on falling edge and beings coasting the motors.
 *	@param		None.
 *	@return		None.
 **/
void __ISR(_EXTERNAL_1_VECTOR, IPL1) isr_motor_fault(void) {
    // Check that it was a motor fault
    if (READ_MOTOR_FAULT_PIN()) {
	motor_coast();	// Stop the motor

	// Flick a light or ideally trigger a semaphore that unblocks a warning screen
	mINT1ClearIntFlag();
    }
}

/**	
 *  @brief  ISR for timer 2. Currently does nothing; but can have additional functionality if desired.
 *  @param  None.
 *  @return None.
 **/
void __ISR(_TIMER_2_VECTOR, IPL1SOFT) isr_timer2(void) {
    mT2ClearIntFlag();
}