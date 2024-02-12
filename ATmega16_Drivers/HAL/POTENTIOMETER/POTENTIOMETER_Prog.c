#include "../../LIB/STD_Types.h"
#include "POTENTIOMETER_Private.h"
#include "POTENTIOMETER_CFG.h"
#include "POTENTIOMETER_Interface.h"

void POTENTIOMETER_voidInit(void)
{
	ADC_voidInit();
}

u16 POTENTIOMETER_u16GetReadingInMilliVolt(void)
{
	u16 local_u16ADCDigitalReading = ADC_u8GetResultSync(POTENTIOMETER_ADC_CHANNEL);
	u16 local_u16ADCAnalogReading = (u16)(((u32)(local_u16ADCDigitalReading) * VREF) / 1024UL);
	return local_u16ADCAnalogReading;
}