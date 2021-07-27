/*
* timers.c
*
* Created: 7/11/2021 11:27:39 AM
*  Author: Marco
*/

#include "timers.h"

uint8_t TOV_Number ;

static void (*Ptr_To_OVFI)(void);
static void (*Ptr_To_OCMI)(void);

void TIMER0_MODE_status(EN_TIMER0_MODE_T MODE){
	switch (MODE){
		case TIMER0_NORMAL_MODE:{
			RESET_BIT(TCCR0,WGM00);
			RESET_BIT(TCCR0,WGM01);
			break;
		}
		case TIMER0_PHASE_CORRECT_PWM_MODE:{
			SET_BIT(TCCR0,WGM00);
			RESET_BIT(TCCR0,WGM01);
			break;
		}
		case TIMER0_CTC_MODE:{
			RESET_BIT(TCCR0,WGM00);
			SET_BIT(TCCR0,WGM01);
			break;
		}
		case TIMER0_FAST_PWM_MODE:{
			SET_BIT(TCCR0,WGM00);
			SET_BIT(TCCR0,WGM01);
			break;
		}
	}
}

void TIMER0_OCIE_status(EN_TOIE0_T TOIE){
	switch (TOIE){
		case TOIE0_DISABLE:{
			RESET_BIT(TIMSK, OCIE0);
			break;
		}
		case TOIE0_ENABLE:{
			SET_BIT(TIMSK,OCIE0);
			break;
		}
	}
}

void TIMER0_OVFI_status(EN_TOIE0_T TOIE){
	switch (TOIE){
		case TOIE0_DISABLE:{
			RESET_BIT(TIMSK, TOIE0);
			break;
		}
		case TOIE0_ENABLE:{
			SET_BIT(TIMSK,TOIE0);
			break;
		}
	}
}

E_STATUS Timer_Init(ST_TIMER_config_T* configurations){
	E_STATUS au8_error = E_INVALID;
	if ((configurations->Timer0_Mode >= TIMER0_NORMAL_MODE) && (configurations->Timer0_Mode <= TIMER0_FAST_PWM_MODE)){
		TIMER0_MODE_status(configurations->Timer0_Mode);
		au8_error = E_OK;
	}
	if ((configurations->Timer0_OVFI == TOIE0_ENABLE) || (configurations->Timer0_OVFI == TOIE0_DISABLE)){
		TIMER0_OVFI_status(configurations->Timer0_OVFI);
		au8_error = E_OK;
	}
	if ((configurations->Timer0_OCIE == OCIE0_ENABLE) || (configurations->Timer0_OCIE == OCIE0_DISABLE)){
		TIMER0_OCIE_status(configurations->Timer0_OCIE);
		au8_error = E_OK;
	}
	if ((configurations->Timer0_PRESCALAR >= TIMER0_STOP) && (configurations->Timer0_PRESCALAR <= EXTERNAL_RISING)){
		TCCR0 |= configurations->Timer0_PRESCALAR;
		au8_error = E_OK;
	}
	TCNT0 = 0;
	return au8_error;
	
}

E_STATUS Timer_OC0_Mode(EN_OC0_MODE_T mode){
	E_STATUS au8_error = E_INVALID;
	if ((mode >= OC0_DISCONNECTED) && (mode <= OC0_INVERTING)){
		au8_error = E_OK;
		switch (mode){
			case OC0_DISCONNECTED:{
				RESET_BIT(TCCR0, COM00);
				RESET_BIT(TCCR0, COM01);
				break;
			}
			case OC0_TOGGLE:{
				SET_BIT(TCCR0, COM00);
				RESET_BIT(TCCR0, COM01);
				break;
			}
			case OC0_NON_INVERTING:{
				RESET_BIT(TCCR0, COM00);
				SET_BIT(TCCR0, COM01);
				break;
			}
			case OC0_INVERTING:{
				SET_BIT(TCCR0, COM00);
				SET_BIT(TCCR0, COM01);
				break;
			}
		}
	}
	return au8_error;
}

E_STATUS Timer_Stop(){
	TCCR0 = STOP_TIMER;
	return E_OK;
}

E_STATUS Timer0_Read_Counter(uint8_t* uint8_tNumOfTicks){
	*uint8_tNumOfTicks = TCNT0;
	return E_OK;
}

E_STATUS Timer0_Set_Compare_Value(uint8_t uint8_tVal){
	OCR0 = uint8_tVal;
	return E_OK;
}

E_STATUS Timer0_Set_Counter_Value(uint8_t uint8_tVal){
	TCNT0 = uint8_tVal;
	return E_OK;
}

E_STATUS Timer0_Set_TOV_Number(uint8_t uint8_tVal){
	TOV_Number = uint8_tVal;
	return E_OK;
}

E_STATUS Timer0_Get_TOV_Number (uint8_t *uint8_tVal){
	*uint8_tVal = TOV_Number ;
	return E_OK;
}

E_STATUS Timer0_Get_Ticks_of_SWcounter (uint32_t *uint8_tVal){
	*uint8_tVal =  256*TOV_Number + TCNT0;
	return E_OK;
}

E_STATUS callback_Timer0_Overflow_Interrupt (void(*Ptr_to_OVI_Function)(void)){
	Ptr_To_OVFI = Ptr_to_OVI_Function;
	return E_OK;
}
E_STATUS callback_OCR0_Compare_Match_Interrupt(void(*Ptr_to_OCM_Function)(void)){
	Ptr_To_OCMI = Ptr_to_OCM_Function;
	return E_OK;
}