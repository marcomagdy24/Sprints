/*
* uart.c
*
* Created: 7/13/2021 8:58:32 PM
*  Author: Marco
*/

/******************************************************************************
*                              Includes													*
*******************************************************************************/
#include "uart.h"

/******************************************************************************
*                         GLOBAL STATIC VARIABLES										*
*******************************************************************************/
static ST_UART_CONFIG_t g_ST_UART_CONFIG_t;
static uint8_t g_u8_UART_init = NOT_INIT;
/******************************************************************************
*                         LOCAL FUNCTION IMPLEMENTATION								*
*******************************************************************************/

void char_bits(uint8_t bits_no)
{
	switch (bits_no){
		case (UART_9_Bit_CHAR) :
		{
			SET_BIT(UCSRC, URSEL);
			UCSRC |= ((uint8_t)(UART_8_Bit_CHAR) << 1);
			SET_BIT(UCSRB, UCSZ2);
		}
		default:
		{
			SET_BIT(UCSRC, URSEL);
			UCSRC |= (bits_no << 1);
		}
	}
}

/******************************************************************************
*                         APIS IMPLEMENTATION											*
*******************************************************************************/
UART_STATUS UART_Init(ST_UART_CONFIG_t config)
{
	g_ST_UART_CONFIG_t = config;
	uint32_t UBRR_VAL;
	/************** Check Baud rate and Speed mode **************/
	if ((g_ST_UART_CONFIG_t.BAUD_RATE >= 0) && (g_ST_UART_CONFIG_t.BAUD_RATE <= MAX_BAUD_RATE))
	{
		if(g_ST_UART_CONFIG_t.SPEED_MODE == UART_NORMAL_SPEED){
			UBRR_VAL = (uint32_t) ((F_CPU/(16*g_ST_UART_CONFIG_t.BAUD_RATE))-1);
		}
		else if(g_ST_UART_CONFIG_t.SPEED_MODE == UART_DOUBLE_SPEED)
		{
			SET_BIT(UCSRA, U2X);
			UBRR_VAL = (uint16_t) ((F_CPU/(8*g_ST_UART_CONFIG_t.BAUD_RATE))-1);
		}
		else{
			return UART_ERROR_NOT_INITIALIZED;
		}
	}
	else
	{
		return UART_INVALID_BAUD_RATE;
	}
	UBRRH =(uint8_t) (UBRR_VAL >> 8);
	UBRRL = (uint8_t) UBRR_VAL;
	
	
	/************** Enable transmitter **************/
	if ((g_ST_UART_CONFIG_t.TRANSMIT == UART_TRANSMIT_ENABLE) || (g_ST_UART_CONFIG_t.TRANSMIT == UART_TRANSMIT_DISABLE))
	{
		UCSRB |= ((uint8_t)(g_ST_UART_CONFIG_t.TRANSMIT));
	}
	else
	{
		return UART_TRANSMIT_ERROR;
	}
	/************** Enable receiver **************/
	if ((g_ST_UART_CONFIG_t.RECIEVE == UART_RECIEVE_ENABLE) || (g_ST_UART_CONFIG_t.RECIEVE == UART_RECIEVE_DISABLE))
	{
		UCSRB |= ((uint8_t)(g_ST_UART_CONFIG_t.RECIEVE));
	}
	else
	{
		return UART_RECIEVE_ERROR;
	}
	/************** Char BITS **************/
	if ((g_ST_UART_CONFIG_t.CHAR_BITS >= UART_5_Bit_CHAR) && (g_ST_UART_CONFIG_t.CHAR_BITS <= UART_9_Bit_CHAR))
	{
		char_bits(g_ST_UART_CONFIG_t.CHAR_BITS);
	}
	else
	{
		return UART_CHAR_BITS_ERROR;
	}
	/************** Stop BITS **************/
	if ((g_ST_UART_CONFIG_t.STOP_BIT == UART_1_STOP_BIT) || (g_ST_UART_CONFIG_t.STOP_BIT == UART_2_STOP_BIT))
	{
		SET_BIT(UCSRC, URSEL);
		UCSRC |= ((uint8_t)(g_ST_UART_CONFIG_t.STOP_BIT));
	}
	else
	{
		return UART_STOP_BITS_ERROR;
	}
	/************** Parity BITS **************/
	if ((g_ST_UART_CONFIG_t.PARITY_MODE == UART_NO_PARITY) || (g_ST_UART_CONFIG_t.PARITY_MODE == UART_EVEN_PARITY) || (g_ST_UART_CONFIG_t.PARITY_MODE == UART_ODD_PARITY))
	{
		SET_BIT(UCSRC, URSEL);
		UCSRC |= ((uint8_t)(g_ST_UART_CONFIG_t.PARITY_MODE));
	}
	else
	{
		return UART_PARITY_ERROR;
	}
	/************** Enable transmitter interrupt**************/
	if ((g_ST_UART_CONFIG_t.TRANSMITER_INT == UART_TRANSMITER_INT_ENABLE) || (g_ST_UART_CONFIG_t.TRANSMITER_INT == UART_TRANSMITER_INT_DISABLE))
	{
		UCSRB |= ((uint8_t)(g_ST_UART_CONFIG_t.TRANSMITER_INT));
	}
	else
	{
		return UART_TRANSMIT_ERROR;
	}
	/************** Enable receiver interrupt **************/
	if ((g_ST_UART_CONFIG_t.RECIEVE_INT == UART_RECIEVER_INT_ENABLE) || (g_ST_UART_CONFIG_t.RECIEVE_INT == UART_RECIEVER_INT_DISABLE))
	{
		UCSRB |= ((uint8_t)(g_ST_UART_CONFIG_t.RECIEVE_INT));
	}
	else
	{
		return UART_RECIEVE_INT_ERROR;
	}
	g_u8_UART_init = INIT;
	return UART_SUCCESS;
}

