/* **************************************************************************
 * File name:   MotorLib.c
 * Association: University of Idaho
 * Author:      Ryan Donahue
 * Dates:       Created 1/9/2018
 * 
 * Summary:     This file contains a functions used to operate a TI DRV8872DDAR
 *              motor driver IC. The device operates via PWM signals generated 
 *              by the PIC32 output compare modules 1 and 2 and GPIO.
 * 
 * Notes:       Software things:
 *              -The toggles per second macro needs to be calibrated for the new 
 *               clock rate.
 *
 *              Hardware things:
 *              -Looks like the nFault pin should have a pullup resistor datasheet says
 *               "high-z when operating normal, low during a fault"
 *              -Add in a sense resistor to prevent overcurrent
 *              -Fix the CN15 label on pin 82 to say "CN14"
 *              -Fix the polarity of the reverse protection diode D9
 * **************************************************************************/
#define _SUPPRESS_PLIB_WARNING
#include <plib.h>
#include "crop_top.h"
#include "MotorLib.h"

/* **************************************************************************
 * Function:    void MotorLib_Init()
 * Summary:     Envokes GPIO, Timers, Output Compare, and Change Notice
 *              interrupt initialization functions.
 * **************************************************************************/
void MotorLib_Init()
{
    //enable GPIO
    MotorLib_PortSetup();
    //enable the timers used by the module
    MotorLib_TimersSetup();
    //enable the output compare peripheral
    MotorLib_OCSetup();
    //enable the fault indicator interrupt
    MotorLib_CNInterruptSetup();
}

/* **************************************************************************
 * Function:    void MotorLib_GPIOSetup()
 * Summary:     Sets port D motor IC pins directions.
 * **************************************************************************/
void MotorLib_PortSetup()
{
    //output compare module pins
    PORTSetPinsDigitalOut(IOPORT_D, (IN1 | IN2)); 
    //driver fault change notice interrupt pin
    PORTSetPinsDigitalIn(IOPORT_D, nFAULT);
}

/* **************************************************************************
 * Function:    void MotorLib_TimersSetup()
 * Summary:     Initializes Timer 2 to generate a priority 1 (sub priority 0)
 *              interrupt every 1 millisecond.
 * **************************************************************************/
void MotorLib_TimersSetup()
{
    //timer 2 generates interrupt once each mS.
    OpenTimer2((T2_ON | T2_SOURCE_INT |T2_PS_1_16), PR2_VALUE);
    //set timer interrupt to priority group to 2, subgroup 0
    ConfigIntTimer2(T2_INT_ON | T2_INT_PRIOR_1 | T2_INT_SUB_PRIOR_0);
    mT2ClearIntFlag();
    mT2IntEnable(1);
}

/* **************************************************************************
 * Function:    void __ISR(_TIMER_2_VECTOR, IPL1SOFT) Timer2Handler(void)
 * Summary:     Entered on Timer 2 reaching count of PR2_VALUE. Afterwards,
 *              Timer 2 interrupt flag is cleared.
 * **************************************************************************/
void __ISR(_TIMER_2_VECTOR, IPL1SOFT) Timer2Handler(void)
{
    LATCINV = LED_A;
    mT2ClearIntFlag();
}

/* **************************************************************************
 * Function:    void MotorLib_OCSetup()
 * Summary:     Initializes Output Compare modules 2 and 3 for 0% duty cycle
 *              based on Timer 2.
 * **************************************************************************/
void MotorLib_OCSetup()
{
    //initial values
    int nOCRS = 0;
    int nOCR = nOCRS;
    //output compare 2
    OpenOC2(OC_ON|OC_TIMER_MODE16|OC_TIMER2_SRC|OC_PWM_FAULT_PIN_DISABLE, nOCRS, nOCR);
    //output compare 3
    OpenOC3(OC_ON|OC_TIMER_MODE16|OC_TIMER2_SRC|OC_PWM_FAULT_PIN_DISABLE, nOCRS, nOCR);
}

/* **************************************************************************
 * Function:    void MotorLib_DutyCycleSet(unsigned int C2DutyCycle, unsigned int C3DutyCycle)
 * arguments:   unsigned int C2DutyCycle,   new (0-100)% PWM setting for OC2
 *              unsigned int C3DutyCycle,   new (0-100)% PWM setting for OC3
 * Summary:     Modifies the DutyCycle of each of the Output Compare modules
 *              to a percentage indicated by the arguments, 100 sets 100% duty 
 *              cycle (DC).
 * **************************************************************************/
