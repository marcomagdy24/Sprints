/*
* timers.h
*
*
*      Author: Bishoy Nabil
*/

#ifndef TIMER_H_
#define TIMER_H_

#include "../../UTILS/utils.h"
#include "../../UTILS/types.h"
#include "../../UTILS/registers.h"


/*****************************************************Common Configurations*********************************************************/
//timer delay return
#define PENDING           0
#define SUCCESS           1
#define ERROR	          2
#define WAITING	          3
//unique priority numbers
#define PRIORITY_NUMBERS			 10

#define TIMER0_OVF_vect				_VECTOR(11)
#define TIMER1_OVF_vect				_VECTOR(9)
#define TIMER2_OVF_vect				_VECTOR(5)

typedef enum
{
	INT_DISABLE,INT_ENABLE
}EN_intState_t;


typedef enum
{
	DISCONNECT,TOGGLE,CLEAR_NON_INVERTING,SET_INVERTING
}EN_outputMode_t;

typedef enum
{
	NO_CLOCK,F_CPU_CLOCK,F_CPU_8,F_CPU_64,F_CPU_256,F_CPU_1024
}EN_clock_t;

typedef enum
{
	TIMER_0,TIMER_1,TIMER_2
}EN_timerno_t;

/***********************************************Timer Configurations Structure******************************************************/
typedef enum Timer16Mode{
	OVERFLOW_16,PWM_P_8,PWM_P_9,PWM_P_10,CTC_OCR,F_PWM_8,F_PWM_9,F_PWM_10,PWM_ICR_BOTTOM,PWM_OCR_BOTTOM,
	PWM_ICR_TOP,PWM_OCR_TOP,CTC_ICR,F_PWM_ICR_BOTTOM = 14,F_PWM_OCR_BOTTOM = 15, OVERFLOW,PWM,COMPARE 
}EN_timer16Mode_t;

typedef struct TimerConfig
{
	EN_timerno_t timer;	 /*choose the timer number*/
	EN_timer16Mode_t mode; /*choose the timer mode*/
	EN_clock_t prescaler; /*choose the pre-scaler*/
	uint16_t initialValue; /*choose initial value*/
	uint16_t compareValue; /*choose compare value*/
	EN_outputMode_t output; /*choose the output mode*/
	EN_intState_t interrupt; /*interrupt enable/disable*/
}ST_TimerConfig_t;

/***********************************************Timer1 Configurations Structure********************************************************/


typedef struct Timer16Config
{	EN_timer16Mode_t mode; /*choose the timer mode*/
	EN_clock_t prescaler; /*choose the pre-scaler*/
	unsigned short initialValue; /*choose initial value*/
	unsigned short compareValue; /*choose compare value*/
	EN_outputMode_t output; /*choose the output mode*/
	EN_intState_t interrupt; /*Enable/disable interrupt*/
}ST_Timer16Config_t;


/************************************************Timers Prototypes**********************************************************************/
E_STATUS TIMER_Init(ST_TimerConfig_t* config_ptr); /*Initialize timer*/
E_STATUS TIMER_Deinit(EN_timerno_t timer); /*Stop timer*/
E_STATUS TIMER_NonBlockingDelay(EN_timerno_t timer, uint32_t time, uint8_t u8_statePriority);		/*Stop timer*/
E_STATUS Timer_tSetTMRValue(EN_timerno_t timer,uint16_t TMRValue);
/******************************************************Call Back Functions Prototype****************************************************/
void TIMER0_OVF_interrupt(void(*a_ptr)(void)); /*Timer0 OVERFLOW Interrupt Service Routine*/
void TIMER0_COMP_interrupt(void(*a_ptr)(void));/*Timer0 COMPARE Interrupt Service Routine*/
void TIMER1_OVF_interrupt(void(*a_ptr)(void)); /*Timer1 OVERFLOW Interrupt Service Routine*/
void TIMER1_COMPA_interrupt(void(*a_ptr)(void)); /*Timer1 COMPARE A Interrupt Service Routine*/
void TIMER1_COMPB_interrupt(void(*a_ptr)(void)); /*Timer1 COMPARE B Interrupt Service Routine*/
void TIMER2_OVF_interrupt(void(*a_ptr)(void)); /*Timer2 OVERFLOW Interrupt Service Routine*/
void TIMER2_COMP_interrupt(void(*a_ptr)(void)); /*Timer2 COMPARE Interrupt Service Routine*/

#endif /* TIMER_H_ */