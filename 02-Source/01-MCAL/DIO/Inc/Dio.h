 /********************************************************************************************************************
 *  File		: Dio.h
 *	Module		: DIO
 *	Target		: ATMEGA32
 *	Author		: mFawzi
 *  Description	:      
 *********************************************************************************************************************/
#ifndef DIO_H_
#define DIO_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Bit_Math.h"
#include "Dio_Cfg.h"
#include "Dio_Private.h"

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
	DIO_CH_0,
	DIO_CH_1,
	DIO_CH_2,
	DIO_CH_3,
	DIO_CH_4,
	DIO_CH_5,
	DIO_CH_6,
	DIO_CH_7		
	}Dio_ChannelID;

typedef enum{
	DIO_PORTA,
	DIO_PORTB,
	DIO_PORTC,
	DIO_PORTD
	}Dio_PortID;

typedef enum{
	STD_LOW,
	STD_HIGH
}Dio_LevelType;

typedef enum{
	INPUT,
	OUTPUT 
}Dio_DirectionType;


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void Dio_ConfigChannel(Dio_PortID portID,Dio_ChannelID channelID, Dio_DirectionType channelDir);
void Dio_ConfigChannelPullUp(Dio_PortID portID,Dio_ChannelID channelID);
void Dio_WriteChannel (Dio_PortID PortID,Dio_ChannelID ChannelId, Dio_LevelType ChannelLevel);
Dio_LevelType Dio_ReadChannel (Dio_PortID PortID,Dio_ChannelID ChannelId);
void Dio_FlipChannel(Dio_PortID PortID,Dio_ChannelID ChannelId);
void Dio_ConfigChannelGroup(Dio_PortID portID, u8 mask, Dio_DirectionType channelDir);
void Dio_WriteChannelGroup(Dio_PortID portID, u8 mask, u8 position, u8 data);
u8 Dio_ReadChannelDroup(Dio_PortID portID, u8 mask, u8 position);

void Dio_ConfigPort(Dio_PortID portID, u8 portDir);
void Dio_WritePort(Dio_PortID PortID, u8 data);
u8 Dio_ReadPort(Dio_PortID PortID);
#endif  /* FILE_NAME_H */

/**********************************************************************************************************************
 *  END OF FILE: DIO.h
 *********************************************************************************************************************/
