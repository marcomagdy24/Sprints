/*
 * uart_registers.h
 *
 * Created: 7/13/2021 10:44:35 PM
 *  Author: Marco
 */ 


#ifndef SPI_REGISTERS_H_
#define SPI_REGISTERS_H_

/******************************************************************************
*                              Includes			                          *
*******************************************************************************/
#include "types.h"

/*------------------------------ SPI REGISTERS ------------------------------*/
/* SPI Control Register*/
/*
SPI2X SPR1 SPR0	 SCK Frequency
  0	 0		0			F_CPU/4
  0	 0		1			F_CPU/16
  0	 1		0			F_CPU/64
  0	 1		1			F_CPU/128
  1	 0		0			F_CPU/2
  1	 0		1			F_CPU/8
  1	 1		0			F_CPU/32
  1	 1		1			F_CPU/64
*/
#define SPCR		  *((volatile uint8_t*) (0x2D))

#define SPR0  (uint8_t) 0   // SPI Clock Rate Select [n = 1:0]
#define SPR1  (uint8_t) 1   // SPI Clock Rate Select [n = 1:0]
#define CPHA  (uint8_t) 2   // Clock Phase
#define CPOL  (uint8_t) 3   // Clock Polarity
#define MSTR  (uint8_t) 4   // Master/Slave Select
#define DORD  (uint8_t) 5   // Data Order
#define SPE   (uint8_t) 6   // SPI Enable
#define SPIE  (uint8_t) 7   // SPI Interrupt Enable


/* SPI Status Register*/
#define SPSR		  *((volatile uint8_t*) (0x2E))

#define SPI2X (uint8_t) 0   // SPI2X: Double SPI Speed Bit
#define WCOL  (uint8_t) 6   // Write Collision Flag
#define SPIF  (uint8_t) 7   // SPI Interrupt Flag


/* SPI Data Register is a read/write register*/
#define SPDR		  *((volatile uint8_t*) (0x2F))


#endif /* SPI_REGISTERS_H_ */