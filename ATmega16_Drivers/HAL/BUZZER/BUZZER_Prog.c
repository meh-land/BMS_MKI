#include "../../LIB/Bit_Math.h"
#include "../../LIB/STD_Types.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "BUZZER_Private.h"
#include "BUZZER_CFG.h"
#include "BUZZER_Interface.h"


void BUZZER_voidInit(void)
{
	DIO_voidSetPinDirection(BUZZER_PORT, BUZZER_PIN, 1);
}

void BUZZER_voidTurnBuzzerOn(void)
{
	DIO_voidSetPinValue(BUZZER_PORT, BUZZER_PIN, BUZZER_ON);
}

void BUZZER_voidTurnBuzzerOff(void)
{
	DIO_voidSetPinValue(BUZZER_PORT, BUZZER_PIN, BUZZER_OFF);
}

void BUZZER_voidToggleBuzzerOnOff(void)
{
	DIO_voidTogglePin(BUZZER_PORT, BUZZER_PIN);
}
