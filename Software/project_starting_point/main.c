/* **************************************************************************
 * 
 * To become DisplayAPP.c, this only operates as main.c for testing purposes!
 * 
 * File name:   main.c
 * Association: University of Idaho
 * Author:      Conrad Mearns
 * Dates:       Created 3/22/2018
 * Summary:     Application level driver for 7" Touchscreen
 * Notes:       
 * *************************************************************************/
#define _SUPPRESS_PLIB_WARNING
#include <plib.h>
#include "config_bits.h"
#include "crop_top.h"
#include "MotorLib.h"
#include "PotLib.h"
#include "FT8xx.h"
#include "DisplayLib.h"

// APPLICATION SPECIFIC DEFINITIONS
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


//FROM EXAMPLE
unsigned int cmdOffset = 0x0000;		// Used to navigate command rung buffer
unsigned long color;				// Variable for changing colors
unsigned int point_size = 0x0100;		// Define a default dot size

///////

// Lame interface
void APP_Init(void);
void APP_FlashingDot(void);

int main()
{
    // Initialize board
    initialize_system();
    
    // Initialize Display MCU
    MCU_Init();
    APP_Init();
    APP_FlashingDot();
    unsigned int TestRead;
    while(1)
    {
//        TestRead = PotLib_SingleRead();
//        LATCINV = LED_A;
    }
}
void initialize_system()
{
	SYSTEMConfig(GetSystemClock(), SYS_CFG_WAIT_STATES | SYS_CFG_PCACHE);
    PORTSetPinsDigitalIn(IOPORT_C, BUTTONS);
    PORTSetPinsDigitalOut(IOPORT_C, LEDS);
    PotLib_Init();
    MotorLib_Init();
    INTEnableSystemMultiVectoredInt();
}
void APP_Init(void)
{
//    // Not listed in Programming manual
//    // PM shows usage of MCU_SPI_CLK_Freq?
//    MCU_PDlow();
//    MCU_Delay_20ms();
//    MCU_PDhigh();
//    MCU_Delay_20ms();

    EVE_CmdWrite(FTD81x_CLKEXT, 0x00);
    EVE_CmdWrite(FTD81x_ACTIVE, 0x00);
    
    // Startup may take 300ms. Wait until ready
    while (EVE_MemRead8(REG_ID) != 0x7C);
    while (EVE_MemRead8(REG_CPURESET) != 0x00);
 
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
    EVE_MemWrite8(REG_PWM_DUTY, 127);
}
void APP_FlashingDot(void)
{
   
    cmdOffset = EVE_WaitCmdFifoEmpty();                                         // Wait for command FIFO to be empty and record current position in FIFO
            
    while(1)
    {   
        if(color == 0x00)                                                       // Toggle colour variable
            color = 0xFF;
        else
            color = 0x00;
        
        MCU_CSlow();                                                            // CS low begins SPI transaction 
        EVE_AddrForWr(RAM_CMD + cmdOffset);                                     // Send address to which first value will be written
       
        EVE_Write32(CMD_DLSTART);                                               // Co-pro starts new DL at RAM_DL + 0
        cmdOffset = EVE_IncCMDOffset(cmdOffset, 4);                             // Keep count of bytes sent so that write pointer can be updated at end
                                                                                // Keeping CS low and FT8xx will auto increment address for 'burst write'

        EVE_Write32(CLEAR_COLOR_RGB(0,0,0));                                    // Set the default clear color to black
        cmdOffset = EVE_IncCMDOffset(cmdOffset, 4);                                

        EVE_Write32(CLEAR(1,1,1));                                              // Clear the screen Attributes color, stencil and tag buffers
        cmdOffset = EVE_IncCMDOffset(cmdOffset, 4);                               

        EVE_Write32 (COLOR_RGB(color,0,0));                                     // Specify RGB colour of subsequent items drawn
        cmdOffset = EVE_IncCMDOffset(cmdOffset, 4);                                 

        EVE_Write32(BEGIN(FTPOINTS));                                           // Begin drawing points
        cmdOffset = EVE_IncCMDOffset(cmdOffset, 4);                               

        EVE_Write32(POINT_SIZE(point_size));                                    // Select the size of the dot to draw
        cmdOffset = EVE_IncCMDOffset(cmdOffset, 4);                              
    
        EVE_Write32(VERTEX2F(100*16,100*16));                                   // Set the point center location
        cmdOffset = EVE_IncCMDOffset(cmdOffset, 4);                               

        EVE_Write32(END());                                                     // End drawing of points
        cmdOffset = EVE_IncCMDOffset(cmdOffset, 4);                           

        EVE_Write32(DISPLAY());                                                 // Instruct the graphics processor to show the list
        cmdOffset = EVE_IncCMDOffset(cmdOffset, 4);                    

        EVE_Write32(CMD_SWAP);                                                  // Make this list active
        cmdOffset = EVE_IncCMDOffset(cmdOffset, 4);                          

        MCU_CShigh();                                                           // Chip Select high concludes burst
    
        EVE_MemWrite32(REG_CMD_WRITE, (cmdOffset));                             // Update the ring buffer pointer 
                                                                                // Co-processor will now execute all of the above commands and create a display list
        cmdOffset = EVE_WaitCmdFifoEmpty();                                     // Await completion of processing and record starting address for next screen update
                                                                         
        MCU_Delay_500ms();                                                      // Delay to slow down the flashing of the dot to allow user to see it
        
    }
}