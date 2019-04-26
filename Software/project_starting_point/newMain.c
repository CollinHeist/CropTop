/*
********************************************************************************
*             FT81x simple library examples for PIC MCU                                 *
********************************************************************************
Copyright (c) Future Technology Devices International / BridgeTek

THIS SOFTWARE IS PROVIDED BY FUTURE TECHNOLOGY DEVICES INTERNATIONAL LIMITED "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL
FUTURE TECHNOLOGY DEVICES INTERNATIONAL LIMITED BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
OF SUBSTITUTE GOODS OR SERVICES LOSS OF USE, DATA, OR PROFITS OR BUSINESS INTERRUPTION)
HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR
TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

FTDI DRIVERS MAY BE USED ONLY IN CONJUNCTION WITH PRODUCTS BASED ON FTDI PARTS.

FTDI DRIVERS MAY BE DISTRIBUTED IN ANY FORM AS LONG AS LICENSE INFORMATION IS NOT MODIFIED.

IF A CUSTOM VENDOR ID AND/OR PRODUCT ID OR DESCRIPTION STRING ARE USED, IT IS THE
RESPONSIBILITY OF THE PRODUCT MANUFACTURER TO MAINTAIN ANY CHANGES AND SUBSEQUENT WHQL
RE-CERTIFICATION AS A RESULT OF MAKING THESE CHANGES.

********************************************************************************
* This code is provided as an example only and is not guaranteed by FTDI.
* FTDI accept no responsibility for any issues resulting from its use.
* The developer of the final application incorporating any parts of this
* sample project is responsible for ensuring its safe and correct operation
* and for any consequences resulting from its use.
*
* Rev       Date        Author          Comment
********************************************************************************
* 1.0       Feb 2018	G Brown         Initial Release
*  *****************************************************************************
*/

#include <xc.h>
#include <string.h>
#include <stdint.h>                                                             // for Uint8/16/32 and Int8/16/32 data types
#include "FT8xx.h"
#include "Library.h"
#include "EVE_RGB565.h"
#include "DIGITfont.h"
#include "LeaveItToEVE.h"
#include "EVE_PNG.h"

#define LCD_800_480				
#define FT81x_ACTIVE	0x00			


// LCD display parameters
uint16_t lcdWidth;                                                              // Active width of LCD display
uint16_t lcdHeight;                                                             // Active height of LCD display
uint16_t lcdHcycle;                                                             // Total number of clocks per line
uint16_t lcdHoffset;                                                            // Start of active line
uint16_t lcdHsync0;                                                             // Start of horizontal sync pulse
uint16_t lcdHsync1;                                                             // End of horizontal sync pulse
uint16_t lcdVcycle;                                                             // Total number of lines per screen
uint16_t lcdVoffset;                                                            // Start of active screen
uint16_t lcdVsync0;                                                             // Start of vertical sync pulse
uint16_t lcdVsync1;                                                             // End of vertical sync pulse
uint8_t lcdPclk;                                                                // Pixel Clock
uint8_t lcdSwizzle;                                                             // Define RGB output pins
uint8_t lcdPclkpol;                                                             // Define active edge of PCLK

uint32_t ramDisplayList = RAM_DL;                                               // Set beginning of display list memory
uint32_t ramCommandBuffer = RAM_CMD;                                            // Set beginning of graphics command memory

uint16_t FT81x_GPIO_DAT;                                                        // Used for GPIO registers
uint16_t FT81x_GPIO_DIR;
uint8_t dly = 0;
uint8_t PWM = 0;
    
// #################### Function Declarations ##################################

// Application Layer
void APP_Init(void);
void APP_Calibrate(void);

void APP_FlashingDot(void);
void APP_VertexTranslate(void);                                                
void APP_LineStrip(void);    
void APP_Text(void);  
void APP_DigitsFont(void);
void APP_ConvertedBitmap(void);                                                          
void APP_InflateImage(void);
void APP_LoadImagePNG(void);
void APP_SliderandButton(void);   
void APP_ScreenRotate(void);
void APP_Append(void);
void APP_SnapShot2PPM(void);


//############################################################################## 
//##############################################################################
//                        MAIN APPLICATION
//##############################################################################  
//##############################################################################

void main(void) 
{
    // ------------------------ Initial Configuration --------------------------
    
    MCU_Init();                                                                 // MCU Initialisation including I/O, oscillator and SPI
    APP_Init();                                                                 // EVE initialisation
    //MCU_UART_Init();       // NOTE: Enable for snapshots                        // Initialise the MCU's UART
    APP_Calibrate();       // NOTE: Enable for any touch-related demos          // Perform calibration of touch screen
    
    // ------------------- Un-comment one of these demo apps -------------------
      
    //**** General ****  
    APP_FlashingDot();                                                        
    //APP_VertexTranslate();     
    //APP_LineStrip();
    //APP_Text();  
    //APP_DigitsFont();
    //APP_ConvertedBitmap();                                                          
    //APP_InflateImage();
    //APP_LoadImagePNG();
    //APP_SliderandButton();          // NOTE: Enable APP_Calibrate() above
    //APP_ScreenRotate();             // NOTE: Enable APP_Calibrate() above
    //APP_Append();
    //APP_SnapShot2PPM();             // NOTE: Enable MCU_UART_Init() above   

      
    while(1)
    {
            // Catch if it ever reaches here
    }    
}

