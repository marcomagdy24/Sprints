/*
* BCM.c
*
* Created: 8/25/2021 4:09:02 PM
*  Author: Marco
*/

/******************************************************************************
*                              INCLUDES										  *
*******************************************************************************/
#include "BCM.h"

/******************************************************************************
*								LOCAL MACROS		 						  *
*******************************************************************************/
#define UART_CH												(uint8_t)(0)
#define SPI_CH												(uint8_t)(1)
#define I2C_CH												(uint8_t)(I2C_CH_0)
#define TIMER_CH											(uint8_t)(TMR2_CHOICE)

#define STATE_PACKET_SENT_INITIALIZED							(255)
#define STATE_PACKET_SENT_COMMAND								(1)
#define STATE_PACKET_SENT_DATA									(2)
#define STATE_PACKET_SENT_COMPLETE								(3)

#define STATE_PACKET_SENDING_INITIALIZED						(255)
#define STATE_PACKET_SENDING_COMMAND							(1)
#define STATE_PACKET_SENDING_BCMID								(2)
#define STATE_PACKET_SENDING_TXID								(3)
#define STATE_PACKET_SENDING_RXID								(4)
#define STATE_PACKET_SENDING_DATA								(9)
#define STATE_PACKET_SENDING_DATASIZE_BYTE_ONE					(5)
#define STATE_PACKET_SENDING_DATASIZE_BYTE_TWO					(6)
#define STATE_PACKET_SENDING_CS									(7)
#define STATE_PACKET_SENDING_COMPLETE							(8)
#define STATE_DATA_SENDING_COMPLETE								(9)

#define STATE_DATA_SENDING										(1)
#define STATE_DATA_SENT											(2)

#define PACKET_COMMAND_START								(uint8_t)(1)
#define PACKET_COMMAND_STOP									(uint8_t)(2)

#define PACKET_COMMAND										(uint8_t)(251)
#define PACKET_DATA											(uint8_t)(252)
#define UART_NOTACK											(uint8_t)(253)
#define UART_ACK											(uint8_t)(254)

#define TIMER_TIMEOUT										(uint8_t)(1000)
#define TIMER_PRIORITY										(uint8_t)(0)

/******************************************************************************
*								LOCAL Data Types	 						  *
*******************************************************************************/
uint8_t gau8_UARTDataArray[MAX_SIZE];
uint8_t gau8_SPIDataArray[MAX_SIZE];
uint8_t gau8_I2CDataArray[MAX_SIZE];
#if TEST
uint8_t gu8_flag;
#endif

uint8_t gu8_SenderID = ZERO;
uint8_t gu8_ReceiverID = ZERO;
uint16_t gu16_ReceivedSize;
uint8_t gu8_IsSent;
uint8_t gu8_IsReceived = FALSE;
uint8_t gu8_Received;
uint8_t gu8_PacketType;
uint8_t gu8_ExpectedReceivedState;
uint16_t gu16_DataCounter = ZERO;
uint8_t gu8_CheckSum = ZERO;
uint8_t gu8_DataState = STATE_DATA_SENDING;
uint8_t gu8_PacketState = STATE_PACKET_SENT_INITIALIZED;
uint8_t gu8_State = STATE_PACKET_SENDING_INITIALIZED;
/******************************************************************************
*                         LOCAL FUNCTION IMPLEMENTATION						  *
*******************************************************************************/
E_STATUS BCM_InitArray(uint16_t size)
{
	uint8_t u8_Retval = E_NOK;
	uint16_t i2c_size = ZERO, uart_size = ZERO, spi_size = ZERO;
	uart_size = size / 3;
	spi_size = size / 3;
	return u8_Retval;
}


