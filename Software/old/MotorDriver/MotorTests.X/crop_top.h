/* **************************************************************************
 * File name:   crop_top.h
 * Association: University of Idaho
 * Author:      Ryan Donahue
 * Dates:       Created 1/29/2018
 * 
 * Summary:     This file contains all the macro definitions used by the entire
 *              project.            
 * *************************************************************************/
#define _SUPPRESS_PLIB_WARNING

#ifndef CROP_TOP_H

//function prototypes
void initialize_system();

//GPIO macros
#define BUTTON_A    BIT_14                  //port c
#define BUTTON_B    BIT_13                  //port c
#define BUTTONS     (BUTTON_A | BUTTON_B)   //port c
#define LED_A       (0x01)<<1               //port c
#define LED_B       (0x01)<<2               //port c
#define LEDS        (LED_A | LED_B)         //port c

//system timing definitions

#define GetSystemClock()		(80000000ul)
#define GetInstructionClock()	(GetSystemClock()/2)	
#define GetPeripheralClock()	(GetSystemClock()/1)	
#define CORE_MS_TICK_RATE	(GetInstructionClock()/1000)
   
#endif