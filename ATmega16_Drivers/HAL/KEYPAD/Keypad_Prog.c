#include "../../MCAL/DIO/DIO_CFG.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "Keypad_CFG.h"
#include "Keypad_Private.h"
#include "Keypad_Interface.h"

void KPD_voidInit(void)
{
	u8 local_u8Iterator;
	for (local_u8Iterator = DIO_PIN0; local_u8Iterator <= DIO_PIN7; local_u8Iterator++) 
	{
		if (local_u8Iterator < DIO_PIN4) 
			DIO_voidSetPinDirection(KPD_PORT, KPD_u8RowPinsArr[local_u8Iterator], DIO_PIN_OUTPUT);
		else
			DIO_voidSetPinDirection(KPD_PORT, KPD_u8ColPinsArr[local_u8Iterator - KPD_NO_OF_COLS], DIO_PIN_INPUT);
	}
	
	DIO_voidSetPortValue(KPD_PORT, 0xFF);
	
}

u8 KPD_u8GetPressedKey(void)
{
	u8 local_u8IteratorCol;
	u8 local_u8IteratorRow;
	u8 local_u8ButtonState;
	
	for (local_u8IteratorRow = 0; local_u8IteratorRow < KPD_NO_OF_ROWS; local_u8IteratorRow++)
	{
		// disable pull-up here
		DIO_voidSetPinValue(KPD_PORT, KPD_u8RowPinsArr[local_u8IteratorRow], DIO_PIN_LOW);
		for (local_u8IteratorCol = 0; local_u8IteratorCol < KPD_NO_OF_COLS; local_u8IteratorCol++)
		{
			local_u8ButtonState = DIO_u8GetPinValue(KPD_PORT, KPD_u8ColPinsArr[local_u8IteratorCol]);
			// read pin
			if (local_u8ButtonState == KPD_BUTTON_PRESSED)
			{
				_delay_ms(25); // debouncing protecc
				local_u8ButtonState = DIO_u8GetPinValue(KPD_PORT, KPD_u8ColPinsArr[local_u8IteratorCol]);
				if (local_u8ButtonState == KPD_BUTTON_PRESSED)
				{
					// handling long pressing
					while (local_u8ButtonState == KPD_BUTTON_PRESSED)
						local_u8ButtonState = DIO_u8GetPinValue(KPD_PORT, KPD_u8ColPinsArr[local_u8IteratorCol]);
					return KPD_u8CharArr[local_u8IteratorRow][local_u8IteratorCol];
				}
			}
		}
		// enable pull-up again
		DIO_voidSetPinValue(KPD_PORT, KPD_u8RowPinsArr[local_u8IteratorRow], DIO_PIN_HIGH);
	}
	
	return 0x00; // no key pressed
}