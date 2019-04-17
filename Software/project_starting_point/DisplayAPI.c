#include "FT8xx.h"
#include "DisplayLib.h"

// APPLICATION DEFINITIONS
#define FTD81x_ACTIVE 0x00
#define FTD81x_CLKEXT 0x44

// LCD display parameters
unsigned int lcdWidth =     800;// Active width of LCD display
unsigned int lcdHeight =    480;// Active height of LCD display
unsigned int lcdHcycle =    928;// Total number of clocks per line
unsigned int lcdHoffset =   88;	// Start of active line
unsigned int lcdHsync0 =    0;	// Start of horizontal sync pulse
unsigned int lcdHsync1 =    48;	// End of horizontal sync pulse
unsigned int lcdVcycle =    525;// Total number of lines per screen
unsigned int lcdVoffset =   32;	// Start of active screen
unsigned int lcdVsync0 =    0;	// Start of vertical sync pulse
unsigned int lcdVsync1 =    3;	// End of vertical sync pulse
unsigned char lcdPclk =     2;	// Pixel Clock
unsigned char lcdSwizzle =  0;	// Define RGB output pins
unsigned char lcdPclkpol =  1;  // Define active edge of PCLK 

unsigned int cmdBufferRd;
unsigned int cmdBufferWr = 0x0000;
unsigned int cmdOffset = 0x0000;


void API_INIT(void)
{
    MCU_PDlow();
    MCU_Delay_ms(20);
    MCU_PDhigh();
    MCU_Delay_ms(20);

    MCU_SetFreq10();
    
    EVE_CmdWrite(FTD81x_CLKEXT, 0x00);
    EVE_CmdWrite(FTD81x_ACTIVE, 0x00);
    
    // Startup may take 300ms. Wait until ready
    while ((EVE_MemRead16(REG_ID) >> 8) != 0x7C);
 
    // Configure display registers
    EVE_MemWrite16(REG_HCYCLE,  lcdHcycle);	
    EVE_MemWrite16(REG_HOFFSET, lcdHoffset);
    EVE_MemWrite16(REG_HSYNC0,  lcdHsync0);	
    EVE_MemWrite16(REG_HSYNC1,  lcdHsync1);	
    EVE_MemWrite16(REG_VCYCLE,  lcdVcycle);	
    EVE_MemWrite16(REG_VOFFSET, lcdVoffset);	
    EVE_MemWrite16(REG_VSYNC0,  lcdVsync0);	
    EVE_MemWrite16(REG_VSYNC1,  lcdVsync1);	
    EVE_MemWrite8(REG_SWIZZLE,  lcdSwizzle);	
    EVE_MemWrite8(REG_PCLK_POL, lcdPclkpol);
    EVE_MemWrite16(REG_HSIZE,   lcdWidth);	
    EVE_MemWrite16(REG_VSIZE,   lcdHeight);
    
    // Write first display list
    // TODO Replace constants!
    EVE_MemWrite32(RAM_DL, 0x02000000);// Clear Color RGB sets the colour to clear screen to
    EVE_MemWrite32(RAM_DL+4, (0x26000000 | 0x00000007));// Clear 00100110 -------- -------- -----CST  (C/S/T define which parameters to clear)                                                // point to next location
    EVE_MemWrite32(RAM_DL+8, 0x00000000);// DISPLAY command 00000000 00000000 00000000 00000000 (end of display list)
    
    //Display list swap
    EVE_MemWrite32(REG_DLSWAP, DLSWAP_FRAME);
    
    // Enable display bit
    EVE_MemWrite8(REG_GPIO_DIR, 0x80 | EVE_MemRead8(REG_GPIO_DIR));
    EVE_MemWrite8(REG_GPIO, 0x80 | EVE_MemRead8(REG_GPIO));

    EVE_MemWrite8(REG_PCLK, lcdPclk);
    EVE_MemWrite16(REG_PWM_HZ, 250);
    EVE_MemWrite8(REG_PWM_DUTY, 63);
    EVE_MemWrite16(REG_GPIOX, 1<<15);
    
    MCU_SetFreq20();

}

void API_CMD(unsigned long command)
{    
    EVE_MemWrite32(RAM_CMD, command);
    
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 4);
    
    EVE_MemWrite32(REG_CMD_WRITE, cmdOffset);
    
    EVE_WaitCmdFifoEmpty();
}