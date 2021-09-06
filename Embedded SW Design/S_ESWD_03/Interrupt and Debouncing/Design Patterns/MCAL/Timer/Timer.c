/*
* timers.c
*
*
*      Author: Bishoy Nabil
*/

#include "Timer.h"

/*******************************************Pointer to Functions for Interrupt Service Routine******************************************/
static void (*timer0_ovf_ptr)(void)  = NULL_PTR; /*pointer to timer0 overflow function*/
static void (*timer0_comp_ptr)(void)  = NULL_PTR; /*pointer to timer0 compare function*/
static void (*timer1_ovf_ptr)(void)  = NULL_PTR; /*pointer to timer1 overflow function*/
static void (*timer1_compa_ptr)(void)  = NULL_PTR; /*pointer to timer1 compare a function*/
static void (*timer1_compb_ptr)(void)  = NULL_PTR; /*pointer to timer1 compare b function*/
static void (*timer2_ovf_ptr)(void)  = NULL_PTR; /*pointer to timer2 overflow function*/
static void (*timer2_comp_ptr)(void)  = NULL_PTR; /*pointer to timer0 compare function*/
#define EMPTY_INDEX				(uint8_t) (255)

volatile uint32_t Timer0_counter=0;
volatile uint32_t Timer1_counter=0;
extern uint32_t Timer2_counter;
volatile uint8_t Timer2_delayflag=0;
uint8_t gau8_TMRDelyPriority[PRIORITY_NUMBERS];
uint8_t u8_IndexToBeExecuted = EMPTY_INDEX;
E_STATUS Timer_tSetTMRValue(EN_timerno_t timer,uint16_t TMRValue);
/**************************************************************ISR of Timers Interrupts***********************************************/


ISR(TIMER1_OVF_vect)
{
	Timer_tSetTMRValue(TIMER_1,255);
	Timer1_counter++;
}

ISR(TIMER0_OVF_vect)
{
	Timer_tSetTMRValue(TIMER_0,255);
	Timer0_counter++;
}

/*timer0 overflow ISR
ISR(TIMER0_OVF_vect){
if(timer0_ovf_ptr != NULL_PTR){
(*timer0_ovf_ptr)();
}
}
timer0 compare ISR
ISR(TIMER0_COMP_vect){
if(timer0_comp_ptr != NULL_PTR){
(*timer0_comp_ptr)();
}
}
timer1 overflow ISR
ISR(TIMER1_OVF_vect){
if(timer1_ovf_ptr != NULL_PTR){
(*timer1_ovf_ptr)();
}
}
timer1 compare a ISR
ISR(TIMER1_COMPA_vect){
if(timer1_compa_ptr != NULL_PTR){
(*timer1_compa_ptr)();
}
}
timer1 compare b ISR
ISR(TIMER1_COMPB_vect){
if(timer1_compb_ptr != NULL_PTR){
(*timer1_compb_ptr)();
}
}

timer2 overflow ISR
ISR(TIMER2_OVF_vect){
if(timer2_ovf_ptr != NULL_PTR){
(*timer2_ovf_ptr)();
}
}
timer2 compare ISR
ISR(TIMER2_COMP_vect){
if(timer2_comp_ptr != NULL_PTR){
(*timer2_comp_ptr)();
}
}*/

