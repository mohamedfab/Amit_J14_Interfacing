 /********************************************************************************************************************
 *  File		: Lcd_Cfg.h
 *	Module		: LCD
 *	Target		: General
 *	Author		: mFawzi
 *  Description	:      
 *********************************************************************************************************************/
#ifndef LCD_CFG_H_
#define LCD_CFG_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define LCD_RS_PORT				DIO_PORTB
#define LCD_RS_CHANNEL			DIO_CH_1

#define LCD_RW_PORT				DIO_PORTB
#define LCD_RW_CHANNEL			DIO_CH_2

#define LCD_EN_PORT				DIO_PORTB
#define LCD_EN_CHANNEL			DIO_CH_3

#define LCD_DATA_PORT			DIO_PORTA
#define LCD_DATA_GRP_POS		(4u)
#define LCD_MASK				(0xF0u)
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

 
#endif  /* LCD_CFG_H_ */

/**********************************************************************************************************************
 *  END OF FILE: Lcd_Cfg.h
 *********************************************************************************************************************/
