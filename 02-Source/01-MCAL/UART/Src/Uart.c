 /**********************************************************************************************************************
 *  File		: Uart.c
 *	Module		: UART
 *	Target		: ATMEGA32
 *	Author		: mFawzi
 *  Description	:
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Uart.h"
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
* \Syntax          : void UART_Init(u16 baudRate)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : baudRate - Baudrate corresponding value
* \Return value:   : None
*******************************************************************************/
void UART_Init(u16 baudRate)
{
	/* Set baud rate */
	UART_UBRRH_REG = (u8)(baudRate>>8);
	UART_UBRRL_REG = (u8)baudRate;
	/* Enable receiver and transmitter */
	SET_BIT(UART_UCSRB_REG,RXEN_BIT_NO);  /* Enable Receiver*/
	SET_BIT(UART_UCSRB_REG,TXEN_BIT_NO);  /* Enable Transmitter */
	/* Set frame format: 8data, 1stop bit, Even Parity */
	UART_UCSRC_REG |= (1 << URSEL_BIT_NO)|UART_8_BIT_DATA | UART_EVEN_PARITY;
}
/******************************************************************************
* \Syntax          : void Uart_TransmitChr(u8 data)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : data - data byte to transmit
* \Return value:   : None
*******************************************************************************/
void UART_TransmitChr(u8 data)
{
	/* Wait for empty transmit buffer */
	while (!(CHECK_BIT(UART_UCSRA_REG,UDRE_BIT_NO)))
			;
	/* Put data into buffer, sends the data */
	UART_UDR_REG = data;
}
/******************************************************************************
* \Syntax          : void Uart_TransmitStr(u8 data)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : data - data byte to transmit
* \Return value:   : None
*******************************************************************************/
void UART_TransmitStr(u8 *str)
{
	/* Wait for empty transmit buffer */
	while (*str != '\0')
	{
		UART_TransmitChr(*str);
		str++;
	}
}
/******************************************************************************
* \Syntax          : u8 Uart_ReceiveChr(void)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : Nonr
* \Return value:   : data byte received
*******************************************************************************/
u8 UART_ReceiveChr(void)
{
	/* Wait for data to be received */
	while (!(CHECK_BIT(UART_UCSRA_REG,RXC_BIT_NO)))
			;
	/* Get and return received data from buffer */
	return UART_UDR_REG;
}

/**********************************************************************************************************************
 *  END OF FILE: Uart.c
 *********************************************************************************************************************/
