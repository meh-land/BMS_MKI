#include "../../LIB/STD_Types.h"
#include "../../MCAL/ADC/ADC_Prog.c"
#include "LDR_Private.h"
#include "LDR_CFG.h"
#include "LDR_Interface.h"

void LDR_voidInit(void)
{
	ADC_voidInit();
}

u16 LDR_u16GetReadingInMilliVolt(void)
{
	u16 local_u16ADCDigitalReading = ADC_u8GetResultSync(LDR_ADC_CHANNEL);
	u16 local_u16ADCAnalogReading = (u16)(((u32)(local_u16ADCDigitalReading) * VREF) / 1024UL);
	return local_u16ADCAnalogReading;
}