/*******************************************************************************

Copyright (c) Future Technology Devices International

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

This code is provided as an example only and is not guaranteed by FTDI/BridgeTek.
FTDI/BridgeTek accept no responsibility for any issues resulting from its use.
By using this code, the developer of the final application incorporating any 
parts of this sample project agrees to take full responsible for ensuring its 
safe and correct operation and for any consequences resulting from its use.

Revision History: 
 
Version Author              Date        Description
******* ******************* *********** ****************************************
1.0     G Brown             Feb 2017    Initial version
 
*/

#include <stdio.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "FT8xx.h"

#ifndef XC_H
#define	XC_H

// MCU Layer
void MCU_Init(void);                                                                 
void MCU_CSlow(void);
void MCU_CShigh(void);
void MCU_PDlow(void);
void MCU_PDhigh(void);
unsigned char MCU_SPIReadWrite(unsigned char DataToWrite);
void MCU_UART_Init(void);
void MCU_UART_Tx(unsigned char SerialTxByte);
unsigned char MCU_UART_Rx(void);
void MCU_Delay_1ms(void);
void MCU_Delay_ms(unsigned int);
void MCU_Delay_1us(void);
void MCU_Delay_us(unsigned int);


void MCU_SetFreq10();
void MCU_SetFreq20();


// EVE Layer
void EVE_AddrForWr(uint32_t ftAddress);
void EVE_AddrForRd(uint32_t ftAddress);
void EVE_Write32(uint32_t ftData32);
void EVE_Write16(uint16_t ftData16);
void EVE_Write8(uint8_t ftData8);
uint32_t EVE_Read32(void);
uint16_t EVE_Read16(void);
uint8_t EVE_Read8(void);
void EVE_MemWrite32(uint32_t ftAddress, uint32_t ftData32);
void EVE_MemWrite16(uint32_t ftAddress, uint16_t ftData16);
void EVE_MemWrite8(uint32_t ftAddress, uint8_t ftData8);
uint32_t EVE_MemRead32(uint32_t ftAddress);
uint16_t EVE_MemRead16(uint32_t ftAddress);
uint8_t EVE_MemRead8(uint32_t ftAddress);
void EVE_CmdWrite(uint8_t EVECmd, uint8_t Param);
uint16_t EVE_IncCMDOffset(uint16_t currentOffset, uint16_t commandSize);
uint8_t EVE_WaitCmdFifoEmptyOLD(void);

uint16_t EVE_WaitCmdFifoEmpty(void);

uint32_t EVE_GetCurrentWritePointer(void);
uint16_t EVE_CheckFreeSpace(uint16_t CmdOffset);

// ######################### API Layer #########################################

// API Functions
void API_LIB_BeginCoProList(void);
void API_LIB_EndCoProList(void);
void API_LIB_AwaitCoProEmpty(void);
void API_LIB_WriteDataRAMG(const uint8_t *ImgData, uint32_t DataSize, uint32_t DestAddress);
uint8_t API_SendString(const char* string);
void API_LIB_WriteDataToCMD(const uint8_t *ImgData, uint32_t TotalDataSize);

