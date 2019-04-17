#include "FT8xx.h"
#include "DisplayLib.h"
#include <string.h>
#include <stdint.h> 

uint16_t cmdBufferRd;		// Used to navigate command ring buffer
uint16_t cmdBufferWr = 0x0000;		// Used to navigate command ring buffer
uint16_t cmdOffset = 0x0000;		// Used to navigate command rung buffer

//##############################################################################
// Library functions
//##############################################################################

// Begins co-pro list for display creation
void API_LIB_BeginCoProList(void)
{
    API_LIB_AwaitCoProEmpty();                                                  // Wait for command FIFO to be empty and record current position in FIFO
       
    MCU_CSlow();                                                                // CS low begins SPI transaction 
    EVE_AddrForWr(RAM_CMD + cmdOffset);                                         // Send address for writing as the next free location in the co-pro buffer                                      
}

// Ends co-pro list for display creation
void API_LIB_EndCoProList(void)
{
    MCU_CShigh();                                                               // Chip Select high concludes burst
    
    EVE_MemWrite32(REG_CMD_WRITE, (cmdOffset));                                 // Update the ring buffer pointer 
}

// Waits for the read and write pointers to become equal
void API_LIB_AwaitCoProEmpty(void)
{
    uint8_t success = 0;
    
    success = EVE_WaitCmdFifoEmpty();                                           // Await completion of processing 
    cmdOffset = EVE_GetCurrentWritePointer();                                   // and record starting address for next screen update
}

// Writes a block of data to the RAM_G
void API_LIB_WriteDataRAMG(const uint8_t *ImgData, uint32_t DataSize, uint32_t DestAddress)
{
    uint16_t DataPointer = 0;   
    uint16_t BitmapDataSize = 0;

    DataPointer = 0;
    
    MCU_CSlow();                                                                // CS low begins SPI transaction 
    EVE_AddrForWr(DestAddress);                                                 // Send address to which first value will be written
  
    while(DataPointer < DataSize)
    {
        EVE_Write8(ImgData[DataPointer]);                                       // Send data byte-by-byte from array
        DataPointer ++;
    }
    
    BitmapDataSize = DataSize - DataPointer;                                    // Add 3, 2 or 1 bytes padding to make it  a multiple of 4 bytes
    BitmapDataSize = BitmapDataSize & 0x03;                                     // Mask off the bottom 2 bits
    
    if (BitmapDataSize == 0x03)
    {
        EVE_Write8(0x00);
    }
    else if (BitmapDataSize == 0x02)
    {
        EVE_Write8(0x00);
        EVE_Write8(0x00);
    }
    else if (BitmapDataSize == 0x01)
    {
        EVE_Write8(0x00);
        EVE_Write8(0x00);
        EVE_Write8(0x00);
    }
              
    MCU_CShigh();                                                               // CS high after burst write of image data
}

// Writes a string over SPI
uint8_t API_SendString(const char* string)
{        
    uint32_t StringLength = 0;
    uint32_t length = strlen(string);
    uint8_t command_size = 0;

    StringLength = (length + 1);
    while(length --)                                                            // Send string data 
    {
        EVE_Write8(*string);
        string ++;
    }
    EVE_Write8(0);                                                              // Append one null as ending flag
    command_size = (command_size + StringLength);
    
    // Pad to multiple of 4
    StringLength = StringLength & 0x03;                                         // Mask off the bottom 2 bits and see if multiple of 4
    if (StringLength == 0x03)
    {
        EVE_Write8(0x00);
        command_size = (command_size + 1);
    }
    else if (StringLength == 0x02)
    {
        EVE_Write8(0x00);
        EVE_Write8(0x00);
        command_size = (command_size + 2);
    }
    else if (StringLength == 0x01)
    {
        EVE_Write8(0x00);
        EVE_Write8(0x00);
        EVE_Write8(0x00);
        command_size = (command_size + 3);
    }
    return command_size;
}


