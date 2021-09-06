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
#include "../Displaying Module/Displaying_MainFunction.h"
#include "../Steering Module/Steering_MainFunction.h"
#include "../Sensing Module/Sensing_MainFunction.h"
#include "../Crashing Module/Crashing_MainFunction.h"

uint8_t APP_INIT();
uint8_t APP_UPDATE();

#endif /* PWM_H_ */