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




#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 


// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

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
void MCU_Delay_20ms(void);
void MCU_Delay_500ms(void);

// EVE Layer
void EVE_AddrForWr(unsigned long ftAddress);
void EVE_AddrForRd(unsigned long ftAddress);
void EVE_Write32(unsigned long ftData32);
void EVE_Write16(unsigned int ftData16);
void EVE_Write8(unsigned char ftData8);
unsigned long EVE_Read32(void);
unsigned int EVE_Read16(void);
unsigned char EVE_Read8(void);
void EVE_MemWrite32(unsigned long ftAddress, unsigned long ftData32);
void EVE_MemWrite16(unsigned long ftAddress, unsigned int ftData16);
void EVE_MemWrite8(unsigned long ftAddress, unsigned char ftData8);
unsigned long EVE_MemRead32(unsigned long ftAddress);
unsigned int EVE_MemRead16(unsigned long ftAddress);
unsigned char EVE_MemRead8(unsigned long ftAddress);
void EVE_CmdWrite(unsigned char EVECmd, unsigned char Param);
unsigned int EVE_IncCMDOffset(unsigned int currentOffset, unsigned char commandSize);
unsigned int EVE_WaitCmdFifoEmpty(void);





#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */

