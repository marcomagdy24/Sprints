/*
 * app.c
 *
 * Created: 8/25/2021 3:22:28 PM
 *  Author: Marco
 */ 

#include "app.h"

extern uint8_t gau8_UARTDataArray[MAX_SIZE];
uint8_t gau8_DataSending[10];
#if (TEST == 0)
	extern uint8_t u8_flag;
#endif

E_STATUS APP_Init()
{
	GIE_voidEnable();
	DIO_SetPinDirection(PortD, PIN1, OUTPUT);
	DIO_SetPortDirection(PortC, OUTPUT_PORT);
	configs.modes.uartEnable = ONE;
	BCM_Init(&configs);
	return E_OK;
}

E_STATUS APP_Update()
{
	#if (TEST == 1)
		if (!u8_flag)
		{
			BCM_RxMainFunction();
		}
		else if (u8_flag)
		{
			while (SUCCESS != Timer_NonBlockingdelay(TMR2_CHOICE, 2000, 1));
			u8_flag = ZERO;
		}
	
	#elif (TEST == 0)
	BCM_RxMainFunction();
	#endif
	for (uint8_t i = 0; i < 10; i++)
	{
		PORTC = gau8_UARTDataArray[i];
	}
	
	return E_OK;
}