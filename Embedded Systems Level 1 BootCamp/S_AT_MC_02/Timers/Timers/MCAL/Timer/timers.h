/*
* timers.h
*
* Created: 7/11/2021 11:27:48 AM
*  Author: Marco
*/


#ifndef TIMERS_H_
#define TIMERS_H_

/******************************************************************************
*                              Includes			                          *
*******************************************************************************/
#include "../../Infrastructure/registers.h"
#include "../../Infrastructure/utils.h"

/******************************************************************************
*                              CONSTANTS			                          *
*******************************************************************************/

typedef uint8_t E_STATUS;

#define E_INVALID (E_STATUS) 0
#define E_OK (E_STATUS) 1
#define TIMER0_COMP_Vector_Num 11
#define TIMER0_OVF_Vector_Num  12

#define STOP_TIMER (uint8_t) 0x00

/******************************************************************************
*                                     ENUMS                                   *
*******************************************************************************/

/*----------------------------------- PINS ----------------------------------*/
typedef enum{
	TIMER0_STOP,
	TIMER0_PRESCALER_1,
	TIMER0_PRESCALER_8,
	TIMER0_PRESCALER_64,
	TIMER0_PRESCALER_256,
	TIMER0_PRESCALER_1024,
	EXTERNAL_FALLING,
	EXTERNAL_RISING
}EN_TIMER0_PRESCALER_T;

typedef enum
{
	TIMER0_NORMAL_MODE,
	TIMER0_PHASE_CORRECT_PWM_MODE,
	TIMER0_CTC_MODE,
	TIMER0_FAST_PWM_MODE
}EN_TIMER0_MODE_T;

typedef enum
{
	OC0_DISCONNECTED,
	OC0_TOGGLE,
	OC0_NON_INVERTING,
	OC0_INVERTING
}EN_OC0_MODE_T;

/*---------------------------- Timer/CounterTimer/Counter0 Overflow Interrupt Enable --------------------------*/

typedef enum    
{
	TOIE0_DISABLE,
	TOIE0_ENABLE
}EN_TOIE0_T;

/*----------------------------- Timer/Counter0 Output Compare Match Interrupt Enable ---------------------------*/

typedef enum    
{
	OCIE0_DISABLE,
	OCIE0_ENABLE
} EN_OCIE0_t;
/*----------------------------- Output Compare Flag 0 ---------------------------*/

typedef enum
{
	OCF0_DISABLE,
	OCF0_ENABLE
}EN_OCF0_T;


typedef enum
{
	TOV0_DISABLE,
	TOV0_ENABLE
} EN_TOV0_T;


/******************************************************************************
*                               STRUCTS AND UNIONS                            *
*******************************************************************************/

/*-------------------------------- PORT CONFIG ------------------------------*/
typedef struct
{
	EN_TOIE0_T Timer0_OVFI ;
	EN_OCIE0_t Timer0_OCIE;
	EN_TIMER0_MODE_T Timer0_Mode ;
	EN_TIMER0_PRESCALER_T Timer0_PRESCALAR;
}ST_TIMER_config_T;


/******************************************************************************
*                               FUNCTION DECLARATIONS                         *
*******************************************************************************/

/*******************************************************************************
* Parameters (in) : configurations - A pointer to a structure (uint8_t port, uint8_t pin, uint8_t dir)
* Parameters (out): None
* Return Value : Error - For error handling if the user input another index for port
* Description : Initialize DIO pins to be input or output
********************************************************************************/
E_STATUS Timer_Init(ST_TIMER_config_T* configurations);
E_STATUS Timer_OC0_Mode(EN_OC0_MODE_T mode);
E_STATUS Timer_Stop();
E_STATUS Timer0_Read_Counter(uint8_t* uint8_tNumOfTicks);
E_STATUS Timer0_Set_Compare_Value(uint8_t uint8_tVal);
E_STATUS Timer0_Set_Counter_Value(uint8_t uint8_tVal);
E_STATUS Timer0_Set_TOV_Number(uint8_t uint8_tVal);
E_STATUS Timer0_Get_TOV_Number(uint8_t *uint8_tVal);
E_STATUS Timer0_Get_Ticks_of_SWcounter (uint32_t *uint8_tVal);
E_STATUS callback_Timer0_Overflow_Interrupt (void(*Ptr_to_OVI_Function)(void));
E_STATUS callback_OCR0_Compare_Match_Interrupt(void(*Ptr_to_OCM_Function)(void));
#endif /* TIMERS_H_ */