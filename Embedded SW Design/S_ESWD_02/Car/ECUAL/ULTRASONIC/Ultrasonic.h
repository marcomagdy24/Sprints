/*
 * Ultrasonic.h
 *
 *  Created on: 10/8/2021
 *      Author: Bishoy Nabil
 */

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include "UltraSonic_config.h"
#include "../../Utils/delay.h"
#include "../../MCAL/DIO/DIO.h"
#include "../../MCAL/INTERRUPT/interrupt.h"
#include "../../MCAL/TIMER/Timer_Int.h"

E_STATUS ULTRASONIC_INIT(void);
E_STATUS ULTRASONIC_GetDist(ptr_float32_t distance);

#endif /* ULTRASONIC_H_ */
