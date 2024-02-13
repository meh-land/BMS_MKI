#ifndef BMS_H_
#define BMS_H_

#pragma once

// no of cells 
#define BMS_NO_OF_CELLS 2

// defining cells
#if (BMS_NO_OF_CELLS == 2)
	#define BMS_CELL_01		ADC_CHANNEL_0
	#define BMS_CELL_02		ADC_CHANNEL_1
#elif (BMS_NO_OF_CELLS == 4)
	#define BMS_CELL_01		ADC_CHANNEL_0
	#define BMS_CELL_02		ADC_CHANNEL_1
	#define BMS_CELL_03		ADC_CHANNEL_2
	#define BMS_CELL_04		ADC_CHANNEL_3
#elif (BMS_NO_OF_CELLS == 6)
	#define BMS_CELL_01		ADC_CHANNEL_0
	#define BMS_CELL_02		ADC_CHANNEL_1
	#define BMS_CELL_03		ADC_CHANNEL_2
	#define BMS_CELL_04		ADC_CHANNEL_3
	#define BMS_CELL_05		ADC_CHANNEL_4
	#define BMS_CELL_06		ADC_CHANNEL_5
#else
	#error WTF?!


// bms_init()
/*
	input: no of cells and *MAYBE* reading update time...?!
	output: void
	what does it do? ADC init + initializes ADC pins based on no of cells + timer initializations
*/
void BMS_voidInit(void);

// bms_read()
/*
	input: cell no
	output: cell voltage (in mV)
	what does it do? reads the value on ADC pin corresponding to cell no
*/
f32 BMS_u16ReadVoltage(u8 copy_u8CellNum);


// bms_disp()
/*
	input: cell no && cell reading (in V)
	output: LCD stuff (void)
	what does it do? what do you think?! XDD
*/
void BMS_voidDisplayReading(u8 copy_u8CellNum, u16 copy_u16CellVoltage);


// bms_periodicDisp()
/*
	input: no of cells
	output: void
	what does it do?
		-> Gets triggered every second (or so)
		-> for loop to read every cell's voltage (use bms_read())
		-> inside the same for loop display the reading of each cell
*/
void BMS_voidPeriodicallyDisplayReading(u8 copy_u8NumOfCells);


#endif