/*
 * PWM.h
 *
 * Created: 8/10/2021 12:10:22 AM
 *  Author: Marco
 */ 


#ifndef PWM_H_
#define PWM_H_

/******************************************************************************
*                              INCLUDES										  *
*******************************************************************************/
#include "../../Utils/registers.h"
#include "PWM_Config.h"

/******************************************************************************
*                              CONSTANTS									  *
*******************************************************************************/
typedef enum {
	PWM_TIMER0,
	PWM_TIMER2
}PWM_TIMER;

/* Timer PRESCALER */
typedef enum {
	PWM_PRESCALLER_DIV_STOPPED,
	PWM_PRESCALLER_DIV_1,
	PWM_PRESCALLER_DIV_8,
	PWM_PRESCALLER_DIV_64,
	PWM_PRESCALLER_DIV_256,
	PWM_PRESCALLER_DIV_1024,
	PWM_PRESCALLER_DIV_FALLING_EDGE,
	PWM_PRESCALLER_DIV_RISING_EDGE
}PWM_PRESCALLER;

/* select mode*/
typedef enum {
	PWM_MODE_PHASECORRECTPWM = (0x40),
	PWM_MODE_FASTPWM = (0x48)
}PWM_MODES;

/* Compare Output Mode*/
typedef enum {
	PWM_OC0_DISCONNECTED_MODE,
	PWM_OC0_NONINVERTING_MODE = (0x20),
	PWM_OC0_INVERTING_MODE	  = (0x30)
}PWM_OC0_MODE;

/******************************************************************************
*                               FUNCTION DECLARATIONS                         *
*******************************************************************************/
E_STATUS PWM_START(PWM_TIMER TimerNo, uint8_t dutyCycle);
E_STATUS PWM_STOP(PWM_TIMER TimerNo);

#endif /* PWM_H_ */