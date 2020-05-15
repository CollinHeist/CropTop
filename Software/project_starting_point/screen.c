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
#include "accelerometer.h"
#include "GPS.h"
#include "RTC.h"
#include "potentiometer.h"
#include "temp_humidity.h"
#include "tests.h"

/* -------------------------- Global Variables and Structures --------------------------- */

static const DmaChannel DMA_channel = DMA_CHANNEL1;	// Active DMA Channel

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
	
	return NO_ERROR;
}

/*
 *	Summary
 *		Function to send a string to the screen.
 *	Parameters
 *		string[in]: Character pointer to the first character of the null-terminated
 *			string to send to the screen. 
 *	Returns
 *		None.
 *	Note
 *		This is a wrapper function to send_string_UART2, and so is technically useless.
 *		However, I think it's useful to obfuscate the UART2 detail from the user, instead
 *		specifying that the message will go to the screen (which is more useful).
 */
inline void send_string_to_screen(const char* string) {
	send_string_UART2(string);
}

/*
 *	Summary
 *		Function that parses the contents of screen_rx_buffer if the received flag has been
 *		set by the DMA ISR. This parses all different types of return codes from the screen,
 *		but does not specifically handle specific functionality (like user-defined screen
 *		messages, etc.). This function is the primary background screen 'loop', and should
 *		thus be called as often as possible.
 *	Parameters
 *		None.
 *	Returns
 *		None.
 *	Note
 *		Not all screen responses can be sent by our model of screen (specifically the 
 *		EEPROM  and CRC messages), but they're listed anyway.
 */
