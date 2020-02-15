/**
 *	File
 *		screen_uart.h
 *	Summary
 *		UART interface to the screen header file.
 *	Author(s)
 *		Collin Heist
 */

#define _SUPPRESS_PLIB_WARNING

#ifndef __SCREEN_H__
	#define __SCREEN_H__

	// Operational Configurations
    #define DMA_BUFFER_SIZE             (256)

    #define SCREEN_UART_DATA_SIZE       (UART_DATA_SIZE_8_BITS) // 8 data bits
    #define SCREEN_UART_PARITY          (UART_PARITY_NONE)      // No parity
    #define SCREEN_UART_STOP_BITS       (UART_STOP_BITS_1)      // 1 stop bit
    #define SCREEN_UART_LINE_CONTROL    (SCREEN_UART_DATA_SIZE | SCREEN_UART_PARITY | SCREEN_UART_STOP_BITS)

	// Function Prototypes
	unsigned int initialize_screen(unsigned int baud);
    void send_string_UART2(char* string);
    void send_byte_UART2(BYTE data);
    static unsigned int initialize_DMA_UART2(void);
    static void restartDMATransfer(void);
#endif