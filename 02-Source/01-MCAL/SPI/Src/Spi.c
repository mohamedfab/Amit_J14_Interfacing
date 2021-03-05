 /**********************************************************************************************************************
 *  File		: Spi.c
 *	Module		: SPI
 *	Target		: ATMEGA32
 *	Author		: mFawzi
 *  Description	:
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Spi.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : void Spi_MasterInit(void)
* \Description     : This service shall initialize SPI in Master mode
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : None
* \Return value:   : None
*******************************************************************************/
void Spi_MasterInit(void)
{
	/*	configure SPI MOSI Pin as output	*/
	Dio_ConfigChannel(SPI_MOSI_PORT, SPI_MOSI_CHANNEL, OUTPUT);
	/*	configure SPI SS Pin as output	*/
	Dio_ConfigChannel(SPI_SS_PORT, SPI_SS_CHANNEL, OUTPUT);
	/*	configure SPI SCK Pin as output	*/
	Dio_ConfigChannel(SPI_SCK_PORT, SPI_SCK_CHANNEL, OUTPUT);
	/*	configure SPI MISO Pin as input	*/
	Dio_ConfigChannel(SPI_MISO_PORT, SPI_MISO_CHANNEL, INPUT);
	/*	initialize SPI SS pin with HIGH (No slave selected) */
	Dio_WriteChannel(SPI_SS_PORT, SPI_SS_CHANNEL, STD_HIGH);
	/*	enable SPI Module	*/
	SET_BIT(SPI_SPCR_REG,SPI_SPE_BIT_NO);
	/*	enable SPI Module in Master mode	*/
	SET_BIT(SPI_SPCR_REG,SPI_MSTR_BIT_NO);
	/*	set SCK frequency by F_CPU/16	*/
	SPI_SPCR_REG|=SPI_SCK_FREQ_FCPU_DIV_16;
}
/******************************************************************************
* \Syntax          : void Spi_SlaveInit(void)
* \Description     : This service shall initialize SPI in Slave mode.
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : None
* \Return value:   : None
*******************************************************************************/
void Spi_SlaveInit(void)
{
	/*	configure SPI MOSI Pin as input	*/
	Dio_ConfigChannel(SPI_MOSI_PORT, SPI_MOSI_CHANNEL, INPUT);
	/*	configure SPI SS Pin as input	*/
	Dio_ConfigChannel(SPI_SS_PORT, SPI_SS_CHANNEL, INPUT);
	/*	configure SPI SCK Pin as input	*/
	Dio_ConfigChannel(SPI_SCK_PORT, SPI_SCK_CHANNEL, INPUT);
	/*	configure SPI MISO Pin as output	*/
	Dio_ConfigChannel(SPI_MISO_PORT, SPI_MISO_CHANNEL, OUTPUT);
	/*	enable SPI Module	*/
	SET_BIT(SPI_SPCR_REG,SPI_SPE_BIT_NO);
	/*	enable SPI Module in Slave mode	*/
	CLEAR_BIT(SPI_SPCR_REG,SPI_MSTR_BIT_NO);
}
/******************************************************************************
* \Syntax          : void Spi_MasterWrite(u8 data)
* \Description     : This service shall send a byte through SPI.
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : datd - a byte of data to send
* \Return value:   : None
*******************************************************************************/
void Spi_MasterWrite(u8 data)
{
	u8 loc_flush_byte;
	/*	load SPI data register with a byte to send	*/
	SPI_SPDR_REG = data;
	/*	wait until byte sent	*/
	while(!(CHECK_BIT(SPI_SPSR_REG,SPI_SPIF_BIT_NO)));
	/*	flush the data register	*/
	loc_flush_byte = SPI_SPDR_REG;
}
/******************************************************************************
* \Syntax          : u8 Spi_MasterRead(void)
* \Description     : This service shall send a byte through SPI.
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : None
* \Return value:   : read byte
*******************************************************************************/
u8 Spi_MasterRead(void)
{
	u8 loc_dummy_byte=0xFF;
	/*	load SPI data register with a byte to send	*/
	SPI_SPDR_REG = loc_dummy_byte;
	/*	wait until byte received	*/
	while(!(CHECK_BIT(SPI_SPSR_REG,SPI_SPIF_BIT_NO)));
	/*	read the data register	*/
	return SPI_SPDR_REG;
}
/******************************************************************************
* \Syntax          : u8 Spi_SlaveRead(void)
* \Description     : This service shall send a byte through SPI.
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : None
* \Return value:   : read byte
*******************************************************************************/
u8 Spi_SlaveRead(void)
{
	/*	wait until byte received	*/
	while(!(CHECK_BIT(SPI_SPSR_REG,SPI_SPIF_BIT_NO)));
	/*	read the data register	*/
	return SPI_SPDR_REG;
}
/**********************************************************************************************************************
 *  END OF FILE: Uart.c
 *********************************************************************************************************************/