void API_LIB_WriteDataToCMD(const uint8_t *ImgData, uint32_t TotalDataSize)
{
    // This code works by sending the data in a series of one or more bursts.
    // If the data is more than 1000 bytes, it is sent as a series of one or more bursts and then the remainder.
    // It uses a target value which specifies the last index (of the source data) for each chunk
    // e.g. if sending 1500 bytes, we set the target to 999 first and send 1000 bytes (image data index 0 to 999). Then we set the 
    // target to 1499 and send the remainder of the data from image data index 1000 to 1499.
    
    uint16_t CurrentIndex = 0;
    uint16_t Target = 0;                                                        
    uint16_t MaxChunkSize = 1000;
    uint16_t CurrentChunk = 0;
    uint16_t EndIndex = 0;
    uint8_t IsLastChunk = 0;
    uint8_t PaddingCheck = 0;
    uint16_t Freespace = 0;
                                                    
    EndIndex = TotalDataSize - 1;                                               // Determine last index since array index is 0 to (TotalDataSize - 1)                                   

    while(CurrentIndex < EndIndex)                                              // While not all data is sent
    {
        if((EndIndex - CurrentIndex) > MaxChunkSize)                            // If more than ChunkSize bytes to send
        {
            Target = CurrentIndex + MaxChunkSize;                               // ... then add ChunkSize to the current target index to make new target
            IsLastChunk = 0;                                                    // ... and this is not the last chunk
        }
        else                                                                    // or if all remaining bytes can fit in one chunk 
        {
            Target = EndIndex;                                                  // ... then add the amount of data to the current target                         
            IsLastChunk = 0xFF;                                                 // .. and this is the last chunk
        }
        
        Freespace = 0;                                                          // Wait until there is space
        while(Freespace < MaxChunkSize)
        {
            Freespace = EVE_CheckFreeSpace(cmdOffset);
        }

        CurrentChunk = 0;
        MCU_CSlow();                                                            // Begin an SPI burst write                                                       
        EVE_AddrForWr(RAM_CMD + cmdOffset);                                     // to the next location in the FIFO
        
        while(CurrentIndex < Target)                                            // From current index value, keep sending and incrementing until we hit the new target
        {
            EVE_Write8(ImgData[CurrentIndex]);                               
            CurrentIndex ++;
            CurrentChunk ++;
        }
        
        if(IsLastChunk != 0)                                                    // If this is the last chunk of the data,  
        {
            EVE_Write8(ImgData[CurrentIndex]);                                  // ... send last data value ...
            CurrentIndex ++;
            CurrentChunk ++;
                                                                                // ... and then pad with 00s if necessary to make overall data size a multiple of 4 bytes
            
            PaddingCheck = (CurrentChunk) & 0x03;                               // Mask off the bottom 2 bits to see if non-zero (indicating not multiple 4))
            if (PaddingCheck == 0x03)
            {
                EVE_Write8(0x00);                                               // Send 1 dummy byte to make up to multiple of 4
                CurrentChunk ++;
            }
            else if (PaddingCheck == 0x02)
            {
                EVE_Write8(0x00);                                               // Send 2 dummy byte to make up to multiple of 4
                EVE_Write8(0x00);
                CurrentChunk = (CurrentChunk + 2);
            }
            else if (PaddingCheck == 0x01)
            {
                EVE_Write8(0x00);                                               // Send 3 dummy byte to make up to multiple of 4
                EVE_Write8(0x00);
                EVE_Write8(0x00);
                CurrentChunk = (CurrentChunk + 3);
            }
        }
                
        MCU_CShigh();                                                           // End the SPI burst
       
        cmdOffset = EVE_IncCMDOffset(cmdOffset, (CurrentChunk));                // Calculate where end of data lies
        EVE_MemWrite32(REG_CMD_WRITE, cmdOffset);                               // and move write pointer to here
    }
}
    
       
    
//##############################################################################
// Display List commands for co-processor
//##############################################################################

void API_CLEAR_COLOR_RGB(uint8_t R, uint8_t G, uint8_t B)
{
    EVE_Write32(CLEAR_COLOR_RGB(R,G,B));                                        
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 4);                                 
}

void API_CLEAR(uint8_t C, uint8_t S, uint8_t T)
{
    EVE_Write32(CLEAR((C&0x01),(S&0x01),(T&0x01)));                                    
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 4); 
}

void API_COLOR_RGB(uint8_t R, uint8_t G, uint8_t B)
{
    EVE_Write32(COLOR_RGB(R,G,B));                             
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 4); 
}

void API_VERTEX2F(int16_t x, int16_t y)
{
    EVE_Write32(VERTEX2F(x, y));                             
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 4); 
}

void API_VERTEX2II(uint16_t x, uint16_t y, uint8_t handle,uint8_t cell)
{
    EVE_Write32(VERTEX2II(x,y,handle,cell));                             
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 4); 
}

void API_BITMAP_HANDLE(uint8_t handle)   
{
    EVE_Write32(BITMAP_HANDLE(handle));                                                   
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 4); 
}

void API_BITMAP_SOURCE(uint32_t addr)
{
    EVE_Write32(BITMAP_SOURCE(addr));                             
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 4); 
}

void API_BITMAP_LAYOUT(uint8_t format, uint16_t linestride, uint16_t height )   
{
    EVE_Write32(BITMAP_LAYOUT(format,linestride,height));                       
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 4); 
}

void API_BITMAP_SIZE(uint8_t filter, uint8_t wrapx, uint8_t wrapy, uint16_t width, uint16_t height)   
{        
    EVE_Write32(BITMAP_SIZE(filter,wrapx,wrapy,width,height));                  
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 4); 
}   

void API_CELL(uint8_t cell)   
{
    EVE_Write32(CELL(cell));                                                    
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 4); 
}

void API_TAG(uint8_t s)
{
    EVE_Write32(TAG(s));                             
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 4); 
}

void API_ALPHA_FUNC(uint8_t func, uint8_t ref)   
{        
    EVE_Write32(ALPHA_FUNC(func,ref));                                          
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 4); 
}
 
void API_STENCIL_FUNC(uint8_t func, uint8_t ref, uint8_t mask)   
{
    EVE_Write32(STENCIL_FUNC(func,ref,mask));                                   
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 4); 
}
                
void API_BLEND_FUNC(uint8_t src, uint8_t dst)   
{
    EVE_Write32(BLEND_FUNC(src,dst));                                           
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 4); 
}
                   
void API_STENCIL_OP(uint8_t sfail, uint8_t spass)   
{
    EVE_Write32(STENCIL_OP(sfail,spass));                                      
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 4); 
}

void API_POINT_SIZE(uint16_t size)   
{
    EVE_Write32(POINT_SIZE(size));                                             
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 4); 
}

void API_LINE_WIDTH(uint16_t width)   
{
    EVE_Write32(LINE_WIDTH(width));            
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 4); 
}

void API_CLEAR_COLOR_A(uint8_t alpha)   
{            
    EVE_Write32(CLEAR_COLOR_A(alpha));          
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 4); 
}

void API_COLOR_A(uint8_t alpha)   
{
    EVE_Write32(COLOR_A(alpha));          
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 4); 
}
 
void API_CLEAR_STENCIL(uint8_t s)   
{
    EVE_Write32(CLEAR_STENCIL(s));          
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 4); 
}

void API_CLEAR_TAG(uint8_t s)   
{
    EVE_Write32(CLEAR_TAG(s));             
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 4); 
}

void API_STENCIL_MASK(uint8_t mask)   
{
    EVE_Write32(STENCIL_MASK(mask));     
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 4); 
}
   
