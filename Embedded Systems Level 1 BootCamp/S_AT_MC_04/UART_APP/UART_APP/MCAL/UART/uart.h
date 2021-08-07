/*
* uart.h
*
* Created: 7/13/2021 8:58:24 PM
*  Author: Marco
*/


#ifndef UART_H_
#define UART_H_

/******************************************************************************
*                              Includes													*
*******************************************************************************/
#include "../../Infrastructure/registers.h"
#include "../../Infrastructure/uart_registers.h"
#include "../../Infrastructure/utils.h"
#include "uartRetval.h"

/******************************************************************************
*                              CONSTANTS													*
*******************************************************************************/
#define F_CPU 1000000UL
#define UART_BAUD		  1200
#define MAX_BAUD_RATE  4095
#define NOT_INIT                          (uint8_t)(0)
#define INIT                              (uint8_t)(1)
#define STRING_START                      (uint8_t)(0)
#define STRING_END								(uint8_t)('\0')
#define NEW_LINE									(uint8_t)('\r')
#define BACKSPACE									(uint8_t)('\b')
#define STRING_MAX_CHAR                   (uint8_t)(200)
/******************************************************************************
*                                     typedef enum                            *
*******************************************************************************/
typedef enum
{
	UART_NORMAL_SPEED =	(0<<1),
	UART_DOUBLE_SPEED =	(1<<1)
} EN_UART_SPEED_MODE_t;

typedef enum
{
	UART_TRANSMIT_DISABLE	 =	  (0<<3),
	UART_TRANSMIT_ENABLE		 =	  (1<<3)
} EN_UART_TRANSMIT_t;

typedef enum
{
	UART_RECIEVE_DISABLE		 =	  (0<<4),
	UART_RECIEVE_ENABLE	    =	  (1<<4)
} EN_UART_RECIEVE_t;

typedef enum
{
	UART_5_Bit_CHAR,
	UART_6_Bit_CHAR,
	UART_7_Bit_CHAR,
	UART_8_Bit_CHAR,
	UART_9_Bit_CHAR
} EN_UART_CHAR_BITS_t;

/* UPMn: Parity Mode [n = 1:0]*/
typedef enum
{
	UART_1_STOP_BIT		 =	  (0<<3),
	UART_2_STOP_BIT		 =	  (1<<3)
} EN_UART_STOP_BIT_t;

typedef enum
{
	UART_NO_PARITY		 =	  (0<<4),
	UART_EVEN_PARITY	 =	  (2<<4),
	UART_ODD_PARITY 	 =	  (3<<4)
} EN_UART_PARITY_MODE_t;

typedef enum
{
	UART_TRANSMITER_INT_DISABLE   =	(0<<6),
	UART_TRANSMITER_INT_ENABLE 	=  (1<<6)
} EN_UART_TRANSMITER_INT_t;

typedef enum
{
	UART_RECIEVER_INT_DISABLE 	   =	(0<<7),
	UART_RECIEVER_INT_ENABLE 	   =	(1<<7)
} EN_UART_RECIEVE_INT_t;


/******************************************************************************
*                               STRUCTS AND UNIONS                            *
*******************************************************************************/
typedef struct
{
	EN_UART_SPEED_MODE_t		 SPEED_MODE;
	uint32_t						 BAUD_RATE;
	EN_UART_TRANSMIT_t		 TRANSMIT;
	EN_UART_RECIEVE_t			 RECIEVE;
	EN_UART_CHAR_BITS_t		 CHAR_BITS ;
	EN_UART_PARITY_MODE_t	 PARITY_MODE;
	EN_UART_STOP_BIT_t		 STOP_BIT;
	EN_UART_TRANSMITER_INT_t TRANSMITER_INT;
	EN_UART_RECIEVE_INT_t	 RECIEVE_INT;
} ST_UART_CONFIG_t;
/******************************************************************************
*                               FUNCTION DECLARATIONS                         *
*******************************************************************************/
UART_STATUS_t UART_Init(ST_UART_CONFIG_t config);
UART_STATUS_t UART_TransmitChar(uint16_t data);
UART_STATUS_t UART_TransmitString(uint8_t *data);
UART_STATUS_t UART_RecieveChar(uint16_t * data);
UART_STATUS_t UART_RecieveString(uint8_t * data);

#endif /* UART_H_ */