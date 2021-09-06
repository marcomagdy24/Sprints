/*
* MotorConfig.h
*
* Created: 28-Jul-21 11:37:51 PM
*  Author: Ayman
*/


#ifndef MotorCONFIG_H_
#define MotorCONFIG_H_

/* ---MotorS CONFIGURATIONS --------------------*/
#define Motor_RIGHT        (uint8_t)(0)
#define Motor_LEFT         (uint8_t)(1)

/* ---SPEED CONFIGURATIONS --------------------*/
#define Motor_MIN_SPEED    (uint8_t)(0)
#define Motor_MAX_SPEED    (uint8_t)(100)
/* ---DIRECTION CONFIGURATIONS --------------------*/
#define Motor_FORWARD    (uint8_t)(0)
#define Motor_BACKWARD    (uint8_t)(1)

///* ---MotorS CTRL PORTS AND PINS --------------------*/
#define Motor_RIGHT_FORWARD_PORT	DIO_PORTD
#define Motor_LEFT_FORWARD_PORT		DIO_PORTD
#define Motor_RIGHT_FORWARD_PIN		PIN_3
#define Motor_LEFT_FORWARD_PIN		PIN_7
#define Motor_RIGHT_BACKWARD_PORT   DIO_PORTD
#define Motor_LEFT_BACKWARD_PORT    DIO_PORTD
#define Motor_RIGHT_BACKWARD_PIN    PIN_2
#define Motor_LEFT_BACKWARD_PIN     PIN_6
/* ---MotorS SPEED CTRL PORTS AND PINS --------------------*/
#define Motor_RIGHT_SPEED_PORT	    DIO_PORTB
#define Motor_LEFT_SPEED_PORT		DIO_PORTB
#define Motor_RIGHT_SPEED_PIN		PIN_3
#define Motor_LEFT_SPEED_PIN		PIN_3

/**********************************************************************************************************************/
///* ---MotorS CTRL PORTS AND PINS --------------------*/
//#define Motor_RIGHT_FORWARD			DIO_uint8_t_PIN_A1
//#define Motor_LEFT_FORWARD			DIO_uint8_t_PIN_A3
//
//#define Motor_RIGHT_BACKWARD		DIO_uint8_t_PIN_A0
//#define Motor_LEFT_BACKWARD		    DIO_uint8_t_PIN_A4
//
/////* ---MotorS SPEED CTRL PORTS AND PINS --------------------*/
//#define Motor_RIGHT_SPEED_PORT	    DIO_uint8_t_PIN_D7
//#define Motor_LEFT_SPEED_PORT		DIO_uint8_t_PIN_D7


/* ---ERRORS DEFINITIONS --------------------*/
typedef uint8_t Motor_ERROR_state_t;
#define    Motor_E_OK                        (Motor_ERROR_state_t)( 0 )
#define    Motor_E_NOT_OK                    (Motor_ERROR_state_t)( 1 )





#endif /* MotorCONFIG_H_ */