void API_TAG_MASK(uint8_t mask)   
{
    EVE_Write32(TAG_MASK(mask));           
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 4); 
}
   
void API_SCISSOR_XY(uint16_t x, uint16_t y)  
{   
    EVE_Write32(SCISSOR_XY(x,y));               
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 4); 
}

void API_SCISSOR_SIZE(uint16_t width, uint16_t height)   
{
    EVE_Write32(SCISSOR_SIZE(width,height));         
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 4); 
}

void API_CALL(uint16_t dest)   
{
    EVE_Write32(CALL(dest));                    
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 4); 
}

void API_JUMP(uint16_t dest)   
{
    EVE_Write32(JUMP(dest));                
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 4); 
}

void API_BEGIN(uint8_t prim)   
{
    EVE_Write32(BEGIN(prim));                     
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 4); 
}

void API_COLOR_MASK(uint8_t r, uint8_t g, uint8_t b, uint8_t a)   
{
    EVE_Write32(COLOR_MASK(r,g,b,a));               
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 4); 
}

void API_END(void)   
{
    EVE_Write32(END());           
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 4); 
}

void API_SAVE_CONTEXT(void)   
{
    EVE_Write32(SAVE_CONTEXT());        
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 4); 
}

void API_RESTORE_CONTEXT(void)   
{
    EVE_Write32(RESTORE_CONTEXT());           
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 4); 
}

void API_RETURN(void)   
{
    EVE_Write32(RETURN());                          
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 4); 
}

void API_MACRO(uint8_t m)   
{
    EVE_Write32(MACRO(m));                
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 4); 
}

void API_DISPLAY(void)   
{
    EVE_Write32(DISPLAY());             
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 4); 
}

//##############################################################################
// Co-Processor Widgets
//##############################################################################

//ft_void_t Ft_Gpu_CoCmd_Text(Ft_Gpu_Hal_Context_t *phost,ft_int16_t x, ft_int16_t y, ft_int16_t font, ft_uint16_t options, const ft_char8_t* s);
void API_CMD_TEXT(int16_t x, int16_t y, int16_t font, uint16_t options, const char* string)
{
    uint32_t command_size = 0;
    uint32_t StringLength = 0;
    
    EVE_Write32(CMD_TEXT);
    EVE_Write32(((uint32_t)y<<16)|(x & 0xffff));
    EVE_Write32(((uint32_t)options<<16)|(font&0xffff));
    command_size = (command_size + 12);
    
    StringLength = API_SendString(string);
    command_size = (command_size + StringLength);

    cmdOffset = EVE_IncCMDOffset(cmdOffset, command_size);                                
}  

//ft_void_t Ft_Gpu_CoCmd_Button(Ft_Gpu_Hal_Context_t *phost,ft_int16_t x, ft_int16_t y, ft_int16_t w, ft_int16_t h, ft_int16_t font, ft_uint16_t options, const ft_char8_t* s);
void API_CMD_BUTTON(int16_t x, int16_t y, int16_t w, int16_t h, int16_t font, uint16_t options, const char* string)
{         
    uint32_t command_size = 0, StringLength = 0;
        
    EVE_Write32( CMD_BUTTON);
    EVE_Write32( (((uint32_t)y<<16)|(x & 0xffff)));
    EVE_Write32( (((uint32_t)h<<16)|(w&0xffff)));
    EVE_Write32( (((uint32_t)options<<16)|(font&0xffff)));
    command_size = (command_size + 16);
    
    StringLength = API_SendString(string);
    command_size = (command_size + StringLength);
    
    cmdOffset = EVE_IncCMDOffset(cmdOffset, command_size);                                
}  
   
//ft_void_t Ft_Gpu_CoCmd_Keys(Ft_Gpu_Hal_Context_t *phost,ft_int16_t x, ft_int16_t y, ft_int16_t w, ft_int16_t h, ft_int16_t font, ft_uint16_t options, const ft_char8_t* s);
void API_CMD_KEYS(int16_t x, int16_t y, int16_t w, int16_t h, int16_t font, uint16_t options, const char* string)
{      
    uint32_t length = strlen(string);
    uint32_t command_size = 0, StringLength = 0;
    
    EVE_Write32( CMD_KEYS);
    EVE_Write32( (((uint32_t)y<<16)|(x & 0xffff)));
    EVE_Write32( (((uint32_t)h<<16)|(w&0xffff)));
    EVE_Write32( (((uint32_t)options<<16)|(font&0xffff)));
    command_size = (command_size + 16);
    
    StringLength = API_SendString(string);
    command_size = (command_size + StringLength);
    
    cmdOffset = EVE_IncCMDOffset(cmdOffset, command_size);                                
}

//ft_void_t Ft_Gpu_CoCmd_Number(Ft_Gpu_Hal_Context_t *phost,ft_int16_t x, ft_int16_t y, ft_int16_t font, ft_uint16_t options, ft_int32_t n);
void API_CMD_NUMBER(int16_t x, int16_t y, int16_t font, uint16_t options, int32_t n)
{
    EVE_Write32(CMD_NUMBER);
    EVE_Write32( (((uint32_t)y<<16)|(x & 0xffff)));
    EVE_Write32( (((uint32_t)options<<16)|(font&0xffff)));
    EVE_Write32( n);
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 16);
}

//ft_void_t Ft_Gpu_CoCmd_LoadIdentity(Ft_Gpu_Hal_Context_t *phost);
void API_CMD_LOADIDENTITY(void)
{
    EVE_Write32( CMD_LOADIDENTITY);
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 4);
}