//########################### INITIALISE EVE ###################################  
  
void APP_Init(void)
{
    // ----------------------- Cycle PD pin to reset device --------------------
    
    MCU_PDlow();                                                                // PD low to reset device                                                                
    MCU_Delay_20ms();
    MCU_PDhigh();                                                               // PD high again
    MCU_Delay_20ms();

    // ---------------------- Delay to allow FT81x start-up --------------------    
    
    EVE_CmdWrite(FT81x_ACTIVE, 0x00);                                           // Sends 00 00 00 to wake FT8xx
    
    MCU_Delay_500ms();                                                          // 500ms delay (EVE requires at least 300ms here))
        
    // --------------- Check that FT8xx ready and SPI comms OK ----------------- 
    
    while (EVE_MemRead8(REG_ID) != 0x7C)                                        // Read REG_ID register until reads 0x7C
    {
    }
      
    while (EVE_MemRead8(REG_CPURESET) != 0x00)                                  // Ensure CPUreset register reads 0 and so FT8xx is ready   
    {
    }

    // ---------------- Configure the GPIO and PWM  --------------------
    
    EVE_MemWrite8(REG_PWM_DUTY, 0);                                             // Backlight off
   
    FT81x_GPIO_DAT = EVE_MemRead16(REG_GPIOX);                                  // Read the FT81x GPIO register for a read/modify/write operation
    FT81x_GPIO_DAT = FT81x_GPIO_DAT | 0x8000;                                   // set bit 15 of GPIO register (DISP). If using audio, also enable the amplifier shutdown GPIO line here
    EVE_MemWrite16(REG_GPIOX, FT81x_GPIO_DAT);                                  // Enable the DISP signal to the LCD panel

    FT81x_GPIO_DIR = EVE_MemRead16(REG_GPIOX_DIR);                              // Read the FT81x GPIO DIR register for a read/modify/write operation
    FT81x_GPIO_DIR = FT81x_GPIO_DIR | 0x8000;                                   // DISP is output, if using audio, also set the associated shutdown line as output (check your Eval module schematic))
    EVE_MemWrite16(REG_GPIOX_DIR, FT81x_GPIO_DIR);                              // Enable the DISP signal to the LCD panel
        
    // ------------------------- Display settings ------------------------------

    // WQVGA display parameters
    lcdWidth   = 800;                                                           // Active width of LCD display
    lcdHeight  = 480;                                                           // Active height of LCD display
    lcdHcycle  = 928;                                                           // Total number of clocks per line
    lcdHoffset = 88;                                                            // Start of active line
    lcdHsync0  = 0;                                                             // Start of horizontal sync pulse
    lcdHsync1  = 48;                                                            // End of horizontal sync pulse
    lcdVcycle  = 525;                                                           // Total number of lines per screen
    lcdVoffset = 32;                                                            // Start of active screen
    lcdVsync0  = 0;                                                             // Start of vertical sync pulse
    lcdVsync1  = 3;                                                             // End of vertical sync pulse
    lcdPclk    = 2;                                                             // Pixel Clock
    lcdSwizzle = 0;                                                             // Define RGB output pins
    lcdPclkpol = 1;                                                             // Define active edge of PCLK
       
    EVE_MemWrite16(REG_HSIZE,   lcdWidth);	
    EVE_MemWrite16(REG_HCYCLE,  lcdHcycle);	
    EVE_MemWrite16(REG_HOFFSET, lcdHoffset);	
    EVE_MemWrite16(REG_HSYNC0,  lcdHsync0);	
    EVE_MemWrite16(REG_HSYNC1,  lcdHsync1);	
    EVE_MemWrite16(REG_VSIZE,   lcdHeight);	
    EVE_MemWrite16(REG_VCYCLE,  lcdVcycle);	
    EVE_MemWrite16(REG_VOFFSET, lcdVoffset);	
    EVE_MemWrite16(REG_VSYNC0,  lcdVsync0);	
    EVE_MemWrite16(REG_VSYNC1,  lcdVsync1);	
    EVE_MemWrite8(REG_SWIZZLE,  lcdSwizzle);	
    EVE_MemWrite8(REG_PCLK_POL, lcdPclkpol);	
    
    // ---------------------- Touch and Audio settings -------------------------

    EVE_MemWrite16(REG_TOUCH_RZTHRESH, 1200);                                   // Eliminate any false touches

    EVE_MemWrite8(REG_VOL_PB, ZERO);                                            // turn recorded audio volume down
    EVE_MemWrite8(REG_VOL_SOUND, ZERO);                                         // turn volume down
    EVE_MemWrite16(REG_SOUND, 0x6000);                                          // set volume mute

    // ---------------------- Create an initial screen before we enable the display -------------------------

    ramDisplayList = RAM_DL;                                                    // start of Display List
    EVE_MemWrite32(ramDisplayList, 0x02000000);                                 // Clear Color RGB sets the colour to clear screen to

    ramDisplayList += 4;                                                        // point to next location
    EVE_MemWrite32(ramDisplayList, (0x26000000 | 0x00000007));                  // Clear 00100110 -------- -------- -----CST  (C/S/T define which parameters to clear)

    ramDisplayList += 4;                                                        // point to next location
    EVE_MemWrite32(ramDisplayList, 0x00000000);                                 // DISPLAY command 00000000 00000000 00000000 00000000 (end of display list)

    EVE_MemWrite32(REG_DLSWAP, DLSWAP_FRAME);                                   // Swap display list to make the edited one active

    // -------------------- Now turn on PCLK and ramp the PWM up  -------------------------------------
    // ---------------- This provides a clean start-up for the application ----------------------------
        
    EVE_MemWrite8(REG_PCLK, lcdPclk);                                           // Now start clocking data to the LCD panel

    MCU_Delay_20ms();
    
    for(PWM = 0; PWM <= 127; PWM ++)
    {
        EVE_MemWrite8(REG_PWM_DUTY, PWM);      
        MCU_Delay_20ms();
    }
   
}     
   
     


  
//############################################################################## 
//##############################################################################
//                     INDIVIDUAL DEMO FUNCTIONS
//##############################################################################  
//##############################################################################

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

