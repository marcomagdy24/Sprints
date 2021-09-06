/****************************************/
/* Author  : Monica Francis				*/
/* Date    : 6/3/2018					*/
/* Version : V01						*/
/****************************************/

#include "timer.h"


#ifndef _TIM0_REG_H
#define _TIM0_REG_H

/*****************************************************************************/
/*private*/

/*set and PreScaler								*/
#define TIM0_uint16_t_DIV_1			1

#define TIM0_uint16_t_DIV_8			8

#define TIM0_uint16_t_DIV_64		64

#define TIM0_uint16_t_DIV_256		256

#define TIM0_uint16_t_DIV_1024		1024

/*	TIMER MODE							*/
#define TIM0_uint8_t_OV_MODE		7
#define TIM0_uint8_t_CTC_MODE		12

/*********************************************/
#define TIM1_uint16_t_DIV_1			1

#define TIM1_uint16_t_DIV_8			8

#define TIM1_uint16_t_DIV_64		64

#define TIM1_uint16_t_DIV_256		256

#define TIM1_uint16_t_DIV_1024		1024

/*	TIMER MODE							*/
#define TIM1_uint8_t_OV_MODE					7

#define TIM1_uint8_t_CTC_MODE					12

#endif

/*****************************************************************************/


static void (*TIM0_CallBack) (void);
static void (*TIM1_CallBack) (void);
static void (*TIM2_CallBack) (void);

E_STATUS TIM_voidInitialize(uint8_t TIMER_Number)
{
	uint8_t uint8_tTimerErrorState=Timer_SUCCESS;
	if(TIMER_Number == TIMER_0)
	{
		#if TIM0_uint8_t_MODE == TIM0_uint8_t_OV_MODE
		/* Disable Timer Interrupt					*/
		CLEAR_BIT(TIMSK,0);
		/* Clear Flag by writing one on it 			*/
		SET_BIT(TIFR,0);
		/*	Set Mode 								*/
		CLEAR_BIT(TCCR0,3);
		CLEAR_BIT(TCCR0,6);
		#elif TIM0_uint8_t_MODE == TIM0_uint8_t_CTC_MODE
		/* Disable Timer Interrupt					*/
		CLEAR_BIT(TIMSK,1);
		/* Clear Flag								*/
		SET_BIT(TIFR,1);
		/*	Set Mode 								*/
		SET_BIT(TCCR0,3);
		CLEAR_BIT(TCCR0,6);
		#endif
		/*set and PreScaler								*/
		#if TIM0_uint16_t_PRESCALER == TIM0_uint16_t_DIV_1
		TCCR0 |= 0b00000001;
		TCCR0 &= 0b11111001;
		#elif TIM0_uint16_t_PRESCALER == TIM0_uint16_t_DIV_8
		TCCR0 |= 0b00000010;
		TCCR0 &= 0b11111010;
		#elif TIM0_uint16_t_PRESCALER == TIM0_uint16_t_DIV_64
		TCCR0 |= 0b00000011;
		TCCR0 &= 0b11111011;
		#elif TIM0_uint16_t_PRESCALER == TIM0_uint16_t_DIV_256
		TCCR0 |= 0b00000100;
		TCCR0 &= 0b11111100;
		#elif TIM0_uint16_t_PRESCALER == TIM0_uint16_t_DIV_1024
		TCCR0 |= 0b00000101;
		TCCR0 &= 0b11111101;
		#endif
		
	}
	else if(TIMER_Number == TIMER_2)
	{
		#if TIM0_uint8_t_MODE == TIM0_uint8_t_OV_MODE
		/* Disable Timer Interrupt					*/
		CLEAR_BIT(TIMSK,6);
		/* Clear Flag by writing one on it 			*/
		SET_BIT(TIFR,6);
		/*	Set Mode 								*/
		CLEAR_BIT(TCCR2,3);
		CLEAR_BIT(TCCR2,6);
		#elif TIM0_uint8_t_MODE == TIM0_uint8_t_CTC_MODE
		/* Disable Timer Interrupt					*/
		CLEAR_BIT(TIMSK,7);
		/* Clear Flag								*/
		SET_BIT(TIFR,7);
		/*	Set Mode 								*/
		SET_BIT(TCCR2,3);
		CLEAR_BIT(TCCR2,6);
		#endif
		/*set and PreScaler								*/
		#if TIM0_uint16_t_PRESCALER == TIM0_uint16_t_DIV_1
		TCCR2 |= 0b00000001;
		TCCR2 &= 0b11111001;
		#elif TIM0_uint16_t_PRESCALER == TIM0_uint16_t_DIV_8
		TCCR2 |= 0b00000010;
		TCCR2 &= 0b11111010;
		#elif TIM0_uint16_t_PRESCALER == TIM0_uint16_t_DIV_64
		TCCR2 |= 0b00000011;
		TCCR2 &= 0b11111011;
		#elif TIM0_uint16_t_PRESCALER == TIM0_uint16_t_DIV_256
		TCCR2 |= 0b00000100;
		TCCR2 &= 0b11111100;
		#elif TIM0_uint16_t_PRESCALER == TIM0_uint16_t_DIV_1024
		TCCR2 |= 0b00000101;
		TCCR2 &= 0b11111101;
		#endif
		
	}
	else if(TIMER_Number == TIMER_1)
	{
		TCCR1A=0;		//for normal and CTC mode this register = 0
		#if TIM1_uint8_t_MODE == TIM1_uint8_t_OV_MODE
		/* Disable Timer Interrupt					*/
		CLEAR_BIT(TIMSK,2);
		/* Clear Flag								*/
		SET_BIT(TIFR,2);
		/*	Set Mode								*/
		CLEAR_BIT(TCCR1B,3);
		CLEAR_BIT(TCCR1B,4);
		#elif TIM1_uint8_t_MODE == TIM1_uint8_t_CTC_MODE
		/* Disable Timer Interrupt					*/
		CLEAR_BIT(TIMSK,4);
		/* Clear Flag								*/
		SET_BIT(TIFR,4);
		/*	Set Mode								*/
		SET_BIT(TCCR1B,3);
		CLEAR_BIT(TCCR1B,4);
		#endif
		#if TIM1_uint16_t_PRESCALER == TIM1_uint16_t_DIV_1
		TCCR1B |= 0b00000001;
		TCCR1B &= 0b11111001;
		#elif TIM1_uint16_t_PRESCALER == TIM1_uint16_t_DIV_8
		TCCR1B |= 0b00000010;
		TCCR1B &= 0b11111010;
		#elif TIM1_uint16_t_PRESCALER == TIM1_uint16_t_DIV_64
		TCCR1B |= 0b00000011;
		TCCR1B &= 0b11111011;
		#elif TIM1_uint16_t_PRESCALER == TIM1_uint16_t_DIV_256
		TCCR1B |= 0b00000100;
		TCCR1B &= 0b11111100;
		#elif TIM1_uint16_t_PRESCALER == TIM1_uint16_t_DIV_1024
		TCCR1B |= 0b00000101;
		TCCR1B &= 0b11111101;
		#endif
	}
	else
	{
		
		uint8_tTimerErrorState=Timer_FAIL;
		
	}
	return 	uint8_tTimerErrorState;
}


