#include <xc.h>
#include "DisplayLib.h" 
#include "FT8xx.h"

#define _XTAL_FREQ 12000000      // Required for _delay() function

// ------------------- MCU specific initialisation  ----------------------------
void MCU_Init(void)
{       
    //Notes: May still need to find a way to make SCLK = FOSC/16
    
    // Port pin set-up
    TRISBbits.TRISB14 = 0;                                                      // CS
    TRISGbits.TRISG9 = 0;                                                       // PD pin
    TRISGbits.TRISG6 = 0;                                                       // SCK 
    TRISGbits.TRISG7 = 1;                                                       // SDI (MISO)
    TRISGbits.TRISG8 = 0;                                                       // SDO (MOSI) 
    
    // SPI 1 set-up
    SPI2CONbits.ON  = 0;                                                    // Disable SPI1 and configure it
    
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
    
    SPI2BRGCLR = 0x000001FF;
    SPI2BRGSET = 0x00000010;

    SPI2CONbits.ON = 1;                                                    // Enable SPI1 after configuration
    
}

// ########################### GPIO CONTROL ####################################

// --------------------- Chip Select line low ----------------------------------
void MCU_CSlow(void)
{
    LATBbits.LATB14 = 0;                                                         // CS# line low
    Nop();
}  

// --------------------- Chip Select line high ---------------------------------
void MCU_CShigh(void)
{
    Nop();
    LATBbits.LATB14 = 1;                                                         // CS# line high
}

// -------------------------- PD line low --------------------------------------
void MCU_PDlow(void)
{
    LATGbits.LATG9 = 0;                                                         // PD# line low
}

// ------------------------- PD line high --------------------------------------
void MCU_PDhigh(void)
{
    LATGbits.LATG9 = 1;                                                         // PD# line high
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

void MCU_Delay_20ms(void)
{
    int delay = 20;
    int i;
    while(delay --){
        for(i=0;i<8850;i++){
            //Do nothing
        }
    }
}

void MCU_Delay_500ms(void){
    unsigned char dly = 0;                                                      
    for(dly =0; dly < 100; dly++){
    MCU_Delay_20ms();
    }
}

