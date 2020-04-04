/**
 *	File
 *		I2CLib.h
 *	Summary
 *		I2C library header file. This provides slave address and clock macros for all I2C
 *		operations, as well as function prototypes.
 *	Author(s)
 *		Collin Heist
 */

#ifndef __I2C_H__
	#define __I2C_H__

	// I2C configurations
	#define I2C_TIMEOUT_COUNT					(20000)
	#define I2C_GNSS_SLAVE_ADDRESS				(0b01000010)	// Slave address of the GNSS Reciever Module
	#define I2C_CLOCK_MAX_PERCENT_DEVIATION		(10)			// Maximum allowable deviation(%) in the clock for I2C1
	#define I2C_CLOCK_MAX_DEVIATION				((float) I2C_CLOCK_MAX_PERCENT_DEVIATION / 100.0)

	// Function prototypes
	unsigned int initialize_i2c(unsigned int i2c_frequency);
	inline char busy_I2C1(void);
	char read_I2C1(char slave_addr, char *read_array, int len);
	char write_I2C1(char slave_addr, char *write_array, int len);
	char read_write_I2C1(char slave_addr, char *write_array, char *read_array, int write_len, int read_len);
	unsigned int wait_for_I2C1_ack(char slave_addr);
#endif


