#include "../../MCAL/DIO/DIO_CFG.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "BUTTON_Private.h"
#include "BUTTON_CFG.h"
#include "BUTTON_Interface.h"

void BTN_voidButtonInit(u8 copy_u8PortName, u8 copy_u8PinNum)
{
	DIO_voidSetPinDirection(copy_u8PortName, copy_u8PinNum, DIO_PIN_INPUT);
}


u8 BTN_u8IsButtonPressed(u8 copy_u8PortName, u8 copy_u8PinNum)
{
	return DIO_u8GetPinValue(copy_u8PortName, copy_u8PinNum);
}