void BCM_SendCommandFrame(uint8_t u8_command, uint8_t u8_RxID, uint16_t u16_size)
{
	uint8_t u8_tempSize = (uint8_t) (u16_size);
	switch(gu8_State)
	{
		case(STATE_PACKET_SENDING_INITIALIZED):
		{
			if (!gu8_IsSent)
			{
				UART_TransmitChar(UART_CH, BCM_ID);
				Timer_NonBlockingdelay(TIMER_CH, TIMER_TIMEOUT, TIMER_PRIORITY);
				gu8_CheckSum += BCM_ID;
				gu8_IsSent = ONE;
			}
			if (UART_ACK == gu8_Received)
			{
				gu8_State = STATE_PACKET_SENDING_BCMID;
				gu8_Received = ZERO;
				gu8_IsSent = ZERO;
				Timer_sint8_tStop(TIMER_CH);
			}
			else if (SUCCESS == Timer_NonBlockingdelay(TIMER_CH, TIMER_TIMEOUT, TIMER_PRIORITY))
			{
				gu8_State = STATE_PACKET_SENDING_INITIALIZED;
				gu8_IsSent = ZERO;
			}
			break;
		}
		case(STATE_PACKET_SENDING_BCMID):
		{
			if (!gu8_IsSent)
			{
				gu8_Received = ZERO;
				UART_TransmitChar(UART_CH, PACKET_COMMAND);
				Timer_NonBlockingdelay(TIMER_CH, TIMER_TIMEOUT, TIMER_PRIORITY);
				gu8_CheckSum += PACKET_COMMAND;
				gu8_IsSent = ONE;
			}
			if (UART_ACK == gu8_Received)
			{
				gu8_State = STATE_PACKET_SENDING_TXID;
				gu8_Received = ZERO;
				gu8_IsSent = ZERO;
				Timer_sint8_tStop(TIMER_CH);
			}
			else if (SUCCESS == Timer_NonBlockingdelay(TIMER_CH, TIMER_TIMEOUT, TIMER_PRIORITY))
			{
				gu8_IsSent = ZERO;
				gu8_State = STATE_PACKET_SENDING_INITIALIZED;
			}
			break;
		}
		case(STATE_PACKET_SENDING_TXID):
		{
			if (!gu8_IsSent)
			{
				gu8_Received = ZERO;
				UART_TransmitChar(UART_CH, MCU_ID);
				Timer_NonBlockingdelay(TIMER_CH, TIMER_TIMEOUT, TIMER_PRIORITY);
				gu8_CheckSum += MCU_ID;
				gu8_IsSent = ONE;
			}
			if (UART_ACK == gu8_Received)
			{
				gu8_State = STATE_PACKET_SENDING_RXID;
				gu8_Received = ZERO;
				gu8_IsSent = ZERO;
				Timer_sint8_tStop(TIMER_CH);
			}
			else if (SUCCESS == Timer_NonBlockingdelay(TIMER_CH, TIMER_TIMEOUT, TIMER_PRIORITY))
			{
				gu8_State = STATE_PACKET_SENDING_INITIALIZED;
				gu8_IsSent = ZERO;
			}
			break;
		}
		case(STATE_PACKET_SENDING_RXID):
		{
			if (!gu8_IsSent)
			{
				gu8_Received = ZERO;
				UART_TransmitChar(UART_CH, u8_RxID);
				Timer_NonBlockingdelay(TIMER_CH, TIMER_TIMEOUT, TIMER_PRIORITY);
				gu8_CheckSum += u8_RxID;
				gu8_IsSent = ONE;
			}
			if (UART_ACK == gu8_Received)
			{
				gu8_State = STATE_PACKET_SENDING_DATASIZE_BYTE_ONE;
				gu8_Received = ZERO;
				gu8_IsSent = ZERO;
				Timer_sint8_tStop(TIMER_CH);
			}
			else if (SUCCESS == Timer_NonBlockingdelay(TIMER_CH, TIMER_TIMEOUT, TIMER_PRIORITY))
			{
				gu8_State = STATE_PACKET_SENDING_INITIALIZED;
				gu8_IsSent = ZERO;
			}
			break;
		}
		case(STATE_PACKET_SENDING_DATASIZE_BYTE_ONE):
		{
			if (!gu8_IsSent)
			{
				gu8_Received = ZERO;
				u8_tempSize = (uint8_t) (u16_size);
				UART_TransmitChar(UART_CH, u8_tempSize);
				Timer_NonBlockingdelay(TIMER_CH, TIMER_TIMEOUT, TIMER_PRIORITY);
				gu8_CheckSum += u8_tempSize;
				gu8_IsSent = ONE;
			}
			if (UART_ACK == gu8_Received)
			{
				gu8_State = STATE_PACKET_SENDING_DATASIZE_BYTE_TWO;
				gu8_Received = ZERO;
				gu8_IsSent = ZERO;
				Timer_sint8_tStop(TIMER_CH);
			}
			else if (SUCCESS == Timer_NonBlockingdelay(TIMER_CH, TIMER_TIMEOUT, TIMER_PRIORITY))
			{
				gu8_State = STATE_PACKET_SENDING_INITIALIZED;
				gu8_IsSent = ZERO;
			}
			break;
		}
		case(STATE_PACKET_SENDING_DATASIZE_BYTE_TWO):
		{
			if (!gu8_IsSent)
			{
				gu8_Received = ZERO;
				u8_tempSize = (uint8_t) (u16_size >> 8);
				UART_TransmitChar(UART_CH, u8_tempSize);
				Timer_NonBlockingdelay(TIMER_CH, TIMER_TIMEOUT, TIMER_PRIORITY);
				gu8_CheckSum += u8_tempSize;
				gu8_IsSent = ONE;
			}
			if (UART_ACK == gu8_Received)
			{
				gu8_State = STATE_PACKET_SENDING_COMMAND;
				gu8_Received = ZERO;
				gu8_IsSent = ZERO;
				Timer_sint8_tStop(TIMER_CH);
			}
			else if (SUCCESS == Timer_NonBlockingdelay(TIMER_CH, TIMER_TIMEOUT, TIMER_PRIORITY))
			{
				gu8_State = STATE_PACKET_SENDING_INITIALIZED;
				gu8_IsSent = ZERO;
			}
			break;
		}
		case(STATE_PACKET_SENDING_COMMAND):
		{
			if (!gu8_IsSent)
			{
				if (PACKET_COMMAND_START == u8_command)
				{
					gu8_Received = ZERO;
					UART_TransmitChar(UART_CH, PACKET_COMMAND_START);
					Timer_NonBlockingdelay(TIMER_CH, TIMER_TIMEOUT, TIMER_PRIORITY);
					gu8_CheckSum += PACKET_COMMAND_START;
					gu8_IsSent = ONE;
				}
				else if (PACKET_COMMAND_STOP == u8_command)
				{
					gu8_Received = ZERO;
					UART_TransmitChar(UART_CH, PACKET_COMMAND_STOP);
					Timer_NonBlockingdelay(TIMER_CH, TIMER_TIMEOUT, TIMER_PRIORITY);
					gu8_CheckSum += PACKET_COMMAND_STOP;
					gu8_IsSent = ONE;
				}
				else
				{
					
				}
				
			}
			if (UART_ACK == gu8_Received)
			{
				gu8_State = STATE_PACKET_SENDING_CS;
				gu8_Received = ZERO;
				gu8_IsSent = ZERO;
				Timer_sint8_tStop(TIMER_CH);
			}
			else if (SUCCESS == Timer_NonBlockingdelay(TIMER_CH, TIMER_TIMEOUT, TIMER_PRIORITY))
			{
				gu8_State = STATE_PACKET_SENDING_INITIALIZED;
				gu8_IsSent = ZERO;
			}
			break;
		}
		case(STATE_PACKET_SENDING_CS):
		{
			if (!gu8_IsSent)
			{
				gu8_Received = ZERO;
				UART_TransmitChar(UART_CH, gu8_CheckSum);
				gu8_IsSent = ONE;
			}
			if (UART_ACK == gu8_Received)
			{
				gu8_State = STATE_PACKET_SENDING_COMPLETE;
				gu8_Received = ZERO;
				gu8_IsSent = ZERO;
				Timer_sint8_tStop(TIMER_CH);
				gu8_CheckSum = ZERO;
			}
			else if (SUCCESS == Timer_NonBlockingdelay(TIMER_CH, TIMER_TIMEOUT, TIMER_PRIORITY))
			{
				gu8_State = STATE_PACKET_SENDING_INITIALIZED;
				gu8_IsSent = ZERO;
			}
			break;
		}
	}
}

