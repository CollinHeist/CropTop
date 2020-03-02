/**
 *	File
 *		screen.c
 *	Summary
 *		UART interface to the screen source file.
 *	Author(s)
 *		Collin Heist
 */

/* ----------------------------------- File Inclusion ----------------------------------- */

#include <plib.h>
#include <stdio.h>
#include <string.h>

#include "hardware.h"
#include "screen.h"

/* -------------------------- Global Variables and Structures --------------------------- */

static DmaChannel DMA_channel = DMA_CHANNEL1;		// Active DMA Channel
static char private_DMA_buffer[DMA_BUFFER_SIZE];	// Private temporary DMA buffer to avoid conflicts
char screen_buffer[DMA_BUFFER_SIZE];				// External screen buffer

/* ---------------------------------- Public Functions ---------------------------------- */

unsigned int initialize_screen(unsigned int baud) {
//	UARTConfigure(UART2, UART_ENABLE_PINS_TX_RX_ONLY);		// Standard RX and TX pins only
//	UARTSetFifoMode(UART2, UART_INTERRUPT_ON_RX_NOT_EMPTY);	// Only interrupt on RX non-empty
//	UARTSetLineControl(UART2, SCREEN_UART_LINE_CONTROL);
//	UARTSetDataRate(UART2, GetPeripheralClock(), baud);
//	UARTEnable(UART2, UART_ENABLE | UART_RX | UART_TX);
	unsigned int brg = (unsigned int)(((float) GetPeripheralClock() / ((float) 4 * (float) baud))- (float) 0.5);
	OpenUART2(UART_EN | UART_BRGH_FOUR | UART_NO_PAR_8BIT, UART_RX_ENABLE | UART_TX_ENABLE, brg);
	
	return initialize_DMA_UART2();
}

void send_string_UART2(char* string) {
	while (*string) {
		while (send_byte_UART2(*string) == ERROR) {}	// Try and send byte until successful
		string++;
	}
}

/* --------------------------------- Private Functions ---------------------------------- */

static unsigned int initialize_DMA_UART2(void) {
	INTClearFlag(INT_SOURCE_DMA(DMA_channel));	// Clear any standing DMA interrupts
	DmaChnOpen(DMA_channel, DMA_CHN_PRI2, DMA_OPEN_MATCH);
	DmaChnSetMatchPattern(DMA_channel, 0);		// Set null as ending character
	
	// Configure the event that starts DMA transfers - RX interrupt 
	DmaChnSetEventControl(DMA_channel, DMA_EV_START_IRQ_EN | DMA_EV_MATCH_EN | DMA_EV_START_IRQ(_UART2_RX_IRQ));
	DmaChnSetTxfer(DMA_channel, (void*)&U2RXREG, private_DMA_buffer, 1, DMA_BUFFER_SIZE, 1);
	
	// Enable the transfer done interrupt on pattern match for all characters transferred
	DmaChnSetEvEnableFlags(DMA_channel, DMA_EV_BLOCK_DONE);
	INTEnable(INT_SOURCE_DMA(DMA_channel), INT_ENABLED);
	INTSetVectorPriority(INT_VECTOR_DMA(DMA_channel), INT_PRIORITY_LEVEL_3);	// Set INT priority
	INTSetVectorSubPriority(INT_VECTOR_DMA(DMA_channel), INT_SUB_PRIORITY_LEVEL_0);	// Set sub-priority
	INTEnable(INT_SOURCE_DMA(DMA_channel), INT_ENABLED);
	
	// Enable the DMA channel now that it's been configured
	DmaChnEnable(DMA_channel);
	
	return NO_ERROR;
}

static void restartDMATransfer(void) {
	DmaChnSetTxfer(DMA_channel, (void*)&U2RXREG, private_DMA_buffer, 1, DMA_BUFFER_SIZE, 1);
	DmaChnEnable(DMA_channel);
}

static unsigned int send_byte_UART2(BYTE data) {
	if (UARTTransmitterIsReady(UART2)) {
		UARTSendDataByte(UART2, data);
		return NO_ERROR;
	}
	
	return ERROR;
}

static inline void clear_buffer(char* buffer, unsigned int length) {
	unsigned int index = 0;
	for (index = 0; index < length; index++) 
		buffer[index] = 0;
}

/* ----------------------------- Interrupt Service Routines ----------------------------- */

void __ISR(_DMA1_VECTOR, IPL3SOFT) isr_DMA_handler(void) {
	if (DmaChnGetEvFlags(DMA_channel) & DMA_EV_ALL_EVNTS) {
		clear_buffer(screen_buffer, DMA_BUFFER_SIZE);		// Clear old contents in public buffer
		strcpy(screen_buffer, private_DMA_buffer);			// Transfer contents
		clear_buffer(private_DMA_buffer, DMA_BUFFER_SIZE);	// Clear old contents in private buffer
		restartDMATransfer();								// A valid event means the DMA must be re-enabled
	}

	INTClearFlag(INT_SOURCE_DMA(DMA_channel));
}