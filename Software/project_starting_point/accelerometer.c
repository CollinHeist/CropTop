/* **************************************************************************
 * File name:   AccelLib.c
 * Association: University of Idaho
 * Author:	  Ryan Donahue
 * Dates:	   Created 3/5/2018
 * Summary:	 Contains functions to operate STmicroelectronics LIS3DHTR
				3 axis accelerometer with the goal of acquiring tilt 
				(rotation) data of the in ZX plane. X measuring +1G and Z 0G 
				will be a tilt of 0 degrees. Rotation will result in an angle
				theta from this reference plane.
 * *************************************************************************/

#include <plib.h>
#include "hardware.h"
#include "I2CLib.h"
#include "accelerometer.h"
#include <stdio.h>
#include <math.h>

/* **************************************************************************
 * Function:	char AccelLib_Init()
 * Summary:	 Disables Accelerometer SA0 pin internal pull-up, and enables
				device for High-resolution X, Y, and Z measurements for +/- 2G
				measurements.
 * Return:		0  - no I2C write errors
				!0 - an I2C write error was encountered
 * **************************************************************************/
unsigned int initialize_accelerometer(void) {
	//control register values
	#define ACC_CFG_0 (SDO_PU_DISC)
	#define ACC_CFG_1 (HR_NORMAL|Z_EN|Y_EN|X_EN)
	#define ACC_CFG_4 (SCALE_2G|HIGH_RES_EN)
	
	// Fill control registers
	int error = AccelLib_SingleWrite(CTRL_REG0,ACC_CFG_0);
	error |= AccelLib_SingleWrite(CTRL_REG1,ACC_CFG_1);
	error |= AccelLib_SingleWrite(CTRL_REG4,ACC_CFG_4);
	error |= AccelLib_SelfTest();
	
	return (error ? ERROR : NO_ERROR);
}


/* **************************************************************************
 * Function:	char AccelLib_SelfTest()
 * Summary:	 Tests Accelerometer by applying a known actuation force to the
				sensor and verifying STmicro specifications.
 * Return:		0  - Test passed
				1  - Test failed
 * **************************************************************************/
char AccelLib_SelfTest() {
	char failed = 0;
	float st_constant_high = 0.36;
	float st_constant_low = 0.017;
	float X_pretest = AccelLib_ReadX();
	float Y_pretest = AccelLib_ReadY();
	float Z_pretest = AccelLib_ReadZ();
	//set self-test bits
	AccelLib_SingleWrite(CTRL_REG4,(ACC_CFG_4|ST0_EN));
	
	//wait at least 8 samples
	int i = 0;
	while (i < 200) {
		i++;
	}
	// Read sensor values
	float X_st = -(X_pretest-AccelLib_ReadX());
	float Y_st = -(Y_pretest-AccelLib_ReadY());
	float Z_st = -(Z_pretest-AccelLib_ReadZ());
	
	//verify in range
	if (((X_st<st_constant_low) && (X_st>st_constant_high)) ||
	((Y_st<st_constant_low) && (Y_st>st_constant_high)) ||
	((Z_st<st_constant_low) && (Z_st>st_constant_high))) {
	
	failed |= ERROR;
	}
	//set self-test bits
	AccelLib_SingleWrite(CTRL_REG4,(ACC_CFG_4|ST1_EN));
	//wait at least 8 samples
	while (i<200) {
		i++;
	}
	//read sensor values
	X_st = X_pretest-AccelLib_ReadX();
	Y_st = Y_pretest-AccelLib_ReadY();
	Z_st = Z_pretest-AccelLib_ReadZ();
	//verify in range
	if (((X_st>st_constant_low) && (X_st<st_constant_high)) ||
	((Y_st>st_constant_low) && (Y_st<st_constant_high)) ||
	((Z_st>st_constant_low) && (Z_st<st_constant_high))) {
	
		failed |= ERROR;
	}
	
	// Clear self-test
	AccelLib_SingleWrite(CTRL_REG4,ACC_CFG_4);
	
	return failed;
}

/* **************************************************************************
 * Function:	char AccelLib_SingleWrite(char subreg, char write_val)
 * Summary:	 Write a value to a single sub register in the Accelerometer
 * Argument:	char subreg, destination address
				char write_val, register value
 * Return:		0  - no I2C write errors
				!0 - an I2C write error was encountered
 * **************************************************************************/
char AccelLib_SingleWrite(char subreg, char write_val) {
	char write[2] = {subreg,write_val};
	char error = write_I2C1(LIS3DHTR_ADDR, write, 2);
	return error;
}

/* **************************************************************************
 * Function:	char AccelLib_SingleRead(char subreg)
 * Summary:	 Retrieve a value from a single sub register in the Accelerometer.
 * Argument:	char subreg, destination address
 * Return:		value retrieved from subreg
 * **************************************************************************/
char AccelLib_SingleRead(char subreg) {
	char read[1];
	char write[1] = {subreg};
	read_write_I2C1(LIS3DHTR_ADDR, write, read, 1, 1);
	
	return read[0];
}

/* **************************************************************************
 * Function:	char AccelLib_ContinuousRead(char subreg, char* read, int len)
 * Summary:	 Retrieve len values from the Accelerometer and store in the 
				array read. Reads begin at the sub register address and auto-
				increment
 * Argument:	char subreg, starting destination address
				char* read, pointer to the array that will be filled
 * **************************************************************************/
void AccelLib_ContinuousRead(char subreg, char* read, int len) {
	char write[1] = {subreg | AUTO_INCREMENT};
	read_write_I2C1(LIS3DHTR_ADDR, write, read, 1, len);
}

/* **************************************************************************
 * Function:	float AccelLib_ReadZ()
 * Summary:	 Reads the Accelerometer Z register then computes the value in
				G's
 * Return:		acceleration in Z direction
 * **************************************************************************/
float AccelLib_ReadZ() {
	unsigned char read[2];
	AccelLib_ContinuousRead(OUT_Z_L, read, 2);
	short out_reg = read[0]|(read[1]<<8);
	float acc = (out_reg/16)*.001;
	
	return acc;
}

/* **************************************************************************
 * Function:	float AccelLib_ReadY()
 * Summary:	 Reads the Accelerometer Y register then computes the value in
				G's
 * Return:		acceleration in Y direction
 * **************************************************************************/
float AccelLib_ReadY() {
	unsigned char read[2];
	AccelLib_ContinuousRead(OUT_Y_L, read, 2);
	short out_reg = read[0] | (read[1] << 8);
	float acc = (out_reg / 16) * 0.001;
	
	return acc;
}

/* **************************************************************************
 * Function:	float AccelLib_ReadX()
 * Summary:	 Reads the Accelerometer X register then computes the value in
				G's
 * Return:		acceleration in X direction
 * **************************************************************************/
float AccelLib_ReadX() {
	unsigned char read[2];
	AccelLib_ContinuousRead(OUT_X_L, read, 2);
	short out_reg = read[0] | (read[1] << 8);
	float acc = (out_reg  /16) * 0.001;
	
	return acc;
}

/* **************************************************************************
 * Function:	double AccelLib_ReadX()
 * Summary:	 Calculates Accelerometer tilt based on X and Z accelerations.
 * Return:		tilt in degrees
 * **************************************************************************/
double AccelLib_ReadTilt() {
	#define RAD2DEG (180.0 / 3.14159265)

	float Z = (AccelLib_ReadZ());
	float Y = (AccelLib_ReadY());
	double theta = atan(Z/Y) * RAD2DEG;
	
	return theta;
}