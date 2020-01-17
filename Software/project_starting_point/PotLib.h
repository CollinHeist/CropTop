/* **************************************************************************
 * File name:   PotLib.h
 * Association: University of Idaho
 * Author:      Ryan Donahue
 * Dates:       Created 2/11/2018
 * Summary:     This file contains macro definitions used in the project.             
 * *************************************************************************/
#define _SUPPRESS_PLIB_WARNING

#ifndef __POTLIB_H__
	#define __POTLIB_H__

	// Macros
	#define POT_ADC_1	(BIT_10)	// POTEN_ADC_1 is Bit 34, AN10, RB10
	#define POT_ADC_2	(BIT_9)		// POTEN_ADC_2 is Bit 33, AN9, RB9

	// Function prototypes
	void initialize_potentiometer();
	unsigned int PotLib_SingleRead();
#endif

