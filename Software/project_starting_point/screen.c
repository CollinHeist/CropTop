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
#include "temp_humidity.h"
#include "potentiometer.h"

/* -------------------------- Global Variables and Structures --------------------------- */

static const DmaChannel DMA_channel = DMA_CHANNEL1;	// Active DMA Channel
static unsigned int current_baud;					// Latest BAUD setting for UART2
static volatile unsigned int received_flag;			// Flag for if a response has been acknowledged
static char screen_rx_buffer[RX_BUFFER_SIZE];		// User-facing screen buffer - utilized to avoid conflict with DMA

/* ---------------------------------- Public Functions ---------------------------------- */

/*
 *	Summary
 *		Function to initialize the screen - primarily UART2 to a desired baud. Also configures
 *		U2RX interrupt to be 4-1. Then sends all initialization messages to screen.
 *	Parameters
 *		baud[in]: Unsigned integer that is the desired baud rate of UART2.
 *	Returns
 *		Unsigned integer that is ERROR or NO_ERROR if initialization was successful.
 */
unsigned int initialize_screen(const unsigned int baud) {
	unsigned int brg = (unsigned int)(((float) GetPeripheralClock() / ((float) 4 * (float) baud))- (float) 0.5);
	OpenUART2(UART_EN | UART_BRGH_FOUR | UART_NO_PAR_8BIT, UART_RX_ENABLE | UART_TX_ENABLE | UART_INT_RX_CHAR, brg);
	mU2RXIntEnable(1);
	mU2SetIntPriority(4);
	mU2SetIntSubPriority(1);

	send_string_UART2(INIT1_RESPOND_FAILURE_ONLY);
	current_baud = baud;
	
	return NO_ERROR;
}

/*
 *	Summary
 *		Function to send a string out over UART2 (to the screen).
 *	Parameters
 *		string[in]: Character pointer that points to the first character of a null-terminated string.
 *	Returns
 *		None.
 */
void send_string_UART2(const char* string) {
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
	// Variables for parsing screen messages
	unsigned int page_number = 0, component_id = 0, event = 0, x_coord = 0, y_coord = 0, numeric_data = 0;
	unsigned int x_msb = 0, x_lsb = 0, y_msb = 0, y_lsb = 0, num_b0 = 0, num_b1 = 0, num_b2 = 0, num_b3 = 0;
	char received_string[RX_BUFFER_SIZE] = {'\0'};
	
	if (UART2GetErrors()) { UART2ClearAllErrors(); } 

	// Only parse the buffer if 
	if (received_flag == COMMAND_RECEIVED) {
		// Need to check this FIRST because it has a non-unique first byte and doesn't work in switch-case
		if (!strcmp(screen_rx_buffer, SCREEN_STARTUP)) {
			// Screen has started or was reset
		}
		else {
			// Buffer-parsing will ignore the first character in screen_rx_buffer
			switch (screen_rx_buffer[0]) {
				case INVALID_INSTRUCTION:			break;
				case INSTRUCTION_SUCCESS:			break;
				case INVALID_COMPONENT_ID:			break;
				case INVALID_PAGE_ID:				break;
				case INVALID_PICTURE_ID:			break;
				case INVALID_FONT_ID:				break;
				case INVALID_FILE_OPERATION:		break;
				case INVALID_CRC:					break;
				case INVALID_BAUD:
					snprintf(received_string, RX_BUFFER_SIZE, "baud=%u\xFF\xFF\xFF", current_baud);
					send_string_UART2(received_string);
					initialize_screen(current_baud);
					break;
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
					sscanf(screen_rx_buffer + 1, "%d%d%d", &page_number, &component_id, &event);
					break;
				case CURRENT_PAGE_NUMBER:
					sscanf(screen_rx_buffer + 1, "%d", &page_number);
					break;
				case TOUCH_COORDINATE_AWAKE:
					sscanf(screen_rx_buffer + 1, "%d%d%d%d%d", &x_msb, &x_lsb, &y_msb, &y_lsb, &event);
					x_coord = (x_msb << 8) | x_lsb;
					y_coord = (y_msb << 8) | y_lsb;
					break;
				case TOUCH_COORDINATE_SLEEP:
					awake_screen();
					break;
				case STRING_DATA_ENCLOSED:
					sscanf(screen_rx_buffer + 1, "%s", received_string);
					parse_string_data(received_string);
					break;
				case NUMERIC_DATA_ENCLOSED:
					sscanf(screen_rx_buffer + 1, "%d%d%d%d", &num_b0, &num_b1, &num_b2, &num_b3);
					numeric_data = num_b0 + (num_b1 << 8) + (num_b2 << 16) + (num_b3 << 24);
					break;
				case AUTO_ENTERED_SLEEP_MODE:		break;
				case AUTO_WAKE_FROM_SLEEP:			break;
				case SCREEN_READY:					break;
				case STARTED_MICROSD_UPGRADE:		break;
				case TRANSPARENT_DATA_FINISHED:		break;
				case TRANSPARENT_DATA_READY:		break;
				default:							break;
			}
		}
		
		received_flag = COMMAND_NOT_RECEIVED;	// Reset flag
	}
}


