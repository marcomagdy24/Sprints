/*
 * uart_registers.h
 *
 * Created: 7/13/2021 10:44:35 PM
 *  Author: Marco
 */ 


#ifndef UART_REGISTERS_H_
#define UART_REGISTERS_H_

/******************************************************************************
*                              Includes			                          *
*******************************************************************************/
#include "types.h"

/*------------------------------ UART REGISTERS ------------------------------*/
/* UART Transmit / Receive Data Buffer*/
#define UDR			  *((volatile uint8_t*) (0x2C))

/* UART Control and Status Register A*/
#define UCSRA		  *((volatile uint8_t*) (0x2B))

#define MPCM  (uint8_t) 0   // Multi-processor Communication Mode
#define U2X	  (uint8_t) 1   // Double the UART Transmission Speed
#define PE    (uint8_t) 2   // Parity Error
#define DOR   (uint8_t) 3   // Data OverRun
#define FE    (uint8_t) 4   // Frame Error
#define UDRE  (uint8_t) 5   // UART Data Register Empty
#define TXC   (uint8_t) 6   // UART Transmit Complete
#define RXC   (uint8_t) 7   // UART Receive Complete

/* UART Control and Status Register B*/
#define UCSRB		  *((volatile uint8_t*) (0x2A))

#define TXB8  (uint8_t) 0   // Transmit Data Bit 8
#define RXB8  (uint8_t) 1   // Receive Data Bit 8
#define UCSZ2 (uint8_t) 2   // Character Size
#define TXEN  (uint8_t) 3   // Transmitter Enable
#define RXEN  (uint8_t) 4   // Receiver Enable
#define UDRIE (uint8_t) 5   // UART Data Register Empty Interrupt Enable
#define TXCIE (uint8_t) 6   // TX Complete Interrupt Enable
#define RXCIE (uint8_t) 7   // RX Complete Interrupt Enable

/* UART Control and Status Register C*/
/*
UPM1 UPM0 ParityMode
0		0	 Disabled
0		1	 Reserved
1		0	 Enabled, Even Parity
1		1	 Enabled, Odd Parity

UCSZ2 UCSZ1 UCSZ0 Character Size
0		0		0			5-bit
0		0		1			6-bit
0		1		0			7-bit
0		1		1			8-bit
1		0		0			Reserved
1		0		1			Reserved
1		1		0			Reserved
1		1		1			9-bit
*/
#define UCSRC		  *((volatile uint8_t*) (0x40))

#define UCPOL (uint8_t) 0   // Transmit Data Bit 8
#define UCSZ0 (uint8_t) 1   // Receive Data Bit 8
#define UCSZ1 (uint8_t) 2   // Character Size
#define USBS  (uint8_t) 3   // Transmitter Enable
#define UPM0  (uint8_t) 4   // UPMn: Parity Mode [n = 1:0]
#define UPM1  (uint8_t) 5   // UPMn: Parity Mode [n = 1:0]
#define UMSEL (uint8_t) 6   // Mode Select
#define URSEL (uint8_t) 7   // Register Select


/* UART Baud Rate Register Low*/
#define UBRRL  *((volatile uint8_t*) (0x29))


/* UART Baud Rate Register High*/
#define UBRRH  *((volatile uint8_t*) (0x40))

#define UBRR0 (uint8_t) 0   // UBRR[3:0]: UART Baud Rate Register [n = 11:8]
#define UBRR1 (uint8_t) 1   // UBRR[3:0]: UART Baud Rate Register [n = 11:8]
#define UBRR2 (uint8_t) 2   // UBRR[3:0]: UART Baud Rate Register [n = 11:8]
#define UBRR3 (uint8_t) 3   // UBRR[3:0]: UART Baud Rate Register [n = 11:8]
#define URSEL (uint8_t) 7   // Transmitter Enable



#endif /* UART_REGISTERS_H_ */