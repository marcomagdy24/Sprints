/*
 * Motor_HardwareProxy.h
 *
 * Created: 02-Sep-21 3:01:24 AM
 *  Author: ayman
 */ 


#ifndef MOTOR_HARDWAREPROXY_H_
#define MOTOR_HARDWAREPROXY_H_

#include "../../ECUAL/Motor/DC_Motor.h"

typedef struct  
{
	ptr_uint8_t Motor_Forwardport;
	ptr_uint8_t Motor_Backwardport;
	
	uint8_t Motor_ForwardPin;
	uint8_t Motor_BackwardPin;
	uint8_t Motor_Direction;
	uint8_t Motor_Speed;   
	
}STR_MotorProxy_t;

void MotorProxy_initialize(STR_MotorProxy_t* MotorProxy);
void MotorProxy_configue(STR_MotorProxy_t* MotorProxy,ptr_uint8_t Motor_ForwardPortaddress,ptr_uint8_t Motor_Backwardportaddress
,uint8_t Motor_ForwardPin,uint8_t Motor_BackwardPin);
void MotorProxy_disable(STR_MotorProxy_t* MotorProxy);
void MotorProxy_access(STR_MotorProxy_t* MotorProxy,ptr_uint8_t Motor_Direction,ptr_uint8_t Motor_Speed);
void MotorProxy_mutate(STR_MotorProxy_t* MotorProxy,uint8_t Motor_Direction,uint8_t Motor_Speed);


#endif /* MOTOR_HARDWAREPROXY_H_ */