//ft_void_t Ft_Gpu_CoCmd_Toggle(Ft_Gpu_Hal_Context_t *phost,ft_int16_t x, ft_int16_t y, ft_int16_t w, ft_int16_t font, ft_uint16_t options, ft_uint16_t state, const ft_char8_t* s);
void API_CMD_TOGGLE(int16_t x, int16_t y, int16_t w, int16_t font, uint16_t options, uint16_t state, const char* string)
{
    uint32_t length = strlen(string);
    uint32_t command_size = 0, StringLength = 0;
    
    EVE_Write32( CMD_TOGGLE);
    EVE_Write32(((uint32_t)y<<16)|(x & 0xffff));
    EVE_Write32(((uint32_t)font<<16)|(w&0xffff));
    EVE_Write32(((uint32_t)state<<16)|options);
    command_size = (command_size + 16);

    StringLength = API_SendString(string);
    command_size = (command_size + StringLength);
 
    cmdOffset = EVE_IncCMDOffset(cmdOffset, command_size);                               
}

/* Error handling for val is not done, so better to always use range of 65535 in order that needle is drawn within display region */
//ft_void_t Ft_Gpu_CoCmd_Gauge(Ft_Gpu_Hal_Context_t *phost,ft_int16_t x, ft_int16_t y, ft_int16_t r, ft_uint16_t options, ft_uint16_t major, ft_uint16_t minor, ft_uint16_t val, ft_uint16_t range);
void API_CMD_GAUGE(int16_t x, int16_t y, int16_t r, uint16_t options, uint16_t major, uint16_t minor, uint16_t val, uint16_t range)
{     
    EVE_Write32( CMD_GAUGE);
    EVE_Write32( (((uint32_t)y<<16)|(x & 0xffff)));
    EVE_Write32( (((uint32_t)options<<16)|(r&0xffff)));
    EVE_Write32( (((uint32_t)minor<<16)|(major&0xffff)));
    EVE_Write32( (((uint32_t)range<<16)|(val&0xffff)));
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 20);
}

// ft_void_t Ft_Gpu_CoCmd_RegRead(Ft_Gpu_Hal_Context_t *phost,ft_uint32_t ptr, ft_uint32_t result);
void API_CMD_REGREAD(uint32_t ptr, uint32_t result)
{       
    EVE_Write32( CMD_REGREAD);
    EVE_Write32( ptr);
    EVE_Write32( 0);
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 12);
}

// ft_void_t Ft_Gpu_CoCmd_GetProps(Ft_Gpu_Hal_Context_t *phost,ft_uint32_t ptr, ft_uint32_t w, ft_uint32_t h);
void API_CMD_GETPROPS(uint32_t ptr, uint32_t w, uint32_t h)
{          
    EVE_Write32( CMD_GETPROPS);
    EVE_Write32( ptr);
    EVE_Write32( w);
    EVE_Write32( h);
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 16);
         
}

// ft_void_t Ft_Gpu_CoCmd_Memcpy(Ft_Gpu_Hal_Context_t *phost,ft_uint32_t dest, ft_uint32_t src, ft_uint32_t num);
void API_CMD_MEMCPY(uint32_t dest, uint32_t src, uint32_t num)
{         
    EVE_Write32( CMD_MEMCPY);
    EVE_Write32( dest);
    EVE_Write32( src);
    EVE_Write32( num);
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 16);
          
}

// ft_void_t Ft_Gpu_CoCmd_Spinner(Ft_Gpu_Hal_Context_t *phost,ft_int16_t x, ft_int16_t y, ft_uint16_t style, ft_uint16_t scale);
void API_CMD_SPINNER(int16_t x, int16_t y, uint16_t style, uint16_t scale)
{        
    EVE_Write32( CMD_SPINNER);
    EVE_Write32( (((uint32_t)y<<16)|(x & 0xffff)));
    EVE_Write32( (((uint32_t)scale<<16)|(style&0xffff)));
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 12);
         
}

// ft_void_t Ft_Gpu_CoCmd_BgColor(Ft_Gpu_Hal_Context_t *phost,ft_uint32_t c);
void API_CMD_BGCOLOR(uint32_t c)
{         
    EVE_Write32( CMD_BGCOLOR);
    EVE_Write32( c);
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 8);  
          
}

// ft_void_t Ft_Gpu_CoCmd_Swap(Ft_Gpu_Hal_Context_t *phost);
void API_CMD_SWAP(void)
{       
    EVE_Write32(CMD_SWAP);
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 4);
}
  
// ft_void_t Ft_Gpu_CoCmd_Inflate(Ft_Gpu_Hal_Context_t *phost,ft_uint32_t ptr);
void API_CMD_INFLATE(uint32_t ptr)
{
    EVE_Write32(CMD_INFLATE);
    EVE_Write32(ptr);
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 8);
}

// ft_void_t Ft_Gpu_CoCmd_Translate(Ft_Gpu_Hal_Context_t *phost,ft_int32_t tx, ft_int32_t ty);
void API_CMD_TRANSLATE(int32_t tx, int32_t ty)
{
    EVE_Write32( CMD_TRANSLATE);
    EVE_Write32( tx);
    EVE_Write32( ty);
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 12);
}

// ft_void_t Ft_Gpu_CoCmd_Stop(Ft_Gpu_Hal_Context_t *phost);
void API_CMD_STOP(void)
{    
    EVE_Write32( CMD_STOP);
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 4);
}

// ft_void_t Ft_Gpu_CoCmd_Slider(Ft_Gpu_Hal_Context_t *phost,ft_int16_t x, ft_int16_t y, ft_int16_t w, ft_int16_t h, ft_uint16_t options, ft_uint16_t val, ft_uint16_t range);
void API_CMD_SLIDER(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t options, uint16_t val, uint16_t range)
{   
    EVE_Write32( CMD_SLIDER);
    EVE_Write32( (((uint32_t)y<<16)|(x & 0xffff)));
    EVE_Write32( (((uint32_t)h<<16)|(w&0xffff)));
    EVE_Write32( (((uint32_t)val<<16)|(options&0xffff)));
    EVE_Write32( range);
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 20);
}

