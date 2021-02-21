 /**********************************************************************************************************************
 *  File		: Led.c
 *	Module		: LED
 *	Target		: General
 *	Author		: mFawzi
 *  Description	:      
 * 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Led.h"
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
* \Syntax          : void Led_Init(void)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : None
* \Return value:   : None
*******************************************************************************/
void Led_Init(void)
{
 Dio_ConfigChannel(LED0_PORT,LED0_CHANNEL,OUTPUT);
 Dio_ConfigChannel(LED1_PORT,LED1_CHANNEL,OUTPUT);
 Dio_ConfigChannel(LED2_PORT,LED2_CHANNEL,OUTPUT);
}
/******************************************************************************
* \Syntax          : void Led_TurnON(LED_ID LedID)
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : LedID	-   LED ID
* \Return value:   : None
*******************************************************************************/
void Led_TurnON(LED_ID LedID)
{
	switch (LedID)
	{
		case LED0:
		Dio_WriteChannel(LED0_PORT,LED0_CHANNEL,STD_HIGH);
		break;	
	
		case LED1:
		Dio_WriteChannel(LED1_PORT,LED1_CHANNEL,STD_HIGH);
		break;	
		case LED2:
		Dio_WriteChannel(LED2_PORT,LED2_CHANNEL,STD_HIGH);
		break;
	}
	
}
/******************************************************************************
* \Syntax          : void Led_TurnOFF(LED_ID LedID)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : LedID	-   LED ID
* \Return value:   : None
*******************************************************************************/
void Led_TurnOFF(LED_ID LedID)
{
		switch (LedID)
		{
			case LED0:
			Dio_WriteChannel(LED0_PORT,LED0_CHANNEL,STD_LOW);
			break;
			
			case LED1:
			Dio_WriteChannel(LED1_PORT,LED1_CHANNEL,STD_LOW);
			break;
			case LED2:
			Dio_WriteChannel(LED2_PORT,LED2_CHANNEL,STD_LOW);
			break;
		}
}
/******************************************************************************
* \Syntax          : void Led_Toggle(LED_ID LedID)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : LedID	-   LED ID
* \Return value:   : None
*******************************************************************************/
void Led_Toggle(LED_ID LedID)
{
	switch (LedID)
	{
	case LED0:
		Dio_FlipChannel(LED0_PORT,LED0_CHANNEL);
		break;

	case LED1:
		Dio_FlipChannel(LED1_PORT,LED1_CHANNEL);
		break;
	case LED2:
		Dio_FlipChannel(LED2_PORT,LED2_CHANNEL);
		break;
	}
}
/**********************************************************************************************************************
 *  END OF FILE: LED.c
 *********************************************************************************************************************/