void parse_screen_response(void) {
	// Check for UART2 errors and clear them if they arise - prevents communication breakdown.
	int e = UART2GetErrors();	// Theoretically, a message should be sent to the user when errors occur.
	if (e)						// However, runtime is not affected (from what I've seen), and given that the screen
		UART2ClearAllErrors();	// only *displays* data (does not process it), the worst-case is a missed message.

	// Only parse the buffer if 
	if (received_flag == COMMAND_RECEIVED) {
		// Need to check this FIRST because it has a non-unique first byte and doesn't work in switch-case
		if (!strncmp(screen_rx_buffer, SCREEN_STARTUP, SCREEN_STARTUP_LENGTH)) {
			// Screen just started or was reset
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
					unsigned int page_number = 0, component_id = 0, event = 0;
					sscanf(screen_rx_buffer + 1, "%d%d%d", &page_number, &component_id, &event);		// Skip over first command character
					break;
				case CURRENT_PAGE_NUMBER:
					unsigned int page_number = 0;
					sscanf(screen_rx_buffer + 1, "%d", &page_number);								   // Skip over first command character
					break;
				case TOUCH_COORDINATE_AWAKE:
					unsigned int x_msb = 0, x_lsb = 0, y_msb = 0, y_lsb = 0, event = 0, x_coord = 0, y_coord = 0;
					sscanf(screen_rx_buffer + 1, "%d%d%d%d%d", &x_msb, &x_lsb, &y_msb, &y_lsb, &event); // Skip over first command character
					x_coord = (x_msb << 8) | x_lsb;
					y_coord = (y_msb << 8) | y_lsb;
					break;
				case TOUCH_COORDINATE_SLEEP:
					awake_screen();
					break;
				case STRING_DATA_ENCLOSED:
					char received_string[RX_BUFFER_SIZE] = {'\0'};
					sscanf(screen_rx_buffer + 1, "%s", received_string);								// Skip over first command character
					parse_string_data(received_string);
					break;
				case NUMERIC_DATA_ENCLOSED:
					unsigned int num_b0 = 0, num_b1 = 0, num_b2 = 0, num_b3 = 0, numeric_data = 0;
					sscanf(screen_rx_buffer + 1, "%d%d%d%d", &num_b0, &num_b1, &num_b2, &num_b3);	   // Skip over first command character
					numeric_data = (num_b3 << 24) + (num_b2 << 16) + (num_b1 << 8) + num_b0;
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
		
		received_flag = COMMAND_NOT_RECEIVED;	// Reset flag now that the message has been parsed
	}
}

/*
 *	Summary
 *		Function to alert the user when the internal PIC memory is full and it is
 *		time to export tests to the attached USB. Send the user to user_warnings page
 *		and sets the next_page to testing page.
 *	Parameters
 *		None.
 *	Returns
 *		None.
 *	Note
 *		This function is ideally only called when a test is saved and we then reach
 *		the end of the memory allocated for tests. To increase this memory, change
 *		MAX_NUMBER_TESTS within tests.h. This function assumes 'testing' is page 3.
 */
inline void alert_user_memory_full(void) {
	send_string_UART2("user_warnings.nextPage.val=3\xFF\xFF\xFF");	// Set the next page to 3 (testing)
	send_string_UART2("user_warnings.messageText=\"The device's internal test storage is full - please export to USB. Subsequent results will be ignored until memory is freed.\"\xFF\xFF\xFF");
	send_string_UART2("page user_warnings\xFF\xFF\xFF");
}

/*
 *	Summary
 *		Function to update the operating BAUD of the UART2 (screen) communication.
 *	Parameters
 *		baud[in]: Unsigned integer that represents the new desired baud rate.
 *	Returns
 *		None.
 */
inline void set_screen_baud(const unsigned int baud) {
	// Tell the screen to update its baud first
	char send_buffer[TX_BUFFER_SIZE];
	clear_buffer(send_buffer, TX_BUFFER_SIZE);
	snprintf(send_buffer, TX_BUFFER_SIZE, "baud=%u\xFF\xFF\xFF", baud);
	send_string_UART2(send_buffer);
	// Update the PIC32's UART2 operation
}

/* --------------------------------- Private Functions ---------------------------------- */

/*
 *	Summary
 *		Private function to send a string out over UART2 (to the screen).
 *	Parameters
 *		string[in]: Character pointer that points to the first character of a null-terminated string.
 *	Returns
 *		None.
 *	Note
 *		If communication errors are persistent enough, a timeout counter should be added to the
 *		send_byte_UART2 function call to avoid halting background operations.
 */
static void send_string_UART2(const char* string) {
	while (*string) {
		while (send_byte_UART2(*string) == ERROR) {}	// Try and send byte until successful
		string++;
	}
}

/*
 *	Summary
 *		Private function to send a single byte out via the UART2 RX register.
 *	Parameters
 *		data[in]: What character to put in U2TX register.
 *	Returns
 *		Unsigned integer that is ERROR or NO_ERROR if the byte was sent successfully.
 */
static unsigned int send_byte_UART2(const BYTE data) {
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
 *		Private function that parses all string data from the screen. These are primarily
 *		the "get" commands written into the GUI to communicate events between devices.
 *	Parameters
 *		buffer[in]: Pointer to the first character of the null-terminated string that contains
 *			the data that is to be parsed by this function. This should match one of the 
 *			definitions inside screen.h, as the buffer is compared to them to determine what
 *			action to take.
 *	Returns
 *		None.
 *	Note
 *		This is a very beefy function. I decided to not partition individual command processing
 *		into function calls because of the additional overhead. However, some processes do call
 *		external functions from various libraries (such as reading from sensors, updating settings,
 *		etc.).
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
		unsigned int hour = 0, minute = 0, month = 0, date = 0;
		get_datetime(&hour, &minute, &month, &date);
		snprintf(send_buffer, TX_BUFFER_SIZE, "timeText.txt=\"%u:%u %u/%u\"\xFF\xFF\xFF", hour, minute, month, date);
		send_string_UART2(send_buffer);
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
		unsigned int hour = 0, minute = 0, month = 0, date = 0;
		get_datetime(&hour, &minute, &month, &date);
		snprintf(send_buffer, TX_BUFFER_SIZE, "timeText.txt=\"%u:%u %u/%u\"\xFF\xFF\xFF", hour, minute, month, date);
		send_string_UART2(send_buffer);
		
		// Create X-Load String
		
		// Create Y-Load String
		
		// Create Potentiometer-Angle String
		
		// Create IMU-Angle String
		
		// Create CPU Time String
		snprintf(send_buffer, TX_BUFFER_SIZE, "timeText.txt=\"%u\"\xFF\xFF\xFF", ReadCoreTimer());
		send_string_UART2(send_buffer);
	}
	else if (!strncmp(buffer, SET_TEMP_MODE, SET_TEMP_MODE_LENGTH)) {
		// Update the current temperature mode
		char mode = '\0';
		sscanf(buffer + SET_TEMP_MODE_LENGTH + 1, "%c", &mode);  // Add 1 to account for space
		if (mode == 'C') { set_temperature_mode(CELSIUS_MODE);		}
		else			 { set_temperature_mode(FAHRENHEIT_MODE);	}
	}
	else if (!strncmp(buffer, SET_DATETIME, SET_DATETIME_LENGTH)) {
		// Update the datetime to the passed string
		unsigned int hour = 0, minute = 0, month = 0, date = 0;
		sscanf(buffer + SET_DATETIME_LENGTH + 1, "%u:%u %u/%u", &hour, &minute, &month, &date);
		adjust_datetime(hour, minute, month, date);
	}
	else if (!strncmp(buffer, SET_ADC_MODE, SET_ADC_MODE_LENGTH)) {
		// Update the current ADC mode
		char mode = '\0';
		sscanf(buffer + SET_ADC_MODE_LENGTH + 1, "%c", mode);	// Add 1 to account for space
		if (mode == 'N') { set_ADC_mode(ADC_MODE_NEWTONS);	}
		else			 { set_ADC_mode(ADC_MODE_VOLTS);	}
	}
	else if (!strncmp(buffer, BACKGROUND_COLOR, BACKGROUND_COLOR_LENGTH)) {
		// Update the global background color variable - Color is 565-bit encoding
		unsigned int red = 0, green = 0, blue = 0;
		sscanf(buffer + BACKGROUND_COLOR_LENGTH + 1, "%u %u %u", &red, &green, &blue);
		snprintf(send_buffer, TX_BUFFER_SIZE, "globalBG.val=%u\xFF\xFF\xFF", color_from_RGB(red, green, blue));
		send_string_UART2(send_buffer);
	}
	else if (!strncmp(buffer, BOX_COLOR, BOX_COLOR_LENGTH)) {
		// Update the global box color variable - Color is 565-bit encoding
		unsigned int red = 0, green = 0, blue = 0;
		sscanf(buffer + BOX_COLOR_LENGTH + 1, "%u %u %u", &red, &green, &blue);
		snprintf(send_buffer, TX_BUFFER_SIZE, "globalBox.val=%u\xFF\xFF\xFF", color_from_RGB(red, green, blue));
		send_string_UART2(send_buffer);
	}
	else if (!strncmp(buffer, FONT_COLOR, FONT_COLOR_LENGTH)) {
		// Update the global font color variable - Color is 565-bit encoding
		unsigned int red = 0, green = 0, blue = 0;
		sscanf(buffer + FONT_COLOR_LENGTH + 1, "%u %u %u", &red, &green, &blue);
		snprintf(send_buffer, TX_BUFFER_SIZE, "globalFont.val=%u\xFF\xFF\xFF", color_from_RGB(red, green, blue));
		send_string_UART2(send_buffer);
	}
	else if (!strcmp(buffer, START_TEST)) {
		// Start the test procedure
		if (check_if_memory_full() == IS_FULL) {	// Verify there is room in memory for the test
			alert_user_memory_full();				// Send the user a warning and do not start the test
		}
		else {
			// Start the test if memory is available
			
		}
	}
	else if (!strcmp(buffer, STOP_TEST)) {
		// Stop the test procedure
	}
	else if (!strncmp(buffer, SAVE_TEST, SAVE_TEST_LENGTH)) {
		// Save the previously run test - parse the passed test information
		Test current_test = parse_test_information(buffer + SAVE_TEST_LENGTH + 1);
		save_test(current_test);
	}
	else if (!strcmp(buffer, VIEW_FIRST_FOLDER)) {
		
	}
	else if (!strcmp(buffer, VIEW_NEXT_FOLDER)) {
		
	}
	else if (!strcmp(buffer, EXPORT_TO_USB)) {
		
	}
	else if (!strcmp(buffer, DELETE_TEST)) {
		// Delete the data taken for the current test
		delete_current_test_data();
	}
	else {
		// Invalid parse string
	}
}

