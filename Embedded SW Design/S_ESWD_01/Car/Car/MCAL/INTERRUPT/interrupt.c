/*
 * interrupt.c
 *
 *  Created on: 10/8/2021
 *      Author: Bishoy Nabil
 */

#include "interrupt.h"

E_STATUS external_interrupt_init(uint8_t external_INT_num, uint8_t edge)
{
	SREG |=(1<<7);
	if(edge == low_lvl || edge == any_logic_lvl || edge == falling_edge || edge == rising_edge )
	{
		if(external_INT_num == interrupt0)
		{
			MCUCR =( MCUCR & 0xfc) | (edge & 0x03);
			GICR |= (1<<int0_bit);
			configs.port = DIO_PORTD;
			configs.pin = PIN_2;
			configs.dir = INPUT;
			DIO_Init(&configs);
			return E_OK;
	
		}
		else if(external_INT_num == interrupt1)
		{
			MCUCR =( MCUCR & 0xf3) | (edge & 0x0c);
			GICR |= (1<<int1_bit);
			configs.port = DIO_PORTD;
			configs.pin = PIN_3;
			configs.dir = INPUT;
			DIO_Init(&configs);
			return E_OK;
	
		}
		else if(external_INT_num == interrupt2)
		{
			if(edge == falling_edge)
			{
				MCUCSR &=~(1<<ISC2);
			}
			else
			{
				MCUCSR |=(1<<ISC2);
			}
			GICR |= (1<<int2_bit);
			configs.port = DIO_PORTB;
			configs.pin = PIN_2;
			configs.dir = INPUT;
			DIO_Init(&configs);
			return E_OK;
			
		}
		else
		{
			return E_NOK;
		}
	}
	else
	{
		return E_NOK;
	}
}
