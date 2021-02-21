 /**********************************************************************************************************************
 *  File		: Dio.c
 *	Module		: DIO
 *	Target		: ATMEGA32
 *	Author		: mFawzi
 *  Description	:      
 * 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Dio.h"
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
* \Syntax          : void Dio_ConfigChannel(Dio_PortID portID,Dio_ChannelID channelID, Dio_DirectionType channelDir)      
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : portID   portID
					:   channelID                                                                      
* \Return value:   :                               
*******************************************************************************/
void Dio_ConfigChannel(Dio_PortID portID,Dio_ChannelID channelID, Dio_DirectionType channelDir)
{
	switch (portID)
	{
	case DIO_PORTA:
		if (channelDir == INPUT)
		{
			CLEAR_BIT(DIO_PORTA_DDR,channelID);
		}

		else
		{
			SET_BIT(DIO_PORTA_DDR,channelID);
		}
		break;
	case DIO_PORTB:
		if (channelDir == INPUT)
		{
			CLEAR_BIT(DIO_PORTB_DDR,channelID);
		}

		else
		{
			SET_BIT(DIO_PORTB_DDR,channelID);
		}
		break;
	case DIO_PORTC:
		if (channelDir == INPUT)
		{
			CLEAR_BIT(DIO_PORTC_DDR,channelID);
		}

		else
		{
			SET_BIT(DIO_PORTC_DDR,channelID);
		}
		break;
	case DIO_PORTD:
		if (channelDir == INPUT)
		{
			CLEAR_BIT(DIO_PORTD_DDR,channelID);
		}

		else
		{
			SET_BIT(DIO_PORTD_DDR,channelID);
		}
		break;
	}
}