/* --------------------------------- Private Functions ---------------------------------- */

/*
 *	Summary
 *		Private function to send a single byte out via the UART2 RX register.
 *	Parameters
 *		data[in]: What character to put in U2TX register.
 *	Returns
 *		Unsigned integer that is ERROR or NO_ERROR if the byte was sent successfully.
 */
static inline unsigned int send_byte_UART2(const char data) {
	if (UARTTransmitterIsReady(UART2)) {
		UARTSendDataByte(UART2, data);

		return NO_ERROR;
	}
	
	return ERROR;
}

/*
 *	Summary
 *		Private function to wake the screen up from sleep mode.
 *	Parameters
 *		None.
 *	Returns
 *		None.
 */
static inline void awake_screen(void) {
	send_string_UART2("sleep=0\xFF\xFF\xFF");
}

/*
 *	Summary
 *		Private function to parse a string return (STRING_DATA_ENCLOSED). This is generic,
 *		and should parse all string return codes listed in the header file.
 *	Parameters
 *		buffer[in]: Character pointer to the first character in the string parsed from the 
 *			screen RX buffer.
 *	Returns
 *		None.
 */
static void parse_string_data(const char* buffer) {
	char send_buffer[TX_BUFFER_SIZE];
	clear_buffer(send_buffer, TX_BUFFER_SIZE);
	
	if (!strcmp(buffer, REFRESH_MAIN_MENU)) {
		// Create Temperature String
		snprintf(send_buffer, TX_BUFFER_SIZE, "tempText.txt=\"%6.2f %c\"\xFF\xFF\xFF", read_temperature(), get_temperature_mode());
		send_string_UART2(send_buffer);
		clear_buffer(send_buffer, TX_BUFFER_SIZE);
		
		// Create Humidity String
		snprintf(send_buffer, TX_BUFFER_SIZE, "humidityText.txt=\"%6.2f%%\"\xFF\xFF\xFF", read_humidity());
		send_string_UART2(send_buffer);
		clear_buffer(send_buffer, TX_BUFFER_SIZE);
		
		// Create GPS String
//		char gps_string[32];
//		clear_buffer(gps_string, 32);
//		read_GPS(gps_string, 32);
//		snprintf(send_buffer, TX_BUFFER_SIZE, "GPSText.txt=\"%s\"\xFF\xFF\xFF", gps_string);
//		send_string_UART2(send_buffer);
//		clear_buffer(send_buffer, TX_BUFFER_SIZE);
		
		// Create Time String
		
	}
	else if (!strcmp(buffer, REFRESH_LIVE_FEED)) {
		// Create Temperature String
		snprintf(send_buffer, TX_BUFFER_SIZE, "tempText.txt=\"%6.2f %c\"\xFF\xFF\xFF", read_temperature(), get_temperature_mode());
		send_string_UART2(send_buffer);
		clear_buffer(send_buffer, TX_BUFFER_SIZE);
		
		// Create Humidity String
		snprintf(send_buffer, TX_BUFFER_SIZE, "humidityText.txt=\"%6.2f%%\"\xFF\xFF\xFF", read_humidity());
		send_string_UART2(send_buffer);
		clear_buffer(send_buffer, TX_BUFFER_SIZE);
		
		// Create GPS String
//		char gps_string[32];
//		clear_buffer(gps_string, 32);
//		read_GPS(gps_string, 32);
//		snprintf(send_buffer, TX_BUFFER_SIZE, "GPSText.txt=\"%s\"\xFF\xFF\xFF", gps_string);
//		send_string_UART2(send_buffer);
//		clear_buffer(send_buffer, TX_BUFFER_SIZE);
		
		// Create Time String
		
		// Create X-Load String
		
		// Create Y-Load String
		
		// Create Potentiometer-Angle String
		
		// Create IMU-Angle String
		
		// Create CPU Time String
		snprintf(send_buffer, TX_BUFFER_SIZE, "timeText.txt=\"%u\"\xFF\xFF\xFF", ReadCoreTimer());
		send_string_UART2(send_buffer);
		clear_buffer(send_buffer, TX_BUFFER_SIZE);
	}
	else if (!strcmp(buffer, TEMPERATURE_MODE_C)) {	set_temperature_mode(CELSIUS_MODE);		}
	else if (!strcmp(buffer, TEMPERATURE_MODE_F)) {	set_temperature_mode(FAHRENHEIT_MODE);	}
	else if (!strcmp(buffer, ADC_MODE_NEWTONS))	{	set_potentiometer_mode(MODE_NEWTONS);	}
	else if (!strcmp(buffer, ADC_MODE_VOLTS)) { 	set_potentiometer_mode(MODE_VOLTS);		}
	else if (!strcmp(buffer, START_TEST)) {
		
	}
	else if (!strcmp(buffer, STOP_TEST)) {
		
	}
	else if (!strcmp(buffer, VIEW_FIRST_FOLDER)) {
		
	}
	else if (!strcmp(buffer, VIEW_NEXT_FOLDER)) {
		
	}
	else if (!strcmp(buffer, EXPORT_TO_USB)) {
		
	}
	else if (!strcmp(buffer, DELETE_TEST)) {
		
	}
	else {
		// Invalid parse string
	}
}

