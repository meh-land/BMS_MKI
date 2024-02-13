#include "BMS.h"


void BMS_voidInit(void)
{
	// initialize ADC
	ADC_voidInit();
	
	// enable interrupts
	sei();
	
	// initialize external interrupt (option to display cells 1,2 or cells 3,4)
	EXTI_voidInit();
	EXTI_voidSetSignalSenseMode(EXTI_SENSE_RISING_EDGE, EXTI_GICR_INT0);
	EXTI_voidEnableInterrupt(EXTI_GICR_INT0);
	EXTI_voidSetCallBack(ISR_INT0, EXTI_INT0);
	EXTI_voidSetSignalSenseMode(EXTI_SENSE_RISING_EDGE, EXTI_GICR_INT1);
	EXTI_voidEnableInterrupt(EXTI_GICR_INT1);
	EXTI_voidSetCallBack(ISR_INT1, EXTI_INT1);
	
	// setup timer 0 interrupt to run every multiple of 1mS (overflow mode)
	TMR0_voidInit();
	TMR_voidCallBack(BMS_voidPeriodicallyDisplayReading, TMR0_OVF_VECTOR_ID);
	TMR0_voidSetOVF(64); // 64

}


f32 BMS_f32ReadVoltage(u8 copy_u8CellNum)
{
	/**Local variables used in calculations*/
	u16 Local_u16DigitalValue = 0;
	f32 Local_f32AnalogValue = 0;
	f32 Local_f32InputValue = 0;
	
	/**return 0 in case of wrong cell number*/
	if ((copy_u8CellNum < BMS_CELL_01) || (copy_u8CellNum > (BMS_NO_OF_CELLS - 1)))
		return Local_f32InputValue;
	
	/**Determine the right resistor ratios*/
	f32 Local_f32ResistorRatio = (11.0 / 14.0) / (BMS_NO_OF_CELLS - copy_u8CellNum);
	/*
		no_of_cells = 2
		cell_no = x where x = [0, 1]
		actual voltage = (no_of_cells - cell_no) * Local_f32AnalogValue * ((R1 + R2) / R2) )
		uppermost cell voltage = 4.2 * 2 = 8.4
							   = ADC_reading * R_ratio / (2 - 0)
							   
		no_of_cells = 3
		cell_no = x where x = [0, 2]
		actual voltage = Local_f32AnalogValue * Local_f32ResistorRatio / (no_of_cells - cell_no)
							3			
		uppermost cell voltage = 4.2 * 3 = 12.6
		= ADC_reading * R_ratio / (3 - 0)
	*/
	
	/**Read ADC pin value (digital)*/
	Local_u16DigitalValue = ADC_u16GetResultSync(copy_u8CellNum);
	
	/**Convert it from V to mV*/
	Local_f32AnalogValue = ((Local_u16DigitalValue * 5) / 1024.0);
	
	/**Calculate Vin in mV*/
	Local_f32InputValue = Local_f32AnalogValue / Local_f32ResistorRatio;

	/**Return Vin in mV*/
	return Local_f32InputValue;
}


void BMS_voidDisplayReading(u8 copy_u8CellNum, f32 copy_f32CellVoltage)
{
	if ((copy_u8CellNum < BMS_CELL_01) || (copy_u8CellNum >= BMS_NO_OF_CELLS))
		return;
	_delay_ms(1);
	LCD_voidDisplayStr("C");
	_delay_ms(1);
	LCD_voidDisplayInt(copy_u8CellNum + 1);
	_delay_ms(1);
	LCD_voidDisplayStr(" = ");
	DISP_voidDisplayOnLCD(copy_f32CellVoltage);
	_delay_ms(1);
	LCD_voidDisplayStr(" V");
	_delay_ms(1);
	
}


void BMS_voidPeriodicallyDisplayReading(u8 copy_u8NumOfCells)
{
	static u16 Local_u16Count = 0;
	
	/*if(Local_u16Count == 3907) // every second
	{ 
		// raise update flag
		is_updated = true;
		
		// clear lcd display
		LCD_voidClrDisplay();
		
		
		
		// reset timer + counter
		Local_u16Count = 0;
		TMR0_voidSetOVF(64);
	}
	
	Local_u16Count++;*/

}


void ISR_INT0(void)
{
	BMS_u8CellIndex++;
	LCD_voidClrDisplay();
	is_updated = true;
}

void ISR_INT1(void)
{
	BMS_u8CellIndex--;
	LCD_voidClrDisplay();
	is_updated = true;
}


void DISP_voidDisplayOnLCD(f32 Copy_f32Result)
{
	s32 Displayed = 0 , Decimal = 1;
	u8 counter = 0;
	
	if(Copy_f32Result < 0)
	{
		LCD_voidDisplayChar('-');
		Copy_f32Result = -1 * Copy_f32Result;
	}
	
	Displayed = (u32) (Copy_f32Result);
	LCD_voidDisplayInt(Displayed);
	
	for(counter = 0 ; counter < DECIMAL ; counter++)
	{
		Decimal *= 10;
	}
	
	LCD_voidDisplayChar('.');
	Displayed = (u32) (Copy_f32Result * Decimal) % Decimal;
	LCD_voidDisplayInt(Displayed);
}