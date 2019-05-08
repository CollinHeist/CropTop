/* **************************************************************************
 * File name:   DisplayAPP.c
 * Association: University of Idaho
 * Author:      Conrad Mearns
 * Dates:       Created 4/25/2018
 * Summary:     Application level driver for 7" Touchscreen
 * Notes:       
 * *************************************************************************/

#include <stdint.h>
#include "DisplayLib.h"

//#define _SUPPRESS_PLIB_WARNING
//#include <plib.h>

// APPLICATION DEFINITIONS
#define FTD81x_ACTIVE 0x00
#define FTD81x_CLKEXT 0x44

// LCD display parameters
uint16_t lcdWidth =     800;// Active width of LCD display
uint16_t lcdHeight =    480;// Active height of LCD display
uint16_t lcdHcycle =    928;// Total number of clocks per line
uint16_t lcdHoffset =   88;	// Start of active line
uint16_t lcdHsync0 =    0;	// Start of horizontal sync pulse
uint16_t lcdHsync1 =    48;	// End of horizontal sync pulse
uint16_t lcdVcycle =    525;// Total number of lines per screen
uint16_t lcdVoffset =   32;	// Start of active screen
uint16_t lcdVsync0 =    0;	// Start of vertical sync pulse
uint16_t lcdVsync1 =    3;	// End of vertical sync pulse
uint8_t lcdPclk =       2;	// Pixel Clock
uint8_t lcdSwizzle =    0;	// Define RGB output pins
uint8_t lcdPclkpol =    1;  // Define active edge of PCLK 

void APP_Init(void)
{
    MCU_PDlow();
    MCU_Delay_ms(20);
    MCU_PDhigh();
    MCU_Delay_ms(20);

    MCU_SetFreq10();
    EVE_CmdWrite(FTD81x_CLKEXT, 0x00);
    EVE_CmdWrite(FTD81x_ACTIVE, 0x00);
    
    MCU_Delay_ms(500);

    // Startup may take 300ms. Wait until ready
    // TODO this should really just be a MemRead8...
    while ((EVE_MemRead16(REG_ID) >> 8) != 0x7C);
//    while (EVE_MemRead8(REG_ID) != 0x7C);

    EVE_MemWrite8(REG_PWM_DUTY, 0);

 
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
    
    
    // Touch settings
    EVE_MemWrite16(REG_TOUCH_MODE, 0x00);
    EVE_MemWrite16(REG_TOUCH_ADC_MODE, 0x01);
    EVE_MemWrite16(REG_TOUCH_CHARGE, 0x1770);
    EVE_MemWrite16(REG_TOUCH_SETTLE, 0x03);
    EVE_MemWrite16(REG_TOUCH_OVERSAMPLE, 0x07);
    EVE_MemWrite16(REG_TOUCH_RZTHRESH, 0xFFFF);

    
    // Write first display list
    EVE_MemWrite32(RAM_DL, 0x02000000);
    EVE_MemWrite32(RAM_DL+4, (0x26000000 | 0x00000007));
    EVE_MemWrite32(RAM_DL+8, 0x00000000);
    EVE_MemWrite32(REG_DLSWAP, DLSWAP_FRAME);
    
    // Enable display bit
    EVE_MemWrite8(REG_GPIO_DIR, 0x80 | EVE_MemRead8(REG_GPIO_DIR));
    EVE_MemWrite8(REG_GPIO, 0x80 | EVE_MemRead8(REG_GPIO));
    
    EVE_MemWrite8(REG_PCLK, lcdPclk);

    uint8_t PWM = 0;
    
    for (PWM = 0; PWM <= 127; PWM++)
    {
        EVE_MemWrite8(REG_PWM_DUTY, PWM);
        MCU_Delay_ms(20);
    }

    /*
    Disabled the following to add this sick PWM loop
    also, previous codes did not include PWM_HZ, or a similar GPIOX line

    What do those do?
    */

    EVE_MemWrite16(REG_PWM_HZ, 250);
    EVE_MemWrite8(REG_PWM_DUTY, 63);
    EVE_MemWrite16(REG_GPIOX, 1<<15);
    
    MCU_SetFreq20();
}

