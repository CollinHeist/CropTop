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
static unsigned int received_flag;					// Flag for if a response has been acknowledged

char screen_rx_buffer[DMA_BUFFER_SIZE];				// External screen buffer

/* ---------------------------------- Public Functions ---------------------------------- */

unsigned int initialize_screen(unsigned int baud) {
//	UARTConfigure(UART2, UART_ENABLE_PINS_TX_RX_ONLY);		// Standard RX and TX pins only
//	UARTSetFifoMode(UART2, UART_INTERRUPT_ON_RX_NOT_EMPTY);	// Only interrupt on RX non-empty
//	UARTSetLineControl(UART2, SCREEN_UART_LINE_CONTROL);
//	UARTSetDataRate(UART2, GetPeripheralClock(), baud);
//	UARTEnable(UART2, UART_ENABLE | UART_RX | UART_TX);
	unsigned int brg = (unsigned int)(((float) GetPeripheralClock() / ((float) 4 * (float) baud))- (float) 0.5);
	OpenUART2(UART_EN | UART_BRGH_FOUR | UART_NO_PAR_8BIT, UART_RX_ENABLE | UART_TX_ENABLE, brg);
	send_string_UART2("bkcmd=2");	// Configure screen to return data only on failure
	
	return initialize_DMA_UART2();
}

void send_string_UART2(char* string) {
	while (*string) {
		while (send_byte_UART2(*string) == ERROR) {}	// Try and send byte until successful
		string++;
	}
}

/*
 *	Summary
 *		Function that parses the contents of screen_rx_buffer if the received flag has been
 *		set by the DMA ISR.
 *	Parameters
 *		None.
 *	Returns
 *		None.
 */
void parse_screen_response(void) {
	unsigned int page_number = 0, component_id = 0, event = 0, x_coord = 0, y_coord = 0, numeric_data = 0;
	unsigned int x_msb = 0, x_lsb = 0, y_msb = 0, y_lsb = 0, num_b0 = 0, num_b1 = 0, num_b2 = 0, num_b3 = 0;
	char received_string[RECEIVED_BUFFER_SIZE] = {'\0'};

	// Only parse the buffer if 
	if (received_flag == COMMAND_RECEIVED) {
		// Need to check this FIRST because it has a non-unique first byte and doesn't work in switch-case
		if (!strcmp(screen_rx_buffer, SCREEN_STARTUP)) {
			// Screen has started or was reset
		}
		else {
			switch (screen_rx_buffer[0]) {
				case INVALID_INSTRUCTION:			break;
				case INSTRUCTION_SUCCESS:			break;
				case INVALID_COMPONENT_ID:			break;
				case INVALID_PAGE_ID:				break;
				case INVALID_PICTURE_ID:			break;
				case INVALID_FONT_ID:				break;
				case INVALID_FILE_OPERATION:		break;
				case INVALID_CRC:					break;
				case INVALID_BAUD:					break;
				case INVALID_WAVEFORM_ID_CHN:		break;
				case INVALID_VAR_NAME_OR_ATTR:		break;
				case INVALID_VARIABLE_OPERATION:	break;
				case ASSIGNMENT_FAILED:				break;
				case EEPROM_OPERATION_FAILED:		break;
				case INVALID_PARAM_QUANTITY:		break;
				case IO_OPERATION_FAILED:			break;
				case ESCAPE_CHAR_INVALID:			break;
				case VARIABLE_NAME_TOO_LONG:		break;
				case SERIAL_BUFFER_OVERFLOW:		break;
				case TOUCH_EVENT:
					sscanf(screen_rx_buffer, "%d%d%d", &page_number, &component_id, &event);
					break;
				case CURRENT_PAGE_NUMBER:
					sscanf(screen_rx_buffer, "%d", &page_number);
					break;
				case TOUCH_COORDINATE_AWAKE:
				case TOUCH_COORDINATE_SLEEP:
					sscanf(screen_rx_buffer, "%d%d%d%d%d", &x_msb, &x_lsb, &y_msb, &y_lsb, &event);
					x_coord = (x_msb << 8) | x_lsb;
					y_coord = (y_msb << 8) | y_lsb;
					break;
				case STRING_DATA_ENCLOSED:
					sscanf(screen_rx_buffer, "%s", received_string);
					break;
				case NUMERIC_DATA_ENCLOSED:
					sscanf(screen_rx_buffer, "%d%d%d%d", &num_b0, &num_b1, &num_b2, &num_b3);
					numeric_data = num_b0 + (num_b1 << 8) + (num_b2 << 16) + (num_b3 << 24);
					break;
				case AUTO_ENTERED_SLEEP_MODE:		break;
				case AUTO_WAKE_FROM_SLEEP:			break;
				case SCREEN_READY:					break;
				case STARTED_MICROSD_UPGRADE:		break;
				case TRANSPARENT_DATA_FINISHED:		break;
				case TRANSPARENT_DATA_READY:		break;
			}
		}
	}
}

