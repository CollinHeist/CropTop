/**
 *	File
 *		GPS.c
 *	Summary
 *		GPS source file.
 *	Author(s)
 *		Collin Heist, Ryan Donahue
 */

/* ----------------------------------- File Inclusion ----------------------------------- */

#include <plib.h>

#include "hardware.h"
#include "GPS.h"
#include "I2CLib.h"

/* -------------------------- Global Variables and Structures --------------------------- */

/* ---------------------------------- Public Functions ---------------------------------- */

/**
 *	Summary
 *		Read the number of available bytes in the message stream
 *	Parameters
 *		None.
 *	Returns
 *		Unsigned integer that denotes how many bytes are available.
 */
unsigned int read_number_bytes_available(void) {
	char write_array[1] = {GPS_NUM_BYTES_ADDRESS};
	char read_array[2] = {'\0', '\0'};

	// Write to select the MSB of number of bytes available, then read the following two registers
	read_write_I2C1(GPS_SLAVE_ADDRESS, write_array, read_array, 1, 2);

	// Read array is structured as [Bytes Available (MSB), Bytes Available (LSB)]
	return ((read_array[0] << 8) & TOP_8_BITS) | (read_array[1] & BOTTOM_8_BITS);
}

/**
 *	Summary
 *		Read the GPS data stored in the GNSS module.
 *	Parameters
 *		read_array[out]: Character pointer that is the buffer to be filled with the
 *		  contents of the GPS.
 *		max_length[in]: The maximum number of bytes to fill of the read_array buffer.
 *	Returns
 *		Character that is the ack-error bits returned by read_write_I2C1.
 */
char read_GPS(char* read_array, const unsigned int max_length) {
	// Read how many bytes are currently available to be read - stop at max_length bytes.
	unsigned int num_bytes_available = read_number_bytes_available();
	num_bytes_available = (num_bytes_available > max_length) ? max_length : num_bytes_available;

	char write_array[1] = {GPS_DATA_ADDRESS};	// Target the data address

	// Write the slave address, and then read however many bytes are available into read_array
	return read_write_I2C1(GPS_SLAVE_ADDRESS, write_array, read_array, 1, num_bytes_available);
}

/* **************************************************************************
 * Function:	char GPSLib_UBXWrite(TBD)
 * Summary:	 
 * Argument:	unsigned char class_id,
 *				unsigned char msg_id, 
 *				unsigned char* payload,
 *				unsigned short payload_len
 * Return:		0  - no I2C write errors
 *  			!0 - an I2C write error was encountered
 * **************************************************************************/
char GPSLib_UBXWrite(unsigned char class_id,unsigned char msg_id, unsigned char* payload,unsigned short payload_len) {
	unsigned char write[9] = {0};
	write[0] = SYNC_1;
	write[1] = SYNC_2;
	write[2] = class_id;
	write[3] = msg_id;
	write[4] = payload_len & 0xFF;
	write[5] = (payload_len >> 8) & 0xFF;
	int i;
	for (i = 0; i<payload_len; i++) {
		write[6+i] = payload[i];
	}

	GPSLib_UBXChecksum(&write[2], payload_len);
	
	return write_I2C1(GPS_ADDR, write, payload_len + 8);
}

/* **************************************************************************
 * Function:	void GPSLib_UBXChecksum(TBD)
 * Summary:	 For a given payload size, calling this routine computes the
 *				checksum for a UBX message and adds them to the payload data 
 *				array.
 * Argument:	unsigned char* data, pointer to the start of checksum data
 *				int payload_len, length of payload
 * **************************************************************************/
void GPSLib_UBXChecksum(unsigned char* data, int payload_len) {
	unsigned char CK_A = 0, CK_B = 0;
	int i = 0;
	for (i = 0; i < (4 + payload_len); i++) {
		CK_A = CK_A + data[i];
		CK_B = CK_B + CK_A;
	}

	data[i + 0] = CK_A;
	data[i + 1] = CK_B;
}

/* --------------------------------- Private Functions ---------------------------------- */

/* ----------------------------- Interrupt Service Routines ----------------------------- */