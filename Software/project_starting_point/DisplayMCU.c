/** 
 *	@file	    DisplayMCU.c
 *	@brief	    
 *	@author	    Collin Heist
 **/

/* ----------------------------------- File Inclusion ----------------------------------- */

#include <plib.h>
#include <xc.h>
#include "hardware.h"
#include "display_library.h" 
#include "FT8xx.h"

/* -------------------------- Global Variables and Structures --------------------------- */

#define _XTAL_FREQ 12000000      // Required for _delay() function
//CS Pin timing
#define CS_LOW_TIMER 8
#define CS_HIGH_TIMER 8

/* ---------------------------------- Public Functions ---------------------------------- */

unsigned int initialize_display(void) {
    // Port pin set-up
    PORTSetPinsDigitalOut(CS_PORT, CS_PIN);	// Was TRISBbits.TRISB14 = 0;
    PORTSetPinsDigitalOut(PD_PORT, PD_PIN);	// Was TRISGbits.TRISG9 = 0;
    PORTSetPinsDigitalOut(SCLK_PORT, SCLK_PIN);	// Was TRISGbits.TRISG6 = 0;
    PORTSetPinsDigitalIn(MISO_PORT, MISO_PIN);	// Was TRISGbits.TRISG7 = 1;
    PORTSetPinsDigitalOut(MOSI_PORT, MOSI_PIN);	// Was TRISGbits.TRISG8 = 0;
    
    // SPI 2 set-up
    SPI1CONbits.ON  = 0;// Disable SPI1 and configure it
    
    set_display_SPI_frequency_10MHZ();
    
    SPI1CONbits.DISSDO = 0;     //SDO pin used by SPI module
    SPI1CONbits.CKP    = 0;     //Clock polarity, idle high | active low  

    SPI1CONbits.MSTEN = 1;      //SPI is in master mode
    SPI1CONbits.MODE32 = 0;
    SPI1CONbits.MODE16 = 0;

    SPI1CONbits.SMP = 0;       //Data samples in middle of data output time
    SPI1CONbits.CKE = 1;       //clock edge select rising edge
    
    SPI1STATbits.SPITBE = 1;  //SPI transmit buffer is empty
    SPI1STATbits.SPIRBF = 0;
    SPI1STATbits.SPIROV = 0;
    
    SPI1CONbits.ON = 1;// Enable SPI1 after configuration
    
    return NO_ERROR;
}
void set_display_SPI_frequency_10MHZ(void) {
    SPI1BRGCLR = 0x000000FF;
    SPI1BRGSET = 0x00000003;
}
void set_display_SPI_frequency_20MHZ(void) {
    SPI1BRGCLR = 0x000000FF;
    SPI1BRGSET = 0x00000001;
}



// ########################### GPIO CONTROL ####################################
// --------------------- Chip Select line low ----------------------------------
void MCU_CSlow(void)
{
    CS_LOW();
    unsigned int i;
    for(i=0; i < CS_LOW_TIMER; i++);
}  

// --------------------- Chip Select line high ---------------------------------
void MCU_CShigh(void)
{
    unsigned int i;
    for (i=0; i < CS_HIGH_TIMER; i++);
    CS_HIGH();
}

// -------------------------- PD line low --------------------------------------
void MCU_PDlow(void)
{
    PD_LOW();
}

// ------------------------- PD line high --------------------------------------
void MCU_PDhigh(void)
{
    PD_HIGH();
}

// ################################# SPI #######################################

// --------------------- SPI Send and Receive ----------------------------------
unsigned char MCU_SPIReadWrite(unsigned char DataToWrite)
{
    unsigned char DataRead = 0;
    
    SPI1BUF = (DataToWrite);                                                    // Write data to SPI data register                          
    while (!SPI1STATbits.SPITBE);                                                    // Wait for completion of the SPI transfer
    DataRead = SPI1BUF;                                                         // Get the value clocked in from the FT8xx
    
    return DataRead;
}

void MCU_Delay_1ms(void)
{
    unsigned int ms = 7272;
    int i;
    for(i=0;i<ms;i++){
        Nop();
    }
}
void MCU_Delay_ms(unsigned int time_in_ms)
{
    unsigned int i;
    for(i=0;i<time_in_ms;i++){
        MCU_Delay_1ms();
    }
}

/* --------------------------------- Private Functions ---------------------------------- */

/* ----------------------------- Interrupt Service Routines ----------------------------- */
