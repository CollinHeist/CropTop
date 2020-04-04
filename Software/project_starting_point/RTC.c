/**
 *	File
 *		real_time_clock.c
 *	Summary
 *		Real Time Clock source file.
 *	Author(s)
 *		Collin Heist
 */

/* ----------------------------------- File Inclusion ----------------------------------- */

#include <plib.h>
#include <stdio.h>
#include <string.h>

#include "hardware.h"
#include "RTC.h"

/* -------------------------- Global Variables and Structures --------------------------- */

/* ---------------------------------- Public Functions ---------------------------------- */

/*
 *	Summary
 *		Function to initialize the Real Time Clock unit.
 *	Parameters
 *		time[in]: rtccTime structure that contains time information to start the unit with.
 *		date[in]: rtccDate structure that contains date information to start the unit with.
 *	Returns
 *		Unsigned integer that is ERROR or NO_ERROR if initialization was successful.
 */
unsigned int initialize_RTC(rtccTime time, rtccDate date) {
	RtccInit();
	// Wait for RTC to be running
	while (RtccGetClkStat() != RTCC_CLK_ON) {}
	RtccSetTimeDate(time, date);
	
	return NO_ERROR;
}

/*
 *	Summary
 *		Function to adjust the RTC unit for a given date and time.
 *	Parameters
 *		hour[in]: Unsigned integer [0-24] that encodes the hour to initialize the unit to.
 *		minute[in]: Unsigned integer [0-60] that encodes the minute to initialize the unit to.
 *		month[in]: Unsigned integer [1-12] that encodes the month to initialize the unit to.
 *		date[in]: Unsigned integer [1-31] that encodes the day of month to initialize the unit to.
 *	Returns
 *		None.
 */
void adjust_datetime(unsigned int hour, unsigned int minute, unsigned int month, unsigned int date) {
	if (hour > 24 | minute > 60 | month == 0 | month > 12 | date == 0 | date > 31)  // Check for invalid entries
		return;
	
	// Update new date and time fields
	rtccTime new_time;
	rtccDate new_date;
	
	new_time.l = 0;							// Reset the whole structure
	new_time.hour = hour & ONE_BYTE_MASK;	// Set the hour field
	new_time.min = minute & ONE_BYTE_MASK;	// Set the minute field
	
	new_date.l = 0;							// Reset the whole structure
	new_date.mon = month & ONE_BYTE_MASK;	// Set the month field
	new_date.mday = date & ONE_BYTE_MASK;	// Set the date field
	
	RtccOpen(new_time.l, new_date.l, 0);	// Set the RTCC peripheral
}

/*
 *	Summary
 *		Function to get the current date and time values from the RTC unit.
 *	Parameters
 *		hour[out]: Pointer to an unsigned integer that will be updated with the current hour.
 *		minute[out]: Pointer to an unsigned integer that will be updated with the current minute.
 *		month[out]: Pointer to an unsigned integer that will be updated with the current month.
 *		date[out]: Pointer to an unsigned integer that will be updated with the current date.
 *	Returns
 *		Unsigned integer that is ERROR or NO_ERROR if initialization was successful.
 */
inline void get_datetime(unsigned int* hour, unsigned int* minute, unsigned int* month, unsigned int* date) {
	rtccTime time;
	rtccDate date;
	
	// Get current datetime - update the return variables
	RtccGetTimeDate(&time, &date);
	*hour = time.hour; *minute = time.min; *month = date.mon; *date = date.mday;
}

/* --------------------------------- Private Functions ---------------------------------- */

/* ----------------------------- Interrupt Service Routines ----------------------------- */