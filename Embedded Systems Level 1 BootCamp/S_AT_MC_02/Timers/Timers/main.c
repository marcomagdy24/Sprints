/*
* Timers.c
*
* Created: 7/11/2021 11:27:10 AM
* Author : Marco
*/
#define F_CPU 1000000ul

#include "MCAL/Timer/timers.h"
#include "MCAL/DIO/dio.h"

//void T0_Delay (void)
//{
//TCNT0 = 0x20;                       // load TCNT0
//TCCR0 = 0x01;                      // Timer0, Normal mode, no prescaler
//while ((TIFR&0x1) ==0);      // wait for TF0 to roll over
//
//TIFR = 0x1;                            // clear TF0
//}

int main(void)
{
	ST_DIO_config port_b_5 = {DIO_PORTB, PIN_5, OUTPUT};
	DIO_Init(&port_b_5);
	ST_TIMER_config_T TM0 = {TOIE0_DISABLE, OCIE0_DISABLE, TIMER0_NORMAL_MODE, TIMER0_PRESCALER_1};
	while (1)
	{
		DIO_Write_PIN(DIO_PORTB, PIN_5, HIGH);
		Timer_Init(&TM0);
		Timer0_Set_Counter_Value(0x20);
		TCCR0 = 0x01;                      // Timer0, Normal mode, no prescaler
		while (!(READ_BIT(TIFR, TOV0)));      // wait for TF0 to roll over
		Timer_Stop();
		TIFR = 0x1;								// repeat forever
		DIO_Write_PIN(DIO_PORTB, PIN_5, LOW);
		Timer0_Set_Counter_Value(0x20);                       // load TCNT0
		TCCR0 = 0x01;                      // Timer0, Normal mode, no prescaler
		while (!(READ_BIT(TIFR, TOV0)));      // wait for TF0 to roll over
		Timer_Stop();
		TIFR = 0x1;
	}
}