//############################################################################## 
//############################################################################## 

void APP_FlashingDot(void)
{
    uint8_t color = 0;
    
    while(1)
    {
        if(color == 0x00)                                                       // Toggle colour variable
            color = 0xFF;
        else
            color = 0x00;
        
        // -------------------  Create screen  -------------------------------------
        
        API_LIB_BeginCoProList();                                               // Begin new screen
        API_CMD_DLSTART();                                                      // Tell co-processor to create new Display List
        
        API_CLEAR_COLOR_RGB(0, 0, 0);                                           // Specify color to clear screen to
        API_CLEAR(1,1,1);                                                       // Clear color, stencil, and tag buffer
        
        API_COLOR_RGB(color, 0, 0);                                             // Set color for subsequent items
        API_BEGIN(FTPOINTS);                                                    // Begin drawing points		
        API_POINT_SIZE(40*16);                                                  // Point size
        API_VERTEX2F(200*16, 200*16);                                           // Place a point at the specified coordinates
        API_END();                                                              // Finished drawing points
        
        API_DISPLAY();                                                          // Tell EVE that this is end of list
        API_CMD_SWAP();                                                         // Swap buffers in EVE to make this list active

        API_LIB_EndCoProList();                                                 // Finish the co-processor list burst write
        API_LIB_AwaitCoProEmpty();                                              // Wait until co-processor has consumed all commands 
                    
        //APP_SnapShot2PPM();                                                   // Un-comment to take snapshot (see BRT_AN_014)
            
        MCU_Delay_500ms();                                                      // Delay to slow down the flashing of the dot to allow user to see it
    }
}

//############################################################################## 
//##############################################################################      
        

void APP_VertexTranslate(void)                                                
{
    API_LIB_BeginCoProList();                                                   // Begin new screen
    API_CMD_DLSTART();                                                          // Tell co-processor to create new Display List    
    
    API_CLEAR_COLOR_RGB(0,0,0);                                                 // Specify color to clear screen to
    API_CLEAR(1,1,1);                                                           // Clear color, stencil, and tag buffer
   
    API_BEGIN(BITMAPS);                                                         // Begin bitmaps                                      		

    API_COLOR_RGB(255, 0, 0);                                                   // Set color to red
    API_VERTEX2II(100,100,30,0x41);                                             // Place bitmap cell (letter A) at (100,100) 
    
    API_COLOR_RGB(0, 255, 0);                                                   // Set color to green
    API_VERTEX2II(500,100,30,0x42);                                             // Place bitmap cell (letter B) at (500,100) 
    
    API_COLOR_RGB(0, 0, 255);                                                   // Set color to blue
    API_VERTEX_TRANSLATE_X(250*16);                                             // Add an offset of 250 to X direction of subsequent Vertex commands
    API_VERTEX2II(500,100,30,0x43);                                             // Place bitmap cell (letter C) at ((500+250),100) == (750,100))
  
    API_COLOR_RGB(255, 0, 255);                                                 // Set color to magenta
    API_VERTEX2II(500,200,30,0x44);                                             // Place bitmap cell (letter D) at ((500+250),200) == (750,200))                   

    API_COLOR_RGB(255, 255, 255);                                               // Set color to white
    API_VERTEX_TRANSLATE_X(0*16);                                               // Return offset to 0 for subsequent Vertex commands
    API_VERTEX2II(500,200,30,0x45);                                             // Place bitmap cell (letter E) at (500,200)
    
    API_DISPLAY();                                                              // Tell EVE that this is end of list
    API_CMD_SWAP();                                                             // Swap buffers in EVE to make this list active

    API_LIB_EndCoProList();                                                     // Finish the co-processor list burst write
    API_LIB_AwaitCoProEmpty();                                                  // Wait until co-processor has consumed all commands 
        
    //APP_SnapShot2PPM();                                                       // Un-comment to take snapshot (see BRT_AN_014)
    
    while(1)
    {
    }
}




