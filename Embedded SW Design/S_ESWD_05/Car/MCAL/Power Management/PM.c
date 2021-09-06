/*
* PM.c
*
* Created: 8/30/2021 4:28:00 PM
*  Author: Marco
*/
#include "PM.h"

E_STATUS PM_Enable(EN_PMSLEEP_MODES_t mode)
{
	uint8_t u8_retval = E_NOK;
	switch (mode)
	{
		case(PM_SLEEP_MODE_IDLE):
		{
			RESET_BIT(MCUCR, SM0);
			RESET_BIT(MCUCR, SM1);
			RESET_BIT(MCUCR, SM2);
			SET_BIT(MCUCR, SE);
			u8_retval = E_OK;
			break;
		}
		case(PM_SLEEP_MODE_ADC):
		{
			SET_BIT(MCUCR, SM0);
			RESET_BIT(MCUCR, SM1);
			RESET_BIT(MCUCR, SM2);
			SET_BIT(MCUCR, SE);
			u8_retval = E_OK;
			break;
		}
		case(PM_SLEEP_MODE_PWR_DOWN):
		{
			RESET_BIT(MCUCR, SM0);
			SET_BIT(MCUCR, SM1);
			RESET_BIT(MCUCR, SM2);
			SET_BIT(MCUCR, SE);
			u8_retval = E_OK;
			break;
		}
		case(PM_SLEEP_MODE_PWR_SAVE):
		{
			SET_BIT(MCUCR, SM0);
			SET_BIT(MCUCR, SM1);
			RESET_BIT(MCUCR, SM2);
			SET_BIT(MCUCR, SE);
			u8_retval = E_OK;
			break;
		}
		case(PM_SLEEP_MODE_STANDBY):
		{
			RESET_BIT(MCUCR, SM0);
			SET_BIT(MCUCR, SM1);
			SET_BIT(MCUCR, SM2);
			SET_BIT(MCUCR, SE);
			u8_retval = E_OK;
			break;
		}
		case(PM_SLEEP_MODE_EXT_STANDBY):
		{
			SET_BIT(MCUCR, SM0);
			SET_BIT(MCUCR, SM1);
			SET_BIT(MCUCR, SM2);
			SET_BIT(MCUCR, SE);
			u8_retval = E_OK;
			break;
		}
		default:
		{
			u8_retval = E_NOK;
			break;
		}
	}
	return u8_retval;
}

/* Description : Disable Power Sleep Mode	*/
E_STATUS PM_Disable(void)
{
	uint8_t u8_retval = E_OK;
	RESET_BIT(MCUCR, SM0);
	RESET_BIT(MCUCR, SM1);
	RESET_BIT(MCUCR, SM2);
	RESET_BIT(MCUCR, SE);
	return u8_retval;
}