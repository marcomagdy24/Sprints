

#ifndef DIO_H_
#define DIO_H_

#include "../../UTILS/utils.h"
#include "../../UTILS/types.h"
#include "../../UTILS/registers.h"

#define ERROR  0
#define Success  1

#define INPUT_PORT 0x00
#define OUTPUT_PORT 0xFF


typedef enum {
	INPUT,
	OUTPUT
}EN_PINDIR_t;

typedef enum {
	LOW,
	HIGH
}EN_PINOUT_t;

typedef enum {
	PIN0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7
}EN_PIN_t;

typedef enum{
	PortA,
	PortB,
	PortC,
	PortD
}EN_PORT_t;



/* API's */

E_STATUS DIO_SetPinDirection(EN_PORT_t port, EN_PIN_t pin, EN_PINDIR_t dir);
E_STATUS DIO_SetPortDirection(EN_PORT_t port, uint8_t dir);
E_STATUS DIO_TogglePin(EN_PORT_t port, EN_PIN_t pin);
E_STATUS DIO_ReadPin(EN_PORT_t port, EN_PIN_t pin, EN_PINOUT_t *value);
E_STATUS DIO_ReadPort(EN_PORT_t port, uint8_t * value);
E_STATUS DIO_WritePin(EN_PORT_t port, EN_PIN_t pin, EN_PINOUT_t data);
E_STATUS DIO_WritePort(EN_PORT_t port, uint8_t data);


#endif /* DIO_H_ */
