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
#include "../MCAL/ADC/ADC_Prog.c"
#include "../MCAL/TIMER/TIMER_Prog.c"
#include "../MCAL/EXTI/EXTI_Prog.c"
#include "../HAL/LCD/LCD_Prog.c"
#include "../HAL/VSEN/VSEN.c"
#include "../HAL/ACS712/ACS712.c"
#include "../APP/calculations.c"
#include "../APP/BMS.c"




int main(void)
{
	BMS_voidInit();
	
	LCD_voidInitDisplay();

	f32 local_f32Temp = 0;
	
	local_f32Temp = BMS_u16ReadVoltage(BMS_CELL_01);
	LCD_voidDisplayStr("V = ");
	_delay_ms(1);
	DISP_voidDisplayOnLCD(local_f32Temp);
	_delay_ms(1);
	LCD_voidDisplayStr(" V");
	_delay_ms(1);
	
    while(true)
    {
        
		
    }
}
