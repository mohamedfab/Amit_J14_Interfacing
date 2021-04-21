/*
 * Dio.h
 *
 *  Created on: Apr 12, 2021
 *      Author: Eng_Fawzi
 */

#ifndef DIO_H_
#define DIO_H_

#include "Dio_Private.h"
#include "Std_Types.h"
#include "Dio_Types.h"
#include "Bit_Math.h"

/*  Functions prototypes    */
void Dio_EnableClock(Dio_PortID port);
void Dio_EnableDigitalChannel(Dio_PortID port, Dio_ChannelID channel);
void Dio_ConfigureChannel(Dio_PortID port, Dio_ChannelID channel, Dio_ChannelDirection dir);
void Dio_WriteChannel(Dio_PortID port, Dio_ChannelID channel, Dio_ChannelLevel level);
#endif /* DIO_H_ */
