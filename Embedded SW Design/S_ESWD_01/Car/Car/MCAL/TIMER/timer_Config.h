/****************************************/
/* Author  : Monica Francis				*/
/* Date    : 6/3/2018					*/
/* Version : V01						*/
/****************************************/

#ifndef _TIM0_CONFIG_H
#define _TIM0_CONFIG_H

/*OPTIONS :		TIM0_uint16_t_DIV_1			*/
/*				TIM0_uint16_t_DIV_8			*/
/*				TIM0_uint16_t_DIV_64			*/
/*				TIM0_uint16_t_DIV_256		*/
/*				TIM0_uint16_t_DIV_1024		*/
#define	TIM0_uint16_t_PRESCALER	TIM0_uint16_t_DIV_1024

/*OPTIONS :		TIM0_uint8_t_OV_MODE			*/
/* 				TIM0_uint8_t_CTC_MODE		*/
#define TIM0_uint8_t_MODE	TIM0_uint8_t_OV_MODE

/****************************************/

/*OPTIONS :		TIM1_uint16_t_DIV_1			*/
/*				TIM1_uint16_t_DIV_8			*/
/*				TIM1_uint16_t_DIV_64			*/
/*				TIM1_uint16_t_DIV_256		*/
/*				TIM1_uint16_t_DIV_1024		*/

#define	TIM1_uint16_t_PRESCALER	TIM1_uint16_t_DIV_1024

/* OPTIONS : 		TIM1_uint8_t_CTC_MODE	*/
/*					TIM1_uint8_t_OV_MODE		*/
#define TIM1_uint8_t_MODE		TIM1_uint8_t_OV_MODE

#endif
