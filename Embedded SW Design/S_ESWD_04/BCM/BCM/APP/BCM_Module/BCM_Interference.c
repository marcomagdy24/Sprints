/*
 * BCM_Interference.c
 *
 * Created: 30-Aug-21 10:35:04 PM
 *  Author: Ayman
 */ 
/******************************************************************************
*                              INCLUDES										  *
*******************************************************************************/
#include "BCM_Interference.h"
extern ptr_uint8_t data;
extern uint8_t u8_RxID;
extern uint16_t u16_size;

/*

*/
/*

*/

/******************************************************************************
*                         APIS IMPLEMENTATION								  *
*******************************************************************************/


E_STATUS BCM_Send(ptr_uint8_t INT_data, uint8_t u8_INT_RxID, uint16_t u16_INT_size)
{
	data=INT_data;
    u8_RxID=u8_INT_RxID;
	u16_size=u16_INT_size;
}


/*
E_STATUS BCM_Receive()
{

}
*/
