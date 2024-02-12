#ifndef SS_CFG_H_
#define SS_CFG_H_

typedef enum sevenSegment
{
	SS_ZERO = 0x3F,
	SS_ONE = 0x06,
	SS_TWO = 0x5B,
	SS_THREE = 0x4F,
	SS_FOUR = 0x66,
	SS_FIVE = 0x6D,
	SS_SIX = 0x7D,
	SS_SEVEN = 0x07,
	SS_EIGHT = 0x7F,
	SS_NINE = 0x6F
} sevenSegment;

const u8 SS_values[] = {SS_ZERO,
						SS_ONE,
						SS_TWO,
						SS_THREE,
						SS_FOUR,
						SS_FIVE,
						SS_SIX,
						SS_SEVEN,
						SS_EIGHT,
						SS_NINE
						};

#endif