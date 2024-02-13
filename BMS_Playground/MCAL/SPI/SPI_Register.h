#ifndef SPI_REGISTER_H_
#define SPI_REGISTER_H_

#define SPCR	(*(volatile u8 *)(0x2D))
#define SPSR	(*(volatile u8 *)(0x2E))
#define SPDR	(*(volatile u8 *)(0x2F))
#define DDR_SPI	(*(volatile u8 *)(0x37))

#endif