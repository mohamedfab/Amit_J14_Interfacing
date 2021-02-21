 /**********************************************************************************************************************
 *  File		: Lcd.c
 *	Module		: LCD
 *	Target		: General
 *	Author		: mFawzi
 *  Description	:      
 * 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Lcd.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
u8 customChar[] = {
		  0x04,
		  0x1F,
		  0x11,
		  0x11,
		  0x1F,
		  0x1F,
		  0x1F,
		  0x1F
};
/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
/******************************************************************************
* \Syntax          : static void enablePulse(void)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : None
* \Return value:   : None
*******************************************************************************/
static void enablePulse(void)
{
	Dio_WriteChannel(LCD_EN_PORT,LCD_EN_CHANNEL,STD_HIGH);
	_delay_us(1);
	Dio_WriteChannel(LCD_EN_PORT,LCD_EN_CHANNEL,STD_LOW);
	_delay_ms(2);
}
/******************************************************************************
* \Syntax          : void Lcd_Write(u8 data)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : data - byte of data to be sent to LCD
* \Return value:   : None
*******************************************************************************/
static void Lcd_Write(u8 data)
{
	u8 MSB_Nibble=data>>LCD_DATA_GRP_POS;
	u8 LSB_Nibble=data;
		Dio_WriteChannelGroup(LCD_DATA_PORT,LCD_MASK,LCD_DATA_GRP_POS,MSB_Nibble);
		enablePulse();
		Dio_WriteChannelGroup(LCD_DATA_PORT,LCD_MASK,LCD_DATA_GRP_POS,LSB_Nibble);
		enablePulse();
}
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/******************************************************************************
* \Syntax          : void Lcd_Cmd(LcdCmdType cmd)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : cmd - command to be sent to LCD
* \Return value:   : None
*******************************************************************************/
void Lcd_Cmd(LcdCmdType cmd)
{
		Dio_WriteChannel(LCD_RW_PORT,LCD_RW_CHANNEL,STD_LOW);		/*	write mode	*/
		Dio_WriteChannel(LCD_RS_PORT,LCD_RS_CHANNEL,STD_LOW);		/*	cmd mode	*/
		Lcd_Write(cmd);
}
/******************************************************************************
* \Syntax          : void Lcd_DisplayChar(u8 data)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : data - byte of data to be sent to LCD
* \Return value:   : None
*******************************************************************************/
void Lcd_DisplayChr(u8 data)
{
		Dio_WriteChannel(LCD_RW_PORT,LCD_RW_CHANNEL,STD_LOW);		/*	write mode	*/
		Dio_WriteChannel(LCD_RS_PORT,LCD_RS_CHANNEL,STD_HIGH);		/*	data mode	*/
		Lcd_Write(data);
}
/******************************************************************************
* \Syntax          : void Lcd_DisplayString(u8 *str)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : str - string to be displayed on LCD
* \Return value:   : None
*******************************************************************************/
void Lcd_DisplayStr(u8 *str)
{
		while(*str !='\0')
		{
			Lcd_DisplayChr(*str);
			str++;
		}
}
/******************************************************************************
* \Syntax          : void Lcd_GotoRowColumn(u8 row,u8 column)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : row - Row number
* 				   : column - Column number
* \Return value:   : None
*******************************************************************************/
void Lcd_GotoRowColumn(u8 row,u8 column)
{
switch (row)
	{
	case 0:
		Lcd_Cmd(0x80+column);
		break;
	case 1:
		Lcd_Cmd(0xC0+column);
		break;
	}
}
void Lcd_WriteCustomChr(void)
{
	u8 indx;
	Lcd_Cmd(0x40);

	for (indx =0;	indx<8;	indx++)
	{
		Lcd_DisplayChr(customChar[indx]);
	}
}
/******************************************************************************
* \Syntax          : void Lcd_Init(void)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : None
* \Return value:   : None
*******************************************************************************/
void Lcd_Init(void)
{
		/*	Configure RS Pin as Output	*/
	Dio_ConfigChannel(LCD_RS_PORT,LCD_RS_CHANNEL,OUTPUT);
		/*	Configure RW Pin as Output	*/
	Dio_ConfigChannel(LCD_RW_PORT,LCD_RW_CHANNEL,OUTPUT);
		/*	Configure EN Pin as Output	*/
	Dio_ConfigChannel(LCD_EN_PORT,LCD_EN_CHANNEL,OUTPUT);
		/*	Configure Data Pins as Output	*/
	Dio_ConfigChannelGroup(LCD_DATA_PORT,LCD_MASK,OUTPUT);

		/*initialize LCD*/
		_delay_ms(15);
		Lcd_Cmd(0x03);
		_delay_ms(5);
		Lcd_Cmd(0x03);
		_delay_us(100);
		Lcd_Cmd(0x03);
		Lcd_Cmd(0x02);
		Lcd_Cmd(0x02);
		Lcd_Cmd(_LCD_4BIT_MODE);
		Lcd_Cmd(_LCD_CLEAR);
}
/**********************************************************************************************************************
 *  END OF FILE: Lcd.c
 *********************************************************************************************************************/