void APP_LineStrip(void)
{
    uint16_t  ChartCounter = 0;
    static uint8_t ChartData[350] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,59,58,57,56,55,54,53,52,51,50,49,48,47,46,45,44,43,42,41,40,39,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,84,83,82,81,80,79,78,77,76,75,74,73,72,71,70,69,68,67,66,65,64,63,62,61,60,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,122,122,122,122,121,120,119,118,117,116,115,114,113,112,111,110,109,108,107,106,105,104,103,102,101,100,99,98,97,96,95,94,93,92,91,90,89,88,87,86,85,84,83,82,81,80,79,78,77,76,75,74,73,72,71,70,69,68,67,66,65,64,63,62,61,60,59,58,57,56,55,54,53,52,51,50,49,48,47,46,45,44,43,42,41,40,39,38,37,36,35,34,33,32,31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,5,6,7,8,7,6,5,4,3};
    uint16_t Chart_SizeX = 350;
    uint16_t Chart_SizeY = 250;
    uint16_t Chart_TopLeftX = 50;
    uint16_t Chart_TopLeftY = 50;    
    uint16_t Chart_BottomRightX = 400;
    uint16_t Chart_BottomRightY = 300;
    
    // ###### Create first part of the display list (clearing screen and chart axes) ######
    API_LIB_BeginCoProList();                                                   // Begin new screen
    API_CMD_DLSTART();                                                          // Tell co-processor to create new Display List
    API_CLEAR_COLOR_RGB(0, 0, 0);                                               // Set colour for clearing screen
    API_CLEAR(1,1,1);                                                           // Clear screen
    API_COLOR_RGB(128, 128, 128);                                               // Set grey colour
    API_BEGIN(LINES);                                                           // Begin drawing lines
    API_LINE_WIDTH(16);                                                         // Set line width
    API_VERTEX2F(Chart_TopLeftX*16, Chart_TopLeftY*16);                         // Draw Y axis of chart as a line from this coordinate ...
    API_VERTEX2F(Chart_TopLeftX*16, Chart_BottomRightY*16);                     // ... to this coordinate
    API_VERTEX2F(Chart_TopLeftX*16, Chart_BottomRightY*16);                     // Draw X axis of chart as a line from this coordinate
    API_VERTEX2F(Chart_BottomRightX*16, Chart_BottomRightY*16);                 // .. to this coordinate
    API_END(); 
    API_LIB_EndCoProList();                                                     // Finish the co-processor list burst write
    API_LIB_AwaitCoProEmpty();                                                  // Wait until co-processor has consumed all commands

    // ###### Create second part of the display list (drawing chart line) ######   
    API_LIB_BeginCoProList();                                                   // Begin new screen
    API_COLOR_RGB(255,0,0);                                                     // Set colour to red for subsequent items     
    API_BEGIN(LINE_STRIP);                                                      // Begin a line strip
    API_LINE_WIDTH(16);                                                         // Set line width
    for (ChartCounter = 0; ChartCounter < 350; ChartCounter++)                  // Draw a line strip with the chart points
    {
        // Each point on chart has X coord defined by the incrementing counter and offset by the X offset of the chart itself (50 here)
        // For each Y point, EVE does it's coords from top-left and so assuming the input data is relative to a zero line, we offset
        // the coord to the bottom of the chart (chart Y offset plus chart Y size) and then subtract the value to be displayed)
        API_VERTEX2F(   ((ChartCounter + Chart_TopLeftX)*16), ((Chart_TopLeftY + Chart_SizeY - ChartData[ChartCounter])*16 )   );
    }
    API_END();
    API_LIB_EndCoProList();                                                     // Finish the co-processor list burst write
    API_LIB_AwaitCoProEmpty();                                                  // Wait until co-processor has consumed all commands
    
    // ###### Create third part of the display list (display and swap commands) ######   
    API_LIB_BeginCoProList();                                                   // Begin new screen
    API_DISPLAY();                                                              // Tell EVE that this is end of list
    API_CMD_SWAP();                                                             // Swap buffers in EVE to make this list active
    API_LIB_EndCoProList();                                                     // Finish the co-processor list burst write
    API_LIB_AwaitCoProEmpty();                                                  // Wait until co-processor has consumed all commands
    
    // APP_SnapShot2PPM();
    
    while(1)
    {
    }
       
}


//############################################################################## 
//##############################################################################

void APP_Text(void)                                                          
{
    API_LIB_BeginCoProList();                                                   // Begin new screen
    API_CMD_DLSTART();                                                          // Tell co-processor to create new Display List
        
    API_CLEAR_COLOR_RGB(0, 0, 0);                                               // Specify color to clear screen to
    API_CLEAR(1,1,1);                                                           // Clear color, stencil, and tag buffer
    
    API_COLOR_RGB(255, 255, 255);                                               // Set color to white
    API_CMD_TEXT(196, 33, 30, 0, "Text!");                                      // Draw the text string
  
    API_DISPLAY();                                                              // Tell EVE that this is end of list
    API_CMD_SWAP();                                                             // Swap buffers in EVE to make this list active

    API_LIB_EndCoProList();                                                     // Finish the co-processor list burst write
    API_LIB_AwaitCoProEmpty();                                                  // Wait until co-processor has consumed all commands 

    //APP_SnapShot2PPM();                                                       // Un-comment to take snapshot (see BRT_AN_014)
    
    while(1)
    {
    }
}

//############################################################################## 
//##############################################################################