UART_STATUS UART_TransmitChar(uint16_t data)
{
	while (! (READ_BIT(UCSRA, UDRE)));
	if (g_ST_UART_CONFIG_t.CHAR_BITS == UART_9_Bit_CHAR)
	{
		UCSRB |= ((data >> 8) & 1);
	}
	/* Put data into buffer, sends the data */
	UDR = data;
	return UART_SUCCESS;
}

UART_STATUS UART_TransmitString(uint8_t *data)
{
	uint8_t j = STRING_START;
	
	while (data[j]!= STRING_END)		/* Send string till null */
	{
		UART_TransmitChar(data[j]);
		j++;
	}
	
	return UART_SUCCESS;
}

UART_STATUS UART_RecieveChar(uint16_t * character)
{
	while (! (READ_BIT(UCSRA, RXC)));
	if (g_ST_UART_CONFIG_t.CHAR_BITS == UART_9_Bit_CHAR)
	{
		while ((UCSRA) & ((1<<FE)|(1<<DOR)|(1<<PE)));
		UCSRB = (UCSRB >> 1) & 0x01;
		*character = ((UCSRB << 8) | UDR);
	}
	
	*character =  UDR;				/* Return the byte*/
	return UART_SUCCESS;
}

UART_STATUS UART_RecieveString(uint8_t *data)
{
	uint8_t i = 0;
	uint8_t size = 10;
	
	while (i < size - 1) {
		uint8_t c;
		// wait for another char
		while (! (READ_BIT(UCSRA, RXC)));
		c = (uint8_t)UDR;
		// break on NULL character
		if ((c == STRING_END) || (c == NEW_LINE)) break;
		else if (c == BACKSPACE)
		{
			i--;
			continue;
		}
		// write into the supplied buffer
		data[i] =  (uint8_t)c;
		i++;
	}
	data[i] = STRING_END;
	//return the received string
	return UART_SUCCESS;
}

