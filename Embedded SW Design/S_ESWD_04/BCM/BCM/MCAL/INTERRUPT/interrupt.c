/*
 * interrupt.c
 *
 *  Created on: 10/8/2021
 *      Author: Bishoy Nabil
 */

#include "interrupt.h"

E_STATUS external_interrupt_init(uint8_t external_INT_num, uint8_t edge)
{
	SET_BIT(SREG, PIN7);
	if((edge == low_lvl) || (edge == any_logic_lvl) || (edge == falling_edge) || (edge == rising_edge) )
	{
		if(external_INT_num == interrupt0)
		{
			MCUCR =( MCUCR & 0xfc) | (edge & 0x03);
			SET_BIT(GICR, int0_bit);
			DIO_SetPinDirection(PortD, PIN2, INPUT);
			return E_OK;
	
		}
		else if(external_INT_num == interrupt1)
		{
			MCUCR =( MCUCR & 0xf3) | (edge & 0x0c);
			SET_BIT(GICR, int1_bit);
			DIO_SetPinDirection(PortD, PIN3, INPUT);
			return E_OK;
	
		}
		else if(external_INT_num == interrupt2)
		{
			if(edge == falling_edge)
			{
				RESET_BIT(MCUCSR, ISC2);
			}
			else
			{
				SET_BIT(MCUCSR, ISC2);
			}
			SET_BIT(GICR, int2_bit);
			DIO_SetPinDirection(PortB, PIN2, INPUT);
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