void APP_DigitsFont(void)
{
    uint16_t DataOffset = 1000;
    uint16_t DataPointer = 0;   
    uint16_t DataSize = 7273; //(148+7125))
    uint16_t BitmapDataSize = 0;

    // ------------------------- Load image data -------------------------------
    
    API_LIB_WriteDataRAMG(DigitsFont, sizeof(DigitsFont), 1000);                // Load the font data from header file into RAM_G                   
   
    // ---------- Now create a screen with text written in this font -----------
       
    API_LIB_BeginCoProList();                                                   // Begin new screen 
    API_CMD_DLSTART();                                                          // Tell co-processor to create new Display List
    
    API_CLEAR_COLOR_RGB(0, 0, 0);                                               // Specify color to clear screen to
    API_CLEAR(1,1,1);                                                           // Clear color, stencil, and tag buffer
        
    API_BITMAP_HANDLE(14);                                                      // Set the bitmap properties for handle 14
    API_BITMAP_SOURCE(-1252);                                                   // This value can be found in font converter output data
    API_BITMAP_LAYOUT(L1,3,25);                                                 // Specify the format, linestride, height 
    API_BITMAP_SIZE(NEAREST, BORDER, BORDER, 18,25);                            // Specify bitmap parameters

    API_CMD_SETFONT(14, 1000);                                                  // Set the font to handle 14
    
    API_COLOR_RGB(255,255,255);                                                 // Text will be drawn white
    API_CMD_TEXT(100,100,14,0,"HELLO");                                         // Place the text
    API_CMD_NUMBER(100, 300, 14, 0, 12345);                                     // Also place a number in font 14
    
    API_DISPLAY();                                                              // Tell EVE that this is end of list
    API_CMD_SWAP();                                                             // Swap buffers in EVE to make this list active

    API_LIB_EndCoProList();                                                     // Finish the co-processor list burst write
    API_LIB_AwaitCoProEmpty();                                                  // Wait until co-processor has consumed all commands 

    //APP_SnapShot2PPM();                                                       // Un-comment to take snapshot (see BRT_AN_014)
    
    while(1)
    {
    }
}

//############################################################################## 
//##############################################################################

void APP_ConvertedBitmap(void)                                                          
{
    // -----------------  Load image data  -------------------------------------
    
    API_LIB_WriteDataRAMG(rawData, sizeof(rawData), 0);                         // Load the image of EVE from header file into RAM_G

    // -------------------  Create screen  -------------------------------------
    
    API_LIB_BeginCoProList();                                                   // Begin new screen
    API_CMD_DLSTART();                                                          // Tell co-processor to create new Display List
        
    API_CLEAR_COLOR_RGB(255, 255, 255);                                         // Specify color to clear screen to
    API_CLEAR(1,1,1);                                                           // Clear color, stencil, and tag buffer
    
    API_BITMAP_HANDLE(0);                                                       // Bitmap handle 0

    //API_BITMAP_HANDLE(0);                                                     // Tell FT81x the properties of the bitmap we will display later
    //API_BITMAP_SOURCE(0);            
    //API_BITMAP_LAYOUT(RGB565, 116, 75);
    //API_BITMAP_SIZE(NEAREST, BORDER, BORDER, 58, 75);
    API_CMD_SETBITMAP(0,RGB565,58,75);                                          // Equivalent to the four lines above
    
    API_COLOR_RGB(255, 255, 255);                                               // Set color to white so that bitmap is drawn in original color
    API_BEGIN(BITMAPS);                                                         // Begin drawing bitmaps
    API_VERTEX2F(0,0);                                                          // Place bitmap
    API_END();                                                                  // Finish drawing bitmaps
    
    API_DISPLAY();                                                              // Tell EVE that this is end of list
    API_CMD_SWAP();                                                             // Swap buffers in EVE to make this list active

    API_LIB_EndCoProList();                                                     // Finish the co-processor list burst write
    API_LIB_AwaitCoProEmpty();                                                  // Wait until co-processor has consumed all commands 

    //APP_SnapShot2PPM();                                                       // Un-comment to take snapshot (see BRT_AN_014)
    
    while(1)
    {
    }
}

//############################################################################## 
//##############################################################################

