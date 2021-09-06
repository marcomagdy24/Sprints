/*
* Timer_Prog.c
*
* Created: 23-Jul-21 6:53:38 PM
*  Author: Ayman
*/


#include "Timer_Int.h"

#define EMPTY_INDEX				(uint8_t) (255)

volatile uint32_t Timer0_counter=0;
volatile uint32_t Timer1_counter=0;
volatile uint32_t Timer2_counter=0;
volatile uint8_t Timer2_delayflag=0;
uint8_t gau8_TMRDelyPriority[PRIORITY_NUMBERS];
uint8_t u8_IndexToBeExecuted = EMPTY_INDEX;

uint8_t Timer_sint8_tInit(uint8_t timer,uint8_t mode,uint32_t prescaler)
{
	if(timer <= TMR2_CHOICE && mode <= 17)
	{
		switch (timer)
		{
			case TMR0_CHOICE:
			switch (mode)
			{
				case NORMAL:
				CLR_BIT(TCCR0,3);
				CLR_BIT(TCCR0,6);
				break;
				case PWM:
				CLR_BIT(TCCR0,3);
				SET_BIT(TCCR0,6);
				break;
				case CTC:
				SET_BIT(TCCR0,3);
				CLR_BIT(TCCR0,6);
				break;
				case FPWM:
				SET_BIT(TCCR0,3);
				SET_BIT(TCCR0,6);
				break;
				default:
				return E_NOK;
				break;
			}

			switch (prescaler)
			{
				case PRS1:
				SET_BIT(TCCR0,0);
				CLR_BIT(TCCR0,1);
				CLR_BIT(TCCR0,2);
				break;
				case PRS8:
				CLR_BIT(TCCR0,0);
				SET_BIT(TCCR0,1);
				CLR_BIT(TCCR0,2);
				return E_OK;
				break;
				case PRS64:
				CLR_BIT(TCCR0,0);
				SET_BIT(TCCR0,1);
				SET_BIT(TCCR0,2);
				return E_OK;
				break;
				case PRS256:
				CLR_BIT(TCCR0,0);
				CLR_BIT(TCCR0,1);
				SET_BIT(TCCR0,2);
				return E_OK;
				break;
				case PRS1024:
				SET_BIT(TCCR0,0);
				CLR_BIT(TCCR0,1);
				SET_BIT(TCCR0,2);
				return E_OK;
				break;
				case PRESOFF: /// stop timer
				CLR_BIT(TCCR0,0);
				CLR_BIT(TCCR0,1);
				CLR_BIT(TCCR0,2);
				return E_OK;
				break;
				default:
				return E_NOK;
				break;
			}

			break;

			case TMR1_CHOICE:
			switch (mode)
			{
				case NORMAL:
				CLR_BIT(TCCR1A,0);
				CLR_BIT(TCCR1A,1);
				CLR_BIT(TCCR1B,3);
				CLR_BIT(TCCR1B,4);
				break;
				case PWMPH8:
				SET_BIT(TCCR1A,0);
				CLR_BIT(TCCR1A,1);
				CLR_BIT(TCCR1B,3);
				CLR_BIT(TCCR1B,4);
				break;
				case PWMPH9:
				CLR_BIT(TCCR1A,0);
				SET_BIT(TCCR1A,1);
				CLR_BIT(TCCR1B,3);
				CLR_BIT(TCCR1B,4);
				break;
				case CTCOCR:
				SET_BIT(TCCR1A,0);
				SET_BIT(TCCR1A,1);
				CLR_BIT(TCCR1B,3);
				CLR_BIT(TCCR1B,4);
				break;
				case FPWM8:
				CLR_BIT(TCCR1A,0);
				CLR_BIT(TCCR1A,1);
				SET_BIT(TCCR1B,3);
				CLR_BIT(TCCR1B,4);
				break;
				case FPWM9:
				SET_BIT(TCCR1A,0);
				CLR_BIT(TCCR1A,1);
				SET_BIT(TCCR1B,3);
				CLR_BIT(TCCR1B,4);
				break;
				case FPWM10:
				CLR_BIT(TCCR1A,0);
				SET_BIT(TCCR1A,1);
				SET_BIT(TCCR1B,3);
				CLR_BIT(TCCR1B,4);
				break;
				case PWMPHFRICR:
				SET_BIT(TCCR1A,0);
				SET_BIT(TCCR1A,1);
				SET_BIT(TCCR1B,3);
				CLR_BIT(TCCR1B,4);
				break;
				case PWMPHFROCR:
				CLR_BIT(TCCR1A,0);
				CLR_BIT(TCCR1A,1);
				CLR_BIT(TCCR1B,3);
				SET_BIT(TCCR1B,4);
				break;
				case PWMPHICR:
				SET_BIT(TCCR1A,0);
				CLR_BIT(TCCR1A,1);
				CLR_BIT(TCCR1B,3);
				SET_BIT(TCCR1B,4);
				break;
				case PWMPHOCR:
				SET_BIT(TCCR1A,0);
				SET_BIT(TCCR1A,1);
				CLR_BIT(TCCR1B,3);
				SET_BIT(TCCR1B,4);
				break;
				case CTCICR:
				CLR_BIT(TCCR1A,0);
				CLR_BIT(TCCR1A,1);
				SET_BIT(TCCR1B,3);
				SET_BIT(TCCR1B,4);
				break;
				case FPWMICR:
				CLR_BIT(TCCR1A,0);
				SET_BIT(TCCR1A,1);
				SET_BIT(TCCR1B,3);
				SET_BIT(TCCR1B,4);
				break;
				case FPWMOCR:
				SET_BIT(TCCR1A,0);
				SET_BIT(TCCR1A,1);
				SET_BIT(TCCR1B,3);
				SET_BIT(TCCR1B,4);
				break;
			}
			switch (prescaler)
			{
				case PRS1:
				SET_BIT(TCCR1B,0);
				CLR_BIT(TCCR1B,1);
				CLR_BIT(TCCR1B,2);
				return E_OK;
				break;
				case PRS8:
				CLR_BIT(TCCR1B,0);
				SET_BIT(TCCR1B,1);
				CLR_BIT(TCCR1B,2);
				return E_OK;
				break;
				case PRS64:
				SET_BIT(TCCR1B,0);
				SET_BIT(TCCR1B,1);
				CLR_BIT(TCCR1B,2);
				return E_OK;
				break;
				case PRS256:
				CLR_BIT(TCCR1B,0);
				CLR_BIT(TCCR1B,1);
				SET_BIT(TCCR1B,2);
				return E_OK;
				break;
				case PRS1024:
				SET_BIT(TCCR1B,0);
				CLR_BIT(TCCR1B,1);
				SET_BIT(TCCR1B,2);
				return E_OK;
				break;
				case PRESOFF: /// stop timer
				CLR_BIT(TCCR1B,0);
				CLR_BIT(TCCR1B,1);
				CLR_BIT(TCCR1B,2);
				return E_OK;
				break;
				default:
				return E_NOK;

				break;
			}
			break;
			case TMR2_CHOICE:
			switch (mode)
			{
				case NORMAL:
				CLR_BIT(TCCR2,3);
				CLR_BIT(TCCR2,6);
				break;
				case PWM:
				CLR_BIT(TCCR2,3);
				SET_BIT(TCCR2,6);
				break;
				case CTC:
				SET_BIT(TCCR2,3);
				CLR_BIT(TCCR2,6);
				break;
				case FPWM:
				SET_BIT(TCCR2,3);
				SET_BIT(TCCR2,6);
				break;
			}

			switch (prescaler)
			{
				case PRS8:
				CLR_BIT(TCCR2,0);
				SET_BIT(TCCR2,1);
				CLR_BIT(TCCR2,2);
				return E_OK;
				break;
				case PRS32:
				SET_BIT(TCCR2,0);
				SET_BIT(TCCR2,1);
				CLR_BIT(TCCR2,2);
				return E_OK;
				break;
				case PRS64:
				CLR_BIT(TCCR2,0);
				CLR_BIT(TCCR2,1);
				SET_BIT(TCCR2,2);
				return E_OK;
				break;
				case PRS128:
				SET_BIT(TCCR2,0);
				CLR_BIT(TCCR2,1);
				SET_BIT(TCCR2,2);
				return E_OK;
				break;
				case PRS256:
				CLR_BIT(TCCR2,0);
				SET_BIT(TCCR2,1);
				SET_BIT(TCCR2,2);
				return E_OK;
				break;
				case PRS1024:
				SET_BIT(TCCR2,0);
				SET_BIT(TCCR2,1);
				SET_BIT(TCCR2,2);
				return E_OK;
				break;
				case PRESOFF: /// stop timer
				CLR_BIT(TCCR2,0);
				CLR_BIT(TCCR2,1);
				CLR_BIT(TCCR2,2);
				return E_OK;
				break;
				default:
				return E_NOK;
				break;
			}
			break;

		}
	}
	return E_NOK;
}

