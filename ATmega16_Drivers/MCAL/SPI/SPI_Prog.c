#include "../../LIB/STD_Types.h"
#include "../../LIB/Bit_Math.h"
#include "SPI_Register.h"
#include "SPI_Private.h"
#include "SPI_CFG.h"
#include "SPI_Interface.h"

void SPI_voidMasterInit(void)
{
	/*set MOSI && SCK as output*/
	SET_BIT(DDR_SPI, SPI_SS); // output for master
	CLR_BIT(DDR_SPI, SPI_MISO);
	SET_BIT(DDR_SPI, SPI_MOSI);
	SET_BIT(DDR_SPI, SPI_SCK);
	
	/*select master mode*/
	SET_BIT(SPCR, SPI_SPCR_MSTR);
	
	/*send MSB first*/
	CLR_BIT(SPCR, SPI_SPCR_DORD);
	
	/*select SCK mode => rising && setup*/
	CLR_BIT(SPCR, SPI_SPCR_CPOL);
	SET_BIT(SPCR, SPI_SPCR_CPHA);
	
	/*select SCK prescaler => f/16*/
	SET_BIT(SPCR, SPI_SPCR_SPR0);
	CLR_BIT(SPCR, SPI_SPCR_SPR1);
	CLR_BIT(SPSR, SPI_SPSR_SPI2X);
	
	/*enable interrupt*/
	//SET_BIT(SPCR, SPI_SPCR_SPIE);
	
	/*enable SPI*/
	SET_BIT(SPCR, SPI_SPCR_SPE);
}

void SPI_voidMasterTransmitByte(u8 copy_u8Data)
{
	SPDR = copy_u8Data;
	
	while (GET_BIT(SPSR, SPI_SPSR_SPIF) == 0);
}

u8 SPI_u8MasterReceiveByte(void)
{
	while (GET_BIT(SPSR, SPI_SPSR_SPIF) == 0);
	
	return SPDR;
}

void SPI_voidSlaveInit(void)
{
	/*set MOSI && SCK as output*/
	CLR_BIT(DDR_SPI, SPI_SS); // input for slave
	SET_BIT(DDR_SPI, SPI_MISO);
	CLR_BIT(DDR_SPI, SPI_MOSI);
	CLR_BIT(DDR_SPI, SPI_SCK);
	
	/*select slave mode*/
	CLR_BIT(SPCR, SPI_SPCR_MSTR);
	
	/*send MSB first*/
	CLR_BIT(SPCR, SPI_SPCR_DORD);
	
	/*select SCK mode => rising && setup*/
	CLR_BIT(SPCR, SPI_SPCR_CPOL);
	SET_BIT(SPCR, SPI_SPCR_CPHA);
	
	/*enable interrupt*/
	//SET_BIT(SPCR, SPI_SPCR_SPIE);
	
	/*enable SPI*/
	SET_BIT(SPCR, SPI_SPCR_SPE);
}

void SPI_voidSlaveTransmitByte(u8 copy_u8Data)
{
	SPDR = copy_u8Data;
}

u8 SPI_u8SlaveReceiveByte(void)
{
	while (GET_BIT(SPSR, SPI_SPSR_SPIF) == 0);
	
	return SPDR;
}

void SPI_MasterTransmitStr(u8 *copy_strData)
{
	if (copy_strData == NULL)
	return;
	u8 local_u8StrIterator;
	for (local_u8StrIterator = 0; copy_strData[local_u8StrIterator] != '\0'; local_u8StrIterator++)
	{
		SPI_voidMasterTransmitByte(copy_strData[local_u8StrIterator]);
	}
}