/*
* PWM.c
*
* Created: 8/10/2021 12:10:22 AM
*  Author: Marco
*/

/******************************************************************************
*                              INCLUDES										  *
*******************************************************************************/
#include "PWM.h"
/******************************************************************************
*                         LOCAL FUNCTIONS									  *
*******************************************************************************/
uint8_t PWM_InitPins(PWM_TIMER TimerNo)
{
	switch (TimerNo)
	{
		{
			case  PWM_TIMER0:
			configs.port = DIO_PORTB;
			configs.pin = PIN_3;
			configs.dir = OUTPUT;
			DIO_Init(&configs);
			break;
		}
		case  PWM_TIMER2:
		{
			configs.port = DIO_PORTD;
			configs.pin = PIN_7;
			configs.dir = OUTPUT;
			DIO_Init(&configs);
			break;
		}
		default:
		{
			return E_NOK;
		}
	}
	return E_OK;
}
/******************************************************************************
*                         APIS IMPLEMENTATION								  *
*******************************************************************************/

uint8_t PWM_START(PWM_TIMER TimerNo, uint8_t dutyCycle)
{
	if (dutyCycle > 100)
	{
		return E_NOK;
	}
	else
	{
		if (TimerNo == PWM_TIMER0)
		{
			TCCR0 |= PWM_TIMER0_MODE;
			TCCR0 |= PWM_TIMER0_PRESCALER;
			TCCR0 |= PWM_TIMER0_OC0_MODE;
			if (PWM_TIMER0_OC0_MODE == PWM_OC0_NONINVERTING_MODE)
			{
				if (dutyCycle == 0)
				{
					OCR0 = 0;
				}
				else
				{
					OCR0 = 2.56 * dutyCycle - 1;
				}
			}
			else if (PWM_TIMER0_OC0_MODE == PWM_OC0_INVERTING_MODE)
			{
				if (dutyCycle == 100)
				{
					OCR0 = 0;
				}
				else
				{
					OCR0 = 255 - 2.56 * dutyCycle;
				}
			}
		}
		else if (TimerNo == PWM_TIMER2)
		{
			TCCR2 |= PWM_TIMER2_MODE;
			TCCR2 |= PWM_TIMER2_PRESCALER;
			TCCR2 |= PWM_TIMER2_OC0_MODE;
			if (PWM_TIMER2_MODE == PWM_MODE_FASTPWM)
			{
				if (PWM_TIMER2_OC0_MODE == PWM_OC0_NONINVERTING_MODE)
				{
					if (dutyCycle == 0)
					{
						OCR2 = 0;
					}
					else
					{
						OCR2 = 2.56 * dutyCycle - 1;
					}
				}
				else if (PWM_TIMER2_OC0_MODE == PWM_OC0_INVERTING_MODE)
				{
					if (dutyCycle == 100)
					{
						OCR2 = 0;
					}
					else
					{
						OCR2 = 255 - 2.56 * dutyCycle;
					}
				}
			}
			else if (PWM_TIMER2_MODE == PWM_MODE_PHASECORRECTPWM)
			{
				if (PWM_TIMER2_OC0_MODE == PWM_OC0_NONINVERTING_MODE)
				{
					if (dutyCycle == 0)
					{
						OCR2 = 0;
					}
					else
					{
						OCR2 = (5.1 * dutyCycle - 1) / 20;
					}
				}
				else if (PWM_TIMER2_OC0_MODE == PWM_OC0_INVERTING_MODE)
				{
					if (dutyCycle == 100)
					{
						OCR2 = 0;
					}
					else
					{
						OCR2 = (510 - 5.1 * dutyCycle) / 20;
					}
				}
				else
				{
					return E_NOK;
				}
			}
		}
		else
		{
			return E_NOK;
		}
	}

	if (E_NOK == PWM_InitPins(TimerNo))
	{
		return E_NOK;
	}
	else
	{
		
	}
	return E_OK;
}

uint8_t PWM_STOP(PWM_TIMER TimerNo)
{
	if (TimerNo == PWM_TIMER0)
	{
		TCCR0 = 0x00;
	}
	else if (TimerNo == PWM_TIMER2)
	{
		TCCR2 = 0x00;
	}
	else
	{
		return E_NOK;
	}
	return E_OK;
}