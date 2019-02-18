/* **************************************************************************
 * File name:   crop_top.h
 * Association: University of Idaho
 * Author:      Ryan Donahue
 * Dates:       Created 1/29/2018
 * Summary:     This file contains all the macro definitions used by the entire
 *              project.             
 * *************************************************************************/
#define _SUPPRESS_PLIB_WARNING

//function prototypes
void initialize_system();

//macros
#define BUTTON_A    (BIT_14)                  //port c
#define BUTTON_B    (BIT_13)                  //port c
#define BUTTONS     (BUTTON_A | BUTTON_B)   //port c
#define LED_A       (BIT_1)               //port c
#define LED_B       (BIT_2)               //port c
#define LEDS        (LED_A | LED_B)         //port c


//system timing definitions

#define GetSystemClock()		(80000000ul)
#define GetInstructionClock()	(GetSystemClock()/2)	
#define GetPeripheralClock()	(GetSystemClock()/1)	
#define CORE_MS_TICK_RATE	(GetInstructionClock()/1000)