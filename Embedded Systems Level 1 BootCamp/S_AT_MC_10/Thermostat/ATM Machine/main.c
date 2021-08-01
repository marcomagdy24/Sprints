/*
* ATM Machine.c
*
* Created: 7/27/2021 12:02:39 AM
* Author : Marco
*/

#include "APP/Thermostat/thermostat.h"

int main(void)
{
	THERMOSTAT_Init();
	while (1)
	{
		THERMOSTAT_Update();
		
		
	}
}

