 /**********************************************************************************************************************
 *  File		: SSD.c
 *	Module		: SSD
 *	Target		: General
 *	Author		: mFawzi
 *  Description	:      
 * 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "SSD.h"
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
* \Syntax          : void SSD_Init(void)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : None
* \Return value:   : None
*******************************************************************************/
void SSD_Init(void)
{
		/*	configure SSD1 Enable Channel as Output	*/
	Dio_ConfigChannel(SSD_DIG1_EN_PORT,SSD_DIG1_EN_CHANNEL,OUTPUT);
		/*	configure SSD1 Enable Channel as Output	*/
	Dio_ConfigChannel(SSD_DIG2_EN_PORT,SSD_DIG2_EN_CHANNEL,OUTPUT);
		/*	configure SSD Data Channels as Output	*/
	Dio_ConfigChannelGroup(SSD_DATA_PORT,SSD_MASK,OUTPUT);
}
/******************************************************************************
* \Syntax          : void SSD_Display(u8 number)
* \Description     : This Service shall be called periodically every 10 ms
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : number - Two digit number (0 : 99)
* \Return value:   : None
*******************************************************************************/
void SSD_Display(u8 number)
{
		/*	Turn ON SSD 1	*/
	Dio_WriteChannel(SSD_DIG1_EN_PORT,SSD_DIG1_EN_CHANNEL,STD_HIGH);
		/*	Turn OFF SSD 2	*/
	Dio_WriteChannel(SSD_DIG2_EN_PORT,SSD_DIG2_EN_CHANNEL,STD_LOW);
		/*	Set First Digit of Displayed Number	*/
	Dio_WriteChannelGroup(SSD_DATA_PORT,SSD_MASK,SSD_DATA_GRP_POS,number%10);
	_delay_ms(1);

		/*	Turn OFF SSD 1	*/
	Dio_WriteChannel(SSD_DIG1_EN_PORT,SSD_DIG1_EN_CHANNEL,STD_LOW);
		/*	Turn ON SSD 2	*/
	Dio_WriteChannel(SSD_DIG2_EN_PORT,SSD_DIG2_EN_CHANNEL,STD_HIGH);
		/*	Set Second Digit of Displayed Number	*/
	Dio_WriteChannelGroup(SSD_DATA_PORT,SSD_MASK,SSD_DATA_GRP_POS,number/10);
	_delay_ms(1);
		/*	Turn OFF SSD 1	*/
	Dio_WriteChannel(SSD_DIG1_EN_PORT,SSD_DIG1_EN_CHANNEL,STD_LOW);
		/*	Turn OFF SSD 2	*/
	Dio_WriteChannel(SSD_DIG2_EN_PORT,SSD_DIG2_EN_CHANNEL,STD_LOW);
}
/**********************************************************************************************************************
 *  END OF FILE: SSD.c
 *********************************************************************************************************************/
