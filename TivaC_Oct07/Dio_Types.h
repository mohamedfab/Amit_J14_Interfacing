/*
 * Dio_Types.h
 *
 *  Created on: Apr 12, 2021
 *      Author: Eng_Fawzi
 */

#ifndef DIO_TYPES_H_
#define DIO_TYPES_H_

typedef enum {
    DIO_PORTA,
    DIO_PORTB,
    DIO_PORTC,
    DIO_PORTD,
    DIO_PORTE,
    DIO_PORTF
}Dio_PortID;

typedef enum{
    DIO_CHANNEL0,
    DIO_CHANNEL1,
    DIO_CHANNEL2,
    DIO_CHANNEL3,
    DIO_CHANNEL4,
    DIO_CHANNEL5,
    DIO_CHANNEL6,
    DIO_CHANNEL7
}Dio_ChannelID;

typedef enum{
    INPUT,
    OUTPUT
}Dio_ChannelDirection;

typedef enum{
    LOW,
    HIGH
}Dio_ChannelLevel;
#endif /* DIO_TYPES_H_ */
