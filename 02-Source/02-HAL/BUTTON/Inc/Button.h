 /********************************************************************************************************************
 *  File		: Button.h
 *	Module		: BUTTON
 *	Target		: General
 *	Author		: mFawzi
 *  Description	:      
 *********************************************************************************************************************/
#ifndef BUTTON_H_
#define BUTTON_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Dio.h"
#include "Button_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum{
	BUTTON0,
	BUTTON1,
	BUTTON2
}Button_Id;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void Button_Init(void);
boolean Button_Pressed(Button_Id ButtonID);
#endif  /* SWTCH_H */

/**********************************************************************************************************************
 *  END OF FILE: Swtch.h
 *********************************************************************************************************************/
