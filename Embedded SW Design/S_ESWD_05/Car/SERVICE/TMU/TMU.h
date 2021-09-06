/*
 * TMU.h
 *
 * Created: 8/29/2021 5:24:34 PM
 *  Author: Marco
 */ 


#ifndef TMU_H_
#define TMU_H_

/******************************************************************************
*                              INCLUDES										  *
*******************************************************************************/
#include "TMU_Config.h"
#include "../../MCAL/Timer/Timer_Int.h"
#include "../../MCAL/Power Management/PM.h"
#include "../../MCAL/INTERRUPT/interrupt.h"

/******************************************************************************
*                               STRUCTS AND UNIONS                            *
*******************************************************************************/
typedef struct 
{
	uint8_t u8_ID;
	uint8_t u8_Priority;
	uint8_t u8_FirstDelay;
	uint8_t u8_Periodicity;
// 	uint8_t u8_CurrentState;
	Ptr_VoidFuncVoid_t pvf_Task;
}ST_Task_Config_t;

/******************************************************************************
*                               APIS DECLARATIONS	                          *
*******************************************************************************/
E_STATUS TMU_Init();
E_STATUS TMU_Run();
E_STATUS TMU_CreateTask(ST_Task_Config_t* configs);
E_STATUS TMU_DeleteTask(uint8_t u8_TaskID);

void Timer2_CompareCallBackFunction();
#endif /* TMU_H_ */