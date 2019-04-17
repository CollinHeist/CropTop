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
//#include "MotorLib.h"
//#include "PotLib.h"
#include "FT8xx.h"
#include "DisplayLib.h"

/*
 *
 *  The graphics engine interprets commands from the MPU host via a 4 Kbyte 
 * FIFO in the FT81x memory at RAM_CMD. 
 * 
 * The MPU/MCU writes commands into the FIFO, and the graphics engine  reads 
 *  and  executes  the  commands. 
 * 
 * The MPU/MCU  updates the register REG_CMD_WRITE to indicate  that  there 
 *  are  new  commands  in  the  FIFO, and  the  graphics  engine 
 *  updates REG_CMD_READ after commands have been executed
 
 */

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
uint8_t lcdPclk =     2;	// Pixel Clock
uint8_t lcdSwizzle =  0;	// Define RGB output pins
uint8_t lcdPclkpol =  1;  // Define active edge of PCLK 

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
    EVE_MemWrite16(REG_TOUCH_RZTHRESH, 1200);  
    
    // Write first display list
    EVE_MemWrite32(RAM_DL, 0x02000000);
    EVE_MemWrite32(RAM_DL+4, (0x26000000 | 0x00000007));
    EVE_MemWrite32(RAM_DL+8, 0x00000000);
    EVE_MemWrite32(REG_DLSWAP, DLSWAP_FRAME);
    
    // Enable display bit
    EVE_MemWrite8(REG_GPIO_DIR, 0x80 | EVE_MemRead8(REG_GPIO_DIR));
    EVE_MemWrite8(REG_GPIO, 0x80 | EVE_MemRead8(REG_GPIO));
    EVE_MemWrite
    EVE_MemWrite8(REG_PCLK, lcdPclk);

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


    //EVE_MemWrite16(REG_PWM_HZ, 250);
    //EVE_MemWrite8(REG_PWM_DUTY, 63);
    //EVE_MemWrite16(REG_GPIOX, 1<<15);
    
    MCU_SetFreq20();

}

void APP_Calibrate(void)
{
    API_LIB_BeginCoProList();                                                   // Begin new co-processor list 
    API_CMD_DLSTART();                                                          // Tell co-processor to create new Display List
       
    API_CLEAR_COLOR_RGB(0,0,0);                                                 // Specify color to clear screen to
    API_CLEAR(1,1,1);                                                           // Clear color, stencil, and tag buffer
    
    API_CMD_TEXT(100, 100, 30, 0, "Calibration - Please tap the dots");         // Message to user
    
    API_CMD_CALIBRATE(0);                                                       // Run the calibration
    
    API_DISPLAY();                                                              // Tell EVE that this is end of list
    API_CMD_SWAP();                                                             

    API_LIB_EndCoProList();                                                     // Finish the co-processor list burst write
    API_LIB_AwaitCoProEmpty();                                                  // Wait until co-processor has consumed all commands 
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
        
        API_DISPLAY();                                                          // Tell EVE that this is end of list
        API_CMD_SWAP();                                                         // Swap buffers in EVE to make this list active

        API_LIB_EndCoProList();                                                 // Finish the co-processor list burst write
        API_LIB_AwaitCoProEmpty();                                              // Wait until co-processor has consumed all commands 
                    
        //APP_SnapShot2PPM();                                                   // Un-comment to take snapshot (see BRT_AN_014)
            
        MCU_Delay_ms(1000);                                                   // Delay to slow down the flashing of the dot to allow user to see it
    }
}

void APP_SliderandButton(void)   
{
    uint32_t TrackerVal = 0;
    uint8_t TagVal = 0;
    uint16_t SlideVal = 0;
    uint16_t Button3D = 0;
    uint8_t color = 0;
   
    while(1)
    {
        API_LIB_BeginCoProList();                                               // Begin new screen 
        API_CMD_DLSTART();                                                      // Tell co-processor to create new Display List
        
        API_CLEAR_COLOR_RGB(0, 0, 0);                                           // Specify color to clear screen to
        API_CLEAR(1,1,1);                                                       // Clear color, stencil, and tag buffer
        
        API_TAG_MASK(1);                                                        // Enable tagging

        API_TAG(2);                                                             // Tag following items with tag 2
        API_CMD_FGCOLOR(0x0000FF);                                              // Blue foreground color
        API_CMD_BUTTON(100, 200, 80, 30, 27, Button3D, "Button");               // Draw button
        
        API_TAG(5);                                                             // Tag following items with tag 5
        API_CMD_SLIDER(300, 100, 16, 200, 0, SlideVal, 255);                    // Draw a slider
        API_CMD_TRACK(300, 100, 16, 200, 5);                                    // Place a tracker
        
        API_TAG_MASK(0);                                                        // Mask tagging so that following items won't be tagged
        
        API_BEGIN(FTPOINTS);                                                    // Draw a dot in red at 140, 100)		
        API_POINT_SIZE(30*16);  
        API_COLOR_RGB(color, 0, 0);                                             // Set colour to blue and write some text
        API_VERTEX2F((140*16), (100*16));
        API_END(); 
        
        API_DISPLAY();                                                          // Tell EVE that this is end of list
        API_CMD_SWAP();                                                         // Swap buffers in EVE to make this list active

        API_LIB_EndCoProList();                                                 // Finish the co-processor list burst write
        API_LIB_AwaitCoProEmpty();                                              // Wait until co-processor has consumed all commands 

        // ------ read tag and tracker values --------
        TagVal = EVE_MemRead8(REG_TOUCH_TAG);                                   // Get Tag value
        TrackerVal = EVE_MemRead32(REG_TRACKER);                                // Read the value of the tag and track register

        if(TagVal == 2)   
        {// If button pushed tag register will read 2
            color = 0xFF;                                                       // change red amount to 255
            Button3D = 256;                                                     // Give the button a pushed-in appearance
        }
        else  
        {// Otherwise...
            color = 0x00;                                                       // change red amount to 0 so dot is not visible
            Button3D = 0;                                                       // Button has 3D effect (not pushed in))
        }
        
        if(TagVal == 5)                                                         // if slider touched...
        {
            SlideVal = (TrackerVal >> 24);                                      // ... then get the tracker value. 
            // Note: Value of tracking is 16 bits but we only use upper 8 bits since the slider is set for 8 bit resolution
        }
                
        //APP_SnapShot2PPM();                                                   // Un-comment to take snapshot (see BRT_AN_014)
        
        // Result of button press and slider value will be displayed next time round
    }
}

int main()
{
    initialize_system();
    MCU_Init();
    APP_Init();
    
    APP_Calibrate();
   
//    APP_SliderandButton();
    
    APP_FlashingDot();
    
//    APP_VertexTranslate();
    
    while (1)
    {
        // yaw hee
    }
    
}
void initialize_system()
{
	SYSTEMConfig(GetSystemClock(), SYS_CFG_WAIT_STATES | SYS_CFG_PCACHE);
    DDPCONbits.JTAGEN = 0;
    PORTSetPinsDigitalIn(IOPORT_C, BUTTONS);
    PORTSetPinsDigitalOut(IOPORT_C, LEDS);
//    MCU_Init();//Configures FT812 SPI Bits, rename to something LCD related
    LATCCLR = LED_A;
    PotLib_Init();
    MotorLib_Init();
    INTEnableSystemMultiVectoredInt();
}
