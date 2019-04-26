/* **************************************************************************
 * File name:   main.c
 * Association: University of Idaho
 * Author:      Ryan Donahue
 * Dates:       Created 2/09/2018
 * Summary:     This file is used to test the added drivers
 * Notes:       
 * *************************************************************************/
#define _SUPPRESS_PLIB_WARNING
#include <plib.h>
#include "config_bits.h"
#include "crop_top.h"
#include "MotorLib.h"
#include "PotLib.h"
#include "I2CLib.h"
#include "Si7006.h"
#include "AccelLib.h"
#include "GPSLib.h"
#include "Expo.h"

int main()
{
    initialize_system();
    int data_len = 0, err = 0, i;
    char write_data_stream[1] = {GPS_DATA};
    char read_data_stream[394] = {0};
    unsigned char payload[1] = {0};
    while(1)
    {
        i = 0;
        while(i<20000)
        {
            i++;
        }
        
        err |= GPSLib_UBXWrite(NAV, NAV_PVT, payload, 0);
//        err |= GPSLib_UBXWrite(NAV, NAV_STATUS, payload, 0);
//        err |= GPSLib_UBXWrite(NAV, NAV_POSLLH, payload, 0);
//        err |= GPSLib_UBXWrite(MON, MON_VER, payload, 0);
//        err |= GPSLib_UBXWrite(CFG, CFG_NAV5, payload, 0);
//        err |= GPSLib_UBXWrite(CFG, CFG_GNSS, payload, 0);
        
        data_len=0;
        while(data_len==0)
        {
            data_len = GPSLib_MessageCount();
        }
        
        err |= I2C_WriteRead(GPS_ADDR, write_data_stream, read_data_stream, 1, 394);
	}
}
void initialize_system()
{
	SYSTEMConfig(GetSystemClock(), SYS_CFG_WAIT_STATES | SYS_CFG_PCACHE);
    PORTSetPinsDigitalIn(IOPORT_C, BUTTONS);
    PORTSetPinsDigitalOut(IOPORT_C, LEDS);
//    PotLib_Init();
//    MotorLib_Init();
    I2CLib_Init();
//    AccelLib_Init();
//    INTEnableSystemMultiVectoredInt();
}