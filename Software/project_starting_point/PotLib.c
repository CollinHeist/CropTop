/** 
 *	@file 		PotLib.c
 *	@brief		Potentiometer library source file. Implements all basic potentiometer ADC functionality.
 *	@author		Collin Heist, Ryan Donahue.
 **/

/* ----------------------------------- File Inclusion ----------------------------------- */

#define _SUPPRESS_PLIB_WARNING
#include <plib.h>
#include "MotorLib.h"
#include "hardware.h"
#include "PotLib.h"

/* -------------------------- Global Variables and Structures --------------------------- */

// Structure and array used to configure timer 3 to the most appropriate setting
// in order to achieve the desired sample frequency 
struct prescale_struct {
	float value;
	long int mask;
};

static struct prescale_struct prescales[] = {
	{1.0, T3_PS_1_1},
	{2.0, T3_PS_1_2},
	{4.0, T3_PS_1_4},
	{8.0, T3_PS_1_8},
	{16.0, T3_PS_1_16},
	{32.0, T3_PS_1_32},
	{64.0, T3_PS_1_64},
	{256.0, T3_PS_1_256},
	{TIMER3_PS_ERROR, (long int) TIMER3_PS_ERROR} // Error value to signify the end of the options
};

/* ---------------------------------- Public Functions ---------------------------------- */

/**	
 *	@brief		Initializes the potentiometer to sample AN9, AN10 at the desired frequency. 
 *	@param[in]	sample_frequency: Float that corresponds to what frequency AN9 and AN10 should be sampled at.
 *	@return		unsigned int that is the error flag if an error occurred trying to configure timer 3.
 **/
unsigned int initialize_potentiometer(float sample_frequency) {
	// Attempt to initialize timer 3 - exit if an error occurs
	if (initialize_timer3(sample_frequency) == ERROR)
		return ERROR;

	// Ensure the ADC is off before configuration
	CloseADC10();

	// Configure ADC to sample AN9 and AN10
	SetChanADC10(ADC_CH0_NEG_SAMPLEA_NVREF | ADC_CH0_POS_SAMPLEA_AN9 |
		ADC_CH0_NEG_SAMPLEB_NVREF | ADC_CH0_POS_SAMPLEB_AN10);

	// Turn module on | Integer output | Conversion triggered by T3 | Auto sample
	// External V+/V- reference | Disable offset test | Scan mode off | 2 Samples per interval | Dual buffer mode | Alternate mode
	// Sample time of 15 | Use internal ADC clock
	// Only scan assigned channels (do not scan all)
	// Set and use AN9 and AN10 as analog inputs
	OpenADC10(ADC_MODULE_ON | ADC_FORMAT_INTG16 | ADC_CLK_TMR | ADC_AUTO_SAMPLING_ON,
		ADC_VREF_AVDD_AVSS | ADC_OFFSET_CAL_DISABLE | ADC_SCAN_OFF | ADC_SAMPLES_PER_INT_2 | ADC_ALT_BUF_ON | ADC_ALT_INPUT_ON,
		ADC_SAMPLE_TIME_15 | ADC_CONV_CLK_INTERNAL_RC,
		SKIP_SCAN_ALL,
		ENABLE_AN9_ANA | ENABLE_AN10_ANA
	);
	EnableADC10();

    // Wait for the first conversion to complete
	while (!mAD1GetIntFlag()) {}

	// Return successfully
	return NO_ERROR;
}

/**	
 *	@brief		Reconfigures timer 3 for the desired sampling frequency.
 *	@param[in]	sample_frequency: Float that corresponds to what frequency AN9 and AN10 should be sampled at.
 *	@return		unsigned int that is the error flag if an error occurred trying to reconfigure timer 3.
 **/
unsigned int reconfigure_timer3(float sample_frequency) {
	CloseTimer3();								// Close T3 for reconfiguration
	DisableIntT3();								// Disable interrupt for T3

	// Reconfigure T3 and return the result
	return initialize_timer3(sample_frequency);	
}

/**	
 *	@brief		Take a single reading of the potentiometer.
 *	@param		None.
 *	@return		unsigned int that is the ADC result of the current sample buffer.
 **/
unsigned int read_potentiometer(void) {
	// Locate the offset of the most recent conversion in the idle buffer
	int offset = 8 * (~ReadActiveBufferADC10() & 0x01);
	
	// Return the ADC result at that buffer location
	return ReadADC10(offset);
}

/* --------------------------------- Private Functions ---------------------------------- */

/**	
 *	@brief		Initializes timer 3 for a desired frequency. Tries using the lowest timer prescale possible.
 *	@param[in]	timer3_frequency: Float that corresponds to what frequency T3 should attempt to operate at.
 *	@return		unsigned int that is the error flag if the frequency was unattainable or an incorrect value was entered.
 **/
static unsigned int initialize_timer3(float timer3_frequency) {
	unsigned int index = 0;
	
	// Return if an invalid frequency was entered
	if (timer3_frequency <= 0.0 || timer3_frequency > (float) TIMER3_BASE_FREQ)
		return ERROR;
	
	while (prescales[index].value != TIMER3_PS_ERROR) {
		float current_PR3_val = (float) TIMER3_BASE_FREQ / (float) prescales[index].value / timer3_frequency;
		if (current_PR3_val < (float) TIMER3_MAX_PR_VAL) {
			// This current prescale value works - configure the timer
			OpenTimer3(T3_ON | T3_SOURCE_INT | prescales[index].mask, (unsigned long int) current_PR3_val);
			mT3SetIntPriority(2);
			mT3SetIntSubPriority(0);
			mT3IntEnable(1);

			return NO_ERROR;
		}
		else {
			index++;	// Move to the next possible prescale iteration
		}
	}

	// This frequency cannot be achieved at any given frequency (must be realllly low)
	return ERROR; 
}

/* ----------------------------- Interrupt Service Routines ----------------------------- */

/**	
 *	@brief		ISR for timer 3. Currently does nothing; but can have additional functionality if desired.
 *	@param		None.
 *	@return		None.
 **/
void __ISR(_TIMER_3_VECTOR, IPL2) isr_timer3(void) {
	mT3ClearIntFlag();
}