void API_BITMAP_TRANSFORM_A(long a)                                                
{
    EVE_Write32(BITMAP_TRANSFORM_A(a));      //    ((21UL<<24)|(((a)&131071UL)<<0))
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 4); 
}
void API_BITMAP_TRANSFORM_B(long b)      
{
    EVE_Write32(BITMAP_TRANSFORM_B(b));     //  ((22UL<<24)|(((b)&131071UL)<<0))
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 4); 
}
void API_BITMAP_TRANSFORM_C(long c)      
{
    EVE_Write32(BITMAP_TRANSFORM_C(c));          //  ((23UL<<24)|(((c)&16777215UL)<<0))
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 4); 
}
void API_BITMAP_TRANSFORM_D(long d)     
{
    EVE_Write32(BITMAP_TRANSFORM_D(d));         //   ((24UL<<24)|(((d)&131071UL)<<0))
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 4); 
}
void API_BITMAP_TRANSFORM_E(long e)      
{
    EVE_Write32(BITMAP_TRANSFORM_E(e));           //   ((25UL<<24)|(((e)&131071UL)<<0))
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 4); 
}
void API_BITMAP_TRANSFORM_F(long f)      
{
    EVE_Write32(BITMAP_TRANSFORM_F(f));            //  ((26UL<<24)|(((f)&16777215UL)<<0))
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 4); 
}

// ft_void_t Ft_Gpu_CoCmd_Interrupt(Ft_Gpu_Hal_Context_t *phost,ft_uint32_t ms);
void API_CMD_INTERRUPT(uint32_t ms)
{       
    EVE_Write32( CMD_INTERRUPT);
    EVE_Write32( ms);
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 8);
}

// ft_void_t Ft_Gpu_CoCmd_FgColor(Ft_Gpu_Hal_Context_t *phost,ft_uint32_t c);
void API_CMD_FGCOLOR(uint32_t c)
{         
    EVE_Write32( CMD_FGCOLOR);
    EVE_Write32( c);
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 8);
}

// ft_void_t Ft_Gpu_CoCmd_Rotate(Ft_Gpu_Hal_Context_t *phost,ft_int32_t a);
void API_CMD_ROTATE(int32_t a)
{            
    EVE_Write32( CMD_ROTATE);
    EVE_Write32( a);
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 8);
}

// ft_void_t Ft_Gpu_CoCmd_MemWrite(Ft_Gpu_Hal_Context_t *phost,ft_uint32_t ptr, ft_uint32_t num);
void API_CMD_MEMWRITE(uint32_t ptr, uint32_t num)
{      
    EVE_Write32( CMD_MEMWRITE);
    EVE_Write32( ptr);
    EVE_Write32( num);
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 12);
}

// ft_void_t Ft_Gpu_CoCmd_Scrollbar(Ft_Gpu_Hal_Context_t *phost,ft_int16_t x, ft_int16_t y, ft_int16_t w, ft_int16_t h, ft_uint16_t options, ft_uint16_t val, ft_uint16_t size, ft_uint16_t range);
void API_CMD_SCROLLBAR(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t options, uint16_t val, uint16_t size, uint16_t range)
{       
    EVE_Write32( CMD_SCROLLBAR);
    EVE_Write32( (((uint32_t)y<<16)|(x & 0xffff)));
    EVE_Write32( (((uint32_t)h<<16)|(w&0xffff)));
    EVE_Write32( (((uint32_t)val<<16)|(options&0xffff)));
    EVE_Write32( (((uint32_t)range<<16)|(size&0xffff)));
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 20);
}

// ft_void_t Ft_Gpu_CoCmd_GetMatrix(Ft_Gpu_Hal_Context_t *phost,ft_int32_t a, ft_int32_t b, ft_int32_t c, ft_int32_t d, ft_int32_t e, ft_int32_t f);
void API_CMD_GETMATRIX(int32_t a, int32_t b, int32_t c, int32_t d, int32_t e, int32_t f)
{     
    EVE_Write32( CMD_GETMATRIX);
    EVE_Write32( a);
    EVE_Write32( b);
    EVE_Write32( c);
    EVE_Write32( d);
    EVE_Write32( e);
    EVE_Write32( f);
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 28); 
}

// ft_void_t Ft_Gpu_CoCmd_Sketch(Ft_Gpu_Hal_Context_t *phost,ft_int16_t x, ft_int16_t y, ft_uint16_t w, ft_uint16_t h, ft_uint32_t ptr, ft_uint16_t format);
void API_CMD_SKETCH(int16_t x, int16_t y, uint16_t w, uint16_t h, uint32_t ptr, uint16_t format)
{      
    EVE_Write32( CMD_SKETCH);
    EVE_Write32( (((uint32_t)y<<16)|(x & 0xffff)));
    EVE_Write32( (((uint32_t)h<<16)|(w&0xffff)));
    EVE_Write32( ptr);
    EVE_Write32( format);
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 20);
}

// ft_void_t Ft_Gpu_CoCmd_MemSet(Ft_Gpu_Hal_Context_t *phost,ft_uint32_t ptr, ft_uint32_t value, ft_uint32_t num);
void API_CMD_MEMSET(uint32_t ptr, uint32_t value, uint32_t num)
{      
    EVE_Write32( CMD_MEMSET);
    EVE_Write32( ptr);
    EVE_Write32( value);
    EVE_Write32( num);
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 16);
}

