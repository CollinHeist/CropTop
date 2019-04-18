/* **************************************************************************
 * File name:   main.c
 * Association: University of Idaho
 * Author:      Ryan Donahue
 * Dates:       Created 2/13/2018
 * Summary:     This file is used to test the I2C library
 * Notes:       
 * *************************************************************************/
#define _SUPPRESS_PLIB_WARNING
#include <plib.h>
#include "config_bits.h"
#include "crop_top.h"
#include "I2CLib.h"
#include "Si7006.h"
#include "AccelLib.h"
#include "GPSLib.h"

int main()
{
    initialize_system();
    int i, err = 0;
//    float temperature, humidity;
//    double tilt;
//    char st_failed;
    int data_len = 0;
    char write_data_len[2] = {MSG_LEN_MSB,MSG_LEN_LSB};
    char write_data_stream[1] = {GPS_DATA};
    char read_data_stream[170] = {0};
    unsigned char payload[1] = {0};
    while(1)
    {
        i = 0;
        while(i<20000)
        {
            i++;
        }
//        temperature = Si7006_ReadTemp();
//        humidity = Si7006_ReadHumidity();
//        tilt = AccelLib_ReadTilt();
//        st_failed = AccelLib_SelfTest();
//        err |= GPSLib_UBXWrite(NAV, NAV_PVT, payload, 0);
        err |= GPSLib_UBXWrite(MON, MON_VER, payload, 0);
        data_len = GPSLib_MessageCount();
        err |= I2C_WriteRead(GPS_ADDR, write_data_stream, read_data_stream, 1, 170);
    }
}
void initialize_system()
{
    PORTSetPinsDigitalIn(IOPORT_C, BUTTONS);
    PORTSetPinsDigitalOut(IOPORT_C, LEDS);
    LATCCLR = LEDS;
    I2CLib_Init();
    AccelLib_Init();
}