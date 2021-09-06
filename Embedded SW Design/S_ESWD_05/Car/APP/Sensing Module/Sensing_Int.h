/*
 * Sensor_Int.h
 *
 * Created: 16-Aug-21 7:22:20 PM
 *  Author: Ayman
 */ 


#ifndef SENSOR_INT_H_
#define SENSOR_INT_H_

/******************************************************************************
*                              INCLUDES										  *
*******************************************************************************/
#include "Sensing_Int.h"
#include "../../ECUAL/ULTRASONIC/Ultrasonic.h"

/******************************************************************************
*                               APIS DECLARATIONS	                          *
*******************************************************************************/
E_STATUS SensingGetDistance(ptr_float32_t Sensor_distance);


#endif /* SENSOR_INT_H_ */