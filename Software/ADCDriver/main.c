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
    SpiChnOpen(SPI_CHANNEL2, (SPI_OPEN_ON | SPI_OPEN_CKE_REV | SPI_OPEN_MSTEN), FPB_DIV_2);
    while(1){
        SpiChnPutC(SPI_CHANNEL2, 0b0);
    }
}








