/*
* TMU.c
*
* Created: 8/29/2021 5:25:00 PM
*  Author: Marco
*/

/******************************************************************************
*                              INCLUDES										  *
*******************************************************************************/
#include "TMU.h"
/******************************************************************************
*                              CONSTANTS									  *
*******************************************************************************/
#define TIMER_CH									TMR2_CHOICE

#define TASK_MAX_PRIORITY							(uint8_t)(255)
#define TASK_TIME									(uint8_t)(250)
#define TIMER_MODE									CTC
#define TIMER_PRESCALLER							PRS64

#define STATE_SCHEDULAR_ACTIVE						(uint8_t)(0)
#define STATE_SCHEDULAR_IDLE						(uint8_t)(1)
#define STATE_SCHEDULAR_PENDING_REQUEST				(uint8_t)(2)

/******************************************************************************
*						GLOBAL EXTERN VARIABLES								  *
*******************************************************************************/
ST_Task_Config_t gast_Tasks[MAX_ID];
volatile uint8_t gu8_TMULoadCounter = ZERO;
uint8_t gu8_TMUSchedularState = STATE_SCHEDULAR_ACTIVE;
uint8_t gu8_LCM = ZERO;
uint8_t u8_MaxPriority = TASK_MAX_PRIORITY;
uint8_t gu8_MinPeriodicity = TASK_MAX_PRIORITY;
uint8_t u8_Counter = ZERO;
/******************************************************************************
*                         LOCAL FUNCTIONS IMPLEMENTATION					  *
*******************************************************************************/
void TMU_GetLCM()
{
	gu8_LCM = gu8_MinPeriodicity;
	for (u8_Counter = ZERO; u8_Counter < MAX_ID; u8_Counter++)
	{
		uint8_t u8_CurrentPeriodicity = gast_Tasks[u8_Counter].u8_Periodicity;
		if (u8_CurrentPeriodicity)
		{
			if (ZERO == (u8_CurrentPeriodicity % gu8_MinPeriodicity))
			{
				gu8_LCM = gu8_LCM * (u8_CurrentPeriodicity / gu8_MinPeriodicity);
			}
			else
			{
				gu8_LCM *= u8_CurrentPeriodicity;
			}
		}
	}
}

void TMU_TasksSchedular()
{
	u8_MaxPriority = TASK_MAX_PRIORITY;
	for (u8_Counter = ZERO; u8_Counter < MAX_ID; u8_Counter++)
	{
		/* Check for Function not Null */
		if (NULL_PTR != gast_Tasks[u8_Counter].pvf_Task)
		{
			/* Check for Highest Priority (Least Number) */
			if ((u8_MaxPriority > gast_Tasks[u8_Counter].u8_Priority) && (ZERO == gast_Tasks[u8_Counter].u8_FirstDelay))
			{
				/* Get Highest Priority (Least Number) */
				u8_MaxPriority = gast_Tasks[u8_Counter].u8_Priority;
			}
			/* Check for Minimum Periodicity */
			if (gu8_MinPeriodicity > gast_Tasks[u8_Counter].u8_Periodicity)
			{
				/* Get Minimum Periodicity */
				gu8_MinPeriodicity = gast_Tasks[u8_Counter].u8_Periodicity;
			}
		}
	}
	/* Loop in Array of Tasks */
	for (u8_Counter = ZERO; u8_Counter < MAX_ID; u8_Counter++)
	{
		/* Check for First Delay is Zero And we got max priority */
		if((ZERO == gast_Tasks[u8_Counter].u8_FirstDelay) && (u8_MaxPriority == gast_Tasks[u8_Counter].u8_Priority))
		{
			/* Check for Function not Null */
			if (NULL_PTR != gast_Tasks[u8_Counter].pvf_Task)
			{
				/* Call Function and decrease Periodicity by One */
				gast_Tasks[u8_Counter].pvf_Task();
				gast_Tasks[u8_Counter].u8_FirstDelay = gast_Tasks[u8_Counter].u8_Periodicity - ONE;
			}
			
		}
		/* Check for First Delay is not Zero */
		else if (ZERO != gast_Tasks[u8_Counter].u8_FirstDelay)
		{
			/* Decrease First Delay by One */
			gast_Tasks[u8_Counter].u8_FirstDelay--;
		}
	}
	if (ZERO == gu8_LCM)
	{
		TMU_GetLCM();
	}
}
/******************************************************************************
*                         APIS IMPLEMENTATION								  *
*******************************************************************************/
E_STATUS TMU_Init()
{
	/* Initialization Timer2 as CTC Mode and Timescale 8 */
	Timer_sint8_tInit(TIMER_CH, TIMER_MODE, TIMER_PRESCALLER);
	/* Initialization Timer preload with TASK_TIME */
	Timer_sint8_tSetTMRValue(OCR2_CHOICE, TASK_TIME);
	/* Enable Timer Interrupt */
	Timer_sint8_tInterruptEnable(TIMER_CH, OSCIE_CHOICE);
	return E_OK;
	
}

E_STATUS TMU_Run()
{
	/* Loop in Array of Tasks */
	switch(gu8_TMUSchedularState)
	{
		/* Case Scheduler Active */
		case(STATE_SCHEDULAR_ACTIVE):
		{
			PM_Enable(PM_SLEEP_MODE_PWR_SAVE);
			TMU_TasksSchedular();
			gu8_TMUSchedularState = STATE_SCHEDULAR_IDLE;
			break;
		}
		case(STATE_SCHEDULAR_IDLE):
		{
			PM_Disable();
			gu8_TMUSchedularState = STATE_SCHEDULAR_PENDING_REQUEST;
			break;
		}
		default:
		{
			break;
		}
	}
	return E_OK;
}

E_STATUS TMU_CreateTask(ST_Task_Config_t* configurations)
{
	gast_Tasks[configurations->u8_ID] = *configurations;
	return E_OK;
}

E_STATUS TMU_DeleteTask(uint8_t u8_TaskID)
{
	gast_Tasks[u8_TaskID].pvf_Task = NULL_PTR;
	return E_OK;
}


void Timer2_CompareCallBackFunction()
{
	gu8_TMULoadCounter++;
	gu8_TMUSchedularState = STATE_SCHEDULAR_ACTIVE;
}


ISR(TIMER2_COMP_vect)
{
	Timer2_CompareCallBackFunction();
}