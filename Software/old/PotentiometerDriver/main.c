/* **************************************************************************
 * File name:   main.c
 * Association: University of Idaho
 * Author:      Ryan Donahue
 * Dates:       Created 2/11/2018
 * Summary:     This file contains a main loop and several functions to test
 *              the PotLib.c library functionality.
 * *************************************************************************/
#define _SUPPRESS_PLIB_WARNING
#include <plib.h>
#include "crop_top.h"
#include "PotLib.h"

int main()
{
    //initialize system
    PotLib_Init();
    //variables
    unsigned int read;
    while(1)
    {
        read = PotLib_SingleRead();
    }
}