uint8_t Timer_sint8_tSetTMRValue(uint8_t timer,uint16_t TMRValue)
{
	switch(timer)
	{
		case TMR0_CHOICE:
		TCNT0=TMRValue;
		return E_OK;
		break;
		case TMR1_CHOICE:
		TCNT1=TMRValue;
		return E_OK;
		break;
		case TMR2_CHOICE:
		TCNT2=TMRValue;
		return E_OK;
		break;
		case TMR1H_CHOICE:
		TCNT1H=TMRValue;
		return E_OK;
		break;
		case TMR1L_CHOICE:
		TCNT1L=TMRValue;
		return E_OK;
		break;
		case OCR1A_CHOICE:
		OCR1A=TMRValue;
		return E_OK;
		break;
		case OCR1AH_CHOICE:
		OCR1AH=TMRValue;
		return E_OK;
		break;
		case OCR1AL_CHOICE:
		OCR1AL=TMRValue;
		return E_OK;
		break;
		case OCR1B_CHOICE:
		OCR1B=TMRValue;
		return E_OK;
		break;
		case OCR1BH_CHOICE:
		OCR1BH=TMRValue;
		return E_OK;
		break;
		case OCR1BL_CHOICE:
		OCR1BL=TMRValue;
		return E_OK;
		break;
		case ICR1_CHOICE:
		ICR1=TMRValue;
		return E_OK;
		break;
		case ICR1H_CHOICE:
		ICR1H=TMRValue;
		return E_OK;
		break;
		case ICR1L_CHOICE:
		ICR1L=TMRValue;
		return E_OK;
		break;
		case OCR2_CHOICE:
		OCR2=TMRValue;
		return E_OK;
		break;
		case OCR0_CHOICE:
		OCR0=TMRValue;
		return E_OK;
		break;
		default:
		return E_NOK;
		break;
	}
	return E_NOK;
}
uint8_t Timer_sint8_tInterruptEnable(uint8_t timer,uint8_t type)
{
	switch (timer)
	{
		case TMR0_CHOICE:
		switch(type)
		{
			case TOIE_CHOICE:
			SET_BIT(TIMSK,0);
			return E_OK;
			break;

			case OSCIE_CHOICE:
			SET_BIT(TIMSK,1);
			return E_OK;
			break;
		}
		break;
		case TMR1_CHOICE:
		switch(type)
		{
			case TOIE_CHOICE:
			SET_BIT(TIMSK,2);
			return E_OK;
			break;

			case OSCIEB_CHOICE:
			SET_BIT(TIMSK,3);
			return E_OK;
			break;
			case OSCIEA_CHOICE:
			SET_BIT(TIMSK,4);
			return E_OK;
			break;

			case TICIE_CHOICE:
			SET_BIT(TIMSK,5);
			return E_OK;
			break;
		}
		break;
		case TMR2_CHOICE:
		switch(type)
		{
			case TOIE_CHOICE:
			SET_BIT(TIMSK,6);
			return E_OK;
			break;

			case OSCIE_CHOICE:
			SET_BIT(TIMSK,7);
			return E_OK;
			break;
		}
		break;
	}
	return E_NOK;
}
uint8_t Timer_sint8_tInterruptDisable(uint8_t timer,uint8_t type)
{
	switch (timer)
	{
		case TMR0_CHOICE:
		switch(type)
		{
			case TOIE_CHOICE:
			CLR_BIT(TIMSK,0);
			return E_OK;
			break;

			case OSCIE_CHOICE:
			CLR_BIT(TIMSK,1);
			return E_OK;
			break;
		}
		break;
		case TMR1_CHOICE:
		switch(type)
		{
			case TOIE_CHOICE:
			CLR_BIT(TIMSK,2);
			return E_OK;
			break;

			case OSCIEB_CHOICE:
			CLR_BIT(TIMSK,3);
			return E_OK;
			break;
			case OSCIEA_CHOICE:
			CLR_BIT(TIMSK,4);
			return E_OK;
			break;
			case TICIE_CHOICE:
			CLR_BIT(TIMSK,5);
			return E_OK;
			break;
		}
		break;
		case TMR2_CHOICE:
		switch(type)
		{
			case TOIE_CHOICE:
			CLR_BIT(TIMSK,6);
			return E_OK;
			break;
			case OSCIE_CHOICE:
			CLR_BIT(TIMSK,7);
			return E_OK;
			break;
		}
		break;

	}
	return E_NOK;
}
uint8_t Timer_sint8_tCompareOutputMode(uint8_t timer,uint8_t mode)
{
	switch(timer)
	{
		case TMR0_CHOICE:
		switch(mode)
		{
			case NORMALOPERATION:
			CLR_BIT(TCCR0,4);
			CLR_BIT(TCCR0,5);
			return E_OK;
			break;
			case TOGGLE:
			SET_BIT(TCCR0,4);
			CLR_BIT(TCCR0,5);
			return E_OK;
			break;
			case CLEAR:
			CLR_BIT(TCCR0,4);
			SET_BIT(TCCR0,5);
			return E_OK;
			break;
			case SET:
			SET_BIT(TCCR0,4);
			SET_BIT(TCCR0,5);
			return E_OK;
			break;
		}
		break;

		case TMR1A_CHOICE:
		switch(mode)
		{
			case NORMALOPERATION:
			CLR_BIT(TCCR1A,6);
			CLR_BIT(TCCR1A,7);
			return E_OK;
			break;
			case TOGGLE:
			SET_BIT(TCCR1A,6);
			CLR_BIT(TCCR1A,7);
			return E_OK;
			break;
			case CLEAR:
			CLR_BIT(TCCR1A,6);
			SET_BIT(TCCR1A,7);
			return E_OK;
			break;
			case SET:
			SET_BIT(TCCR1A,6);
			SET_BIT(TCCR1A,7);
			return E_OK;
			break;
		}
		break;
		case TMR1B_CHOICE:
		switch(mode)
		{
			case NORMALOPERATION:
			CLR_BIT(TCCR1A,4);
			CLR_BIT(TCCR1A,5);
			return E_OK;
			break;
			case TOGGLE:
			SET_BIT(TCCR1A,4);
			CLR_BIT(TCCR1A,5);
			return E_OK;
			break;
			case CLEAR:
			CLR_BIT(TCCR1A,4);
			SET_BIT(TCCR1A,5);
			return E_OK;
			break;
			case SET:
			SET_BIT(TCCR1A,4);
			SET_BIT(TCCR1A,5);
			return E_OK;
			break;
		}
		break;
		case TMR2_CHOICE:
		switch(mode)
		{
			case NORMALOPERATION:
			CLR_BIT(TCCR2,4);
			CLR_BIT(TCCR2,5);
			return E_OK;
			break;
			case TOGGLE:
			SET_BIT(TCCR2,4);
			CLR_BIT(TCCR2,5);
			return E_OK;
			break;
			case CLEAR:
			CLR_BIT(TCCR2,4);
			SET_BIT(TCCR2,5);
			return E_OK;
			break;
			case SET:
			SET_BIT(TCCR2,4);
			SET_BIT(TCCR2,5);
			return E_OK;
			break;
		}
		break;
	}
	return E_NOK;
}
uint8_t Timer_sint32_tTMRValue(uint8_t timer,uint16_t*TimerCountsValue)
{
	switch(timer)
	{
		case TMR0_CHOICE:
		(*TimerCountsValue)=TCNT0;
		return E_OK;
		break;
		case TMR1_CHOICE:
		(*TimerCountsValue)=TCNT1;
		return E_OK;
		break;
		case TMR2_CHOICE:
		(*TimerCountsValue)=TCNT2;
		return E_OK;
		break;

	}
	return E_NOK;
}

