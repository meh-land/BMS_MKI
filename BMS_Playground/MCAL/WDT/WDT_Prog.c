#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"
#include "WDT_Register.h"
#include "WDT_Private.h"
#include "WDT_CFG.h"
#include "WDT_Interface.h"

void WDT_voidEnable(void)
{
	SET_BIT(WDTCR, WDT_WDTCR_WDE);
	
	WDTCR &= WDT_PRESCALER_MASK;
	WDTCR |= WDT_WAIT_TIME;
}

void WDT_voidDisable(void)
{
	// write 1 to both WDTOE && WDE at the same time
	WDTCR |= WDT_DISABLE_MASK;
	// clear to turn off
	WDTCR = 0x00;
}