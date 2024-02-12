#ifndef KEYPAD_PRIVATE_H_
#define KEYPAD_PRIVATE_H_

typedef enum KPD_buttonCode
{
	KPD_ONE   = 0b10111110,
	KPD_TWO   = 0b10111101,
	KPD_THREE = 0b10111011,
	KPD_FOUR  = 0b11011110,
	KPD_FIVE  = 0b11011101,
	KPD_SIX   = 0b11011011,
	KPD_SEVEN = 0b11101110,
	KPD_EIGHT = 0b11101101,
	KPD_NINE  = 0b11101011,
	KPD_ZERO  = 0b01111101,
	KPD_CLR   = 0b01111110,
	KPD_DIV   = 0b11100111,
	KPD_MUL   = 0b11010111,
	KPD_SUB   = 0b10110111,
	KPD_ADD   = 0b01110111,
	KPD_EQUAL = 0b01111011
} KPD_buttonCode;

const u8 KPD_u8CharArr[KPD_NO_OF_COLS][KPD_NO_OF_ROWS] = KPD_BUTTON_CFG;

const u8 KPD_u8CharCodeArr[KPD_NO_OF_COLS][KPD_NO_OF_ROWS] = 
					{ 							
							{KPD_SEVEN, KPD_EIGHT, KPD_NINE, KPD_DIV},   
							{KPD_FOUR, KPD_FIVE, KPD_SIX, KPD_MUL},   
							{KPD_ONE, KPD_TWO, KPD_THREE, KPD_SUB},   
							{KPD_CLR, KPD_ZERO, KPD_EQUAL, KPD_ADD}    
					};
					
const u8 KPD_u8RowPinsArr[KPD_NO_OF_ROWS] = {	KPD_ROW_PIN1, 
												KPD_ROW_PIN2,
												KPD_ROW_PIN3,
												KPD_ROW_PIN4
											};
										
const u8 KPD_u8ColPinsArr[KPD_NO_OF_COLS] = {	KPD_COL_PIN1, 
												KPD_COL_PIN2,
												KPD_COL_PIN3,
												KPD_COL_PIN4
											};

#endif