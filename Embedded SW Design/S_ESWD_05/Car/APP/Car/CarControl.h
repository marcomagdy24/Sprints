/*
 * PWM.h
 *
 * Created: 8/9/2021 8:07:33 PM
 *  Author: Marco
 */ 


#ifndef CAR_H_
#define CAR_H_

/******************************************************************************
*                              INCLUDES										  *
*******************************************************************************/
#include "../Steering Module/Steering_MainFunction.h"
#include "../Sensing Module/Sensing_MainFunction.h"
#include "../Crashing Module/Crashing_MainFunction.h"
#include "../../SERVICE/TMU/TMU.h"
#include "../../MCAL/Global_INERRUPT/GIE_int.h"

/******************************************************************************
*                               APIS DECLARATIONS	                          *
*******************************************************************************/
uint8_t SYS_Init();
uint8_t SYS_Update();

#endif /* PWM_H_ */