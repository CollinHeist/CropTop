/* **************************************************************************
 * File name:   I2CLib.c
 * Association: University of Idaho
 * Author:      Ryan Donahue
 * Dates:       Created 2/13/2019
 * Summary:     Function to initialize and use I2C module 1.
 * **************************************************************************/
#define _SUPPRESS_PLIB_WARNING
#include <plib.h>
#include "hardware.h"
#include "I2CLib.h"

/* **************************************************************************
 * Function:    void I2CLib_Init()
 * Summary:     Enables I2C1 for 100kbaud
 * **************************************************************************/
void I2CLib_Init()
{
    I2CConfigure(I2C1,0);
    I2CSetFrequency(I2C1, GetPeripheralClock(), I2C_CLOCK_FREQ);
    I2CEnable(I2C1, TRUE);
}

/* **************************************************************************
 * Function:    char BusyI2C1()
 * Summary:     Reads PIC32 I2C1 busy status registers
 * Return:		1 - busy flag is set
				0 - busy flags are cleared
 * **************************************************************************/
char BusyI2C1()
{
    return(I2C1CONbits.SEN || I2C1CONbits.PEN || I2C1CONbits.RSEN ||
            I2C1CONbits.RCEN || I2C1CONbits.ACKEN || I2C1STATbits.TRSTAT);
}

/* **************************************************************************
 * Function:    char I2C_Read(char slave_addr, char *read_array, int len)
 * Summary:     Reads len items from slave device into read_array from I2C1
 * Argument:    char slave_addr, 7-bit slave address
				char *read_array, pointer to character array of length > len
				len, number of characters to read
 * Return:		0  - no errors
				!0 - an error was encountered
 * **************************************************************************/
char I2C_Read(char slave_addr, char *read_array, int len)
{
    char error = 0;
    StartI2C1();
    IdleI2C1();
    error |= MasterWriteI2C1((slave_addr<<1)|1);
    while(1)
    {
        len--;
        *read_array = MasterReadI2C1();
        if(len == 0)
        {
            return;
        }
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