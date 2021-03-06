 /********************************************************************************************************************
 *  File		: Spi.h
 *	Module		: SPI
 *	Target		: ATMEGA32
 *	Author		: mFawzi
 *  Description	:
 *********************************************************************************************************************/
#ifndef SPI_H
#define SPI_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Bit_Math.h"
#include "Spi_Cfg.h"
#include "Spi_Private.h"
#include "Dio.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define SPI_SCK_FREQ_FCPU_DIV_4			(0<<0)
#define SPI_SCK_FREQ_FCPU_DIV_16		(1<<0)
#define SPI_SCK_FREQ_FCPU_DIV_64		(2<<0)
#define SPI_SCK_FREQ_FCPU_DIV_128		(3<<0)


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void Spi_Init(u16 baudRate);
void Spi_TransmitChr(u8 data);
void Spi_TransmitStr(u8 *str);
u8 Spi_ReceiveChr(void);
#endif  /* UART_H */

/**********************************************************************************************************************
 *  END OF FILE: Eeprom.h
 *********************************************************************************************************************/
