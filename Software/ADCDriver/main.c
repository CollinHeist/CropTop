#include <stdlib.h>
#include <plib.h>
#include "crop_top.h"
#include "config_bits.h"
#define _SUPPRESS_PLIB_WARNING
#define FPB_DIV_2   2
#define SYS_FREQ    (80000000L)

int main(void){
    SYSTEMConfig(SYS_FREQ, SYS_CFG_WAIT_STATES | SYS_CFG_PCACHE);
    DDPCONbits.JTAGEN = 0;
    SpiChnOpen(SPI_CHANNEL3, (SPI_OPEN_ON | SPI_OPEN_CKE_REV | SPI_OPEN_MSTEN), FPB_DIV_2);
    
    PORTSetPinsDigitalOut(IOPORT_C, LEDS);
    PORTSetPinsDigitalOut(IOPORT_A, BIT_14);
    
    LATASET = BIT_14;
    LATCSET = LED_A;
    while(1){
        //LATACLR = BIT_14;
        SpiChnPutC(SPI_CHANNEL3, 0xAA);
        LATASET = BIT_14;
    }
}








