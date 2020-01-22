/** 
 *	@file 		i2c.c
 *	@brief		I2C library source file. Implements functionality of I2C module 1.
 *	@author		Collin Heist, Ryan Donahue.
 **/

/* ----------------------------------- File Inclusion ----------------------------------- */

#define _SUPPRESS_PLIB_WARNING
#include <plib.h>
#include "hardware.h"
#include "I2CLib.h"

/* -------------------------- Global Variables and Structures --------------------------- */

/* ---------------------------------- Public Functions ---------------------------------- */

/**	
 *	@brief		Initializes I2C1 module to the desired frequency.
 *	@param[in]	i2c_frequency: Unsigned int that signifies what frequency the I2C clock line should operate at.
 *	@return		unsigned int that is the error flag if the frequency was achieved with an adequate amount of accuracy
 **/
unsigned int initialize_i2c(unsigned int i2c_frequency) {
    I2CConfigure(I2C1, 0);  // Configure I2C1 with no special options
    
    // Check if the actual frequency of the I2C bus is acceptable close to what we wanted
    float actual_freq = (float) I2CSetFrequency(I2C1, GetPeripheralClock(), (UINT32) i2c_frequency);
    if ((actual_freq - (float) i2c_frequency > (float) i2c_frequency * I2C_CLOCK_MAX_DEVIATION) ||
	((float) i2c_frequency - actual_freq > (float) i2c_frequency * I2C_CLOCK_MAX_DEVIATION)) {
	return ERROR;
    }
//    I2CSetSlaveAddress(I2C1, I2C_GNSS_SLAVE_ADDRESS, 0, I2C_USE_7BIT_ADDRESS);    // Not used for some reason?
    I2CEnable(I2C1, TRUE);
    
    return NO_ERROR;
}

/**	
 *	@brief		Reads the I2C1 busy status registers.
 *	@param		None.
 *	@return		character that is either 1, or 0. 1 if the flags are SET, 0 if they're cleared
 **/
char BusyI2C1() {
    return(I2C1CONbits.SEN || I2C1CONbits.PEN || I2C1CONbits.RSEN || I2C1CONbits.RCEN || I2C1CONbits.ACKEN || I2C1STATbits.TRSTAT);
}

/**	
 *	@brief		Reads (len) items from slave device into read_array over I2C1 bus.
 *	@param[in]	slave_addr: Character that is the device to read from.
 *	@param[out]	read_array: Pointer to character array that will be filed with (len) bytes from the slave device.
 *	@param[in]	len: Integer corresponding to how many characters to read from the slave.
 *	@return		character that is either 0 (if no errors occurred) or non-zero if an error occurred.
 **/
char I2C_Read(char slave_addr, char *read_array, int len) {
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

/* **************************************************************************
 * Function:    char I2C_Write(char slave_addr, char *write_array, int len)
 * Summary:     Writes len items or null-terminated array to slave at location
				slave_addr
 * Argument:    char slave_addr, 7-bit destination slave address
				char *write_array, pointer to string of minimum length len
				len, number of characters to read
 * Return:		0  - no errors
				!0 - an error was encountered
 * **************************************************************************/
char I2C_Write(char slave_addr, char *write_array, int len)
{
    char error = 0;
    StartI2C1();
    IdleI2C1();
    error |= MasterWriteI2C1(slave_addr<<1|0);
//    while((write_array!= NULL)&&(len!=0))
    while((len!=0))
    {
        error |= MasterWriteI2C1(*write_array);
        write_array++;
        len--;
    }
    StopI2C1();
    IdleI2C1(); 
    return error;
}

/* **************************************************************************
 * Function:    char I2C_WriteRead(char slave_addr, char *write_array, char *read_array, int write_len, int read_len)
 * Summary:     Writes write_len items to slave at location slave_addr, polls
				for a read acknowledgement, then reads read_len items into 
				read_array from slave_addr. The function will timeout after 
				50,000 polls for completion without acknowledgement.
 * Argument:    char slave_addr, 7-bit destination slave address
				char *write_array, pointer to string of minimum length len
				char *read_array, pointer to character array of length > len
				write_len, number of characters to read
				read_len, number of characters to read
 * Return:		0  - no errors
				!0 - an error was encountered
 * **************************************************************************/
char I2C_WriteRead(char slave_addr, char *write_array, char *read_array, int write_len, int read_len)
{
    int i = 0;
    StartI2C1();
    IdleI2C1();
    char error = MasterWriteI2C1(slave_addr<<1|0x00);
    while((write_array!= NULL)&&(write_len!=0))
    {
        error |= MasterWriteI2C1(*write_array);
        write_array++;
        write_len--;
    }
    RestartI2C1();
    IdleI2C1();
    while(1)
    {
        MasterWriteI2C1(slave_addr<<1|0x01);
        if(I2C1STATbits.ACKSTAT == 0)
        {
            break;
        }
        if(i++>20000)
        {
            StopI2C1();
            IdleI2C1();
            return 1;
        }
        RestartI2C1();
        IdleI2C1();
    }
    while(1)
    {
        *read_array = MasterReadI2C1();
        read_array++;
		read_len--;
        if(read_len == 0)
        {
            break;
        }
        AckI2C1();
        IdleI2C1();
    }
    NotAckI2C1();
    IdleI2C1();
    StopI2C1();
    IdleI2C1();
    return error;
}

/* **************************************************************************
 * Function:    char I2C_WaitForSlaveAck(char slave_addr)
 * Summary:     Polls for a read acknowledgement from slave_addr. After 20ms 
				without acknowledgement function will exit.
 * Argument:    char slave_addr, 7-bit destination slave address
 * Return:		0  - no acknowledgement
				!0 - a read was acknowledged
 * Notes:		Untested
 * **************************************************************************/
char I2C_WaitForSlaveAck(char slave_addr)
{
    int i = 0;
    StartI2C1();
    IdleI2C1();
    while(1)
    {
        MasterWriteI2C1(slave_addr<<1|0x01);
        if(I2C1STATbits.ACKSTAT == 0)
        {
            StopI2C1();
            IdleI2C1();
            return 1;
        }
        if(i++>20000)
        {
            return 0;
        }
        RestartI2C1();
        IdleI2C1();
    }
}

/* --------------------------------- Private Functions ---------------------------------- */

/* ----------------------------- Interrupt Service Routines ----------------------------- */