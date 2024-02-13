/*
 * main.c
 *
 * Created: 9/5/2023 3:10:20 PM
 *  Author: Ahmed
 */ 

//#include <avr/io.h>
//#include <avr/interrupt.h>


#include "../LIB/BIT_Math.h"
#include "../LIB/STD_Types.h"
#include <util/delay.h>
#include "../MCAL/DIO/DIO_Prog.c"
#include "../MCAL/GIE/GIE_Prog.c"
#include "../MCAL/ADC/ADC_Prog.c"
#include "../MCAL/TIMER/TIMER_Prog.c"
#include "../MCAL/EXTI/EXTI_Prog.c"
#include "../HAL/LCD/LCD_Prog.c"
#include "../HAL/VSEN/VSEN.c"
#include "../HAL/ACS712/ACS712.c"
#include "../APP/BMS.c"




int main(void)
{
	BMS_voidInit();
	
	LCD_voidInitDisplay();

	f32 local_f32Temp = 0;
	
	/*local_f32Temp = BMS_f32ReadVoltage(BMS_CELL_01);
	BMS_voidDisplayReading(BMS_CELL_01, local_f32Temp);*/
	
	/*local_f32Temp = BMS_f32ReadVoltage(BMS_CELL_04);
	LCD_voidSetCursorPosition(0,2);
	BMS_voidDisplayReading(BMS_CELL_04, local_f32Temp);*/
	
	
    while(true)
    {
        if (is_updated)
		{
			if (BMS_u8CellIndex % 2 == 0)
			{
				local_f32Temp = BMS_f32ReadVoltage(BMS_CELL_01);
				BMS_voidDisplayReading(BMS_CELL_01, local_f32Temp);
				
				local_f32Temp = BMS_f32ReadVoltage(BMS_CELL_02);
				LCD_voidSetCursorPosition(0,2);
				BMS_voidDisplayReading(BMS_CELL_02, local_f32Temp);
				
				is_updated = false;
			}
			else if (BMS_u8CellIndex % 2 == 1)
			{
				
				local_f32Temp = BMS_f32ReadVoltage(BMS_CELL_03);
				BMS_voidDisplayReading(BMS_CELL_03, local_f32Temp);
				
				local_f32Temp = BMS_f32ReadVoltage(BMS_CELL_04);
				LCD_voidSetCursorPosition(0,2);
				BMS_voidDisplayReading(BMS_CELL_04, local_f32Temp);
				
				is_updated = false;
			}
		}
		
	}
}