/* --------------------------------- Private Functions ---------------------------------- */

/*
 *	Summary
 *		Private function to initialize the DMA for UART2RX events. This triggers transfers
 *		from U2RXREG to private_DMA_buffer on reception of COMMAND_END_CHARACTER. The 
 *		associated DMA interrupt is IPL3-0.
 *	Parameters
 *		None.
 *	Returns
 *		Unsigned int that is ERROR or NO_ERROR if the initialization was successful.
 */
static unsigned int initialize_DMA_UART2(void) {
	INTClearFlag(INT_SOURCE_DMA(DMA_channel));					// Clear any standing DMA interrupts
	DmaChnOpen(DMA_channel, DMA_CHN_PRI2, DMA_OPEN_MATCH);
	DmaChnSetMatchPattern(DMA_channel, COMMAND_END_CHARACTER);	// Set null as ending character
	
	// Configure the event that starts DMA transfers - RX interrupt 
	DmaChnSetEventControl(DMA_channel, DMA_EV_START_IRQ_EN | DMA_EV_MATCH_EN | DMA_EV_START_IRQ(_UART2_RX_IRQ));
	DmaChnSetTxfer(DMA_channel, (void*)&U2RXREG, private_DMA_buffer, 1, DMA_BUFFER_SIZE, 1);
	
	// Enable the transfer done interrupt on pattern match for all characters transferred
	DmaChnSetEvEnableFlags(DMA_channel, DMA_EV_BLOCK_DONE);	// Transfer done interrupt on pattern match or all chars transferred
	INTEnable(INT_SOURCE_DMA(DMA_channel), INT_ENABLED);
	INTSetVectorPriority(INT_VECTOR_DMA(DMA_channel), INT_PRIORITY_LEVEL_3);	// Set INT priority
	INTSetVectorSubPriority(INT_VECTOR_DMA(DMA_channel), INT_SUB_PRIORITY_LEVEL_0);	// Set sub-priority
	INTEnable(INT_SOURCE_DMA(DMA_channel), INT_ENABLED);
	
	// Enable the DMA channel now that it's been configured
	DmaChnEnable(DMA_channel);
	
	return NO_ERROR;
}

/*
 *	Summary
 *		Private function to restart the DMA channel once an event has been acknowledged.
 *	Parameters
 *		None.
 *	Returns
 *		None.
 */
static inline void restart_DMA_transfer(void) {
	DmaChnSetTxfer(DMA_channel, (void*)&U2RXREG, private_DMA_buffer, 1, DMA_BUFFER_SIZE, 1);
	DmaChnEnable(DMA_channel);
}

/*
 *	Summary
 *		Private function to send a single byte out via the UART2 RX register.
 *	Parameters
 *		data[in]: What character to put in U2TX register.
 *	Returns
 *		Unsigned int that is ERROR or NO_ERROR if the byte was sent successfully.
 */
static unsigned int send_byte_UART2(BYTE data) {
	if (UARTTransmitterIsReady(UART2)) {
		UARTSendDataByte(UART2, data);

		return NO_ERROR;
	}
	
	return ERROR;
}

/* ----------------------------- Interrupt Service Routines ----------------------------- */

/*
 *	Summary
 *		Interrupt Service Routine for a completed DMA channel event. In particular, when
 *		COMMAND_END_CHARACTER is detected in the UART2RX register. This places the contents
 *		of the in-use private_DMA_buffer into the public-facing screen_rx_buffer array. The
 *		DMA transfer is then restarted right away.
 *	Parameters
 *		None.
 *	Returns
 *		None.
 */
void __ISR(_DMA1_VECTOR, IPL3SOFT) isr_DMA_handler(void) {
	if (DmaChnGetEvFlags(DMA_channel) & DMA_EV_ALL_EVNTS) {
		clear_buffer(screen_rx_buffer, DMA_BUFFER_SIZE);		// Clear old contents in public buffer
		strcpy(screen_rx_buffer, private_DMA_buffer);			// Transfer contents
		clear_buffer(private_DMA_buffer, DMA_BUFFER_SIZE);	// Clear old contents in private buffer
		restart_DMA_transfer();								// A valid event means the DMA must be re-enabled

		received_flag = COMMAND_RECEIVED;					// Set the received flag
	}

	INTClearFlag(INT_SOURCE_DMA(DMA_channel));
}