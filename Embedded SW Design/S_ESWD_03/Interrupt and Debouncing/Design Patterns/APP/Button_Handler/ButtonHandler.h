/*
 * ButtonHandler.h
 *
 * Created: 8/22/2021 3:00:30 PM
 *  Author: Marco
 */ 


#ifndef BUTTONHANDLER_H_
#define BUTTONHANDLER_H_

#include "../../UTILS/utils.h"
#include "../../UTILS/types.h"
#include "../../UTILS/Interrupt_Vector_Table.h"
#include "../../ECUAL/LED/LED.h"
#include "../../ECUAL/BUTTON/Button.h"
#include "../../MCAL/INTERRUPT/interrupt.h"


extern ButtonVectorPtr oldVectors[10];
/* Operations */
void ButtonHandler_Install(void);
void ButtonHandler_DeINIT(void);
void ButtonHandler_EventReceive();
void handleButtonPushInterrupt(void);
void handleButtonReleaseInterrupt(void);
LED ButtonHandler_getItsLED(void); 
void ButtonHandler_setItsLED(LED p_LED);
BUTTON ButtonHandler_getItsButton(void);
void ButtonHandler_setItsButton(BUTTON p_button);


#endif /* BUTTONHANDLER_H_ */