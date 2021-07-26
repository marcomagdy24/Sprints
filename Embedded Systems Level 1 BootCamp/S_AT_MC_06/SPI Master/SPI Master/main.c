/*
 * SPI Master.c
 *
 * Created: 7/14/2021 10:33:03 PM
 * Author : Marco
 */ 

/******************************************************************************
*                              Includes													*
*******************************************************************************/
#include "APP/SPI_MASTER/master.h"

int main(void)
{
    /* Replace with your application code */
	 SPI_Master_Init();
    while (1) 
    {
		 SPI_Master_Update();
    }
}

