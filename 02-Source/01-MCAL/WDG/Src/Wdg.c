 /**********************************************************************************************************************
 *  File		: Wdg.c
 *	Module		: WDG
 *	Target		: ATMEGA32
 *	Author		: mFawzi
 *  Description	:
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Wdg.h"
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
* \Syntax          : void WDG_ON(void)
* \Description     :  This service shall configure and enable WDG timer
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : None
* \Return value:   : None
*******************************************************************************/
void WDG_ON(void)
{
	/*	Set Watchdog Timer Window to 2.1 Sec	*/
	WDG_WDTCR_REG |= WDG_WINDOW_5V_2POINT1_SEC;
	/*	Enable Watchdog Timer	*/
	SET_BIT(WDG_WDTCR_REG,WDG_ENABLE_BIT);
}
/******************************************************************************
* \Syntax          : void WDG_OFF(void)
* \Description     :  This service shall Disable WDG timer
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : None
* \Return value:   : None
*******************************************************************************/
void WDG_OFF(void)
{
	WDG_WDTCR_REG =(WDG_ENABLE)|(WDG_TURN_OFF_ENABLE);
	CLEAR_BIT(WDG_WDTCR_REG,WDG_ENABLE_BIT);
}
/******************************************************************************
* \Syntax          : void WDG_Refresh(void)
* \Description     :  This service shall Refresh WDG timer
*
* \Sync\Async      : Asynchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : None
* \Return value:   : None
*******************************************************************************/
void WDG_Refresh(void)
{
	asm("WDR");
}
/**********************************************************************************************************************
 *  END OF FILE: Wdg.c
 *********************************************************************************************************************/