// Graphics instructions
void API_CLEAR_COLOR_RGB(uint8_t R, uint8_t G, uint8_t B);
void API_CLEAR(uint8_t C, uint8_t S, uint8_t T);
void API_COLOR_RGB(uint8_t R, uint8_t G, uint8_t B);
void API_VERTEX2F(int16_t x, int16_t y);
void API_VERTEX2II(uint16_t x, uint16_t y, uint8_t handle,uint8_t cell);
void API_BITMAP_HANDLE(uint8_t handle);
void API_BITMAP_SOURCE(uint32_t addr);
void API_BITMAP_LAYOUT(uint8_t format, uint16_t linestride, uint16_t height);   
void API_BITMAP_SIZE(uint8_t filter, uint8_t wrapx, uint8_t wrapy, uint16_t width, uint16_t height);   
void API_CELL(uint8_t cell);   
void API_TAG(uint8_t s);
void API_ALPHA_FUNC(uint8_t func, uint8_t ref);   
void API_STENCIL_FUNC(uint8_t func, uint8_t ref, uint8_t mask);   
void API_BLEND_FUNC(uint8_t src, uint8_t dst);   
void API_STENCIL_OP(uint8_t sfail, uint8_t spass);   
void API_POINT_SIZE(uint16_t size);   
void API_LINE_WIDTH(uint16_t width);   
void API_CLEAR_COLOR_A(uint8_t alpha);   
void API_COLOR_A(uint8_t alpha);   
void API_CLEAR_STENCIL(uint8_t s);   
void API_CLEAR_TAG(uint8_t s);   
void API_STENCIL_MASK(uint8_t mask);   
void API_TAG_MASK(uint8_t mask);   
void API_SCISSOR_XY(uint16_t x, uint16_t y);  
void API_SCISSOR_SIZE(uint16_t width, uint16_t height);   
void API_CALL(uint16_t dest);   
void API_JUMP(uint16_t dest);   
void API_BEGIN(uint8_t prim);   
void API_COLOR_MASK(uint8_t r, uint8_t g, uint8_t b, uint8_t a); 
void API_END(void);   
void API_SAVE_CONTEXT(void);   
void API_RESTORE_CONTEXT(void);   
void API_RETURN(void);   
void API_MACRO(uint8_t m);   
void API_DISPLAY(void);   

// Co-Processor Widgets
void API_CMD_TEXT(int16_t x, int16_t y, int16_t font, uint16_t options, const char* string);
void API_CMD_BUTTON(int16_t x, int16_t y, int16_t w, int16_t h, int16_t font, uint16_t options, const char* string);
void API_CMD_KEYS(int16_t x, int16_t y, int16_t w, int16_t h, int16_t font, uint16_t options, const char* string);
void API_CMD_NUMBER(int16_t x, int16_t y, int16_t font, uint16_t options, int32_t n);
void API_CMD_LOADIDENTITY(void);
void API_CMD_TOGGLE(int16_t x, int16_t y, int16_t w, int16_t font, uint16_t options, uint16_t state, const char* string);
void API_CMD_GAUGE(int16_t x, int16_t y, int16_t r, uint16_t options, uint16_t major, uint16_t minor, uint16_t val, uint16_t range);
void API_CMD_REGREAD(uint32_t ptr, uint32_t result);
void API_CMD_GETPROPS(uint32_t ptr, uint32_t w, uint32_t h);
void API_CMD_MEMCPY(uint32_t dest, uint32_t src, uint32_t num);
void API_CMD_SPINNER(int16_t x, int16_t y, uint16_t style, uint16_t scale);
void API_CMD_BGCOLOR(uint32_t c);
void API_CMD_SWAP(void);
void API_CMD_INFLATE(uint32_t ptr);
void API_CMD_TRANSLATE(int32_t tx, int32_t ty);
void API_CMD_STOP(void);
void API_CMD_SLIDER(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t options, uint16_t val, uint16_t range);
void API_BITMAP_TRANSFORM_A(long a);                                               
void API_BITMAP_TRANSFORM_B(long b);      
void API_BITMAP_TRANSFORM_C(long c);      
void API_BITMAP_TRANSFORM_D(long d);     
void API_BITMAP_TRANSFORM_E(long e);      
void API_BITMAP_TRANSFORM_F(long f);      
void API_CMD_INTERRUPT(uint32_t ms);
void API_CMD_FGCOLOR(uint32_t c);
void API_CMD_ROTATE(int32_t a);
void API_CMD_MEMWRITE(uint32_t ptr, uint32_t num);
void API_CMD_SCROLLBAR(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t options, uint16_t val, uint16_t size, uint16_t range);
void API_CMD_GETMATRIX(int32_t a, int32_t b, int32_t c, int32_t d, int32_t e, int32_t f);
void API_CMD_SKETCH(int16_t x, int16_t y, uint16_t w, uint16_t h, uint32_t ptr, uint16_t format);
void API_CMD_MEMSET(uint32_t ptr, uint32_t value, uint32_t num);
void API_CMD_GRADCOLOR(uint32_t c);
void API_CMD_BITMAP_TRANSFORM(int32_t x0, int32_t y0, int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t tx0, int32_t ty0, int32_t tx1, int32_t ty1, int32_t tx2, int32_t ty2, uint16_t result);
void API_CMD_CALIBRATE(uint32_t result);
void API_CMD_SETFONT(uint32_t font, uint32_t ptr);
void API_CMD_LOGO(void);
void API_CMD_APPEND(uint32_t ptr, uint32_t num);
void API_CMD_MEMZERO(uint32_t ptr, uint32_t num);
void API_CMD_SCALE(int32_t sx, int32_t sy);
void API_CMD_CLOCK(int16_t x, int16_t y, int16_t r, uint16_t options, uint16_t h, uint16_t m, uint16_t s, uint16_t ms);
void API_CMD_GRADIENT(int16_t x0, int16_t y0, uint32_t rgb0, int16_t x1, int16_t y1, uint32_t rgb1);
void API_CMD_SETMATRIX(void);
void API_CMD_TRACK(int16_t x, int16_t y, int16_t w, int16_t h, int16_t tag);
void API_CMD_GETPTR(uint32_t result);
void API_CMD_PROGRESS(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t options, uint16_t val, uint16_t range);
void API_CMD_COLDSTART(void);
void API_CMD_DIAL(int16_t x, int16_t y, int16_t r, uint16_t options, uint16_t val);
void API_CMD_LOADIMAGE(uint32_t ptr, uint32_t options);
void API_CMD_DLSTART(void);
void API_CMD_SNAPSHOT(uint32_t ptr);
void API_CMD_SCREENSAVER(void);
void API_CMD_MEMCRC(uint32_t ptr, uint32_t num, uint32_t result);


