/* **************************************************************************
 * File name:   MotorLib.h
 * Association: University of Idaho
 * Author:      Ryan Donahue
 * Dates:       Created 2/9/2018
 * Summary:     This file contains macro definitions and prototypes for the
				motor library.     
 * *************************************************************************/
#define _SUPPRESS_PLIB_WARNING

//timer macros
#define T2_PRESCALE 16
#define T2_TOGGLES_PER_SEC 1000
#define PR2_VALUE (GetPeripheralClock()/T2_PRESCALE/T2_TOGGLES_PER_SEC)

//pin macros
#define nFAULT (BIT_5)                                //port D
#define IN1 (BIT_1)                                   //port D
#define IN2 (BIT_2)                                   //port D

//prototypes
void MotorLib_Init();
void MotorLib_PortSetup();
void MotorLib_TimersSetup();
void MotorLib_OCSetup();
void MotorLib_DutyCycleSet(unsigned int C2DutyCycle, unsigned int C3DutyCycle);
void MotorLib_CNInterruptSetup();
void MotorLib_Forward(unsigned int speed);
void MotorLib_Reverse(unsigned int speed);
void MotorLib_Coast();
void MotorLib_Brake();
void MotorLib_ForwardBackwardTest(unsigned int speed);