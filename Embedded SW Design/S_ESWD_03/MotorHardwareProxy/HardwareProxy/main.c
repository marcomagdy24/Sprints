/*
 * HardwareProxy.c
 *
 * Created: 02-Sep-21 2:01:04 AM
 * Author : ayman
 */ 
#include "Platform/HardwareProxy/Motor_HardwareProxy.h"
#include "UTILS/delay.h"


int main(void)
{
    /* Replace with your application code */
	STR_MotorProxy_t DCmotor;
	MotorProxy_initialize(&DCmotor);
	MotorProxy_configue(&DCmotor,&PORTA,&PORTA,0,1);

	
    while (1) 
    {
			MotorProxy_mutate(&DCmotor,MOTOR_FORWARD,30);
			for(uint32_t i=0;i<500000;i++);
			MotorProxy_mutate(&DCmotor,MOTOR_BACKWARD,30);
			for(uint32_t i=0;i<500000;i++);
    }
}