uint8_t Timer_sint8_tStop(uint8_t timer)
{
	if(timer <= TMR2_CHOICE)
	{
		switch (timer)
		{
			case TMR0_CHOICE:
			CLR_BIT(TCCR0,0);
			CLR_BIT(TCCR0,1);
			CLR_BIT(TCCR0,2);
			return E_OK;
			break;
			case TMR1_CHOICE:
			CLR_BIT(TCCR1B,0);
			CLR_BIT(TCCR1B,1);
			CLR_BIT(TCCR1B,2);
			return E_OK;
			break;
			case TMR2_CHOICE:
			CLR_BIT(TCCR2,0);
			CLR_BIT(TCCR2,1);
			CLR_BIT(TCCR2,2);
			return E_OK;
			break;
		}
	}
	return E_NOK;
	
}
void __vector_5 (void)
{
	Timer_sint8_tSetTMRValue(TMR2_CHOICE,255);
	Timer2_counter++;
}

void __vector_9 (void)
{
	Timer_sint8_tSetTMRValue(TMR1_CHOICE,255);
	Timer1_counter++;
}

void __vector_11 (void)
{
	Timer_sint8_tSetTMRValue(TMR0_CHOICE,255);
	Timer0_counter++;
}

uint8_t Timer_NonBlockingdelay(uint8_t timer, uint32_t time, uint8_t u8_statePriority)
{
	uint8_t retval = ERROR;
	switch (timer)
	{
		case TMR0_CHOICE:
		{
			break;
		}
		case TMR1_CHOICE:
		{
			break;
		}
		case TMR2_CHOICE:
		{
			if(ZERO == Timer2_delayflag)
			{
				Timer_sint8_tSetTMRValue(TMR2_CHOICE,255);
				Timer_sint8_tInterruptEnable(TMR2_CHOICE,TOIE_CHOICE);
				Timer_sint8_tInit(TMR2_CHOICE,NORMAL,PRS8);
				Timer2_delayflag = ONE; 
				for (uint8_t i = ZERO; i < PRIORITY_NUMBERS; i++)
				{
					if (gau8_TMRDelyPriority[i] != ZERO)
					{
						u8_IndexToBeExecuted = i;
						break;
					}
				}
			}

			if((time < Timer2_counter) && (u8_statePriority == u8_IndexToBeExecuted))
			{
				Timer_sint8_tStop(TMR2_CHOICE);
				Timer2_counter = ZERO;
				Timer2_delayflag = ZERO;
				gau8_TMRDelyPriority[u8_IndexToBeExecuted] = ZERO;
				u8_IndexToBeExecuted = EMPTY_INDEX;
				retval = SUCCESS;
				Timer_NonBlockingdelay(TMR2_CHOICE, 0, 9);
				
			}
			else if (u8_statePriority != u8_IndexToBeExecuted)
			{
				gau8_TMRDelyPriority[u8_statePriority] = time;
				retval = WAITING;
			}
			else if ((time > Timer2_counter) && (u8_statePriority == u8_IndexToBeExecuted))
			{
				retval = PENDING;
			}
			else
			{
				retval = ERROR;
			}
			break;
		}
	}
	if (EMPTY_INDEX == u8_IndexToBeExecuted)
	{
		Timer_sint8_tStop(TMR2_CHOICE);
		Timer2_counter = ZERO;
		Timer2_delayflag = ZERO;
	}
	return retval;
}