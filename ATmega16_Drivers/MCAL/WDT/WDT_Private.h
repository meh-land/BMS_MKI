#ifndef WDT_PRIVATE_H_
#define WDT_PRIVATE_H_

#define WDT_WDTCR_WDTOE		4
#define WDT_WDTCR_WDE		3
#define WDT_WDTCR_WDP2		2
#define WDT_WDTCR_WDP1		1
#define WDT_WDTCR_WDP0		0

#define WDT_PRESCALER_MASK	0xF8

#define WDT_WAIT_TIME_16_3_ms	0x00
#define WDT_WAIT_TIME_32_5_ms	0x01
#define WDT_WAIT_TIME_65_ms		0x02
#define WDT_WAIT_TIME_130_ms	0x03
#define WDT_WAIT_TIME_260_ms	0x04
#define WDT_WAIT_TIME_520_ms	0x05
#define WDT_WAIT_TIME_1_s		0x06
#define WDT_WAIT_TIME_2_1_s	 	0x07

#define WDT_DISABLE_MASK		0x18

#endif