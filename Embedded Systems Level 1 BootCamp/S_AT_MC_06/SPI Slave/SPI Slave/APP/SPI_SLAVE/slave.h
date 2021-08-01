/*
 * master.h
 *
 * Created: 7/15/2021 1:05:48 AM
 *  Author: Marco
 */ 


#ifndef MASTER_H_
#define MASTER_H_

/******************************************************************************
*                              Includes													*
*******************************************************************************/
#include "../../MCAL/SPI/SPI.h"
#include "../../MCAL/DIO/dio.h"


/******************************************************************************
*                               FUNCTION DECLARATIONS                         *
*******************************************************************************/
void SPI_Slave_Init(void);
void SPI_Slave_Update(void);


#endif /* MASTER_H_ */