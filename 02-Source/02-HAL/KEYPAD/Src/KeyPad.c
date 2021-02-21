 /**********************************************************************************************************************
 *  File		: KeyPad.c
 *	Module		: KEYPAD
 *	Target		: General
 *	Author		: mFawzi
 *  Description	:      
 * 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "KeyPad.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
const u8 KeyPad_Vlues[4][4] = {  	{'7','8','9','/'},
                                    {'4','5','6','*'},
								    {'1','2','3','-'},
								    {'c','0','=','+'}
								};
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
* \Syntax          : void KeyPad_Init(void)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : None
* \Return value:   : None
*******************************************************************************/
void KeyPad_Init(void)
{
	Dio_ConfigChannel(KEYPAD_DATA_PORT ,COL0, OUTPUT);
	Dio_ConfigChannel(KEYPAD_DATA_PORT ,COL1, OUTPUT);
	Dio_ConfigChannel(KEYPAD_DATA_PORT ,COL2, OUTPUT);
	Dio_ConfigChannel(KEYPAD_DATA_PORT ,COL3, OUTPUT);

	Dio_ConfigChannel(KEYPAD_DATA_PORT ,ROW0, INPUT);
	Dio_ConfigChannel(KEYPAD_DATA_PORT ,ROW1, INPUT);
	Dio_ConfigChannel(KEYPAD_DATA_PORT ,ROW2, INPUT);
	Dio_ConfigChannel(KEYPAD_DATA_PORT ,ROW3, INPUT);

	Dio_ConfigChannelPullUp(KEYPAD_DATA_PORT ,ROW0);
	Dio_ConfigChannelPullUp(KEYPAD_DATA_PORT ,ROW1);
	Dio_ConfigChannelPullUp(KEYPAD_DATA_PORT ,ROW2);
	Dio_ConfigChannelPullUp(KEYPAD_DATA_PORT ,ROW3);

	Dio_WriteChannel(KEYPAD_DATA_PORT, COL0, STD_HIGH);
	Dio_WriteChannel(KEYPAD_DATA_PORT, COL1, STD_HIGH);
	Dio_WriteChannel(KEYPAD_DATA_PORT, COL2, STD_HIGH);
	Dio_WriteChannel(KEYPAD_DATA_PORT, COL3, STD_HIGH);
}
/******************************************************************************
* \Syntax          : u8 KeyPad_Scan(void)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : None
* \Return value:   : None
*******************************************************************************/
u8 KeyPad_Scan(void)
{
		u8 LOC_Coloum = 0;

		u8 LOC_ROW = 0;

		u8 Value = 0;

		u8 Temp = 0;

		for(LOC_Coloum = COL0 ; LOC_Coloum <= COL3 ; LOC_Coloum++)
		{

			Dio_WriteChannel(KEYPAD_DATA_PORT, LOC_Coloum, STD_LOW);

			for(LOC_ROW = ROW0 ; LOC_ROW <= ROW3 ; LOC_ROW++)
			{

				Temp=Dio_ReadChannel(KEYPAD_DATA_PORT, LOC_ROW);

				if(!Temp)
				{
					Value = KeyPad_Vlues[LOC_ROW - ROW0][LOC_Coloum - COL0];

					while(!Temp)
					{
						Temp=Dio_ReadChannel(KEYPAD_DATA_PORT, LOC_ROW);
					}

					_delay_ms(10);
				}

			}
			Dio_WriteChannel(KEYPAD_DATA_PORT, LOC_Coloum, STD_HIGH);
		}

		return Value ;
}
/**********************************************************************************************************************
 *  END OF FILE: KeyPad.c
 *********************************************************************************************************************/