void MotorLib_DutyCycleSet(unsigned int C2DutyCycle, unsigned int C3DutyCycle)
{
    //calculate the new PWM register values
    int new_nOC2RS = (PR2_VALUE*C2DutyCycle/100)-1;
    int new_nOC3RS = (PR2_VALUE*C3DutyCycle/100)-1;
    //change the PWM setting
    SetDCOC2PWM(new_nOC2RS);
    SetDCOC3PWM(new_nOC3RS);
}

/* **************************************************************************
 * Function:    void MotorLib_CNInterruptSetup()
 * Summary:     Initializes change notice priority level 2 interrupts for the 
 *              voltage transitions of the nFAULT pin.
 * **************************************************************************/
void MotorLib_CNInterruptSetup()
{
    //variable for dummy read
    unsigned int dummy;    
    //enable CN14 for pin 82
    mCNOpen(CN_ON, CN14_ENABLE, 0);
    //set priority levels group level 1, subgroup 0
    mCNSetIntPriority(1);
    mCNSetIntSubPriority(0);
    //read port to clear difference
    dummy = PORTReadBits(IOPORT_D, nFAULT);
    //clear flag and enable interrupt
    mCNClearIntFlag();
    mCNIntEnable(1);
}

/* **************************************************************************
 * Function:    void __ISR(_CHANGE_NOTICE_VECTOR, IPL1SOFT) CNIntHandler(void)
 * Summary:     Activated by over current, undervoltage, or thermal overload 
 *              the motor driver triggering nfault interrupt. The handler 
 *              immediately stops the motor and issues a fault message 
 *              semaphore.
 * **************************************************************************/
void __ISR(_CHANGE_NOTICE_VECTOR, IPL1SOFT) CNIntHandler(void)
{
    //check that it was a motor fault
    if(PORTReadBits(IOPORT_D, nFAULT))
    {
        //Stop the motor
        MotorLib_Coast();
        //flick a light or ideally trigger a semaphore that unblocks a warning
        //screen task
    }
}

/* **************************************************************************
 * Function:    void MotorLib_Forward(unsigned int speed)
 * Argument:    unsigned int speed, (0-100)% speed for forward movement
 * Summary:     Sets output PWM signals to move motor forward.
 * **************************************************************************/
void MotorLib_Forward(unsigned int speed)
{
    MotorLib_DutyCycleSet(speed, 0);
}

/* **************************************************************************
 * Function:    void MotorLib_Reverse(unsigned int speed)
 * Argument:    unsigned int speed, (0-100)% speed for reverse movement
 * Summary:     Sets output PWM signals to move motor backward.
 * **************************************************************************/
void MotorLib_Reverse(unsigned int speed)
{
    MotorLib_DutyCycleSet(0, speed);
}

/* **************************************************************************
 * Function:    void MotorLib_Coast()
 * Summary:     Sets output PWM signals to High-Z state allowing the motor
 *              to "coast".
 * **************************************************************************/
void MotorLib_Coast()
{
    MotorLib_DutyCycleSet(0, 0);
}

/* **************************************************************************
 * Function:    void MotorLib_Brake()
 * Summary:     Brakes motor through low-side decay.
 * **************************************************************************/
void MotorLib_Brake()
{
    MotorLib_DutyCycleSet(100, 100);
}

/* **************************************************************************
 * Function:    void MotorLib_ForwardBackwardTest(unsigned int speed)
 * Argument:    unsigned int speed, (0-100)% speed for movement
 * Summary:     Reads status of buttons 1 and 2 to control the operation of
 *              linear actuator. Used for debug and testing.
 * **************************************************************************/
void MotorLib_ForwardBackwardTest(unsigned int speed)
{
    //local variables
    int ButtonA, ButtonB;
    //configure IO
    ButtonA = (PORTReadBits(IOPORT_C, BUTTON_A))>>14;
    ButtonB = (PORTReadBits(IOPORT_C, BUTTON_B))>>13;
    if((ButtonA == 1) && (ButtonB ==0))
    {
        MotorLib_Forward(speed);
    }
    else if((ButtonA == 0) && (ButtonB == 1))
    {
        MotorLib_Reverse(speed);
    }
    else
    {
        MotorLib_Coast();
    }
}