void BCM_SendDataFrame(uint8_t u8_RxID, uint8_t u8_Data, uint16_t u16_Size)
{
	switch (gu8_DataState)
	{
		case  (STATE_DATA_SENDING):
		{
			switch(gu8_State)
			{
				case(STATE_PACKET_SENDING_INITIALIZED):
				{
					if (!gu8_IsSent)
					{
						UART_TransmitChar(UART_CH, BCM_ID);
						Timer_NonBlockingdelay(TIMER_CH, TIMER_TIMEOUT, TIMER_PRIORITY);
						gu8_CheckSum += BCM_ID;
						gu8_IsSent = ONE;
					}
					if (UART_ACK == gu8_Received)
					{
						gu8_State = STATE_PACKET_SENDING_BCMID;
						gu8_Received = ZERO;
						gu8_IsSent = ZERO;
						Timer_sint8_tStop(TIMER_CH);
					}
					else if (SUCCESS == Timer_NonBlockingdelay(TIMER_CH, TIMER_TIMEOUT, TIMER_PRIORITY))
					{
						gu8_State = STATE_PACKET_SENDING_INITIALIZED;
						gu8_IsSent = ZERO;
					}
					break;
				}
				case(STATE_PACKET_SENDING_BCMID):
				{
					if (!gu8_IsSent)
					{
						UART_TransmitChar(UART_CH, PACKET_DATA);
						Timer_NonBlockingdelay(TIMER_CH, TIMER_TIMEOUT, TIMER_PRIORITY);
						gu8_CheckSum += PACKET_DATA;
						gu8_IsSent = ONE;
					}
					if (UART_ACK == gu8_Received)
					{
						gu8_State = STATE_PACKET_SENDING_RXID;
						gu8_Received = ZERO;
						gu8_IsSent = ZERO;
						Timer_sint8_tStop(TIMER_CH);
					}
					else if (SUCCESS == Timer_NonBlockingdelay(TIMER_CH, TIMER_TIMEOUT, TIMER_PRIORITY))
					{
						gu8_State = STATE_PACKET_SENDING_INITIALIZED;
						gu8_IsSent = ZERO;
					}
					break;
				}
				case(STATE_PACKET_SENDING_TXID):
				{
					if (!gu8_IsSent)
					{
						UART_TransmitChar(UART_CH, MCU_ID);
						Timer_NonBlockingdelay(TIMER_CH, TIMER_TIMEOUT, TIMER_PRIORITY);
						gu8_CheckSum += MCU_ID;
						gu8_IsSent = ONE;
					}
					if (UART_ACK == gu8_Received)
					{
						gu8_State = STATE_PACKET_SENDING_RXID;
						gu8_Received = ZERO;
						gu8_IsSent = ZERO;
						Timer_sint8_tStop(TIMER_CH);
					}
					else if (SUCCESS == Timer_NonBlockingdelay(TIMER_CH, TIMER_TIMEOUT, TIMER_PRIORITY))
					{
						gu8_State = STATE_PACKET_SENDING_INITIALIZED;
						gu8_IsSent = ZERO;
					}
					break;
				}
				case(STATE_PACKET_SENDING_RXID):
				{
					if (!gu8_IsSent)
					{
						UART_TransmitChar(UART_CH, u8_RxID);
						Timer_NonBlockingdelay(TIMER_CH, TIMER_TIMEOUT, TIMER_PRIORITY);
						gu8_CheckSum += u8_RxID;
						gu8_IsSent = ONE;
					}
					if (UART_ACK == gu8_Received)
					{
						gu8_State = STATE_PACKET_SENDING_DATA;
						gu8_Received = ZERO;
						gu8_IsSent = ZERO;
						Timer_sint8_tStop(TIMER_CH);
					}
					else if (SUCCESS == Timer_NonBlockingdelay(TIMER_CH, TIMER_TIMEOUT, TIMER_PRIORITY))
					{
						gu8_State = STATE_PACKET_SENDING_INITIALIZED;
						gu8_IsSent = ZERO;
					}
					break;
				}
				case(STATE_PACKET_SENDING_DATA):
				{
					if (!gu8_IsSent)
					{
						gu8_CheckSum += u8_Data;
						UART_TransmitChar(UART_CH, u8_Data);
						Timer_NonBlockingdelay(TIMER_CH, TIMER_TIMEOUT, TIMER_PRIORITY);
						gu8_IsSent = ONE;
					}
					if (UART_ACK == gu8_Received)
					{
						gu8_State = STATE_PACKET_SENDING_CS;
						gu8_Received = ZERO;
						gu8_IsSent = ZERO;
						Timer_sint8_tStop(TIMER_CH);
					}
					else if (SUCCESS == Timer_NonBlockingdelay(TIMER_CH, TIMER_TIMEOUT, TIMER_PRIORITY))
					{
						gu8_State = STATE_PACKET_SENDING_INITIALIZED;
						gu8_IsSent = ZERO;
					}
					break;
				}
				case(STATE_PACKET_SENDING_CS):
				{
					if (!gu8_IsSent)
					{
						UART_TransmitChar(UART_CH, gu8_CheckSum);
						Timer_NonBlockingdelay(TIMER_CH, TIMER_TIMEOUT, TIMER_PRIORITY);
						gu8_IsSent = ONE;
					}
					if (UART_ACK == gu8_Received)
					{
						gu8_State = STATE_PACKET_SENT_INITIALIZED;
						gu8_Received = ZERO;
						gu8_IsSent = ZERO;
						Timer_sint8_tStop(TIMER_CH);
						gu16_DataCounter++;
						gu8_CheckSum = ZERO;
						if (u16_Size == gu16_DataCounter)
						{
							gu16_DataCounter = ZERO;
							gu8_DataState = STATE_DATA_SENT;
						}
					}
					else if (SUCCESS == Timer_NonBlockingdelay(TIMER_CH, TIMER_TIMEOUT, TIMER_PRIORITY))
					{
						gu8_State = STATE_PACKET_SENDING_INITIALIZED;
						gu8_IsSent = ZERO;
					}
					break;
				}
			}
			break;
		}
		case (STATE_DATA_SENT):
		{
			gu8_State = STATE_PACKET_SENDING_COMPLETE;
			break;
		}
	}
}

