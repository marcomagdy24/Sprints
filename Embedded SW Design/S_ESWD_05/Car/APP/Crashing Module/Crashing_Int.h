/*
 * CRASHING_Int.h
 *
 * Created: 17-Aug-21 12:03:32 AM
 *  Author: Ayman
 */ 


#ifndef CRASHING_INT_H_
#define CRASHING_INT_H_

/******************************************************************************
*                              INCLUDES										  *
*******************************************************************************/
#include "../../UTILS/types.h"
#include "../../UTILS/utils.h"
#include "../Steering Module/Steering_Int.h"

/******************************************************************************
*                              LOCAL MACROS									  *
*******************************************************************************/
/* ---SPEED CONFIGURATIONS --------------------*/
#define MOTOR_MIN_SPEED			  (uint8_t)(0)
#define MOTOR_MAX_SPEED			  (uint8_t)(100)

#define STATE_MOTOR_STOP	      (uint8_t)(0)
#define STATE_MOTOR_FORWARD       (uint8_t)(1)
#define STATE_MOTOR_BACKWARD      (uint8_t)(2)
#define STATE_MOTOR_RIGHT	      (uint8_t)(3)
#define STATE_MOTOR_LEFT	      (uint8_t)(4)
#define STATE_MOTOR_INIT	      (uint8_t)(255)

/******************************************************************************
*                               APIS DECLARATIONS	                          *
*******************************************************************************/
E_STATUS CrashingModule_GetDirection(ptr_uint8_t MotorDirection);
E_STATUS CrashingModule_GetSpeed(ptr_uint8_t Speed);

#endif /* CRASHING_INT_H_ */