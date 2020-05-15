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
 *			contents of the GPS.
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

/**
 *	Summary
 *		Write to the GPS using the correct packet construction.
 *	Parameters
 *		class_id[in]: Unsigned char that is the class id for the write operation.
 *		message_id[in]: Unsigned character that is the ID for the message.
 *		payload[in]: Pointer to the first value in the unsigned character array to 
 *			be written to the GPS module.
 *		payload_len[in]: Unsigned short that is how long the payload being written is.
 *	Returns
 *		Character that is 0 if no I2C write errors occurred, and non-zero if a write
 *		error occurred.
 */
char GPSLib_UBXWrite(const unsigned char class_id, const unsigned char message_id, const unsigned char* payload, const unsigned short payload_length) {
	unsigned char write[9] = {0};
	write[0] = SYNC_1;
	write[1] = SYNC_2;
	write[2] = class_id;
	write[3] = message_id;
	write[4] = payload_length & 0xFF;
	write[5] = (payload_length >> 8) & 0xFF;

	int i;
	for (i = 0; i < payload_length; i++) { write[6+i] = payload[i]; }

	GPSLib_UBXChecksum(&write[2], payload_length);
	
	return write_I2C1(GPS_ADDR, write, payload_length + 8);
}

/**
 *	Summary
 *		For a given payload size, this function computes the checksum for a UCX message
 *		and adds them to the payload data array.
 *	Parameters
 *		data[out]: The payload to have the checksum appended onto.
 *		payload_length[in]: The length of the payload to compute the checksum for.
 *	Returns
 *		None.
 */
void GPSLib_UBXChecksum(unsigned char* data, const int payload_length) {
	unsigned char CK_A = 0, CK_B = 0;
	int i;
	for (i = 0; i < (4 + payload_length); i++) {
		CK_A = CK_A + data[i];
		CK_B = CK_B + CK_A;
	}

	data[i + 0] = CK_A;
	data[i + 1] = CK_B;
}

/* --------------------------------- Private Functions ---------------------------------- */

/* ----------------------------- Interrupt Service Routines ----------------------------- */