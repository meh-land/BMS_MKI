#include "../../LIB/STD_Types.h"
#include "../../LIB/Bit_Math.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "DCM_Private.h"
#include "DCM_CFG.h"
#include "DCM_Interface.h"


void DCM_voidInit(void)
{
	DIO_voidSetPinDirection(DCM_PORT, DCM_PIN0, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(DCM_PORT, DCM_PIN1, DIO_PIN_OUTPUT);
}

void DCM_voidStartMotorCW(void)
{
	DIO_voidSetPinValue(DCM_PORT, DCM_PIN0, DIO_PIN_HIGH);
	DIO_voidSetPinValue(DCM_PORT, DCM_PIN1, DIO_PIN_LOW);
}

void DCM_voidStartMotorACW(void)
{
	DIO_voidSetPinValue(DCM_PORT, DCM_PIN0, DIO_PIN_LOW);	
	DIO_voidSetPinValue(DCM_PORT, DCM_PIN1, DIO_PIN_HIGH);
}

void DCM_voidStopMotor(void)
{
	DIO_voidSetPinValue(DCM_PORT, DCM_PIN0, DIO_PIN_LOW);
	DIO_voidSetPinValue(DCM_PORT, DCM_PIN1, DIO_PIN_LOW);
}