/***************************************************************LOCAL FUNCTIONS ***************************************************/
E_STATUS Timer_tSetTMRValue(EN_timerno_t timer,uint16_t TMRValue)
{
	switch(timer)
	{
		case TIMER_0:
		TCNT0=TMRValue;
		return E_OK;
		break;
		case TIMER_1:
		TCNT1=TMRValue;
		return E_OK;
		break;
		case TIMER_2:
		TCNT2=TMRValue;
		return E_OK;
		break;
		default:
		return E_NOK;
		break;
	}
	return E_NOK;
}
/***********************************************************Timer0 Initialize Function***********************************************/
E_STATUS Timer0_INIT(ST_TimerConfig_t* config_ptr)
{
	if((*config_ptr).mode == OVERFLOW){
		/*choose overflow*/
		TCCR0 &= ~(1<<WGM00);
		TCCR0 &= ~(1<<WGM01);
		/*choose pre-scaler*/
		TCCR0 |= (TCCR0 & 0xF8) | ((*config_ptr).prescaler);
		/*choose initial value*/
		TCNT0 = (*config_ptr).initialValue;
		/*Enable Interrupt*/
		if((*config_ptr).interrupt == INT_ENABLE){
			TIMSK = (1<<TOIE0);
			/* Global Interrupt Enable */
			SREG|=(1<<7);
		}
	}
	/*if the use choose compare mode*/
	else if((*config_ptr).mode == COMPARE)
	{
		/*choose compare mood*/
		TCCR0 = (1<<WGM01);
		/*choose from DISCONNECT, TOGGLE, CLEAR, SET*/
		TCCR0 = (TCCR0 & 0xCF) | (((*config_ptr).output)<<4);
		/*choose pre-scaler*/
		TCCR0 |= (TCCR0 & 0xF8) | ((*config_ptr).prescaler);
		/*choose initial value*/
		TCNT0 = (*config_ptr).initialValue;
		/*choose compare value*/
		OCR0 = (*config_ptr).compareValue;
		/*Enable Interrupt*/
		if((*config_ptr).interrupt == INT_ENABLE){
			TIMSK = (1<<OCIE0);
			/* Global Interrupt Enable */
			SREG|=(1<<7);
		}
	}
	else if((*config_ptr).mode == PWM){
		/*choose PWM mood*/
		TCCR0 |= (1<<WGM00) | (1<<WGM01);
		/*choose from DISCONNECT,NON_INVERTING,NVERTING*/
		TCCR0 = (TCCR0 & 0xCF) | (((*config_ptr).output)<<4);
		/*choose pre-scaler*/
		TCCR0 |= (TCCR0 & 0xF8) | ((*config_ptr).prescaler);
		/*choose initial value*/
		TCNT0 = (*config_ptr).initialValue;
		/*choose compare value*/
		OCR0 = (*config_ptr).compareValue;
		/*Enable Interrupt*/
		if((*config_ptr).interrupt == INT_ENABLE){
			TIMSK = (1<<OCIE0);
			/* Global Interrupt Enable */
			SREG|=(1<<7);
		}
	}
	return E_OK;
}

/***********************************************************Timer1 Initialise Function***********************************************/
E_STATUS TIMER1_init(const ST_TimerConfig_t* config_ptr)
{
	if((*config_ptr).mode == OVERFLOW_16){
		/*choose overflow mode*/
		TCCR1A = (*config_ptr).mode;
		TCCR1B = (*config_ptr).mode;
		/*set HIGH with non-WM mode*/
		TCCR1A |= (1<<FOC1A) | (1<<FOC1B);
		/*Enable Overflow Interrupt*/
		if((*config_ptr).interrupt == INT_ENABLE){
			TIMSK |= (1<<TOIE1);
			/* Global Interrupt Enable */
			SREG|=(1<<7);
		}
	}else if(((*config_ptr).mode == PWM_P_8) || ((*config_ptr).mode == PWM_P_9) || ((*config_ptr).mode == PWM_P_10)
	|| ((*config_ptr).mode == F_PWM_8) || ((*config_ptr).mode == F_PWM_9) || ((*config_ptr).mode == F_PWM_10)
	|| ((*config_ptr).mode == PWM_ICR_BOTTOM) || ((*config_ptr).mode == PWM_OCR_BOTTOM) || ((*config_ptr).mode == PWM_ICR_TOP)
	|| ((*config_ptr).mode == PWM_OCR_TOP) || ((*config_ptr).mode == F_PWM_ICR_BOTTOM) || ((*config_ptr).mode == F_PWM_OCR_BOTTOM)){
		/*choose overflow mode*/
		TCCR1A = ((*config_ptr).mode & 0x03);
		TCCR1B = (((*config_ptr).mode & 0x0C)<<1);
		/*set LOW for PWM mode*/
		TCCR1A &= ~((1<<FOC1A) | (1<<FOC1B));
		/*Enable Interrupt*/
		if((*config_ptr).interrupt == INT_ENABLE){
			TIMSK |= (1<<OCIE1A);
			TIMSK |= (1<<OCIE1B);
			/* Global Interrupt Enable */
			SREG|=(1<<7);
		}
	}
	else if(((*config_ptr).mode == CTC_OCR) || ((*config_ptr).mode == CTC_ICR)){
		/*choose overflow mode*/
		TCCR1A = ((*config_ptr).mode & 0x03);
		TCCR1B = (((*config_ptr).mode & 0x0C)<<1);
		/*set HIGH with non-WM mode*/
		TCCR1A |= (1<<FOC1A) | (1<<FOC1B);
		/*Enable Interrupt*/
		if((*config_ptr).interrupt == INT_ENABLE){
			TIMSK |= (1<<OCIE1A);
			TIMSK |= (1<<OCIE1B);
			/* Global Interrupt Enable */
			SREG|=(1<<7);
		}
	}
	/*set compare output mode*/
	TCCR1A = (TCCR1A & 0x0F) | ((*config_ptr).output<<4);
	TCCR1A = (TCCR1A & 0x0F) | ((*config_ptr).output<<6);
	/*set pre-scaler*/
	TCCR1B = (TCCR1B & 0xF8) | (*config_ptr).prescaler;
	/*set initial value*/
	TCNT1 = (*config_ptr).initialValue;
	/*set compare value*/
	OCR1A = (*config_ptr).compareValue;
	return E_OK;
}


