#include "BMS.h"



void BMS_voidInit(u8 copy_u8NumOfCells, u8 copy_u8UpdateReadingTime)
{
	ADC_voidInit();
	
	//setup the timer interrupt to run every multiple of 1mS
	sei();
	
	// initialize external interrupt (option to display cells 1,2 or cells 3,4)
	EXTI_voidInit();
	EXTI_voidSetSignalSenseMode(EXTI_SENSE_RISING_EDGE, EXTI_GICR_INT0);
	EXTI_voidEnableInterrupt(EXTI_GICR_INT0);
	EXTI_voidSetCallBack(ISR_INT0, EXTI_INT0);
	EXTI_voidSetSignalSenseMode(EXTI_SENSE_RISING_EDGE, EXTI_GICR_INT1);
	EXTI_voidEnableInterrupt(EXTI_GICR_INT1);
	EXTI_voidSetCallBack(ISR_INT1, EXTI_INT1);
	
	TMR0_voidInit();
	TMR_voidCallBack(CALC_voidPeriodicFunc, TMR0_OVF_VECTOR_ID);
	TMR0_voidSetOVF(copy_u8UpdateReadingTime); // 64
}


u16 BMS_u16ReadVoltage(u8 copy_u8CellNum)
{
	
}


void BMS_voidDisplayReading(u8 copy_u8CellNum, u16 copy_u16CellVoltage)
{
	
}


void BMS_voidPeriodicallyDisplayReading(u8 copy_u8NumOfCells)
{
	
}


/*
void CALC_voidPeriodicFunc(void)
{
	static u16 Local_u16Count =0;
	//enter this condition every SMAPLING_PERIOD_mS 
	if(Local_u16Count == 3907){ ////////////////////?????????????????????????????????
		
		is_updated = true;
		LCD_voidClrDisplay();
		
		//read inst volt
		Global_f64InstVoltage_mv = VSEN_f32GetVoltageReading();
		//read inst current
		Global_f64InstCurrent_mA = ACS712_f32GetCurrentReading();
	
		Global_f64InstPower_mW = Global_f64InstVoltage_mv * Global_f64InstCurrent_mA; 
		Global_f64Energy_mJ += Global_f64InstPower_mW; 
		
		Local_u16Count = 0;
		TMR0_voidSetOVF(64);
	}

	Local_u16Count++;
}


// reset
void ISR_INT0(void)
{
	Global_f64InstVoltage_mv = 0;
	
	Global_f64InstCurrent_mA = 0;
	
	Global_f64InstPower_mW = 0;
	
	Global_f64Energy_mJ = 0;
	
}

void ISR_INT1(void)
{
	Global_u8DisplayFlag += 1;
	
	if (Global_u8DisplayFlag > 3)
		Global_u8DisplayFlag = 0;
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
*/