void APP_InflateImage(void)
{
    uint16_t Reg_Cmd_Write_Offset = 0;
    uint32_t End_Address = 0;
    
    // ###### Send INFLATE command followed by image data ######
    API_LIB_BeginCoProList();                                                   // Begin new co-processor list
    API_CMD_INFLATE(0);                                                         // Send the inflate command with destination parameter set to 0
    API_LIB_EndCoProList();                                                     // Finish the burst write
    API_LIB_WriteDataToCMD(LeaveItToEVE, sizeof(LeaveItToEVE));                 // Now send the data to the co-processor FIFO immediately after the command
    API_LIB_AwaitCoProEmpty();                                                  // Ensure that all data was consumed correctly
        
    // ###### Optionally check where the end of the data is ######
    API_LIB_BeginCoProList();                                                   // New co-processor list
    API_CMD_GETPTR(0);                                                          // Command 'Get Pointer' with dummy 0x00000000 parameter
    API_LIB_EndCoProList();                                                     // Execute the command
    API_LIB_AwaitCoProEmpty();                                                  // Ensure that all data was consumed correctly
          
    Reg_Cmd_Write_Offset = EVE_MemRead16(REG_CMD_WRITE);                        // Check the current write pointer value
    Reg_Cmd_Write_Offset = ((Reg_Cmd_Write_Offset - 4) & 4095);                 // Go back by 4 bytes to where the dummy values was placed, allowing for the possibility of the rollover
    End_Address = EVE_MemRead32((RAM_CMD+Reg_Cmd_Write_Offset));                // Read this value. The co-processor will have replaced it with the end address
        
    // ###### Now display the image ######
    API_LIB_BeginCoProList();                                                   // Begin new screen 
    API_CMD_DLSTART();                                                          // Tell co-processor to create new Display List
    API_CLEAR_COLOR_RGB(0, 0, 0);                                               // Specify color to clear screen to
    API_CLEAR(1,1,1);                                                           // Clear color, stencil, and tag buffer
    API_COLOR_RGB(255,255,255);                                                 // Specify colour of text
    API_BITMAP_HANDLE(5);                                                       // Tell FT81x the properties of the bitmap we will display. Handle set to 5
    API_BITMAP_SOURCE(0);                                              
    API_BITMAP_LAYOUT(RGB332, 200, 141);                                        // FMT, STR, H
    API_BITMAP_SIZE(BILINEAR, BORDER, BORDER, 200, 141);                        // W, H
    API_BEGIN(BITMAPS);                                                         // Place the bitmap (handle 5) at (100,100)
    API_VERTEX2II(100,100,5,0);   
    API_END(); 
    
    // ###### Just for the demo, we print the ending address in dec and hex ######
    API_COLOR_RGB(255,255,255);                                                 // Use the Number command to print the end address
    API_CMD_NUMBER(300, 260, 30, 0, End_Address);
    API_CMD_SETBASE(16);                                                        // Set hex base and re-print the hex equivalent
    API_CMD_NUMBER(300, 300, 30, 0, End_Address);
    
    // ###### Now display the screen created above ######
    API_DISPLAY();                                                              // Tell EVE that this is end of list
    API_CMD_SWAP();                                                             // Swap buffers in EVE to make this list active
    API_LIB_EndCoProList();                                                     // Finish the co-processor list burst write
    API_LIB_AwaitCoProEmpty();                                                  // Wait until co-processor has consumed all commands
    
    //APP_SnapShot2PPM();                                                       // Un-comment to take snapshot (see BRT_AN_014)
    
    while(1)
    {
    }
}

//############################################################################## 
//##############################################################################

void APP_LoadImagePNG(void)
{
    uint16_t Reg_Cmd_Write_Offset = 0;
    uint16_t ParameterAddr = 0;
    uint32_t End_Address = 0;
    uint32_t Width = 0;
    uint32_t Height = 0;
    uint32_t StartAddress = 0;
    
    
    API_LIB_BeginCoProList();                                                   // Begin new co-processor list
    API_CMD_LOADIMAGE(StartAddress,0);                                          // Load image command. Extract data to RAM_G + 0, options = 0
    API_LIB_EndCoProList();                                                     // Finish the co-processor list
    API_LIB_WriteDataToCMD(EVE_PNG, sizeof(EVE_PNG));                           // Send data immediately after the command (since we don't select MEDIAFIFO as source in Options))
    API_LIB_AwaitCoProEmpty();                                                  // Await completion of the Load Image. Image will now be in RAM_G
        
    // ###### Check parameters of decompressed image ########
    API_LIB_BeginCoProList();                                                   // Begin co-pro list
    API_CMD_GETPROPS(0, 0, 0);                                                  // GetProps command with three dummy 32-bit values
    API_LIB_EndCoProList();                                                     // Finish the co-processor list
    API_LIB_AwaitCoProEmpty();                                                  // Await the command completion

    Reg_Cmd_Write_Offset = EVE_MemRead16(REG_CMD_WRITE);                        // Check current pointer value

    ParameterAddr = ((Reg_Cmd_Write_Offset - 12) & 4095);                       // Go back by 12 bytes to get end address parameter
    End_Address = EVE_MemRead32((RAM_CMD+ParameterAddr));

    ParameterAddr = ((Reg_Cmd_Write_Offset - 8) & 4095);                        // Go back by 8 bytes to get width parameter
    Width = EVE_MemRead32((RAM_CMD+ParameterAddr));    

    ParameterAddr = ((Reg_Cmd_Write_Offset - 4) & 4095);                        // Go back by 4 bytes to get height parameter
    Height = EVE_MemRead32((RAM_CMD+ParameterAddr));    
    
    // ######################################################      

    API_LIB_BeginCoProList();                                                   // Begin new screen 
    API_CMD_DLSTART();                                                          // Tell co-processor to create new Display List
    API_CLEAR_COLOR_RGB(0, 0, 0);                                               // Specify color to clear screen to
    API_CLEAR(1,1,1);                                                           // Clear color, stencil, and tag buffer
    API_COLOR_RGB(255,255,255);                                                 // White colour will display image with original colours
    
    API_BITMAP_HANDLE(0);                                                       // Tell FT81x the properties of the bitmap we will display. 
    API_BITMAP_SOURCE(StartAddress);                                              
    API_BITMAP_LAYOUT(RGB565, Width*2, Height);                                 // FMT, STR, H
    API_BITMAP_SIZE(BILINEAR, BORDER, BORDER, Width, Height);                   // W, H
	API_BITMAP_LAYOUT_H((Width * 2) >> 10, Height >> 9);
	API_BITMAP_SIZE_H(Width >> 9, Width >> 9);
       
    API_BEGIN(BITMAPS);      
    API_VERTEX2II(200,200,0,0);                                                 // Display image at (200,200)
    API_END(); 
   
    // ###### OPTIONAL SECTION - print parameters of decompressed image ########
    API_COLOR_RGB(255,255,255);                                                 // Print labels
    API_CMD_TEXT(300, 200, 28, 0, "End Addr");
    API_CMD_TEXT(300, 240, 28, 0, "Width");    
    API_CMD_TEXT(300, 280, 28, 0, "Height");    
    
    API_CMD_NUMBER(400, 200, 28, 0, End_Address);                               // Print associated values
    API_CMD_NUMBER(400, 240, 28, 0, Width);
    API_CMD_NUMBER(400, 280, 28, 0, Height);
    API_CMD_SETBASE(16);
    API_CMD_NUMBER(500, 200, 28, 0, End_Address);
    // ######  END OF OPTIONAL SECTION - print parameters of decompressed image ########

    API_DISPLAY();                                                              // Tell EVE that this is end of list
    API_CMD_SWAP();                                                             // Swap buffers in EVE to make this list active
    API_LIB_EndCoProList();                                                     // Finish the co-processor list burst write
    API_LIB_AwaitCoProEmpty();                                                  // Wait until co-processor has consumed all commands
    
   //APP_SnapShot2PPM();                                                        // Un-comment to take snapshot (see BRT_AN_014)
    
    while(1)
    {
    }
}


