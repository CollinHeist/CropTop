/* **************************************************************************
 * File name:   I2CLib.h
 * Association: University of Idaho
 * Author:      Ryan Donahue
 * Dates:       Created 2/13/2018
 * Summary:     This file contains macro definitions and prototypes for the
				I2C library.     
 * *************************************************************************/
#define _SUPPRESS_PLIB_WARNING

#ifndef __I2C_H__
    #define __I2C_H__

    // I2C configurations
    #define I2C_GNSS_SLAVE_ADDRESS              (0b01000010)    // Slave address of the GNSS Reciever Module
    #define I2C_CLOCK_MAX_PERCENT_DEVIATION     (10)    // Maximum allowable deviation(%) in the clock for I2C1
    #define I2C_CLOCK_MAX_DEVIATION             ((float) I2C_CLOCK_MAX_PERCENT_DEVIATION / 100.0)

    // Function prototypes
    void I2CLib_Init();
    char BusyI2C1();
    char I2C_Read(char slave_addr, char *read_array, int len);
    char I2C_Write(char slave_addr, char *write_array, int len);
    char I2C_WriteRead(char slave_addr, char *write_array, char *read_array, int write_len, int read_len);
    char I2C_WaitForSlaveAck(char slave_addr);

#endif


