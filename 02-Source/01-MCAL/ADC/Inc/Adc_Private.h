 /********************************************************************************************************************
 *  File		: Adc_Private.h
 *	Module		: ADC
 *	Target		: ATMEGA32
 *	Author		: mFawzi
 *  Description	:
 *********************************************************************************************************************/
#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define ADC_ADMUX_REG       (*(volatile u8*)0x27)
#define ADC_ADCSRA_REG		(*(volatile u8*)0x26)
#define ADC_ADCH_REG		(*(volatile u8*)0x25)
#define ADC_ADCL_REG		(*(volatile u8*)0x24)


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


#endif  /* ADC_PRIVATE_H */

/**********************************************************************************************************************
 *  END OF FILE: Adc_Private.h
 *********************************************************************************************************************/