// ft_void_t Ft_Gpu_CoCmd_GradColor(Ft_Gpu_Hal_Context_t *phost,ft_uint32_t c);
void API_CMD_GRADCOLOR(uint32_t c)
{     
    EVE_Write32( CMD_GRADCOLOR);
    EVE_Write32( c);
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 8);
}

// ft_void_t Ft_Gpu_CoCmd_Bitmap_Transform(Ft_Gpu_Hal_Context_t *phost,ft_int32_t x0, ft_int32_t y0, ft_int32_t x1, ft_int32_t y1, ft_int32_t x2, ft_int32_t y2, ft_int32_t tx0, ft_int32_t ty0, ft_int32_t tx1, ft_int32_t ty1, ft_int32_t tx2, ft_int32_t ty2, ft_uint16_t result);
void API_CMD_BITMAP_TRANSFORM(int32_t x0, int32_t y0, int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t tx0, int32_t ty0, int32_t tx1, int32_t ty1, int32_t tx2, int32_t ty2, uint16_t result)
{       
    EVE_Write32( CMD_BITMAP_TRANSFORM);
    EVE_Write32( x0);
    EVE_Write32( y0);
    EVE_Write32( x1);
    EVE_Write32( y1);
    EVE_Write32( x2);
    EVE_Write32( y2);
    EVE_Write32( tx0);
    EVE_Write32( ty0);
    EVE_Write32( tx1);
    EVE_Write32( ty1);
    EVE_Write32( tx2);
    EVE_Write32( ty2);
    EVE_Write32( result);
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 56);
}

// ft_void_t Ft_Gpu_CoCmd_Calibrate(Ft_Gpu_Hal_Context_t *phost,ft_uint32_t result);
void API_CMD_CALIBRATE(uint32_t result)
{    
    EVE_Write32( CMD_CALIBRATE);
    EVE_Write32( result);
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 8);
    // Ft_Gpu_Hal_WaitCmdfifo_empty(phost);
}

// ft_void_t Ft_Gpu_CoCmd_SetFont(Ft_Gpu_Hal_Context_t *phost,ft_uint32_t font, ft_uint32_t ptr);
void API_CMD_SETFONT(uint32_t font, uint32_t ptr)
{     
    EVE_Write32( CMD_SETFONT);
    EVE_Write32( font);
    EVE_Write32( ptr);
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 12);
}

// ft_void_t Ft_Gpu_CoCmd_Logo(Ft_Gpu_Hal_Context_t *phost);
void API_CMD_LOGO(void)
{   
    EVE_Write32( CMD_LOGO);  
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 4);
}

// ft_void_t Ft_Gpu_CoCmd_Append(Ft_Gpu_Hal_Context_t *phost,ft_uint32_t ptr, ft_uint32_t num);
void API_CMD_APPEND(uint32_t ptr, uint32_t num)
{       
    EVE_Write32( CMD_APPEND);
    EVE_Write32( ptr);
    EVE_Write32( num);
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 12);
}

// ft_void_t Ft_Gpu_CoCmd_MemZero(Ft_Gpu_Hal_Context_t *phost,ft_uint32_t ptr, ft_uint32_t num);
void API_CMD_MEMZERO(uint32_t ptr, uint32_t num)
{      
    EVE_Write32( CMD_MEMZERO);
    EVE_Write32( ptr);
    EVE_Write32( num);
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 12);
}

// ft_void_t Ft_Gpu_CoCmd_Scale(Ft_Gpu_Hal_Context_t *phost,ft_int32_t sx, ft_int32_t sy);
void API_CMD_SCALE(int32_t sx, int32_t sy)
{      
    EVE_Write32( CMD_SCALE);
    EVE_Write32( sx);
    EVE_Write32( sy);
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 12);
}

// ft_void_t Ft_Gpu_CoCmd_Clock(Ft_Gpu_Hal_Context_t *phost,ft_int16_t x, ft_int16_t y, ft_int16_t r, ft_uint16_t options, ft_uint16_t h, ft_uint16_t m, ft_uint16_t s, ft_uint16_t ms);
void API_CMD_CLOCK(int16_t x, int16_t y, int16_t r, uint16_t options, uint16_t h, uint16_t m, uint16_t s, uint16_t ms)
{         
    EVE_Write32( CMD_CLOCK);
    EVE_Write32( (((uint32_t)y<<16)|(x & 0xffff)));
    EVE_Write32( (((uint32_t)options<<16)|(r&0xffff)));
    EVE_Write32( (((uint32_t)m<<16)|(h&0xffff)));
    EVE_Write32( (((uint32_t)ms<<16)|(s&0xffff)));
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 20);
}

// ft_void_t Ft_Gpu_CoCmd_Gradient(Ft_Gpu_Hal_Context_t *phost,ft_int16_t x0, ft_int16_t y0, ft_uint32_t rgb0, ft_int16_t x1, ft_int16_t y1, ft_uint32_t rgb1);
void API_CMD_GRADIENT(int16_t x0, int16_t y0, uint32_t rgb0, int16_t x1, int16_t y1, uint32_t rgb1)
{        
    EVE_Write32( CMD_GRADIENT);
    EVE_Write32( (((uint32_t)y0<<16)|(x0 & 0xffff)));
    EVE_Write32( rgb0);
    EVE_Write32( (((uint32_t)y1<<16)|(x1 & 0xffff)));
    EVE_Write32( rgb1);
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 20);
}

// ft_void_t Ft_Gpu_CoCmd_SetMatrix(Ft_Gpu_Hal_Context_t *phost);
void API_CMD_SETMATRIX(void)
{       
    EVE_Write32( CMD_SETMATRIX);
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 4);
}

