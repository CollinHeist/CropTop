/**
 *	File
 *		screen_uart.h
 *	Summary
 *		UART interface to the screen header file.
 *	Author(s)
 *		Collin Heist
 */

#ifndef __SCREEN_H__
	#define __SCREEN_H__

	// Operational Configurations
    #define DMA_BUFFER_SIZE             (32)
	#define RECEIVED_BUFFER_SIZE		(32)

    #define SCREEN_UART_DATA_SIZE       (UART_DATA_SIZE_8_BITS) // 8 data bits
    #define SCREEN_UART_PARITY          (UART_PARITY_NONE)      // No parity
    #define SCREEN_UART_STOP_BITS       (UART_STOP_BITS_1)      // 1 stop bit
    #define SCREEN_UART_LINE_CONTROL    (SCREEN_UART_DATA_SIZE | SCREEN_UART_PARITY | SCREEN_UART_STOP_BITS)

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
	unsigned int initialize_screen(unsigned int baud);
    void send_string_UART2(char* string);
    static unsigned int send_byte_UART2(BYTE data);
    static unsigned int initialize_DMA_UART2(void);
    static inline void restart_DMA_transfer(void);
#endif