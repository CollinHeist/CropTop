/**
 *	File
 *		accelerometer.c
 *	Summary
 *		Accelerometer library source file. Contains functions for the LIS3DHTR 3-Axis
 *		accelerometer. Has the goal of acquiring tilt data in XZ plane. X measuring
 *		+1G and Z 0G will be a tilt of 0 degrees. 
 *	Author(s)
 *		Collin Heist, Ryan Donahue
 */

/* ----------------------------------- File Inclusion ----------------------------------- */

#include <plib.h>
#include <stdio.h>
#include <math.h>

#include "hardware.h"
#include "accelerometer.h"
#include "I2CLib.h"

/* -------------------------- Global Variables and Structures --------------------------- */

/* ---------------------------------- Public Functions ---------------------------------- */

/**
 *	Summary
 *		Function to initialize the accelerometer. Disables SA0 pin's internal pull up, and
 *		enables device for high-resolution XYZ measurements for +/- 2G measurements.
 *	Parameters
 *		None.
 *	Returns
 *		Unsigned int that is ERROR or NO_ERROR if an I2C write error occurred.
 */
unsigned int initialize_accelerometer(void) {
	//control register values
	#define ACC_CFG_0 (SDO_PU_DISC)
	#define ACC_CFG_1 (HR_NORMAL|Z_EN|Y_EN|X_EN)
	#define ACC_CFG_4 (SCALE_2G|HIGH_RES_EN)
	
	// Fill control registers
	int error = single_write_accelerometer(CTRL_REG0, ACC_CFG_0);
	error |= single_write_accelerometer(CTRL_REG1, ACC_CFG_1);
	error |= single_write_accelerometer(CTRL_REG4, ACC_CFG_4);
	error |= perform_accelerometer_self_test();
	
	return (error ? ERROR : NO_ERROR);
}

/**
 *	Summary
 *		Function to write a single value to a single subregister in the accelerometer.
 *	Parameters
 *		sub_register[in]: Character that is the destination address.
 *		write_value[in]: Character that is to be writen to the subregister.
 *	Returns
 *		I2C error result of the write operation - should be zero.
 */
inline char single_write_accelerometer(const char sub_register, const char write_value) {
	char write[2] = {sub_register, write_value};
	return write_I2C1(LIS3DHTR_ADDR, write, 2);
}

/**
 *	Summary
 *		Function to read a single value from a given sub regsiter in the accelerometer.
 *	Parameters
 *		sub_register[in]: Character that is the source address.
 *	Returns
 *		Value retrieved from sub_register.
 */
inline char single_read_accelerometer(const char sub_register) {
	char read[1];
	read_write_I2C1(LIS3DHTR_ADDR, &sub_register, read, 1, 1);
	
	return read[0];
}

/**
 *	Summary
 *		Function to read the Z-axis of the accelerometer.
 *	Parameters
 *		None.
 *	Returns
 *		Float that is the Z-axis register of the accelerometer (in G's).
 */
float read_z_accelerometer(void) {
	unsigned char read[2];
	continuous_read_accelerometer(OUT_Z_L, read, 2);
	short out_reg = read[0] | (read[1] << 8);
	
	return (float) ((out_reg / 16) * 0.001);
}

/**
 *	Summary
 *		Function to read the Y-axis of the accelerometer.
 *	Parameters
 *		None.
 *	Returns
 *		Float that is the Y-axis register of the accelerometer (in G's).
 */
float read_y_accelerometer(void) {
	unsigned char read[2];
	continuous_read_accelerometer(OUT_Y_L, read, 2);
	short out_reg = read[0] | (read[1] << 8);

	return (float) ((out_reg / 16) * 0.001);
}

/**
 *	Summary
 *		Function to read the X-axis of the accelerometer.
 *	Parameters
 *		None.
 *	Returns
 *		Float that is the X-axis register of the accelerometer (in G's).
 */
float read_x_accelerometer(void) {
	unsigned char read[2];
	continuous_read_accelerometer(OUT_X_L, read, 2);
	short out_reg = read[0] | (read[1] << 8);

	return (float) ((out_reg / 16) * 0.001);
}

/**
 *	Summary
 *		Function to calculate the accelerometer tilt based on the X and Z accelerations.
 *	Parameters
 *		None.
 *	Returns
 *		Double that is the tilt of the accelerometer (in degrees).
 */
inline double read_tilt_accelerometer(void) {
	return (double) (atan(read_z_accelerometer() / read_y_accelerometer()) * 180.0 / 3.14159265);
}

/* --------------------------------- Private Functions ---------------------------------- */

static inline void delay_8_samples(void) {
	unsigned int i;
	for (i = 0; i < SAMPLE_DELAY_COUNT; i++) {}
}

/**
 *	Summary
 *		Private Function to test the accelerometer by applying a known actuation force to
 *		the sensor and verifying the STmicro specifications.
 *	Parameters
 *		None.
 *	Returns
 *		Unsigned int that is ERROR or NO_ERROR if an I2C write error occurred.
 */
static char perform_accelerometer_self_test(void) {
	char failed = 0;
	float st_constant_high = 0.36;
	float st_constant_low = 0.017;
	float X_pretest = read_x_accelerometer();
	float Y_pretest = read_y_accelerometer();
	float Z_pretest = read_z_accelerometer();

	// Set self-test bits
	single_write_accelerometer(CTRL_REG4, (ACC_CFG_4 | ST0_EN));
	delay_8_samples();
	
	// Read sensor values
	float X_st = -(X_pretest - read_x_accelerometer());
	float Y_st = -(Y_pretest - read_y_accelerometer());
	float Z_st = -(Z_pretest - read_z_accelerometer());
	
	// Verify in range
	if (((X_st < st_constant_low) && (X_st > st_constant_high)) || ((Y_st < st_constant_low) && (Y_st > st_constant_high)) || ((Z_st < st_constant_low) && (Z_st > st_constant_high))) {
		failed |= ERROR;
	}

	// Set self-test bits
	single_write_accelerometer(CTRL_REG4, (ACC_CFG_4 | ST1_EN));
	delay_8_samples();

	// Read sensor values
	X_st = X_pretest - read_x_accelerometer();
	Y_st = Y_pretest - read_y_accelerometer();
	Z_st = Z_pretest - read_z_accelerometer();
	// Verify in range
	if (((X_st > st_constant_low) && (X_st < st_constant_high)) || ((Y_st > st_constant_low) && (Y_st < st_constant_high)) || ((Z_st > st_constant_low) && (Z_st < st_constant_high))) {
		failed |= ERROR;
	}
	
	// Clear self-test
	single_write_accelerometer(CTRL_REG4, ACC_CFG_4);
	
	return failed;
}

/**
 *	Summary
 *		Private Function to retrieve length values from the accelerometer, starting at
 *		sub_register, and filling the read array.
 *	Parameters
 *		sub_register[in]: Character that is the source address.
 *		read[out]: Pointer to the first character in the array to read into.
 *		length[in]: Unsigned int that is how many bytes to read from the accelerometer.
 *	Returns
 *		None.
 */
static inline void continuous_read_accelerometer(const char sub_register, char* read, const unsigned int length) {
	char write[1] = {sub_register | AUTO_INCREMENT};
	read_write_I2C1(LIS3DHTR_ADDR, write, read, 1, length);
}

/* ----------------------------- Interrupt Service Routines ----------------------------- */