// ft_void_t Ft_Gpu_CoCmd_Track(Ft_Gpu_Hal_Context_t *phost,ft_int16_t x, ft_int16_t y, ft_int16_t w, ft_int16_t h, ft_int16_t tag);
void API_CMD_TRACK(int16_t x, int16_t y, int16_t w, int16_t h, int16_t tag)
{      
    EVE_Write32( CMD_TRACK);
    EVE_Write32( (((uint32_t)y<<16)|(x & 0xffff)));
    EVE_Write32( (((uint32_t)h<<16)|(w&0xffff)));
    EVE_Write32( tag);
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 16);
}

// ft_void_t Ft_Gpu_CoCmd_GetPtr(Ft_Gpu_Hal_Context_t *phost,ft_uint32_t result);
void API_CMD_GETPTR(uint32_t result)
{        
    EVE_Write32( CMD_GETPTR);
    EVE_Write32( result);
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 8);
}

// ft_void_t Ft_Gpu_CoCmd_Progress(Ft_Gpu_Hal_Context_t *phost,ft_int16_t x, ft_int16_t y, ft_int16_t w, ft_int16_t h, ft_uint16_t options, ft_uint16_t val, ft_uint16_t range);
void API_CMD_PROGRESS(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t options, uint16_t val, uint16_t range)
{       
    EVE_Write32( CMD_PROGRESS);
    EVE_Write32( (((uint32_t)y<<16)|(x & 0xffff)));
    EVE_Write32( (((uint32_t)h<<16)|(w&0xffff)));
    EVE_Write32( (((uint32_t)val<<16)|(options&0xffff)));
    EVE_Write32( range);
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 20);
}

// ft_void_t Ft_Gpu_CoCmd_ColdStart(Ft_Gpu_Hal_Context_t *phost);
void API_CMD_COLDSTART(void)
{      
    EVE_Write32( CMD_COLDSTART);
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 4);
}

// ft_void_t Ft_Gpu_CoCmd_Dial(Ft_Gpu_Hal_Context_t *phost,ft_int16_t x, ft_int16_t y, ft_int16_t r, ft_uint16_t options, ft_uint16_t val);
void API_CMD_DIAL(int16_t x, int16_t y, int16_t r, uint16_t options, uint16_t val)
{        
    EVE_Write32( CMD_DIAL);
    EVE_Write32( (((uint32_t)y<<16)|(x & 0xffff)));
    EVE_Write32( (((uint32_t)options<<16)|(r&0xffff)));
    EVE_Write32( val);
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 16);  
}

// ft_void_t Ft_Gpu_CoCmd_LoadImage(Ft_Gpu_Hal_Context_t *phost,ft_uint32_t ptr, ft_uint32_t options);
void API_CMD_LOADIMAGE(uint32_t ptr, uint32_t options)
{         
    EVE_Write32( CMD_LOADIMAGE);
    EVE_Write32( ptr);
    EVE_Write32( options);
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 12);  
}

// ft_void_t Ft_Gpu_CoCmd_Dlstart(Ft_Gpu_Hal_Context_t *phost);
void API_CMD_DLSTART(void)
{          
    EVE_Write32( CMD_DLSTART);
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 4);             
}

// ft_void_t Ft_Gpu_CoCmd_Snapshot(Ft_Gpu_Hal_Context_t *phost,ft_uint32_t ptr);
void API_CMD_SNAPSHOT(uint32_t ptr)
{            
    EVE_Write32( CMD_SNAPSHOT);
    EVE_Write32( ptr);
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 8);     
}

// ft_void_t Ft_Gpu_CoCmd_ScreenSaver(Ft_Gpu_Hal_Context_t *phost);
void API_CMD_SCREENSAVER(void)
{          
    EVE_Write32( CMD_SCREENSAVER);
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 4);         
}

// ft_void_t Ft_Gpu_CoCmd_Memcrc(Ft_Gpu_Hal_Context_t *phost,ft_uint32_t ptr, ft_uint32_t num, ft_uint32_t result);
void API_CMD_MEMCRC(uint32_t ptr, uint32_t num, uint32_t result)
{            
    EVE_Write32( CMD_MEMCRC);
    EVE_Write32( ptr);
    EVE_Write32( num);
    EVE_Write32( result);
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 16);     
}




// FT81X-only features
#ifdef FT_81X_ENABLE

// ###############       GPU        ############################################

void API_VERTEX_FORMAT(uint8_t frac)   
{
    EVE_Write32(VERTEX_FORMAT(frac));               
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 4); 
}

void API_BITMAP_LAYOUT_H(uint8_t linestride, uint8_t height)   
{
    EVE_Write32(BITMAP_LAYOUT_H(linestride,height));          
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 4); 
}

void API_BITMAP_SIZE_H(uint8_t width, uint8_t height)   
{
    EVE_Write32(BITMAP_SIZE_H(width,height));              
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 4); 
}

void API_PALETTE_SOURCE(uint32_t addr)   
{
    EVE_Write32(PALETTE_SOURCE(addr));                   
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 4); 
}

void API_VERTEX_TRANSLATE_X(uint32_t x)   
{
    EVE_Write32(VERTEX_TRANSLATE_X(x));             
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 4); 
}

void API_VERTEX_TRANSLATE_Y(uint32_t y)   
{
    EVE_Write32(VERTEX_TRANSLATE_Y(y));               
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 4); 
}

void API_NOP(void)   
{
    EVE_Write32(NOP());                       
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 4); 
}

// ###############       CO-PRO        #########################################

// ft_void_t Ft_Gpu_CoCmd_SetRotate(Ft_Gpu_Hal_Context_t *phost,ft_uint32_t r);
void API_CMD_SETROTATE(uint32_t r)
{          
    EVE_Write32( CMD_SETROTATE);
    EVE_Write32( r);
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 8);
}

