#include "../../MCAL/DIO/DIO_CFG.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "SS_CFG.h"
#include "SS_Private.h"
#include "SS_Interface.h"

void SS_voidSevenSegInit(u8 copy_u8PortName)
{
	DIO_voidSetPortDirection(copy_u8PortName, DIO_PORT_OUTPUT);
	DIO_voidSetPortValue(copy_u8PortName, DIO_PORT_LOW);
}

void SS_voidDisplayNumber(u8 copy_u8PortName, u8 copy_u8Number)
{
	DIO_voidSetPortValue(copy_u8PortName, copy_u8Number);
}