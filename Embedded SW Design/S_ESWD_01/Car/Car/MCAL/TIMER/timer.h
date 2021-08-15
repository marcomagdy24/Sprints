/********************************************/
/* Author  : Monica Francis		    		*/
/* Date    : 6/3/2018				    	*/
/* Version : V01						    */
/********************************************/

#ifndef _TIM0_INT_H
#define _TIM0_INT_H
/*****************************************************************************/
/*registers*/
#include "../../UTILS/registers.h"
#include "timer_Config.h"
#include "../../UTILS/types.h"
#include "../../UTILS/utils.h"


/*TIMER_Number*/
#define TIMER_0	0
#define TIMER_1	1
#define TIMER_2	2
/*return */
#define Timer_SUCCESS 1
#define Timer_FAIL    0

E_STATUS TIM_voidInitialize(uint8_t TIMER_Number);

E_STATUS TIM_voidEnableInt(uint8_t TIMER_Number);

E_STATUS TIM_voidDisableInt(uint8_t TIMER_Number);

E_STATUS TIM_uint8_tDeInit(uint8_t TIMER_Number);

#if TIM0_uint8_t_MODE == TIM0_uint8_t_OV_MODE
E_STATUS  TIM_voidSetRegister(uint8_t TIMER_Number, uint16_t Copy_uint8_tValue);


#elif TIM0_uint8_t_MODE == TIM0_uint8_t_CTC_MODE
E_STATUS TIM_voidSetCTCRegister(uint8_t TIMER_Number, uint16_t Copy_uint8_tValue);
#endif

E_STATUS TIM_voidSetCallBack(uint8_t TIMER_Number, void(*Copy_ptr) (void));

#endif
