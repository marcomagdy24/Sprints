/*
 * Traffic_Lights.h
 *
 * Created: 7/14/2021 7:48:02 PM
 *  Author: Marco
 */ 


#ifndef TRAFFIC_LIGHTS_H_
#define TRAFFIC_LIGHTS_H_

/******************************************************************************
*                              Includes													*
*******************************************************************************/
#include "../../MCAL/UART/uart.h"
#include "../../MCAL/DIO/dio.h"

/******************************************************************************
*                              CONSTANTS													*
*******************************************************************************/
#define INTRO_TERMINAL_MESSAGE     (uint8_t* )("Welcome to our Traffic Lights System\r")
#define START_MESSAGE              (uint8_t* )("START")
#define START_TERMINAL_MESSAGE     (uint8_t* )("[REPLY] Green LED is on\r")
#define WAIT_MESSAGE               (uint8_t* )("WAIT")
#define WAIT_TERMINAL_MESSAGE      (uint8_t* )("[REPLY] Yellow LED is on\r")
#define STOP_MESSAGE               (uint8_t* )("STOP")
#define STOP_TERMINAL_MESSAGE      (uint8_t* )("[REPLY] Red LED is on\r")
#define AT_MESSAGE					  (uint8_t* )("AT")
#define OK_TERMINAL_MESSAGE		  (uint8_t* )("[REPLY] OK\r")
#define INVALID_TERMINAL_MESSAGE	  (uint8_t* )("[INFO] Invalid message\r")

/******************************************************************************
*                               FUNCTION DECLARATIONS                         *
*******************************************************************************/
void Traffic_Init(void);
void Traffic_Update(void);

#endif /* TRAFFIC_LIGHTS_H_ */