/*
 * MotorInt.h
 *
 * Created: 16-Aug-21 6:02:46 PM
 *  Author: Ayman
 */ 


#ifndef MotorINT_H_
#define MotorINT_H_

/******************************************************************************
*                              INCLUDES										  *
*******************************************************************************/
#include "../../UTILS/types.h"
#include "../../UTILS/utils.h"
#include "../Crashing Module/Crashing_Int.h"

/******************************************************************************
*                               APIS DECLARATIONS	                          *
*******************************************************************************/
E_STATUS Steering_SetDirection(ptr_uint8_t MotorDirection);
E_STATUS Steering_SetSpeed(ptr_uint8_t MotorSpeed);

#endif /* MotorINT_H_ */
