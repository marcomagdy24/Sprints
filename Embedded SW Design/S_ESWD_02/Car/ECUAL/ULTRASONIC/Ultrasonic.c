/*
* main.c
*
*  Created on: 10/8/2021
*      Author: Bishoy Nabil
*/



/********************************************/
#include "Ultrasonic.h"
/**********************************************/


uint16_t g_timer1=0;
uint8_t g_tick=0;


E_STATUS ULTRASONIC_INIT(void)
{
	if(((ULTRASONIC_Trigger_PORT >= DIO_PORTA) && (ULTRASONIC_Trigger_PORT <= DIO_PORTD))
	&&((ULTRASONIC_Trigger_PIN>=PIN_0)&&(ULTRASONIC_Trigger_PIN<=PIN_7)))
	{
		configs.port = ULTRASONIC_Trigger_PORT;
		configs.pin = ULTRASONIC_Trigger_PIN;
		configs.dir = OUTPUT;
		DIO_Init(&configs);
		configs.port = ULTRASONIC_ECHO_PORT;
		configs.pin = ULTRASONIC_ECHO_PIN;
		configs.dir = INPUT;
		DIO_Init(&configs);
		external_interrupt_init(interrupt2,rising_edge);
		return E_OK;
	}
	else
	{
		return E_NOK;
	}
}


E_STATUS ULTRASONIC_GetDist(ptr_float32_t distance)
{
	
	DIO_WritePIN(ULTRASONIC_Trigger_PORT, ULTRASONIC_Trigger_PIN, LOW);
	_delay_us(2);
	DIO_WritePIN(ULTRASONIC_Trigger_PORT, ULTRASONIC_Trigger_PIN, HIGH);
	_delay_us(10);
	DIO_WritePIN(ULTRASONIC_Trigger_PORT, ULTRASONIC_Trigger_PIN, LOW);
	/*(registerReading*time of tick*speed of sound)/2*/
	/*time of tick =1024/8000000=128*10^-6 S = 128Ms*/
	/*dist = (Reading * 128 * 0.034)/2*/
	*distance=g_timer1*2.176;
	if (*distance >= 400)
	{
		*distance = 400;
	}
	else if (*distance <= 2)
	{
		*distance = ONE;
	}
	return E_OK;
	
}

ISR(INT2_vect)
{
	g_tick++;
	if(g_tick==1)
	{
		Timer_sint8_tSetTMRValue(TMR1_CHOICE, 0);
		Timer_sint8_tInit(TMR1_CHOICE, NORMAL, PRS1024);
		external_interrupt_init(interrupt2,falling_edge);
	}
	else if(g_tick==2)
	{
		Timer_sint32_tTMRValue(TMR1_CHOICE, &g_timer1);
		external_interrupt_init(interrupt2,rising_edge);
		Timer_sint8_tStop(TMR1_CHOICE);
		g_tick=0;
	}
	else
	{
		
	}
}