//############################################################################## 
//##############################################################################

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

void APP_ScreenRotate(void)
{
    uint32_t TrackerVal = 0;
    uint8_t TagVal = 0;
    uint16_t SlideVal = 0;
    uint16_t Button3D = 0;
    uint8_t color = 0;
   
    uint32_t TrackerVal = 0;
    uint8_t TagVal = 0;
    uint16_t SlideVal = 0;
    uint16_t Button3D = 0;
    uint8_t color = 0;
      
    // The screen calibration should have been completed before this point
    
    // First, run the SetRotate command which will set the display and touch rotation
    
    API_LIB_BeginCoProList();                                                   // New co-processor list
    API_CMD_SETROTATE(2);                                                       // Send the command to the FIFO
    API_LIB_EndCoProList();                                                     // End the co-processor list
    API_LIB_AwaitCoProEmpty();                                                  // Await for the co-processor to complete the command
        
    // Then run the same code as the ButtonAndSlider demo
   
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
        API_COLOR_RGB(color, 0, 0);                                              // Set colour to blue and write some text
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



//############################################################################## 
//##############################################################################

void APP_Append(void)
{       
    uint32_t dlOffset = 0;
    uint8_t GaugeVal = 0;
    uint8_t GaugeDir = 0;
    uint16_t Toggle = 0;
    
    // *******************  Create the static screen content *******************
        
    API_LIB_BeginCoProList();                                                   // Begin new screen
    API_CMD_DLSTART();                                                          // Tell co-processor to create new Display List
    // API_CLEAR_COLOR_RGB(255, 255, 255);                                      // These should be commented out. They will be sent as 
    // API_CLEAR(1,1,1);                                                        // part of the final screen
    
    API_CMD_GRADIENT(300, 0, 0x0000FF, 300, 480, 0xFF0000);                     // Gradient background
    API_COLOR_RGB(255, 255, 255);                                              
    API_CMD_TEXT(200, 50, 25, 0, "Optimising Screen Updates!");                 // Text in white color
    API_COLOR_RGB(200, 200, 200);        
    API_BEGIN(LINE_STRIP);                                                      // Draw line strip in grey color to make a border around the screen
    API_VERTEX2F(20*16, 20*16);                                                 // Top-left coordinate
    API_VERTEX2F(780*16, 20*16);                                                // Top-Right corner
    API_VERTEX2F(780*16, 460*16);                                               // Bottom-Right corner
    API_VERTEX2F(20*16, 460*16);                                                // Bottom-left corner 
    API_VERTEX2F(20*16, 20*16);                                                 // Back up to the top-left corner to complete the border
    API_END();                                                                  // Finish drawing line strip
    
    // API_DISPLAY();                                                           // These should be commented out. They will be sent as  
    // API_CMD_SWAP();                                                          // part of the final screen
    API_LIB_EndCoProList();                                                     // Finish the co-processor list burst write
    API_LIB_AwaitCoProEmpty();                                                  // Wait until co-processor has consumed all commands and generated DL
    
    // ******************  Store the static screen content *********************
    // Determine length to be copied and then copy the generated DL to RAM_G 
    // by running a MEMCPY command
    
    dlOffset = EVE_MemRead32(REG_CMD_DL);                                       // Check where the end of the new DL is in RAM_DL (i.e. the length))
    
    API_LIB_BeginCoProList();                                                   // Begin new co-processor command list
    API_CMD_MEMCPY(1000, RAM_DL, dlOffset);                                     // Copy [dlOffset] bytes beginning from RAM_DL, to RAM_G location 1000 onwards  
    API_LIB_EndCoProList();                                                     // Finish the co-processor list burst write
    API_LIB_AwaitCoProEmpty();                                                  // Wait until co-processor has consumed all commands
        
    // *********  Create the final screen adding the dynamic parts *************
           
     while(1)
    {
        if (GaugeVal == 100)                                                    // Sweep gauge needle from 0 to 100
        {
            GaugeDir = 0;
            Toggle = 0;
        }
        else if (GaugeVal == 0)
        {
            GaugeDir = 0xFF;
            Toggle = 65535;        
        }  
               
        
        if(GaugeDir == 0)
            GaugeVal --;
        else
            GaugeVal ++;
        
        
        MCU_Delay_20ms();                                                       // Delay stops needle moving too fast for viewer to see
        MCU_Delay_20ms();                                                       // Delay stops needle moving too fast for viewer to see
    
    
        API_LIB_BeginCoProList();                                               // Begin new screen
        API_CMD_DLSTART();                                                      // Tell co-processor to create new Display List
        API_CLEAR_COLOR_RGB(255, 255, 255);                                     // Specify color to clear screen to
        API_CLEAR(1,1,1);                                                       // Clear color, stencil, and tag buffer
        API_CMD_APPEND(1000, dlOffset);
        API_COLOR_RGB(255, 255, 255);                                           // Set colour to blue and write some text
        API_CMD_GAUGE(400, 200, 60, 0, 4, 8, GaugeVal, 100);                    // Draw gauge with pointer defined by variable at top of this function 
        API_CMD_FGCOLOR(0xFF0000);   
        API_CMD_TOGGLE(350, 400, 100, 23, 0, Toggle, "Down" "\xff" "Up");       // Draw a toggle switch
        API_CMD_NUMBER(400, 300, 25, OPT_CENTER, GaugeVal);                     // Print the numerical value of the variable GaugeVal
        
        API_DISPLAY();                                                          // Tell EVE that this is end of list
        API_CMD_SWAP();                                                         // Swap buffers in EVE to make this list active
        API_LIB_EndCoProList();                                                 // Finish the co-processor list burst write
        API_LIB_AwaitCoProEmpty();                                              // Wait until co-processor has consumed all commands

        //APP_SnapShot2PPM();                                                   // Un-comment to take snapshot (see BRT_AN_014)
    }
}

//############################################################################## 
//##############################################################################

void APP_SnapShot2PPM(void)
{
    uint32_t Pointer = 0;                                                       // Where to start image in RAM_G
    uint32_t SerialCounter = 0;
    uint8_t SerByteA = 0;
    uint8_t SerByteR = 0;
    uint8_t SerByteG = 0;
    uint8_t SerByteB = 0;
    uint8_t StartCode = 0;
    uint32_t ColorData = 0;
    uint16_t ScreenWidth = 800;
    uint16_t ScreenHeight = 480;
    uint32_t RowNum = 0;
       
       
    //Wait here until we receive starting code 0x53 over UART
    StartCode = 0x00;
    while(StartCode != 0x53)
    {
        StartCode = MCU_UART_Rx();
    }
            
    // Send PPM header
    MCU_UART_Tx(0x50); // P
    MCU_UART_Tx(0x36); // 6 
    MCU_UART_Tx(0x0A); // LineFeed
    MCU_UART_Tx(0x38); // 8
    MCU_UART_Tx(0x30); // 0
    MCU_UART_Tx(0x30); // 0
    MCU_UART_Tx(0x0A); // LineFeed 
    MCU_UART_Tx(0x34); // 4
    MCU_UART_Tx(0x38); // 8
    MCU_UART_Tx(0x30); // 0
    MCU_UART_Tx(0x0A); // LineFeed 
    MCU_UART_Tx(0x32); // 2
    MCU_UART_Tx(0x35); // 5   
    MCU_UART_Tx(0x35); // 5
    MCU_UART_Tx(0x0A); // LineFeed 
            
    Pointer =  1040000;                                                         // Store snapshot data near end of RAM_G
    RowNum = 0;
    while(RowNum < ScreenHeight)                                                // For each row in turn
    {
        API_LIB_BeginCoProList();                                               // Begin co-processor command
        API_CMD_SNAPSHOT2(0x20, Pointer, 0, RowNum, (ScreenWidth*2), 1);        // Take a snapshot in ARGB8 format (see FT81x Programmers Guide))
        API_LIB_EndCoProList();                                                 // 
        API_LIB_AwaitCoProEmpty();                                              // 
                
        // Notes on SnapShot2 (see FT81x programmers Guide)
        //   0x20 means ARGB8 format
        //   Pointer specifies destination of snapshot data in RAM_G
        //   X value: 0 means the snapshot begins at X = 0 (start of row)
        //   Y Value: RowNum specifies Y as current row number
        //   Width: Width of Snapshot is 2*ScreenWidth (the 2* is required if ARGB4)
        //   Height: Height is always 1 row as we are taking the snapshot line-by-line)
        
        MCU_Delay_20ms();                                                       // ensure co-pro has finished taking snapshot
        
        SerialCounter = 0;
        while(SerialCounter < (ScreenWidth*4))                                  // Read the data (4 bytes per pixel for ARGB) for each pixel)
        {
            ColorData = EVE_MemRead32(Pointer + SerialCounter);                 // Get the 32-bit ARGB value

            SerByteR = (uint8_t) ((ColorData >> 16));                           // Send the R, G and B bytes only
            SerByteG = (uint8_t) (ColorData >>8);
            SerByteB = (uint8_t) (ColorData);                    
                    
            MCU_UART_Tx(SerByteR);  
            MCU_UART_Tx(SerByteG);
            MCU_UART_Tx(SerByteB);  
            
        SerialCounter = SerialCounter + 4;                                      // Move on to next pixel data         
        }
        
        RowNum ++;                                                              // Once this row has been done, repeat for next row
        
    }
                   
    while(1)
    {
        Nop();
    }
}






 

