/*
 *	Summary
 *		Helper function to get the final 565 color code for GUI objects from separated RGB
 *		color channels. Bit formatting is 0bRRRRRGGGGGGBBBBB (hence 565).
 *	Parameters
 *		red[in]: Unsigned integer that represents the red channel. Should be limited to 5-bits.
 *		green[in]: Unsigned integer that represents the green channel. Should be limited to 6-bits.
 *		blue[in]: Unsigned integer that represents the blue channel. Should be limited to 5-bits.
 *	Returns
 *		Unsigned integer that is the full 565-bit color to be sent to the Nextion GUI.
 */
static inline unsigned int color_from_RGB(const unsigned int red, const unsigned int green, const unsigned int blue) {
	return (red << 11) + (green << 5) + blue;
}

/* ----------------------------- Interrupt Service Routines ----------------------------- */

/*
 *	Summary
 *		Interrupt service routine for the UART2 vector. Handled when character is sent
 *		or received via the UART2 buffer. Stores character in the private isr_buffer
 *		until COMMAND_END_CHARACTER ('\xFF') is detected - then received_flag is set and
 *		the contents of isr_buffer are copied into the public-facing screen_rx_buffer.
 *	Parameters
 *		None.
 *	Returns
 *		None.
 */
void __ISR(_UART2_VECTOR, IPL4SOFT) isr_UART2_handler(void) {
	static unsigned int buffer_index = 0, received_real_char_flag = FALSE;
	static char isr_buffer[RX_BUFFER_SIZE];	// Temporary buffer

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