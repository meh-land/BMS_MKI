#ifndef BMS_H_
#define BMS_H_

// bms_init()
/*
	input: no of cells
	output: void
	what does it do? initializes ADC pins + timer initializations
*/
void BMS_voidInit(u8 copy_u8NumOfCells);

// bms_read()
/*
	input: cell no
	output: cell voltage (in mV)
	what does it do? reads the value on ADC pin corresponding to cell no
*/
u16 BMS_u16ReadVoltage(u8 copy_u8CellNum);


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