#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

// SPCR
#define SPI_SPCR_SPIE	7 //1=>enables SPI interrupts
#define SPI_SPCR_SPE	6 //1=>enables SPI
// (both options exist because some sensors require only one of them)
#define SPI_SPCR_DORD	5 //1=> Transmit LSB first && 0=> transmit MSB first (both master and slave should choose the same setting)
#define SPI_SPCR_MSTR	4 //1=> master mode && 0=> slave mode
#define SPI_SPCR_CPOL	3 //1=> leading edge = falling && 0=> leading edge = rising
#define SPI_SPCR_CPHA	2 //1=> setup @ leading edge && 0=> setup @ trailing edge
#define SPI_SPCR_SPR1	1 //SCK prescaler select
#define SPI_SPCR_SPR0	0 //SCK prescaler select

// SPSR
#define SPI_SPSR_SPIF	7 //interrupt flag (cleared by reading it then accessing SPDR)
#define SPI_SPSR_WCOL	6 //indicates data loss by overwriting them
#define SPI_SPSR_SPI2X	0 //1=> double SPI speed

/*
	SPI modes of operation are determined by:
		SPI_SPCR_CPOL && SPI_SPCR_CPHA
*/

#define SPI_SS			4
#define SPI_MOSI		5
#define SPI_MISO		6
#define SPI_SCK			7

// set SPI2X to 0
#define SPI_NORM_SPEED_CLK_PRESCALER_DIV_4		0x00
#define SPI_NORM_SPEED_CLK_PRESCALER_DIV_16		0x01
#define SPI_NORM_SPEED_CLK_PRESCALER_DIV_64		0x10
#define SPI_NORM_SPEED_CLK_PRESCALER_DIV_128	0x11

// set SPI2X to 1
#define SPI_2X_SPEED_CLK_PRESCALER_DIV_2		0x00
#define SPI_2X_SPEED_CLK_PRESCALER_DIV_8		0x01
#define SPI_2X_SPEED_CLK_PRESCALER_DIV_32		0x10
#define SPI_2X_SPEED_CLK_PRESCALER_DIV_64		0x11

// SPI MODES
#define SPI_SCK_MODE_LEAD_RISING_LEAD_SAMPLE	0x00
#define SPI_SCK_MODE_LEAD_RISING_LEAD_SETUP		0x04
#define SPI_SCK_MODE_LEAD_FALLING_LEAD_SAMPLE	0x08
#define SPI_SCK_MODE_LEAD_FALLING_LEAD_SETUP	0x0C

#endif