E_STATUS TIM_uint8_tDeInit(uint8_t TIMER_Number)
{
	uint8_t uint8_tTimerErrorState=Timer_SUCCESS;
	if(TIMER_Number == TIMER_0)
	{
		/*Timer stop*/
		TCCR0 = 0;
		TCNT0 = 0;
		OCR0= 0;
		TIMSK &= ~(0<<TOIE0);
	}
	else if(TIMER_Number == TIMER_1)
	{
		/*Timer stop*/
		TCCR1A = 0;
		TCCR1B = 0;
		TCNT1 = 0;
		OCR1A = 0;
		TIMSK &= ~(1<<TOIE1);
	}
	else if(TIMER_Number == TIMER_2)
	{
		/*Timer stop*/
		TCCR2 = 0;
		TCNT2 = 0;
		OCR2= 0;
		TIMSK &= ~(6<<TOIE0);
	}
	
	else
	{
		
		uint8_tTimerErrorState=Timer_FAIL;
		
	}
	return 	uint8_tTimerErrorState;
	
}

E_STATUS TIM_voidEnableInt(uint8_t TIMER_Number)
{
	uint8_t uint8_tTimerErrorState=Timer_SUCCESS;
	if(TIMER_Number == TIMER_0)
	{
		#if TIM0_uint8_t_MODE == TIM0_uint8_t_OV_MODE
		SET_BIT(TIMSK,0);
		#elif TIM0_uint8_t_MODE == TIM0_uint8_t_CTC_MODE
		SET_BIT(TIMSK,1);
		#endif
	}
	else if(TIMER_Number == TIMER_1)
	{
		#if TIM1_uint8_t_MODE == TIM1_uint8_t_OV_MODE
		SET_BIT(TIMSK,2);
		#elif TIM1_uint8_t_MODE == TIM1_uint8_t_CTC_MODE
		SET_BIT(TIMSK,4);
		#endif
	}
	
	else if(TIMER_Number == TIMER_2)
	{
		#if TIM1_uint8_t_MODE == TIM1_uint8_t_OV_MODE
		SET_BIT(TIMSK,6);
		#elif TIM1_uint8_t_MODE == TIM1_uint8_t_CTC_MODE
		SET_BIT(TIMSK,7);
		#endif
	}
	else
	{
		
		uint8_tTimerErrorState=Timer_FAIL;
		
	}
	return 	uint8_tTimerErrorState;
	
}