void APP_Calibrate(void)
{
    API_LIB_BeginCoProList();
    API_CMD_DLSTART();
       
    API_CLEAR_COLOR_RGB(0,0,0);
    API_CLEAR(1,1,1);
    
    API_CMD_TEXT(100, 100, 30, 0, "Calibration - Please tap the dots"); 
    
    API_CMD_CALIBRATE(0);
    
    API_DISPLAY();
    API_CMD_SWAP();

    API_LIB_EndCoProList();
    API_LIB_AwaitCoProEmpty();
}

void APP_SliderandButton(void)   
{
    uint32_t TrackerVal = 0;
    uint8_t TagVal = 0;
    uint16_t SlideVal = 0;
    uint16_t Button3D = 0;
    uint8_t color = 0xFF;
    char status[100];
   
    while(1)
    {
        API_LIB_BeginCoProList();                                              
        API_CMD_DLSTART();                                                
        
        API_CLEAR_COLOR_RGB(0, 0, 0);                                        
        API_CLEAR(1,1,1);                                             

        API_TAG_MASK(1);                                
        API_TAG(2);                                               
        API_CMD_FGCOLOR(0x0000FF);                                            
        API_CMD_BUTTON(100, 200, 80, 30, 27, Button3D, "Button");                     
        API_TAG_MASK(0);                                
        
        API_BEGIN(FTPOINTS);                                       	
        API_POINT_SIZE(30*16);  
        API_COLOR_RGB(color, 0, 0);                     
        API_VERTEX2F((140*16), (100*16));
        API_END(); 
        
        API_COLOR_RGB(0xFF, 0xFF, 0xFF);
        API_CMD_TEXT(10, 10, 30, 0, status);
        
        API_DISPLAY();
        API_CMD_SWAP(); 

        API_LIB_EndCoProList();
        API_LIB_AwaitCoProEmpty();

        TagVal = EVE_MemRead8(0x30212C);
        //TagVal = EVE_MemRead8(REG_TOUCH_TAG);
        TrackerVal = EVE_MemRead32(REG_TRACKER);

        if(TagVal == 2)   
        {
            color = 0xFF;
            Button3D = 256;
        } else {
            color = 0x55;
            Button3D = 0;
        }
        
        uint16_t rz = EVE_MemRead16(0x302120);
        
        sprintf(status, "tag:[%d] track:[%d] rz:[%d]", TagVal, TrackerVal, rz);
                
        //APP_SnapShot2PPM();                                                   // Un-comment to take snapshot (see BRT_AN_014)
        
        // Result of button press and slider value will be displayed next time round
        MCU_Delay_ms(100);

    }
}

void APP_FlashingDot(void)
{
    uint8_t r = 0x00; 

    while(1)
    {
        if(r == 0x00)                                                       // Toggle colour variable
        {
            r = 0xFF;
        }else{
            r = 0x00;
        }
        // -------------------  Create screen  -------------------------------------
        
        API_LIB_BeginCoProList();                                               // Begin new screen
        API_CMD_DLSTART();                                                      // Tell co-processor to create new Display List
        
        API_CLEAR_COLOR_RGB(0, 0, 0);                                           // Specify color to clear screen to
        API_CLEAR(1,1,1);                                                       // Clear color, stencil, and tag buffer
        
        API_COLOR_RGB(r, 0x00, 0x00);                                             // Set color for subsequent items
        API_BEGIN(FTPOINTS);                                                    // Begin drawing points		
        API_POINT_SIZE(40*16);                                                  // Point size
        API_VERTEX2F(200*16, 200*16);                                           // Place a point at the specified coordinates
        API_END();                                                              // Finished drawing points
        
        API_COLOR_RGB(0xFF, 0xFF, 0xFF);
        API_CMD_TEXT(100, 100, 30, 0, "Hmmm, think time");

        
        API_DISPLAY();                                                          // Tell EVE that this is end of list
        API_CMD_SWAP();                                                         // Swap buffers in EVE to make this list active

        API_LIB_EndCoProList();                                                 // Finish the co-processor list burst write
        API_LIB_AwaitCoProEmpty();                                              // Wait until co-processor has consumed all commands 
                    
        //APP_SnapShot2PPM();                                                   // Un-comment to take snapshot (see BRT_AN_014)
            
        MCU_Delay_ms(1000);                                                   // Delay to slow down the flashing of the dot to allow user to see it
    }
}