/***********************************************************Timer2 Initialize Function***********************************************/
E_STATUS TIMER2_init(ST_TimerConfig_t* config_ptr)
{
	/*If the use choose overflow mode*/
	if((*config_ptr).mode == OVERFLOW){
		/*choose overflow*/
		TCCR2 &= ~(1<<WGM20);
		TCCR2 &= ~(1<<WGM21);
		/*choose pre-scaler*/
		TCCR2 |= (TCCR2 & 0xF8) | ((*config_ptr).prescaler);
		/*choose initial value*/
		TCNT2 = (*config_ptr).initialValue;
		/*Enable Interrupt*/
		if((*config_ptr).interrupt == INT_ENABLE){
			TIMSK = (1<<TOIE2);
			/* Global Interrupt Enable */
			SREG|=(1<<7);
		}
	}
	/*if the use choose compare mode*/
	else if((*config_ptr).mode == COMPARE)
	{
		/*choose compare mood*/
		TCCR2 = (1<<WGM21);
		/*choose from DISCONNECT, TOGGLE, CLEAR, SET*/
		TCCR2 = (TCCR2 & 0xCF) | (((*config_ptr).output)<<4);
		/*choose pre-scaler*/
		TCCR2 |= (TCCR2 & 0xF8) | ((*config_ptr).prescaler);
		/*choose initial value*/
		TCNT2 = (*config_ptr).initialValue;
		/*choose compare value*/
		OCR2 = (*config_ptr).compareValue;
		/*Enable Interrupt*/
		if((*config_ptr).interrupt == INT_ENABLE){
			TIMSK = (1<<OCIE2);
			/* Global Interrupt Enable */
			SREG|=(1<<7);
		}
	}
	else if((*config_ptr).mode == PWM){
		/*choose PWM mood*/
		TCCR2 |= (1<<WGM20) | (1<<WGM21);
		/*choose from DISCONNECT,NON_INVERTING,NVERTING*/
		TCCR2 = (TCCR2 & 0xCF) | (((*config_ptr).output)<<4);
		/*choose pre-scaler*/
		TCCR2 |= (TCCR2 & 0xF8) | ((*config_ptr).prescaler);
		/*choose initial value*/
		TCNT2 = (*config_ptr).initialValue;
		/*choose compare value*/
		OCR2 = (*config_ptr).compareValue;
		/*Enable Interrupt*/
		if((*config_ptr).interrupt == INT_ENABLE){
			TIMSK = (1<<OCIE2);
			/* Global Interrupt Enable */
			SREG|=(1<<7);
		}
	}
	return E_OK;
}

