/*
 * Timer_Interface.h
 *
 * Created: 23-Jul-21 6:51:52 PM
 *  Author: Ayman
 */ 


#ifndef TIMER_INT_H_
#define TIMER_INT_H_
#include "../../UTILS/registers.h"
#include "../../Utils/types.h"
#include "../../Utils/utils.h"
uint8_t Timer_sint8_tInit(uint8_t timer,uint8_t mode,uint32_t prescaller);
uint8_t Timer_sint8_tSetTMRValue(uint8_t timer,uint16_t TMRValue);
uint8_t Timer_sint8_tInterruptEnable(uint8_t timer,uint8_t type);
uint8_t Timer_sint8_tInterruptDisable(uint8_t timer,uint8_t type);
uint8_t Timer_sint8_tCompareOutputMode(uint8_t timer,uint8_t mode);
uint8_t Timer_sint32_tTMRValue(uint8_t timer,uint16_t*TimerCountsValue);
uint8_t Timer_sint8_tStop(uint8_t timer);
uint8_t Timer_NonBlockingdelay(uint8_t timer, uint32_t time, uint8_t u8_statePriority);
void __vector_5 (void) __attribute__((signal));
void __vector_9 (void) __attribute__((signal));
void __vector_11 (void) __attribute__((signal));
//modes
#define NORMAL 		 0
#define PWM   		 1
#define CTC  		 2
#define FPWM  		 3
#define PWMPH8  	 4
#define PWMPH9  	 5
#define PWMPH10  	 6
#define CTCOCR  	 7
#define CTCICR   	 8
#define FPWM8    	 9
#define FPWM9   	 10
#define FPWM10   	 11
#define PWMPHFRICR   12
#define PWMPHFROCR   13
#define PWMPHICR   	 14
#define PWMPHOCR   	 15
#define FPWMICR   	 16
#define FPWMOCR   	 17
//timers and registers
#define TMR0_CHOICE     		  0
#define TMR1_CHOICE    	      1
#define TMR2_CHOICE     		  2
#define TMR1A_CHOICE      		  3
#define TMR1B_CHOICE      		  4
#define TMR1H_CHOICE      		  5    //for TCNTH register
#define TMR1L_CHOICE      		  6    //for TCNTL register
#define OCR1A_CHOICE   	      7
#define OCR1AH_CHOICE    		  8
#define OCR1AL_CHOICE   		  9
#define OCR1B_CHOICE    		 10
#define OCR1BH_CHOICE   		 11
#define OCR1BL_CHOICE    		 12
#define ICR1_CHOICE      		 13
#define ICR1H_CHOICE     		 14
#define ICR1L_CHOICE     		 15
#define OCR2_CHOICE	         16
#define OCR0_CHOICE			 17


//prescalers
#define PRS1	   0
#define PRS8       1
#define PRS32      2
#define PRS64      3
#define PRS128     4
#define PRS256     5
#define PRS1024    6
#define PRESOFF    7
//interrupts
#define TOIE_CHOICE       0
#define OSCIE_CHOICE      1
#define OSCIEA_CHOICE     2
#define OSCIEB_CHOICE     3
#define TICIE_CHOICE      4
//compare output modes
#define NORMALOPERATION  0
#define TOGGLE           1
#define CLEAR            2
#define SET              3
#define TIMERERROR       -1
#define TIMERVALID        1
//timer delay return
#define PENDING           0
#define SUCCESS           1
#define ERROR	          2
#define WAITING	          3
//unique priority numbers
#define PRIORITY_NUMBERS			 10

#endif /* TIMER_INTERFACE_H_ */
