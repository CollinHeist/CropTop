#include <xc.h>
#include "DisplayLib.h" 
#include "FT8xx.h"

#define _XTAL_FREQ 12000000      // Required for _delay() function

//CS Pin timing
#define CS_LOW_TIMER 8
#define CS_HIGH_TIMER 8

/*
 * Section 23.3.2.1, DS61106E-page 23-23, ~Page 775 of
 * PIC32MX Family Reference Manual
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Perform the following steps to set up the SPI module 
 * for the Master mode of operation:
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

 * 1.Disable the SPI interrupts in the respective IEC0/1 register.
 * 2.Stop and reset the SPI module by clearing the ON bit.
 * 3.Clear the receive buffer.
 * 4. <SKIP>
 * 5.Write the Baud Rate register, SPIxBRG.
 * 6.Clear the SPIROV bit (SPIxSTAT<6>).
 * 7.Write the desired settings to the SPIxCON register with MSTEN (SPIxCON<5>) =1. 
 * 8.Enable SPI operation by setting the ON bit (SPIxCON<15>).
 * 9.Write the data to be transmitted to the SPIxBUF register. Transmission (and reception) willstart as soon as data is written to the SPIxBUF register.
  
 */

// ------------------- MCU specific initialisation  ----------------------------
void MCU_Init(void)
{    
    // Port pin set-up
    TRISBbits.TRISB14 = 0;                                                      // CS
    TRISGbits.TRISG9 = 0;                                                       // PD pin
    TRISGbits.TRISG6 = 0;                                                       // SCK 
    TRISGbits.TRISG7 = 1;                                                       // SDI (MISO)
    TRISGbits.TRISG8 = 0;                                                       // SDO (MOSI) 
    
    // SPI 2 set-up
    SPI2CONbits.ON  = 0;// Disable SPI1 and configure it
    
    MCU_SetFreq10();
    
    SPI2CONbits.DISSDO = 0;     //SDO pin used by SPI module
    SPI2CONbits.CKP    = 0;     //Clock polarity, idle high | active low  

    SPI2CONbits.MSTEN = 1;      //SPI is in master mode
    SPI2CONbits.MODE32 = 0;
    SPI2CONbits.MODE16 = 0;

    SPI2CONbits.SMP = 0;       //Data samples in middle of data output time
    SPI2CONbits.CKE = 1;       //clock edge select rising edge
    
    SPI2STATbits.SPITBE = 1;  //SPI transmit buffer is empty
    SPI2STATbits.SPIRBF = 0;
    SPI2STATbits.SPIROV = 0;
    
    SPI2CONbits.ON = 1;// Enable SPI1 after configuration
    
}
// ######################### FREQUENCY CONTROL #################################
// Set Frequency to 10Mhz
// TODO Rename along lines of SPI_FREQ
void MCU_SetFreq10()
{
    SPI2BRGCLR = 0x000000FF;
    SPI2BRGSET = 0x00000003;
}
// Set Frequency to 20Mhz
void MCU_SetFreq20()
{
    SPI2BRGCLR = 0x000000FF;
    SPI2BRGSET = 0x00000001;
}



// ########################### GPIO CONTROL ####################################
// --------------------- Chip Select line low ----------------------------------
void MCU_CSlow(void)
{
    LATGbits.LATG9 = 0;
    unsigned int i;
    for(i=0; i < CS_LOW_TIMER; i++);
}  

// --------------------- Chip Select line high ---------------------------------
void MCU_CShigh(void)
{
    unsigned int i;
    for(i=0; i < CS_HIGH_TIMER; i++);
    LATGbits.LATG9 = 1;
}

// -------------------------- PD line low --------------------------------------
void MCU_PDlow(void)
{
    LATBbits.LATB14 = 0;
}

// ------------------------- PD line high --------------------------------------
void MCU_PDhigh(void)
{
    LATBbits.LATB14 = 1;
}

// ################################# SPI #######################################

// --------------------- SPI Send and Receive ----------------------------------
unsigned char MCU_SPIReadWrite(unsigned char DataToWrite)
{
    unsigned char DataRead = 0;
    
    SPI2BUF = (DataToWrite);                                                    // Write data to SPI data register                          
    while(!SPI2STATbits.SPITBE);                                                    // Wait for completion of the SPI transfer
    DataRead = SPI2BUF;                                                         // Get the value clocked in from the FT8xx
    
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