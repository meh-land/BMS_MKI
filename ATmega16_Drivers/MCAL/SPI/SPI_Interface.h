#ifndef SPI_Interface_H_
#define SPI_Interface_H_

void SPI_voidMasterInit(void);
void SPI_voidMasterTransmitByte(u8 copy_u8Data);
u8   SPI_u8MasterReceiveByte(void);

void SPI_voidSlaveInit(void);
void SPI_voidSlaveTransmitByte(u8 copy_u8Data);
u8   SPI_u8SlaveReceiveByte(void);

#endif