#include "STUB_DIO.h"

E_STATUS DIO_Init(ST_DIO_config* configurations)
{
	return E_OK;
}

E_STATUS DIO_ReadPIN(uint8_t port, EN_pins pin, uint8_t* data)
{
	return E_OK;
}

E_STATUS DIO_WritePIN(uint8_t port, EN_pins pin, uint8_t data)
{
	return E_OK;
}

E_STATUS DIO_WritePORT(uint8_t port, uint8_t data)
{
	return E_OK;
}

E_STATUS DIO_TogglePIN(uint8_t port, EN_pins pin)
{
	return E_OK;
}