void BCM_ReceiveDataFrame()
{
	switch(gu8_ExpectedReceivedState)
	{
		case (PACKET_DATA):
		{
			if (gu8_IsReceived)
			{
				gu8_CheckSum += PACKET_DATA;
				gu8_IsReceived = FALSE;
				gu8_ExpectedReceivedState = STATE_PACKET_SENDING_RXID;
				UART_TransmitChar(UART_CH, UART_ACK);
			}
			break;
		}
		case (STATE_PACKET_SENDING_RXID):
		{
			gu8_ReceiverID = gu8_Received;
			if ((gu8_IsReceived) && (MCU_ID == gu8_ReceiverID))
			{
				gu8_CheckSum += MCU_ID;
				gu8_IsReceived = FALSE;
				gu8_ExpectedReceivedState = STATE_PACKET_SENDING_DATA;
				UART_TransmitChar(UART_CH, UART_ACK);
			}
			else
			{
			}
			break;
		}
		case (STATE_PACKET_SENDING_DATA):
		{
			if (gu8_IsReceived)
			{
				gu8_CheckSum += gu8_Received;
				gau8_UARTDataArray[gu16_DataCounter++] = gu8_Received;
				gu8_IsReceived = FALSE;
				gu8_ExpectedReceivedState = STATE_PACKET_SENDING_CS;
				UART_TransmitChar(UART_CH, UART_ACK);
			}
			else
			{
			}
			break;
		}
		case (STATE_PACKET_SENDING_CS):
		{
			if (gu8_IsReceived)
			{
				if (gu8_CheckSum == gu8_Received)
				{
					UART_TransmitChar(UART_CH, UART_ACK);	
					gu8_ExpectedReceivedState = ZERO;
				}
				else
				{
					UART_TransmitChar(UART_CH, UART_NOTACK);
				}
				
				gu8_IsReceived = FALSE;
				gu8_CheckSum = ZERO;
			}
			else
			{
			}
			break;
		}
	}
}

