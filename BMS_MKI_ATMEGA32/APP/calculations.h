#pragma once
#ifndef CALC_H_
#define CALC_H_
#include "../LIB/STD_Types.h"

#define SMAPLING_PERIOD_mS 	1
#define SMAPLING_COUNT 		1000

#define DECIMAL			2

u8 Global_u8DisplayFlag = 0;

bool is_updated = false;

#define DISP_I	0
#define DISP_V	1
#define DISP_P	2
#define DISP_E	3

void ISR_INT0(void);
void ISR_INT1(void);

void DISP_voidDisplayOnLCD(f32 Copy_f32Result);

void CALC_voidInit(void);

void CALC_voidPeriodicFunc(void);

void CALC_voidReset(void);

f64 CALC_f64GetInstPower_mW(void);

f64 CALC_f64GetInstVoltage_mV(void);

f64 CALC_f64GetInstCurrent_mA(void);

f64 CALC_f64GetEnergy_mJ(void);

/*
f64 CALC_f64GetRMSVoltage_mV(void);

f64 CALC_f64GetRMSCurrent_mA(void);

f64 CALC_f64GetRMSPower_mW(void);
*/
#endif
