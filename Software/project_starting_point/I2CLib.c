/**
 *	File
 *		i2c.c
 *	Summary
 *		I2C library source file. Implements functionality for initializing, reading to, and
 *		writing from I2C1.
 *	Author(s)
 *		Collin Heist, Ryan Donahue.
 */

/* ----------------------------------- File Inclusion ----------------------------------- */

#include <plib.h>

#include "hardware.h"
#include "I2CLib.h"

/* -------------------------- Global Variables and Structures --------------------------- */

/* ---------------------------------- Public Functions ---------------------------------- */

/**
 *	Summary
 *		Initializes I2C1 module to the desired frequency.
 *	Parameters
 *		i2c_frequency[in]: Unsigned int that signifies what frequency the I2C clock line
 *			should operate at.
 *	Returns
 *		Unsigned int that is ERROR or NO_ERROR if initialization was successful.
 */
unsigned int initialize_i2c(unsigned int i2c_frequency) {
	I2CConfigure(I2C1, 0);  // Configure I2C1 with no special options
	
	// Check if the actual frequency of the I2C bus is acceptable close to what we wanted
	float actual_freq = (float) I2CSetFrequency(I2C1, GetPeripheralClock(), (UINT32) i2c_frequency);
	if ((actual_freq - (float) i2c_frequency > (float) i2c_frequency * I2C_CLOCK_MAX_DEVIATION) ||
		((float) i2c_frequency - actual_freq > (float) i2c_frequency * I2C_CLOCK_MAX_DEVIATION)) {
		
		return ERROR;
	}
	I2CEnable(I2C1, TRUE);
	
	return NO_ERROR;
}

/**
 *	Summary
 *		Reads the I2C1 busy status registers.
 *	Parameters
 *		None.
 *	Returns
 *		Character that is either 1 or 0. 1 if any busy flags are SET, 0 is CLEAR.
 *	Note
 *		This reads the SEN, PEN, RSEN, RCEN, ACKEN, and TRSTAT bits of the I2C1 controller.
 */
inline char busy_I2C1(void) {
	return (I2C1CONbits.SEN || I2C1CONbits.PEN || I2C1CONbits.RSEN || I2C1CONbits.RCEN || I2C1CONbits.ACKEN || I2C1STATbits.TRSTAT);
}

/**
 *	Summary
 *		Reads (len) items from slave device into read_array over I2C1 bus.
 *	Parameters
 *		slave_addr[in]: Character that is the device address to read from.
 *		read_array[out]: Pointer to character array that will be filed with (len) bytes from
 *			the slave device.
 *		len[in]: Integer corresponding to how many characters to read from the slave.
 *	Returns
 *		Character that is either 0 (for no errors) or non-zero if errors occurred during read.
 */
char read_I2C1(char slave_addr, char *read_array, int len) {
	char error = 0;
	
	// Begin I2C transaction by addressing the slave with a READ 
	StartI2C1();
	IdleI2C1();
	error |= MasterWriteI2C1((slave_addr<<1)|1);
	
	// Begin reading from I2C bus into the array
	while (len >= 0) {
		len--;
		*read_array = MasterReadI2C1();
		if (len == 0)
			return NO_ERROR;
		AckI2C1();
		IdleI2C1();
		read_array++;
	}
	NotAckI2C1();
	IdleI2C1();
	StopI2C1();
	IdleI2C1();
	
	return error;
}

/**	
 *	@brief		Writes (len) items to slave at (slave_addr).
 *	@param[in]	slave_addr: Character that is the 7-bit destination slave address.
 *	@param[in]	write_array: Character pointer to the string being written over I2C.
 *	@param[in]	len: Integer that denotes the length of the write array. 
 *	@return		character that is either 1, or 0 if there was an error during writing.
 **/
char write_I2C1(char slave_addr, char *write_array, int len) {
	StartI2C1();
	IdleI2C1();
	char error = MasterWriteI2C1(slave_addr << 1 | 0);
	while (len!=0) {
		error |= MasterWriteI2C1(*write_array);
		write_array++;
		len--;
	}

	StopI2C1();
	IdleI2C1();

	return error;
}

/**	
 *	@brief		Writes write_len items from write_array to slave_addr, polls for
 *				acknowledgement, then reads read_len items into read_array. This
 *				function times out after I2C_READ_WRITE_TIMEOUT_COUNT polls.
 *	@param[in]	slave_addr: Character that is the device to read from.
 *	@param[in]	write_array: Pointer to character array that will be written to slave device.
 *	@param[out]	read_array: Pointer to character array that will be filed with (len) bytes from the slave device.
 *	@param[in]	write_len: Integer corresponding to how many characters to write to the slave.
 *	@param[in]	read_len: Integer corresponding to how many character to read from the slave.
 *	@return		character that is either 0 (if no errors occurred) or non-zero if an error occurred.
 **/
char read_write_I2C1(char slave_addr, char *write_array, char *read_array, int write_len, int read_len) {
	int i = 0;
	StartI2C1();
	IdleI2C1();
	char error = MasterWriteI2C1(slave_addr << 1 | 0);
	while ((write_array != NULL) && (write_len != 0)) {
		error |= MasterWriteI2C1(*write_array);
		write_array++;
		write_len--;
	}
	RestartI2C1();
	IdleI2C1();

	while (1) {
		MasterWriteI2C1(slave_addr << 1 | 1);
		if (I2C1STATbits.ACKSTAT == 0) {
			break;
		}

		if (i++ > I2C_TIMEOUT_COUNT) {
			StopI2C1();
			IdleI2C1();

			return 1;
		}

		RestartI2C1();
		IdleI2C1();
	}

	while (1) {
		*read_array = MasterReadI2C1();
		read_array++;
		if (read_len == 0)
			break;
		
		AckI2C1();
		IdleI2C1();
	}

	NotAckI2C1();
	IdleI2C1();
	StopI2C1();
	IdleI2C1();

	return error;
}

/**	
 *	@brief		Polls for a read acknowledgement from (slave_addr). After I2C_TIMEOUT_COUNT
 *				polls without acknowledgement, the function exits.
 *	@param[in]	slave_addr: Character that is the device to read from.
 *	@return		unsigned int that is either 0 (if no errors occurred) or non-zero if an error occurred.
 **/
unsigned int wait_for_I2C1_ack(char slave_addr) {
	int i = 0;
	StartI2C1();
	IdleI2C1();
	while (1) { 
		MasterWriteI2C1(slave_addr << 1 | 1);

		if (I2C1STATbits.ACKSTAT == 0) {
			StopI2C1();
			IdleI2C1();

			return NO_ERROR;
		}

		if (i++ > I2C_TIMEOUT_COUNT) {
			return ERROR;
		}

		RestartI2C1();
		IdleI2C1();
	}
}

/* --------------------------------- Private Functions ---------------------------------- */

/* ----------------------------- Interrupt Service Routines ----------------------------- */