#ifdef FT_81X_ENABLE
//GPU
void API_VERTEX_FORMAT(uint8_t frac);   
void API_BITMAP_LAYOUT_H(uint8_t linestride, uint8_t height);   
void API_BITMAP_SIZE_H(uint8_t width, uint8_t height);   
void API_PALETTE_SOURCE(uint32_t addr);   
void API_VERTEX_TRANSLATE_X(uint32_t x);   
void API_VERTEX_TRANSLATE_Y(uint32_t y);   
void API_NOP(void);  
//CO-PRO
void API_CMD_VIDEOSTART(void);
void API_CMD_SETROTATE(uint32_t r);
void API_CMD_SETFONT2(uint32_t font, uint32_t ptr, uint32_t firstchar);
void API_CMD_MEDIAFIFO(uint32_t ptr, uint32_t size);
void API_CMD_SNAPSHOT2(uint32_t fmt, uint32_t ptr, int16_t x, int16_t y, int16_t w, int16_t h);
void API_CMD_INT_SWLOADIMAGE(uint32_t ptr, uint32_t options);
void API_CMD_CSKETCH(int16_t x, int16_t y, uint16_t w, uint16_t h, uint32_t ptr, uint16_t format,uint16_t freq);
void API_CMD_ROMFONT(uint32_t font, uint32_t romslot);
void API_CMD_PLAYVIDEO(uint32_t options);
void API_CMD_SYNC(void);
void API_CMD_VIDEOFRAME(uint32_t dst, uint32_t ptr);
void API_CMD_SETBASE(uint32_t base);
void API_CMD_SETBITMAP(uint32_t source, uint16_t fmt, uint16_t w, uint16_t h);
void API_CMD_SETSCRATCH(uint32_t handle);
#endif

// ######################### APP Layer #########################################

void APP_Init(void);
void APP_Calibrate(void);
void APP_SliderandButton(void);
void APP_FlashingDot(void);

#endif	/* XC_HEADER_TEMPLATE_H */

#ifdef	__cplusplus
}
#endif /* __cplusplus */