void BCM_ReceiveCommandFrame()
{
	switch(gu8_ExpectedReceivedState)
	{
		case (PACKET_COMMAND):
		{
			if (gu8_IsReceived)
			{
				gu8_CheckSum += PACKET_COMMAND;
				gu8_ExpectedReceivedState = STATE_PACKET_SENDING_BCMID;
				gu8_IsReceived = FALSE;
				UART_TransmitChar(UART_CH, UART_ACK);
			}
			break;
		}
		case (STATE_PACKET_SENDING_BCMID):
		{
			if (gu8_IsReceived)
			{
				gu8_SenderID = gu8_Received;
				gu8_CheckSum += gu8_Received;
				gu8_ExpectedReceivedState = STATE_PACKET_SENDING_RXID;
				gu8_IsReceived = FALSE;
				UART_TransmitChar(UART_CH, UART_ACK);
			}
			else
			{
			}
			break;
		}
		case (STATE_PACKET_SENDING_RXID):
		{
			if ((gu8_IsReceived) && (MCU_ID == gu8_Received))
			{
				gu8_CheckSum += gu8_Received;
				gu8_ExpectedReceivedState = STATE_PACKET_SENDING_DATASIZE_BYTE_ONE;
				gu8_IsReceived = FALSE;
				#if TEST
					gu8_flag = ONE;
				#endif
				UART_TransmitChar(UART_CH, UART_ACK);
			}
			else
			{
			}
			break;
		}
		case (STATE_PACKET_SENDING_DATASIZE_BYTE_ONE):
		{
			if (gu8_IsReceived)
			{
				gu16_ReceivedSize = gu8_Received;
				gu8_CheckSum += gu8_Received;
				gu8_ExpectedReceivedState = STATE_PACKET_SENDING_DATASIZE_BYTE_TWO;
				gu8_IsReceived = FALSE;
				UART_TransmitChar(UART_CH, UART_ACK);
			}
			else
			{
			}
			break;
		}
		case (STATE_PACKET_SENDING_DATASIZE_BYTE_TWO):
		{
			if (gu8_IsReceived)
			{
				gu16_ReceivedSize = gu8_Received << 8;
				gu8_CheckSum += gu8_Received;
				gu8_ExpectedReceivedState = STATE_PACKET_SENDING_COMMAND;
				gu8_IsReceived = FALSE;
				UART_TransmitChar(UART_CH, UART_ACK);
			}
			else
			{
			}
			break;
		}
		case (STATE_PACKET_SENDING_COMMAND):
		{
			if (gu8_IsReceived)
			{
				if (PACKET_COMMAND_START == gu8_Received)
				{
					BCM_Setup_RxBuffer(gu16_ReceivedSize);
					gu8_CheckSum += gu8_Received;
					gu8_ExpectedReceivedState = STATE_PACKET_SENDING_CS;
					UART_TransmitChar(UART_CH, UART_ACK);
				}
				else if (PACKET_COMMAND_STOP == gu8_Received)
				{
					gu8_CheckSum += gu8_Received;
					gu8_ExpectedReceivedState = STATE_PACKET_SENDING_CS;
					UART_TransmitChar(UART_CH, UART_ACK);
				}
				else
				{
					//UART_TransmitChar(UART_CH, UART_NOTACK);
				}
				gu8_IsReceived = FALSE;
			}
			break;
		}
		case (STATE_PACKET_SENDING_CS):
		{
			if (gu8_IsReceived)
			{
				if (gu8_CheckSum == gu8_Received)
				{
					UART_TransmitChar(UART_CH, UART_ACK);
					gu8_ExpectedReceivedState = ZERO;
					gu8_IsReceived = FALSE;
					gu8_CheckSum = ZERO;
				}
				else
				{
					UART_TransmitChar(UART_CH, UART_NOTACK);
					gu8_ExpectedReceivedState = ZERO;
					gu8_IsReceived = FALSE;
					gu8_CheckSum = ZERO;
				}
				
			}
			else
			{
			}
			break;
		}
	}
}

