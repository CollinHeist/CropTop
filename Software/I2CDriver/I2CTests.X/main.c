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

int main()
{
    initialize_system();
    int i;
    unsigned char who_is_it;
    float Z_read, Y_read, X_read;
    float temperature, humidity;
    double tilt;
    char st_failed;
    while(1)
    {
        i = 0;
        while(i<20000)
        {
            i++;
        }
        // do some shit
        temperature = Si7006_ReadTemp();
        humidity = Si7006_ReadHumidity();
        Z_read = AccelLib_ReadZ();
        Y_read = AccelLib_ReadY();
        X_read = AccelLib_ReadX();
        tilt = AccelLib_ReadTilt();
        st_failed = AccelLib_SelfTest();
        who_is_it = AccelLib_SingleRead(WHO_AM_I);
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