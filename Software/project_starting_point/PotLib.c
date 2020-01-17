/* **************************************************************************
 * File name:   PotLib.c
 * Association: University of Idaho
 * Author:      Ryan Donahue
 * Dates:       Created 2/10/2018 
 * Summary:     This file contains a collection of functions and macros used to 
 *              enable the PIC32 ADC peripheral. The measurements will be used
 *              to encode the position of a rotary or linear potentiometer.
* *************************************************************************/
#define _SUPPRESS_PLIB_WARNING
#include <plib.h>
#include "MotorLib.h"
#include "hardware.h"
#include "PotLib.h"

/* **************************************************************************
 * Function:    void PotLib_Init()
 * Summary:     Initializes AN9 pins and peripheral for analog to digital
 *              conversion.
 * **************************************************************************/
void PotLib_Init()
{
    PORTSetPinsAnalogIn(IOPORT_B, AN9);
    PotLib_ADCInit();
}

/* **************************************************************************
 * Function:    void PotLib_ADCInit()
 * Summary:     Initializes ADC SFRs for analog to digital conversion with 
				auto sampling, auto trigger and dual buffer timed by the ADC
				internal clock.
 * **************************************************************************/
void PotLib_ADCInit()
{
    //ensure the ADC is off before configuration
	CloseADC10();
    //configure AN9 for samples referenced to ground
	SetChanADC10(ADC_CH0_POS_SAMPLEA_AN9|ADC_CH0_NEG_SAMPLEA_NVREF);
    //configure ADC capture settings
                //turn module on | integer output  | auto trigger | auto sample
    #define PARAM1 ADC_MODULE_ON | ADC_FORMAT_INTG | ADC_CLK_AUTO | ADC_AUTO_SAMPLING_ON
                //external reference  | disable offset test    | scan mode off| 2 samples per interval| use dual buffers| use alternate mode
    #define PARAM2 ADC_VREF_AVDD_AVSS | ADC_OFFSET_CAL_DISABLE | ADC_SCAN_OFF | ADC_SAMPLES_PER_INT_2 | ADC_ALT_BUF_ON | ADC_ALT_INPUT_ON
                //use internal ADC clock    | sample time of 15
    #define PARAM3 ADC_CONV_CLK_INTERNAL_RC | ADC_SAMPLE_TIME_15
                //only scan assigned channels
    #define PARAM4 SKIP_SCAN_ALL
                //set AN9 as analog input
    #define PARAM5 ENABLE_AN9_ANA
    OpenADC10(PARAM1, PARAM2, PARAM3, PARAM4, PARAM5);
    //enable the ADC module
	EnableADC10();
    //wait for first data to be read
     while(!mAD1GetIntFlag());
}

/* **************************************************************************
 * Function:    unsigned int PotLib_SingleRead()
 * Return:		ADC value (0 to 1023)
 * Summary:     Returns the most recent 10-bit AN9 ADC value. 
 * **************************************************************************/
unsigned int PotLib_SingleRead()
{
    //locate the offset of the most recent conversion in the idle buffer
    int offset = 8*(~ReadActiveBufferADC10()&0x01);
    //return the ADC result from the buffer
    return ReadADC10(offset);
}