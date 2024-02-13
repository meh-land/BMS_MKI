#include "../../LIB/STD_Types.h"
#include "../../LIB/Bit_Math.h"
#include "GIE_Register.h"
#include "GIE_Private.h"
#include "GIE_CFG.h"
#include "GIE_Interface.h"

void sei(void)
{
	SET_BIT(SREG, GIE_SREG_I);
} 

void cli(void)
{
	CLR_BIT(SREG, GIE_SREG_I);
}