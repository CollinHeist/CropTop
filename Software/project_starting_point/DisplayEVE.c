#include "xc.h"
#include "DisplayLib.h" 
#include "FT8xx.h"

#define MEM_WRITE	0x80			// FT800 Host Memory Write
#define MEM_READ	0x00			// FT800 Host Memory Read


//############################################################################## 
//##############################################################################
//                        EVE INTERFACE LAYER 
//##############################################################################  
//##############################################################################


// ############### INDIVIDUAL ADDRESSING AND DATA FUNCTIONS ####################

// This section has separate calls for addressing and data phases of the transaction which allows for burst writes and reads.

// ------------------ Send FT81x register address for writing ------------------
void EVE_AddrForWr(unsigned long ftAddress)
{
    unsigned char dummyRead = 0;
    // Send three bytes of a register address which has to be subsequently written. Ignore return values as this is an SPI write only.
    dummyRead = MCU_SPIReadWrite( (char) ((ftAddress >> 16) | MEM_WRITE) );     // Send high byte of address with 'write' bits set

    dummyRead = MCU_SPIReadWrite( (char) (ftAddress >> 8) );                    // Send middle byte of address

    dummyRead = MCU_SPIReadWrite( (char) (ftAddress) );                         // Send low byte of address
}

// ------------------ Send FT81x register address for reading ------------------
void EVE_AddrForRd(unsigned long ftAddress)
{
    unsigned char dummyRead = 0;
    // Send three bytes of a register address which has to be subsequently read. Ignore return values as this is an SPI write only.
    dummyRead = MCU_SPIReadWrite( (char) ((ftAddress >> 16) | MEM_READ) );      // Send high byte of address with 'read' bits set

    dummyRead = MCU_SPIReadWrite( (char) (ftAddress >> 8) );                    // Send middle byte of address

    dummyRead = MCU_SPIReadWrite( (char) (ftAddress) );                         // Send low byte of address

    dummyRead = MCU_SPIReadWrite( 0x00 );                                       // Send dummy byte before doing the read
}

// ------------------------ Send a 32-bit data value --------------------------
void EVE_Write32(unsigned long ftData32)
{    
    unsigned char dummyRead = 0;
    // Send four bytes of data after previously sending address. Ignore return values as this is an SPI write only.
    dummyRead = MCU_SPIReadWrite( (char) (ftData32) );                          // Send low byte of data   

    dummyRead = MCU_SPIReadWrite( (char) (ftData32 >> 8) );                     //

    dummyRead = MCU_SPIReadWrite( (char) (ftData32 >> 16) );                    //

    dummyRead = MCU_SPIReadWrite( (char) (ftData32 >> 24) );                    // Send high byte of data       
}

// ------------------------ Send a 16-bit data value --------------------------
void EVE_Write16(unsigned int ftData16)
{
    
    unsigned char dummyRead = 0;    
    // Send two bytes of data after previously sending address. Ignore return values as this is an SPI write only.
    dummyRead = MCU_SPIReadWrite( (char) (ftData16) );                          // Send low byte of data  

    dummyRead = MCU_SPIReadWrite( (char) (ftData16 >> 8) );                     // Send high byte of data
}

// ------------------------ Send an 8-bit data value ---------------------------
void EVE_Write8(unsigned char ftData8)
{
    unsigned char dummyRead = 0;    
    // Send one byte of data after previously sending address. Ignore return values as this is an SPI write only.
    dummyRead = MCU_SPIReadWrite( (char) (ftData8) );                          // Send byte of data  
}

// ------------------------ Read a 32-bit data value --------------------------
unsigned long EVE_Read32(void)
{    
    // Read 4 bytes from a register has been previously addressed. Send dummy 00 bytes as only the incoming value is important.
    unsigned long ftData32 = 0x00000000;
    unsigned long tempData32 = 0x00000000;
       
    tempData32 = MCU_SPIReadWrite( 0x00 );                                      // Read low byte of data first
    ftData32 = ftData32 | tempData32;
     
    tempData32 = MCU_SPIReadWrite( 0x00 );
    tempData32 = ((tempData32 << 8) & 0x0000FF00);
    ftData32 = ftData32 | tempData32;

    tempData32 = MCU_SPIReadWrite( 0x00 );
    tempData32 = ((tempData32 << 16) & 0x00FF0000);
    ftData32 = ftData32 | tempData32;    
    
    tempData32 = MCU_SPIReadWrite( 0x00 );                                      // Read high byte of data last
    tempData32 = ((tempData32 << 24) & 0xFF000000);
    ftData32 = ftData32 | tempData32;  

    return ftData32;                                                            // Return combined 32-bit value
}

// ------------------------ Read a 16-bit data value ---------------------------
unsigned int EVE_Read16(void)
{
    // Read 2 bytes from a register has been previously addressed. Send dummy 00 bytes as only the incoming value is important.
    unsigned int ftData16 = 0x0000;
    unsigned int tempData16 = 0x0000;
    
    tempData16 = MCU_SPIReadWrite( 0x00 );                                      // Read low byte of data first
    ftData16 = ftData16 | tempData16;
     
    tempData16 = MCU_SPIReadWrite( 0x00 );                                      // Read high byte of data last
    tempData16 = ((tempData16 << 8) & 0xFF00);
    ftData16 = ftData16 | tempData16;

    return ftData16;                                                            // Return combined 16-bit value
}