// ft_void_t Ft_Gpu_CoCmd_SetFont2(Ft_Gpu_Hal_Context_t *phost,ft_uint32_t font, ft_uint32_t ptr, ft_uint32_t firstchar);
void API_CMD_SETFONT2(uint32_t font, uint32_t ptr, uint32_t firstchar)
{           
    EVE_Write32( CMD_SETFONT2);
    EVE_Write32( font);
    EVE_Write32( ptr);
    EVE_Write32( firstchar);
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 16);      
}

// ft_void_t Ft_Gpu_CoCmd_Snapshot2(Ft_Gpu_Hal_Context_t *phost,ft_uint32_t fmt, ft_uint32_t ptr, ft_int16_t x, ft_int16_t y, ft_int16_t w, ft_int16_t h);
void API_CMD_SNAPSHOT2(uint32_t fmt, uint32_t ptr, int16_t x, int16_t y, int16_t w, int16_t h)
{          
    EVE_Write32( CMD_SNAPSHOT2);
    EVE_Write32( fmt);
    EVE_Write32( ptr);
    EVE_Write32( (((uint32_t)y<<16)|(x & 0xffff)));
    EVE_Write32( (((uint32_t)h<<16)|(w&0xffff)));
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 20); 
}

// ft_void_t Ft_Gpu_CoCmd_MediaFifo(Ft_Gpu_Hal_Context_t *phost,ft_uint32_t ptr, ft_uint32_t size);
void API_CMD_MEDIAFIFO(uint32_t ptr, uint32_t size)
{    
    EVE_Write32( CMD_MEDIAFIFO);
    EVE_Write32( ptr);
    EVE_Write32( size);
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 12);
}


// ft_void_t Ft_Gpu_CoCmd_Int_SWLoadImage(Ft_Gpu_Hal_Context_t *phost,ft_uint32_t ptr, ft_uint32_t options);
void API_CMD_INT_SWLOADIMAGE(uint32_t ptr, uint32_t options)
{        
    EVE_Write32( CMD_INT_SWLOADIMAGE);
    EVE_Write32( ptr);
    EVE_Write32( options);
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 12);
}

// ft_void_t Ft_Gpu_CoCmd_Sync(Ft_Gpu_Hal_Context_t *phost);
void API_CMD_SYNC(void)
{        
    EVE_Write32( CMD_SYNC);
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 4);
}

// ft_void_t Ft_Gpu_CoCmd_CSketch(Ft_Gpu_Hal_Context_t *phost,ft_int16_t x, ft_int16_t y, ft_uint16_t w, ft_uint16_t h, ft_uint32_t ptr, ft_uint16_t format,ft_uint16_t freq);
void API_CMD_CSKETCH(int16_t x, int16_t y, uint16_t w, uint16_t h, uint32_t ptr, uint16_t format,uint16_t freq)
{        
    EVE_Write32( CMD_CSKETCH);
    EVE_Write32( (((uint32_t)y<<16)|(x & 0xffff)));
    EVE_Write32( (((uint32_t)h<<16)|(w&0xffff)));
    EVE_Write32( ptr);
    EVE_Write32( (((uint32_t)freq<<16)|(format&0xffff)));
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 20);
}

// ft_void_t Ft_Gpu_CoCmd_RomFont(Ft_Gpu_Hal_Context_t *phost,ft_uint32_t font, ft_uint32_t romslot);
void API_CMD_ROMFONT(uint32_t font, uint32_t romslot)
{       
    EVE_Write32( CMD_ROMFONT);
    EVE_Write32( font);
    EVE_Write32( romslot);
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 12);
}

// ft_void_t Ft_Gpu_CoCmd_PlayVideo(Ft_Gpu_Hal_Context_t *phost,ft_uint32_t options);
void API_CMD_PLAYVIDEO(uint32_t options)
{      
    EVE_Write32( CMD_PLAYVIDEO);
    EVE_Write32( options);
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 8);
}

// ft_void_t Ft_Gpu_CoCmd_VideoFrame(Ft_Gpu_Hal_Context_t *phost,ft_uint32_t dst, ft_uint32_t ptr);
void API_CMD_VIDEOFRAME(uint32_t dst, uint32_t ptr)
{  
    EVE_Write32( CMD_VIDEOFRAME);
    EVE_Write32( dst);
    EVE_Write32( ptr);
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 12);
}

// ft_void_t Ft_Gpu_CoCmd_VideoStart(Ft_Gpu_Hal_Context_t *phost);
void API_CMD_VIDEOSTART(void)
{
    EVE_Write32( CMD_VIDEOSTART);
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 4);         
}

// ft_void_t Ft_Gpu_CoCmd_SetBase(Ft_Gpu_Hal_Context_t *phost,ft_uint32_t base);
void API_CMD_SETBASE(uint32_t base)
{
    EVE_Write32( CMD_SETBASE);
    EVE_Write32( base);
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 8);
}

//ft_void_t Ft_Gpu_CoCmd_SetBitmap(Ft_Gpu_Hal_Context_t *phost,ft_uint32_t source, ft_uint16_t fmt, ft_uint16_t w, ft_uint16_t h);
void API_CMD_SETBITMAP(uint32_t source, uint16_t fmt, uint16_t w, uint16_t h)
{
    EVE_Write32(CMD_SETBITMAP);
    EVE_Write32( source);
    EVE_Write32( (((uint32_t)w<<16)|(fmt & 0xffff)));
    EVE_Write32( h);
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 16);
}

//ft_void_t Ft_Gpu_CoCmd_SetScratch(Ft_Gpu_Hal_Context_t *phost,ft_uint32_t handle);
void API_CMD_SETSCRATCH(uint32_t handle)
{
    EVE_Write32( CMD_SETSCRATCH);
    EVE_Write32( handle);
    cmdOffset = EVE_IncCMDOffset(cmdOffset, 8);
}
#endif  // FT81X-only features






