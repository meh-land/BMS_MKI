#include "../../LIB/STD_Types.h"
#include "LM35_Private.h"
#include "LM35_CFG.h"
#include "LM35_Interface.h"

void LM35_voidInit(void)
{
	ADC_voidInit();
}
u16 LM35_u16GetReadingInCelcius(void)
{
	u16 local_u16ADCDigitalReading = ADC_u8GetResultSync(LM35_ADC_CHANNEL);
	u16 local_u16ADCAnalogReading = (u16)(((u32)(local_u16ADCDigitalReading) * VREF) / 1024UL);
	local_u16ADCAnalogReading /= 10;
	return local_u16ADCAnalogReading;
}