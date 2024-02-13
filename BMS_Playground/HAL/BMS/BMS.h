#ifndef BMS_H_
#define BMS_H_


// bms_init()
/*
	input: no of cells
	output: void
	what does it do? initializes ADC pins + timer initializations
*/

// bms_read()
/*
	input: cell no
	output: cell voltage (in mV)
	what does it do? reads the value on ADC pin corresponding to cell no
*/

// bms_disp()
/*
	input: cell no && cell reading (in V)
	output: LCD stuff
	what does it do? what do you think?! XDD
*/

// bms_periodicDisp()
/*
	input: no of cells
	output: void
	what does it do?
		-> Gets triggered every second (or so)
		-> for loop to read every cell's voltage (use bms_read())
		-> inside the same for loop display the reading of each cell
*/



#endif