void Receive_CallBackFunction()
{
	UART_ReceiveChar(UART_CH, &gu8_Received);
	gu8_IsReceived = TRUE;
}
/******************************************************************************
*                         APIS IMPLEMENTATION								  *
*******************************************************************************/
E_STATUS BCM_Init(ST_BCMConfig_t* configurations)
{
	uint8_t u8_ModesCounter = ZERO;
	uint8_t u8_Retval = E_NOK;
	if (configurations->modes.uartEnable)
	{
		if(OperationSuccess == UART_Init(UART_CH))
		{
			UART_EnableInterrupt(UART_CH, RECIVE_INT);
			UART_SetCallback(UART_CH, RECIVE_INT, Receive_CallBackFunction);
			u8_Retval = E_OK;
			u8_ModesCounter++;
		}
		else
		{
			u8_Retval = E_NOK;
		}
	}
	if (configurations->modes.spiEnable)
	{
		if(OperationSuccess == SPI_Init(SPI_CH))
		{
			u8_Retval = E_OK;
			u8_ModesCounter++;
		}
		else
		{
			u8_Retval = E_NOK;
		}
	}
	if (configurations->modes.i2cEnable)
	{
		if(OperationSuccess == I2C_Init(I2C_CH))
		{
			u8_Retval = E_OK;
			u8_ModesCounter++;
		}
		else
		{
			u8_Retval = E_NOK;
		}
	}
	return u8_Retval;
}

