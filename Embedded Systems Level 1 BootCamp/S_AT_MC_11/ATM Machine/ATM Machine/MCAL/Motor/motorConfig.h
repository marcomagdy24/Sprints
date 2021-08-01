/*
 * motorConfig.h
 *
 * Created: 7/28/2021 12:08:06 PM
 *  Author: Marco
 */ 


#ifndef MOTORCONFIG_H_
#define MOTORCONFIG_H_
/******************************************************************************
*                              Includes													*
*******************************************************************************/
#include "../../Infrastructure/registers.h"
#include "../../Infrastructure/utils.h"
#include "../../Infrastructure/types.h"
#include "../../MCAL/DIO/dio.h"
/******************************************************************************
*                              CONSTANTS													*
*******************************************************************************/
/*------------------------------- MOTOR CONFIG -------------------------------*/
#define MOTOR_PORT			PORT_B
#define MOTOR_PORT_DIR   	DDRB
#define MOTOR_READ			PINB

#define MOTOR_PIN				(uint8_t) 1

#endif /* MOTORCONFIG_H_ */