/* ----------------------------- Interrupt Service Routines ----------------------------- */

/*
 *	Summary
 *		Interrupt service routine for the UART2 vector. Handled when character is sent
 *		or received via the UART2 buffer. Stores character in private_DMA_buffer until
 *		COMMAND_END_CHARACTER ('\xFF') is detected - then received_flag is set.
 *	Parameters
 *		None.
 *	Returns
 *		None.
 */
void __ISR(_UART2_VECTOR, IPL4SOFT) isr_UART2_handler(void) {
	static unsigned int buffer_index = 0, received_real_char_flag = FALSE;
	static char isr_buffer[RX_BUFFER_SIZE];   // Temporary buffer

	if (mU2RXGetIntFlag()) {
		char c = ReadUART2();
		if ((c == COMMAND_END_CHARACTER) && (received_real_char_flag == TRUE)) {
			// If the terminating character was sent after a 'real' character was received (i.e. not just \xFF)
			clear_buffer(screen_rx_buffer, RX_BUFFER_SIZE);				// Clear public buffer
			copy_buffer(screen_rx_buffer, isr_buffer, RX_BUFFER_SIZE);	// Transfer contents
			clear_buffer(isr_buffer, RX_BUFFER_SIZE);					// Clear private buffer
			
			// Reset placement index, set received flag, and reset real character flag
			buffer_index = 0;
			received_real_char_flag = FALSE;
			received_flag = COMMAND_RECEIVED;
		}
		else if (c != COMMAND_END_CHARACTER) {
			// A real character has been received (i.e. not \xFF))
			isr_buffer[buffer_index++] = c;
			received_real_char_flag = TRUE;
		}
	}

	mU2ClearAllIntFlags();
}