E_STATUS TIM_voidDisableInt(uint8_t TIMER_Number)
{
	uint8_t uint8_tTimerErrorState=Timer_SUCCESS;
	if(TIMER_Number == TIMER_0)
	{
		#if TIM0_uint8_t_MODE == TIM0_uint8_t_OV_MODE
		CLEAR_BIT(TIMSK,0);
		#elif TIM0_uint8_t_MODE == TIM0_uint8_t_CTC_MODE
		CLEAR_BIT(TIMSK,1);
		#endif
	}
	else if(TIMER_Number == TIMER_1)
	{
		#if TIM1_uint8_t_MODE == TIM1_uint8_t_OV_MODE
		CLEAR_BIT(TIMSK,2);
		#elif TIM1_uint8_t_MODE == TIM1_uint8_t_CTC_MODE
		CLEAR_BIT(TIMSK,4);
		#endif
	}
	else if(TIMER_Number == TIMER_2)
	{
		#if TIM0_uint8_t_MODE == TIM0_uint8_t_OV_MODE
		CLEAR_BIT(TIMSK,6);
		#elif TIM0_uint8_t_MODE == TIM0_uint8_t_CTC_MODE
		CLEAR_BIT(TIMSK,7);
		#endif
	}
	else
	{
		
		uint8_tTimerErrorState=Timer_FAIL;
		
	}
	return 	uint8_tTimerErrorState;
	
}

E_STATUS TIM_voidSetRegister(uint8_t TIMER_Number, uint16_t Copy_uint8_tValue)
{
	uint8_t uint8_tTimerErrorState=Timer_SUCCESS;
	if(TIMER_Number == TIMER_0)
	{
		TCNT0 = Copy_uint8_tValue;
	}
	else if(TIMER_Number == TIMER_1)
	{
		//	TCNT1 = Copy_uint8_tValue;
		TCNT1H = (uint8_t)(Copy_uint8_tValue>>8);
		TCNT1L = (uint8_t) (Copy_uint8_tValue);
	}
	else if(TIMER_Number == TIMER_0)
	{
		TCNT2 = Copy_uint8_tValue;
	}
	else
	{
		uint8_tTimerErrorState=Timer_FAIL;
	}
	return 	uint8_tTimerErrorState;
}

E_STATUS TIM_voidSetCTCRegister(uint8_t TIMER_Number, uint16_t Copy_uint8_tValue)
{
	uint8_t uint8_tTimerErrorState=Timer_SUCCESS;
	if(TIMER_Number == TIMER_0)
	{
		OCR0 = Copy_uint8_tValue;
	}
	else if(TIMER_Number == TIMER_1)
	{
		//OCR1A = Copy_uint8_tValue;
		OCR1AH = (uint8_t)(Copy_uint8_tValue>>8);
		OCR1AL = (uint8_t) (Copy_uint8_tValue);
	}
	else if(TIMER_Number == TIMER_2)
	{
		//OCR1A = Copy_uint8_tValue;
		OCR2 = Copy_uint8_tValue;
	}
	else
	{
		uint8_tTimerErrorState=Timer_FAIL;
	}
	return 	uint8_tTimerErrorState;
}

E_STATUS TIM_voidSetCallBack(uint8_t TIMER_Number, void(*Copy_ptr) (void))
{
	uint8_t uint8_tTimerErrorState=Timer_SUCCESS;
	if(TIMER_Number == TIMER_0)
	{
		TIM0_CallBack = Copy_ptr;
	}
	else if(TIMER_Number == TIMER_1)
	{
		TIM1_CallBack = Copy_ptr;
	}
	else if(TIMER_Number == TIMER_2)
	{
		TIM2_CallBack = Copy_ptr;
	}
	else
	{
		uint8_tTimerErrorState=Timer_FAIL;
	}
	return 	uint8_tTimerErrorState;
}

/*TIMER0 Overflow*/
void __vector_11 (void)	__attribute__((signal,used));
void __vector_11 (void)
{
	TIM0_CallBack();
}
/*TIMER0 Compare match*/

void __vector_10 (void)	__attribute__((signal,used));
void __vector_10 (void)
{
	TIM0_CallBack();
}
/************************************************/

/*TIMER1 OVF*/
void __vector_9 (void)	__attribute__((signal,used));
void __vector_9 (void)
{
	TIM1_CallBack();
}
/*TIMER1 COMPA*/
void __vector_7 (void)	__attribute__((signal,used));
void __vector_7 (void)
{
	TIM1_CallBack();
}


/************************************************/



/*TIMER1 Overflow*/
void __vector_5 (void)	__attribute__((signal,used));
void __vector_5 (void)
{
	TIM2_CallBack();
}
/*TIMER0 Compare match*/

void __vector_4 (void)	__attribute__((signal,used));
void __vector_4 (void)
{
	TIM2_CallBack();
}
/************************************************/
