/*
 * app.h
 *
 * Created: 8/25/2021 3:22:13 PM
 *  Author: Marco
 */ 


#ifndef APP_H_
#define APP_H_

#include "../../MCAL/Global_INERRUPT/GIE_int.h"
#include "../BCM_Module/BCM_MainFunction.h"
#include "../../MCAL/DIO/dio.h"

E_STATUS APP_Init();
E_STATUS APP_Update();



#endif /* APP_H_ */