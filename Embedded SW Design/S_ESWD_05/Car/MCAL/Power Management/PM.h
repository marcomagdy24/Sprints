/*
 * PM.h
 *
 * Created: 8/30/2021 4:27:49 PM
 *  Author: Marco
 */ 


#ifndef PM_H_
#define PM_H_


#include "../../UTILS/registers.h"
#include "../../UTILS/utils.h"



typedef enum 
{
	PM_SLEEP_MODE_IDLE,
	PM_SLEEP_MODE_ADC,
	PM_SLEEP_MODE_PWR_DOWN,
	PM_SLEEP_MODE_PWR_SAVE,
	PM_SLEEP_MODE_STANDBY,
	PM_SLEEP_MODE_EXT_STANDBY
}EN_PMSLEEP_MODES_t;

/* Description : Enable Power Sleep Mode	*/
E_STATUS PM_Enable(EN_PMSLEEP_MODES_t mode);

/* Description : Disable Power Sleep Mode	*/
E_STATUS PM_Disable(void);

#endif /* PM_H_ */