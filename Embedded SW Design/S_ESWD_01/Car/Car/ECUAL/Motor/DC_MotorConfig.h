/*
* MotorConfig.h
*
* Created: 28-Jul-21 11:37:51 PM
*  Author: Ayman
*/


#ifndef MOTORCONFIG_H_
#define MOTORCONFIG_H_

/* ---MOTORS CONFIGURATIONS --------------------*/
#define MOTOR_RIGHT        (uint8_t)(0)
#define MOTOR_LEFT         (uint8_t)(1)

/* ---SPEED CONFIGURATIONS --------------------*/
#define MOTOR_MIN_SPEED    (uint8_t)(0)
#define MOTOR_MAX_SPEED    (uint8_t)(100)
/* ---DIRECTION CONFIGURATIONS --------------------*/
#define MOTOR_FORWARD    (uint8_t)(0)
#define MOTOR_BACKWARD    (uint8_t)(1)

///* ---MOTORS CTRL PORTS AND PINS --------------------*/
#define MOTOR_RIGHT_FORWARD_PORT	DIO_PORTD
#define MOTOR_LEFT_FORWARD_PORT		DIO_PORTD
#define MOTOR_RIGHT_FORWARD_PIN		PIN_3
#define MOTOR_LEFT_FORWARD_PIN		PIN_7
#define MOTOR_RIGHT_BACKWARD_PORT   DIO_PORTD
#define MOTOR_LEFT_BACKWARD_PORT    DIO_PORTD
#define MOTOR_RIGHT_BACKWARD_PIN    PIN_2
#define MOTOR_LEFT_BACKWARD_PIN     PIN_6
/* ---MOTORS SPEED CTRL PORTS AND PINS --------------------*/
#define MOTOR_RIGHT_SPEED_PORT	    DIO_PORTB
#define MOTOR_LEFT_SPEED_PORT		DIO_PORTB
#define MOTOR_RIGHT_SPEED_PIN		PIN_3
#define MOTOR_LEFT_SPEED_PIN		PIN_3

/**********************************************************************************************************************/
///* ---MOTORS CTRL PORTS AND PINS --------------------*/
//#define MOTOR_RIGHT_FORWARD			DIO_uint8_t_PIN_A1
//#define MOTOR_LEFT_FORWARD			DIO_uint8_t_PIN_A3
//
//#define MOTOR_RIGHT_BACKWARD		DIO_uint8_t_PIN_A0
//#define MOTOR_LEFT_BACKWARD		    DIO_uint8_t_PIN_A4
//
/////* ---MOTORS SPEED CTRL PORTS AND PINS --------------------*/
//#define MOTOR_RIGHT_SPEED_PORT	    DIO_uint8_t_PIN_D7
//#define MOTOR_LEFT_SPEED_PORT		DIO_uint8_t_PIN_D7


/* ---ERRORS DEFINITIONS --------------------*/
typedef uint8_t Motor_ERROR_state_t;
#define    MOTOR_E_OK                        (Motor_ERROR_state_t)( 0 )
#define    MOTOR_E_NOT_OK                    (Motor_ERROR_state_t)( 1 )





#endif /* MOTORCONFIG_H_ */
