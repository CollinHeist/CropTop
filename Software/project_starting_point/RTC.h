/**
 *	File
 *		real_time_clock.h
 *	Summary
 *		Real Time Clock header file - has macros and function prototypes.
 *	Author(s)
 *		Collin Heist
 */

#ifndef __REAL_TIME_CLOCK_H__
	#define __REAL_TIME_CLOCK_H__

	// Operational Configurations
	#define ONE_BYTE_MASK		(0xFF)

	// Function Prototypes
	unsigned int initialize_RTC(const rtccTime time, const rtccDate date);
	void adjust_datetime(const unsigned int hour, const unsigned int minute, const unsigned int month, const unsigned int date);
	inline void get_datetime(unsigned int* hour, unsigned int* minute, unsigned int* month, unsigned int* date);
	inline void get_datetime_rtcc(rtccTime* time, rtccDate* date);
#endif