/******************************************************************************
* \Syntax          : void Dio_ConfigChannelPullUp(Dio_PortID portID,Dio_ChannelID channelID)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : portID   portID
					:   channelID
* \Return value:   :
*******************************************************************************/
void Dio_ConfigChannelPullUp(Dio_PortID portID,Dio_ChannelID channelID)
{
	switch (portID)
	{
		case DIO_PORTA:
			SET_BIT(DIO_PORTA_DATA_OUT,channelID);
		break;
		case DIO_PORTB:
			SET_BIT(DIO_PORTB_DATA_OUT,channelID);
		break;
		case DIO_PORTC:
			SET_BIT(DIO_PORTC_DATA_OUT,channelID);
		break;
		case DIO_PORTD:
			SET_BIT(DIO_PORTD_DATA_OUT,channelID);
		break;
	}
}
/************************************************************************************************************************
* \Syntax          : void Dio_ConfigChannel(Dio_PortType PortID,Dio_ChannelType ChannelId,Dio_DirectionType ChannelDir)       
* \Description     : This service configure DIO channels directions                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : PortID - Dio_PortType ID of DIO Port
*				   : ChannelId - Dio_ChannelType ID of DIO channel
				   : ChannelLevel- Dio_LevelType DIO channel Level                                                                     
* \Return value:   : None                        
**************************************************************************************************************************/
void Dio_WriteChannel (Dio_PortID PortID,Dio_ChannelID ChannelId, Dio_LevelType ChannelLevel)
{
	switch (PortID)
	{
		case DIO_PORTA:
		if (ChannelLevel == STD_LOW)
		{
			CLEAR_BIT(DIO_PORTA_DATA_OUT,ChannelId);
		}
		else
		{
			SET_BIT(DIO_PORTA_DATA_OUT,ChannelId);
		}
		break;
		case DIO_PORTB:
		if (ChannelLevel == STD_LOW)
		{
			CLEAR_BIT(DIO_PORTB_DATA_OUT,ChannelId);
		}
		else
		{
			SET_BIT(DIO_PORTB_DATA_OUT,ChannelId);
		}
		break;
		case DIO_PORTC:
		if (ChannelLevel == STD_LOW)
		{
			CLEAR_BIT(DIO_PORTC_DATA_OUT,ChannelId);
		}
		else
		{
			SET_BIT(DIO_PORTC_DATA_OUT,ChannelId);
		}
		break;
		case DIO_PORTD:
		if (ChannelLevel == STD_LOW)
		{
			CLEAR_BIT(DIO_PORTD_DATA_OUT,ChannelId);
		}
		else
		{
			SET_BIT(DIO_PORTD_DATA_OUT,ChannelId);
		}
		break;
	}
}
/************************************************************************************************************************
* \Syntax          : void Dio_ConfigChannel(Dio_PortType PortID,Dio_ChannelType ChannelId,Dio_DirectionType ChannelDir)       
* \Description     : This service configure DIO channels directions                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : PortID - Dio_PortType ID of DIO Port
*				   : ChannelId - Dio_ChannelType ID of DIO channel
				   : ChannelLevel- Dio_LevelType DIO channel Level                                                                     
* \Return value:   : None                        
**************************************************************************************************************************/
Dio_LevelType Dio_ReadChannel (Dio_PortID PortID,Dio_ChannelID ChannelId)
{
	Dio_LevelType Loc_Read=STD_LOW;
	switch (PortID)
	{
	case DIO_PORTA:
		if (CHECK_BIT(DIO_PORTA_DATA_IN,ChannelId))
		{
			Loc_Read = STD_HIGH;
		}
		else
		{
			Loc_Read = STD_LOW;
		}
		break;
	case DIO_PORTB:
		if (CHECK_BIT(DIO_PORTB_DATA_IN,ChannelId))
		{
			Loc_Read = STD_HIGH;
		}
		else
		{
			Loc_Read = STD_LOW;
		}
		break;
	case DIO_PORTC:
		if (CHECK_BIT(DIO_PORTC_DATA_IN,ChannelId))
		{
			Loc_Read = STD_HIGH;
		}
		else
		{
			Loc_Read = STD_LOW;
		}
		break;
	case DIO_PORTD:
		if (CHECK_BIT(DIO_PORTD_DATA_IN,ChannelId))
		{
			Loc_Read = STD_HIGH;
		}
		else
		{
			Loc_Read = STD_LOW;
		}
		break;
	}
	return Loc_Read;	
}
/************************************************************************************************************************
* \Syntax          : void Dio_FlipChannel(Dio_PortID PortID,Dio_ChannelID ChannelId)
* \Description     : This service Flip DIO channels
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : PortID - Dio_PortType ID of DIO Port
*				   : ChannelId - Dio_ChannelType ID of DIO channel
* \Return value:   : None
**************************************************************************************************************************/
void Dio_FlipChannel(Dio_PortID PortID,Dio_ChannelID ChannelId)
{
	switch (PortID)
	{
		case DIO_PORTA:
			FLIP_BIT(DIO_PORTA_DATA_OUT,ChannelId);
			break;
		case DIO_PORTB:
			FLIP_BIT(DIO_PORTB_DATA_OUT,ChannelId);
			break;
		case DIO_PORTC:
			FLIP_BIT(DIO_PORTC_DATA_OUT,ChannelId);
			break;
		case DIO_PORTD:
			FLIP_BIT(DIO_PORTD_DATA_OUT,ChannelId);
			break;
	}
}
/************************************************************************************************************************
* \Syntax          : void Dio_ConfigChannelGroup(Dio_PortID portID,u8 mask, Dio_DirectionType channelDir)      
* \Description     : This service configure DIO channels directions                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : PortID			- ID of DIO Port
*				   : mask			- DIO channel group position 
				   : channelDir		- DIO channel group direction                                                                     
* \Return value:   : None                        
**************************************************************************************************************************/
void Dio_ConfigChannelGroup(Dio_PortID portID,u8 mask, Dio_DirectionType channelDir)
{
	switch (portID)
	{
	case DIO_PORTA:
		if (channelDir == OUTPUT)
		{
			DIO_PORTA_DDR|= mask;
		}
		else
		{
			DIO_PORTA_DDR&= ~mask;
		}
		break;
	case DIO_PORTB:
		if (channelDir == OUTPUT)
		{
			DIO_PORTB_DDR|= mask;
		}
		else
		{
			DIO_PORTB_DDR&= ~mask;
		}
		break;
	case DIO_PORTC:
		if (channelDir == OUTPUT)
		{
			DIO_PORTC_DDR|= mask;
		}
		else
		{
			DIO_PORTC_DDR&= ~mask;
		}
		break;
	case DIO_PORTD:
		if (channelDir == OUTPUT)
		{
			DIO_PORTD_DDR|= mask;
		}
		else
		{
			DIO_PORTD_DDR&= ~mask;
		}
		break;
	}	
}
/************************************************************************************************************************
* \Syntax          : void Dio_ConfigChannelGroup(Dio_PortID portID,u8 mask, u8 data)     
* \Description     : This service configure DIO channels directions                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : PortID			- ID of DIO Port
*				   : mask			- DIO channel group position 
				   : data			- DIO channel group Level                                                                     
* \Return value:   : None                        
**************************************************************************************************************************/
void Dio_WriteChannelGroup(Dio_PortID portID, u8 mask, u8 position, u8 data)
{
	switch (portID)
	{
	case DIO_PORTA:
		DIO_PORTA_DATA_OUT = (DIO_PORTA_DATA_OUT & ~mask)|(data<<position) ;
		break;

	case DIO_PORTB:
		DIO_PORTB_DATA_OUT = (DIO_PORTB_DATA_OUT & ~mask)|(data<<position) ;
		break;
	case DIO_PORTC:
		DIO_PORTC_DATA_OUT = (DIO_PORTC_DATA_OUT & ~mask)|(data<<position) ;
		break;
	case DIO_PORTD:
		DIO_PORTD_DATA_OUT = (DIO_PORTD_DATA_OUT & ~mask)|(data<<position) ;
		break;
	}	
}
/************************************************************************************************************************
* \Syntax          : u8 Dio_ReadChannelDroup(Dio_PortID portID, u8 mask, u8 position)
* \Description     : This service configure DIO channels directions
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : PortID			- ID of DIO Port
*				   : mask			- DIO channel group mask
				   : position		- DIO channel group position
* \Return value:   : None
**************************************************************************************************************************/
u8 Dio_ReadChannelDroup(Dio_PortID portID, u8 mask, u8 position)
{
	u8 ret_Value=0;

	switch (portID)
	{
	case DIO_PORTA:
		ret_Value=DIO_PORTA_DATA_IN & mask;
		ret_Value=ret_Value<<position;
		break;
	case DIO_PORTB:
		ret_Value=DIO_PORTB_DATA_IN & mask;
		ret_Value=ret_Value<<position;
		break;
	case DIO_PORTC:
		ret_Value=DIO_PORTC_DATA_IN & mask;
		ret_Value=ret_Value<<position;
		break;
	case DIO_PORTD:
		ret_Value=DIO_PORTD_DATA_IN & mask;
		ret_Value=ret_Value<<position;
		break;
	}
	return ret_Value;
}
/************************************************************************************************************************
* \Syntax          : void Dio_ConfigPort(Dio_PortID portID, Dio_DirectionType portDir)
* \Description     : This service configure DIO channels directions
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : PortID			- ID of DIO Port
*				   : channelDir		- DIO channel port direction
* \Return value:   : None
**************************************************************************************************************************/
void Dio_ConfigPort(Dio_PortID portID, u8 portDir)
{
	switch (portID)
	{
	case DIO_PORTA:
		DIO_PORTA_DDR=portDir;
		break;
	case DIO_PORTB:
		DIO_PORTB_DDR=portDir;
		break;
	case DIO_PORTC:
		DIO_PORTC_DDR=portDir;
		break;
	case DIO_PORTD:
		DIO_PORTD_DDR=portDir;
		break;
	}
}
/************************************************************************************************************************
* \Syntax          : void Dio_WritePort(Dio_PortID portID, u8 data)
* \Description     : This service configure DIO channels directions
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : PortID			- ID of DIO Port
*				   : data			- data to be written
* \Return value:   : None
**************************************************************************************************************************/
void Dio_WritePort(Dio_PortID portID, u8 data)
{
	switch (portID)
	{
	case DIO_PORTA:
		DIO_PORTA_DATA_OUT=data;
		break;
	case DIO_PORTB:
		DIO_PORTB_DATA_OUT=data;
		break;
	case DIO_PORTC:
		DIO_PORTC_DATA_OUT=data;
		break;
	case DIO_PORTD:
		DIO_PORTD_DATA_OUT=data;
		break;
	}
}
/************************************************************************************************************************
* \Syntax          : u8 Dio_ReadPort(Dio_PortID portID)
* \Description     : This service configure DIO channels directions
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : PortID			- ID of DIO Port
* \Return value:   : port data value - u8
**************************************************************************************************************************/
u8 Dio_ReadPort(Dio_PortID portID)
{
	u8 data_Read=0;
	switch (portID)
	{
	case DIO_PORTA:
		data_Read = DIO_PORTA_DATA_IN;
		break;
	case DIO_PORTB:
		data_Read = DIO_PORTB_DATA_IN;
		break;
	case DIO_PORTC:
		data_Read = DIO_PORTC_DATA_IN;
		break;
	case DIO_PORTD:
		data_Read = DIO_PORTD_DATA_IN;
		break;
	}
	return data_Read;
}
/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