/***************************************************Call Back Functions For ISR***************************************************/
/*timer0 overflow Call Back Function*/
void TIMER0_OVF_interrupt(void(*a_ptr)(void))
{
	timer0_ovf_ptr = a_ptr;
}
/*timer0 compare Call Back Function*/
void TIMER0_COMP_interrupt(void(*a_ptr)(void))
{
	timer0_comp_ptr = a_ptr;
}
/*timer1 overflow Call Back Function*/
void TIMER1_OVF_interrupt(void(*a_ptr)(void))
{
	timer1_ovf_ptr = a_ptr;
}
/*timer1 compare a Call Back Function*/
void TIMER1_COMPA_interrupt(void(*a_ptr)(void))
{
	timer1_compa_ptr = a_ptr;
}
/*timer1 compare b Call Back Function*/
void TIMER1_COMPB_interrupt(void(*a_ptr)(void))
{
	timer1_compb_ptr = a_ptr;
}
/*timer2 overflow Call Back Function*/
void TIMER2_OVF_interrupt(void(*a_ptr)(void))
{
	timer2_ovf_ptr = a_ptr;
}
/*timer02 compare Call Back Function*/
void TIMER2_COMP_interrupt(void(*a_ptr)(void))
{
	timer2_comp_ptr = a_ptr;
}

/***********************************************************Timers Functions*********************************************************/

/***********************************************************Timer0 Initialize Function***********************************************/
E_STATUS TIMER_Init(ST_TimerConfig_t* config_ptr)
{
	/*If the use choose overflow mode*/
	uint8_t retval = E_NOK;
	switch(config_ptr->timer)
	{
		case (TIMER_0):
		{
			Timer0_INIT(config_ptr);
			break;
		}
		case (TIMER_1):
		{
			TIMER1_init(config_ptr);
			break;
		}
		case (TIMER_2):
		{
			TIMER2_init(config_ptr);
			break;
		}
		default:
		{
			retval = E_NOK;
			break;
		}
	}
	return retval;
}

/**********************************************************Timer Stop Function*******************************************************/
E_STATUS TIMER_Deinit(EN_timerno_t timer)
{
	uint8_t retval = E_NOK;
	switch(timer)
	{
		case (TIMER_0):
		{
			/*Timer stop*/
			TCCR0 = 0;
			retval = E_OK;
			break;
		}
		case (TIMER_1):
		{
			/*Timer stop*/
			TCCR1A = 0;
			TCCR1B = 0;
			TCNT1 = 0;
			OCR1A = 0;
			OCR1B = 0;
			TIMSK &= ~(1<<TOIE1);
			retval = E_OK;
			break;
		}
		case (TIMER_2):
		{
			/*Timer stop*/
			TCCR2 = 0;
			retval = E_OK;
			break;
		}
		default:
		{
			retval = E_NOK;
			break;
		}
	}
	return retval;
}

/**********************************************************Timer Delay Function*******************************************************/
E_STATUS TIMER_NonBlockingDelay(uint8_t timer, uint32_t time, uint8_t u8_statePriority)
{
	uint8_t retval = ERROR;
	switch (timer)
	{
		case TIMER_0:
		{
			break;
		}
		case TIMER_1:
		{
			break;
		}
		case TIMER_2:
		{
			if(ZERO == Timer2_delayflag)
			{
				ST_TimerConfig_t timerConfig = {TIMER_2, OVERFLOW, F_CPU_8, 255, 0, DISCONNECT, INT_ENABLE};
				TIMER_Init(&timerConfig);
				// 				Timer_sint8_tSetTMRValue(TIMER_2,255);
				// 				Timer_sint8_tInterruptEnable(TIMER_2,TOIE_CHOICE);
				// 				Timer_sint8_tInit(TIMER_2,NORMAL,PRS8);
				Timer2_delayflag = ONE;
				for (uint8_t i = ZERO; i < PRIORITY_NUMBERS; i++)
				{
					if (ZERO != gau8_TMRDelyPriority[i])
					{
						u8_IndexToBeExecuted = i;
						break;
					}
				}
			}

			if((time < Timer2_counter) && (u8_statePriority == u8_IndexToBeExecuted))
			{
				TIMER_Deinit(TIMER_2);
				Timer2_counter = ZERO;
				Timer2_delayflag = ZERO;
				gau8_TMRDelyPriority[u8_IndexToBeExecuted] = ZERO;
				u8_IndexToBeExecuted = EMPTY_INDEX;
				retval = SUCCESS;
				TIMER_NonBlockingDelay(TIMER_2, 0, 9);
				
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
		TIMER_Deinit(TIMER_2);
		Timer2_counter = ZERO;
		Timer2_delayflag = ZERO;
	}
	return retval;
}
