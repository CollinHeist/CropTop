/* **************************************************************************
 * File name:   AccelLib.c
 * Association: University of Idaho
 * Author:      Ryan Donahue
 * Dates:       Created 4/12/2018
 * Summary:     
 * *************************************************************************/
#define _SUPPRESS_PLIB_WARNING
#include <plib.h>
#include "crop_top.h"
#include "I2CLib.h"
#include "GPSLib.h"

/* **************************************************************************
 * Function:    char GPSLib_Init()
 * Summary:     
 * Return:		0  - no I2C write errors
 *  			!0 - an I2C write error was encountered
 * **************************************************************************/
char GPSLib_Init()
{
    //configure device
//	char error |= GPSLib_UBXWrite(unsigned char class_id,unsigned char msg_id, unsigned char* payload,unsigned short payload_len);
//    return error;
}

/* **************************************************************************
 * Function:    int GPSLib_MessageCount()
 * Summary:     Retrieve number of messages waiting in GPS data stream.
 * Return:      number of messages in data stream
 * **************************************************************************/
int GPSLib_MessageCount()
{
    char write[1] = {MSG_LEN_MSB};
    char read[2] = {0,0};
    I2C_WriteRead(GPS_ADDR, write, read, 1, 2);
    if(read[0]!=0x00)
    {
        return ((read[0]<<8)&0xFF00)|(read[1]&0xFF);
    }
    else
    {
        return 0;
    }
}

/* **************************************************************************
 * Function:    char GPSLib_ContinuousRead(char subreg, char* read, int len)
 * Summary:     Retrieve GPS data and store in the array read.
 * Argument:    char* read, pointer to array GPS that fills with data stream
 * **************************************************************************/
char GPSLib_Read(char* read)
{
    char num_messages_hex[2] = {0,0};
    char write[1] = {MSG_LEN_MSB};
    char error = I2C_WriteRead(GPS_ADDR, write, num_messages_hex, 1, 2);
    int num_messages_int = (num_messages_hex[0]<<1)|num_messages_hex[1];
    write[1] = GPS_DATA;
    error |= I2C_WriteRead(GPS_ADDR, write, read, 1, num_messages_int);
    return error;
}

/* **************************************************************************
 * Function:    char GPSLib_UBXWrite(TBD)
 * Summary:     
 * Argument:    unsigned char class_id,
 *				unsigned char msg_id, 
 *				unsigned char* payload,
 *				unsigned short payload_len
 * Return:		0  - no I2C write errors
 *  			!0 - an I2C write error was encountered
 * **************************************************************************/
char GPSLib_UBXWrite(unsigned char class_id,unsigned char msg_id, unsigned char* payload,unsigned short payload_len)
{
    unsigned char write[9] = {0};
    write[0] = SYNC_1;
    write[1] = SYNC_2;
    write[2] = class_id;
    write[3] = msg_id;
    write[4] = payload_len & 0xFF;
    write[5] = (payload_len>>8) & 0xFF;
    int i;
    for(i = 0; i<payload_len; i++)
    {
        write[6+i] = payload[i];
    }
    GPSLib_UBXChecksum(&write[2],payload_len);
    return I2C_Write(GPS_ADDR, write, payload_len+8);
}

/* **************************************************************************
 * Function:    void GPSLib_UBXChecksum(TBD)
 * Summary:     For a given payload size, calling this routine computes the
 *				checksum for a UBX message and adds them to the payload data 
 *				array.
 * Argument:    unsigned char* data, pointer to the start of checksum data
 *				int payload_len, length of payload
 * **************************************************************************/
void GPSLib_UBXChecksum(unsigned char* data,int payload_len)
{
    unsigned char CK_A = 0, CK_B = 0;
    int i = 0;
    for(i=0; i<(4+payload_len); i++)
    {
        CK_A = CK_A + data[i];
        CK_B = CK_B + CK_A;
    }
    data[i+0] = CK_A;
    data[i+1] = CK_B;
}