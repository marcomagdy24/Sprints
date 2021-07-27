/*
 * SPI Slave.c
 *
 * Created: 7/15/2021 11:30:44 AM
 * Author : Marco
 */ 
/******************************************************************************
*                              Includes													*
*******************************************************************************/
#include "APP/SPI_SLAVE/slave.h"

int main(void)
{
    /* Replace with your application code */
	 SPI_Slave_Init();
	 
    while (1) 
    {
		 SPI_Slave_Update();
    }
}

