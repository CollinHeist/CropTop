/**
 *	File
 *		screen_uart.h
 *	Summary
 *		UART interface to the screen header file. Provides definition for the screen UART interface,
 *		return codes from Nextion devices, as well as GUI-configured commands.
 *	Author(s)
 *		Collin Heist
 */

#ifndef __SCREEN_H__
	#define __SCREEN_H__

	// Operational Configurations
	#define RX_BUFFER_SIZE				(128)	// Maximum number of characters sent by the screen in any one message
	#define TX_BUFFER_SIZE				(48)	// Maximum number of characters sent to the screen in any one message

	#define SCREEN_UART_DATA_SIZE		(UART_DATA_SIZE_8_BITS)	// 8 data bits
	#define SCREEN_UART_PARITY			(UART_PARITY_NONE)		// No parity
	#define SCREEN_UART_STOP_BITS		(UART_STOP_BITS_1)		// 1 stop bit
	#define SCREEN_UART_LINE_CONTROL	(SCREEN_UART_DATA_SIZE | SCREEN_UART_PARITY | SCREEN_UART_STOP_BITS)

	// GUI-Based String Data - these are sent with "get" command within Nextion screen
		// Length of some commands is specified to properly compute strncmp()
	#define REFRESH_MAIN_MENU			("refresh_main_menu")
	#define REFRESH_LIVE_FEED			("refresh_live_feed")
	#define SET_TEMP_MODE				("temperature_mode")
		#define SET_TEMP_MODE_LENGTH	(16)
	#define SET_DATETIME				("set_datetime")
		#define SET_DATETIME_LENGTH		(12)
	#define SET_ADC_MODE				("adc_mode")
		#define SET_ADC_MODE_LENGTH		(8)
	#define BACKGROUND_COLOR			("bg_color")
		#define BACKGROUND_COLOR_LENGTH	(8)
	#define BOX_COLOR					("box_color")
		#define BOX_COLOR_LENGTH		(9)
	#define FONT_COLOR					("font_color")
		#define FONT_COLOR_LENGTH		(10)
	#define START_TEST					("start_test")
	#define STOP_TEST					("stop_test")
	#define SAVE_TEST					("save_test")
		#define SAVE_TEST_LENGTH		(9)
	#define VIEW_FIRST_FOLDER			("view_first_folder")
	#define VIEW_NEXT_FOLDER			("view_next_folder")
	#define EXPORT_TO_USB				("export_to_usb")
	#define DELETE_TEST					("delete_test")

	// Initialization Commands
	#define INIT1_RESPOND_FAILURE_ONLY	("bkcmd=2\xFF\xFF\xFF")	 // Only respond to commands when they've failed - reduces CPU parsing

	// Useful macros and default end character
	#define COMMAND_RECEIVED			(1)
	#define COMMAND_NOT_RECEIVED		(0)
	#define COMMAND_END_CHARACTER		('\xFF')

	// Return Codes - all of these are from https://nextion.tech/instruction-set/
		// These ones are affected by 'bkcmd' command which sets level of return data
	#define INVALID_INSTRUCTION			('\x00')
	#define INSTRUCTION_SUCCESS			('\x01')
	#define INVALID_COMPONENT_ID		('\x02')
	#define INVALID_PAGE_ID				('\x03')
	#define INVALID_PICTURE_ID			('\x04')
	#define INVALID_FONT_ID				('\x05')
	#define INVALID_FILE_OPERATION		('\x06')
	#define INVALID_CRC					('\x09')
	#define INVALID_BAUD				('\x11')
	#define INVALID_WAVEFORM_ID_CHN		('\x12')
	#define INVALID_VAR_NAME_OR_ATTR	('\x1A')
	#define INVALID_VARIABLE_OPERATION	('\x1B')
	#define ASSIGNMENT_FAILED			('\x1C')
	#define EEPROM_OPERATION_FAILED		('\x1D')
	#define INVALID_PARAM_QUANTITY		('\x1E')
	#define IO_OPERATION_FAILED			('\x1F')
	#define ESCAPE_CHAR_INVALID			('\x20')
	#define VARIABLE_NAME_TOO_LONG		('\x23')
		// These codes are NOT affected by 'bkcmd' command
	#define SCREEN_STARTUP				("\x00\x00\x00")
		#define SCREEN_STARTUP_LENGTH	(3)
	#define SERIAL_BUFFER_OVERFLOW		('\x24')
	#define TOUCH_EVENT					('\x65')	// Data event
		#define PRESS					(1)
		#define RELEASE					(0)
	#define CURRENT_PAGE_NUMBER			('\x66')	// Data event
	#define TOUCH_COORDINATE_AWAKE		('\x67')	// Data event
	#define TOUCH_COORDINATE_SLEEP		('\x68')	// Data event
	#define STRING_DATA_ENCLOSED		('\x70')	// Data event
	#define NUMERIC_DATA_ENCLOSED		('\x71')	// Data event
	#define AUTO_ENTERED_SLEEP_MODE		('\x86')
	#define AUTO_WAKE_FROM_SLEEP		('\x87')
	#define SCREEN_READY				('\x88')
	#define STARTED_MICROSD_UPGRADE		('\x89')
	#define TRANSPARENT_DATA_FINISHED	('\xFD')
	#define TRANSPARENT_DATA_READY		('\xFE')

	// Function Prototypes
	unsigned int initialize_screen(const unsigned int baud);
	inline void send_string_to_screen(const char* string);
	void parse_screen_response(void);
	inline void alert_user_memory_full(void);
	static unsigned int send_byte_UART2(const BYTE data);
	static void send_string_UART2(const char* string);
	static inline void awake_screen(void);
	static void parse_string_data(const char* buffer);
	static inline unsigned int color_from_RGB(const unsigned int red, const unsigned int green, const unsigned int blue);
#endif