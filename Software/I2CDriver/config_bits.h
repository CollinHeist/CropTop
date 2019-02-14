/* **************************************************************************
 * File name:   config_bits.h
 * Association: University of Idaho
 * Author:      Ryan Donahue
 * Dates:       Created 1/29/2018
 * Summary:     This file contains configuration bits for initializing the
 *              PIC32 hardware.              
 * *************************************************************************/
#define _SUPPRESS_PLIB_WARNING
#pragma config FSRSSEL  = PRIORITY_7/* Interrupt priority 7 assigned to shadow set */
#pragma config FMIIEN   = OFF       /* RMII Ethernet PHY */
#pragma config FETHIO   = OFF       /* Default Ethernet I/O pin configuration */
#pragma config FCANIO   = OFF       /* Alternate CAN I/O pin configuration */
#pragma config FUSBIDIO = ON        /* USBID pin controlled by USB module */
#pragma config FVBUSONIO= ON        /* VBUSON pin controlled by USB module */
#pragma config FPLLIDIV = DIV_2     /* PLL input divider, divide by 2 */
#pragma config FPLLMUL  = MUL_20	/* PLL multiplier, multiply by 20 */
#pragma config UPLLIDIV = DIV_1     /* USB PLL input divider, divide by 2 */
#pragma config UPLLEN   = OFF       /* USB PLL disabled */
#pragma config FPLLODIV = DIV_1     /* PLL output divider, divide by 1 */
#pragma config FNOSC    = PRIPLL	/* Primary oscillator (XT,HS, EC) w/PLL */
#pragma config FSOSCEN  = OFF       /* Secondary oscillator disabled */
#pragma config IESO     = OFF       /* Internal/external clock switchover disabled */
#pragma config POSCMOD  = HS        /* Primary oscillator config,  8MHz resonator */
#pragma config OSCIOFNC = OFF       /* CLK0 disabled on OSCO pin */
#pragma config FPBDIV   = DIV_1     /* Peripheral bus clock divisor, divide by 1 */
#pragma config FCKSM    = CSDCMD	/* Clock Switching & Fail Safe Clock Monitor disabled */
#pragma config WDTPS    = PS1       /* Watchdog timer postcaler, 1:1 */
#pragma config FWDTEN   = OFF       /* Watchdog timer disabled */
#pragma config ICESEL   = ICS_PGx2	/* ICE/ICD Comm Channel Select, use PGC1 and PGD1 */
#pragma config BWP      = OFF       /* Boot Flash Write Protect, disabled */
#pragma config CP       = OFF       /* Code Protect disabled */
#pragma config DEBUG    = ON        /* Background debugger */    