E_STATUS BCM_Send(ptr_uint8_t data, uint8_t u8_RxID, uint16_t u16_size)
{
	uint8_t u8_Retval = E_NOK;
	if (NULL_PTR == data)
	{
		u8_Retval = E_NOK;
	}
	else
	{
		switch(gu8_PacketState)
		{
			case(STATE_PACKET_SENT_INITIALIZED):
			{
				BCM_SendCommandFrame(PACKET_COMMAND_START, u8_RxID, u16_size);
				if (STATE_PACKET_SENDING_COMPLETE == gu8_State)
				{
					gu8_State = STATE_PACKET_SENDING_INITIALIZED;
					gu8_PacketState = STATE_PACKET_SENT_COMMAND;
				}
				break;
			}
			case(STATE_PACKET_SENT_COMMAND):
			{
				BCM_SendDataFrame(u8_RxID, (*(data + gu16_DataCounter)), u16_size);
				if (STATE_PACKET_SENDING_COMPLETE == gu8_State)
				{
					gu8_State = STATE_PACKET_SENDING_INITIALIZED;
					gu8_PacketState = STATE_PACKET_SENT_DATA;
				}
				break;
			}
			case(STATE_PACKET_SENT_DATA):
			{
				BCM_SendCommandFrame(PACKET_COMMAND_STOP, u8_RxID, u16_size);
				if (STATE_PACKET_SENDING_COMPLETE == gu8_State)
				{
					gu8_State = STATE_PACKET_SENDING_INITIALIZED;
					gu8_PacketState = STATE_PACKET_SENT_INITIALIZED;
					gu8_DataState = STATE_DATA_SENDING;
				}
				break;
			}
		}
	}
	return u8_Retval;
}

E_STATUS BCM_Receive()
{
	uint8_t u8_Retval = E_NOK;
	
	if ((BCM_ID == gu8_Received) && !((gu8_ExpectedReceivedState >= STATE_PACKET_SENDING_BCMID) && (gu8_ExpectedReceivedState <= STATE_PACKET_SENDING_DATA)))
	{
		if(gu8_IsReceived)
		{
			gu8_IsReceived = FALSE;
			gu8_CheckSum = ZERO;
			gu8_CheckSum += BCM_ID;
			gu8_Received = ZERO;
			UART_TransmitChar(UART_CH, UART_ACK);
		}
	}
	else if ((PACKET_COMMAND == gu8_Received) || (PACKET_DATA == gu8_Received))
	{
		//if(!((gu8_ExpectedReceivedState >= STATE_PACKET_SENDING_BCMID) && (gu8_ExpectedReceivedState <= STATE_PACKET_SENDING_DATA)))
		if(gu8_IsReceived)
		{
			gu8_ExpectedReceivedState = gu8_Received;
		}
		
		gu8_PacketType = gu8_Received;
	}
	if (PACKET_DATA == gu8_PacketType)
	{
		BCM_ReceiveDataFrame();
	}
	else if (PACKET_COMMAND == gu8_PacketType)
	{
		gu16_DataCounter = ZERO;
		BCM_ReceiveCommandFrame();
	}
	else
	{
		
	}
	return u8_Retval;
}


E_STATUS BCM_Setup_RxBuffer(uint16_t size)
{
	uint8_t u8_Retval = E_NOK;
	if (MAX_SIZE >= size)
	{
		gu16_ReceivedSize = size;
		u8_Retval = E_OK;
		while(size)
		{
			gau8_UARTDataArray[size--] = ZERO;
		}
	}
	else
	{
		u8_Retval = E_NOK;
	}
	return u8_Retval;
}

E_STATUS BCM_RxUnlock()
{
	uint8_t u8_Retval = E_NOK;
	
	return u8_Retval;
}