// ------------------------ Read an 8-bit data value ---------------------------
unsigned char EVE_Read8(void)
{
    // Read 1 byte from a register has been previously addressed. Send dummy 00 byte as only the incoming value is important.
    unsigned char ftData8 = 0x00;
    
    ftData8 = MCU_SPIReadWrite( 0x00 );                                         // Read byte of data
      
    return ftData8;                                                             // Return 8-bit value read
}



// ################# COMBINED ADDRESSING AND DATA FUNCTIONS ####################

// This section has combined calls which carry out a full write or read cycle including chip select, address, and data transfer.
// This would often be used for register writes and reads. 

// -------------- Write a 32-bit value to specified address --------------------
void EVE_MemWrite32(unsigned long ftAddress, unsigned long ftData32)
{
    MCU_CSlow();                                                                // CS low begins the SPI transfer    
  
    EVE_AddrForWr(ftAddress);                                                   // Send address to be written
  
    EVE_Write32(ftData32);                                                      // Send the data value
    
    MCU_CShigh();                                                               // CS high terminates the SPI transfer

}

// -------------- Write a 16-bit value to specified address --------------------
void EVE_MemWrite16(unsigned long ftAddress, unsigned int ftData16)
{
    MCU_CSlow();                                                                // CS low begins the SPI transfer 
  
    EVE_AddrForWr(ftAddress);                                                   // Send address to be written
  
    EVE_Write16(ftData16);                                                      // Send the data value        
    
    MCU_CShigh();                                                               // CS high terminates the SPI transfer
}

// -------------- Write an 8-bit value to specified address --------------------
void EVE_MemWrite8(unsigned long ftAddress, unsigned char ftData8)
{
    MCU_CSlow();                                                                // CS low begins the SPI transfer 
  
    EVE_AddrForWr(ftAddress);                                                   // Send address to be written

    EVE_Write8(ftData8);                                                        // Send the data value        
    
    MCU_CShigh();                                                               // CS high terminates the SPI transfer
}



// -------------- Read a 32-bit value from specified address --------------------
unsigned long EVE_MemRead32(unsigned long ftAddress)
{
    unsigned long ftData32 = 0x00000000;
  
    MCU_CSlow();                                                                // CS low begins the SPI transfer 
  
    EVE_AddrForRd(ftAddress);                                                   // Send address to be read
       
    ftData32 = EVE_Read32();                                                    // Read the data value    

    MCU_CShigh();                                                               // CS high terminates the SPI transfer
    
    return ftData32;                                                            // Return 32-bit value read
}

// -------------- Read a 16-bit value from specified address --------------------
unsigned int EVE_MemRead16(unsigned long ftAddress)
{
    unsigned int ftData16 = 0x0000;
  
    MCU_CSlow();                                                                // CS low begins the SPI transfer 
    
    EVE_AddrForRd(ftAddress);                                                   // Send address to be read
        
    ftData16 = EVE_Read16();                                                    // Read the data value      

    MCU_CShigh();                                                               // CS high terminates the SPI transfer

    return ftData16;                                                            // Return 16-bit value read
}

// -------------- Read an 8-bit value from specified address --------------------
unsigned char EVE_MemRead8(unsigned long ftAddress)
{
    unsigned char ftData8 = 0x00;
  
    MCU_CSlow();                                                                // CS low begins the SPI transfer 
  
    EVE_AddrForRd(ftAddress);                                                   // Send address to be read
       
    ftData8 = EVE_Read8();                                                      // Read the data value   

    MCU_CShigh();                                                               // CS high terminates the SPI transfer
 
    return ftData8;                                                             // Return 8-bit value read
}





// ############################# HOST COMMANDS #################################

// -------------------------- Write a host command -----------------------------
void EVE_CmdWrite(unsigned char EVECmd, unsigned char Param)
{
    unsigned char dummyRead = 0;

    MCU_CSlow();                                                                // CS low begins the SPI transfer
    
    dummyRead = MCU_SPIReadWrite( (char) (EVECmd) );                            // Send command 

    dummyRead = MCU_SPIReadWrite( (char) (Param) );                             // followed by parameter

    dummyRead = MCU_SPIReadWrite( 0x00 );                                       // and a dummy 00 byte
    
    MCU_CShigh();                                                               // CS high terminates the SPI transfer
}

// ######################## SUPPORTING FUNCTIONS ###############################

// --------- Increment co-processor address offset counter --------------------
unsigned int EVE_IncCMDOffset(unsigned int currentOffset, unsigned char commandSize)
{
    unsigned int newOffset;                                                     // Used to hold new offset
    
    newOffset = currentOffset + commandSize;                                    // Calculate new offset
    
    if(newOffset > 4095)                                                        // If new offset past top of buffer...
    {
        newOffset = (newOffset - 4096);                                         // ... roll over
    }
    
    return newOffset;                                                           // Return new offset
}

// ------ Wait for co-processor read and write pointers to be equal ------------

unsigned int EVE_WaitCmdFifoEmpty(void)
{
    unsigned int ReadPointer, WritePointer;
        
    do
    {
        ReadPointer = EVE_MemRead32(REG_CMD_READ);                              // Read the graphics processor read pointer
        WritePointer = EVE_MemRead32(REG_CMD_WRITE);                            // Read the graphics processor write pointer
    }while (WritePointer != ReadPointer);                                       // Wait until the two registers match

    return WritePointer;                                                        // New starting point will be first location after the last command
}










