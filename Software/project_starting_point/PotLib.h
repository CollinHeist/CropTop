/* **************************************************************************
 * File name:   PotLib.h
 * Association: University of Idaho
 * Author:      Ryan Donahue
 * Dates:       Created 2/11/2018
 * Summary:     This file contains macro definitions used in the project.             
 * *************************************************************************/
#define _SUPPRESS_PLIB_WARNING

//macros
#define AN9 (0x01<<9)   //port b

//function declarations
void PotLib_Init();
void PotLib_ADCInit();
unsigned int PotLib_SingleRead();