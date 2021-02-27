/************************************************
 * AVR_Interfacing.c
 * Created: 1/15/2021 8:44:14 PM
 * Author: Eng_Fawzi
 **********************************************/ 
#define F_CPU 16000000UL
#include <stdio.h>
#include <util/delay.h>
#include <stdlib.h>
#include "Std_Types.h"
#include "Dio.h"
#include "Led.h"
#include "Button.h"
#include "SSD.h"
#include "Buzzer.h"
#include "Lcd.h"
#include "Eeprom.h"
#include <avr/interrupt.h>
#include <avr/io.h>
#include "Int.h"
#include "Adc.h"
#include "Wdg.h"
#include "Uart.h"
#define BAUD_PRESCALE (103)

int main(void)
{
	u8 data =0;
	Led_Init();
	UART_Init(103);
	UART_TransmitStr((u8*)"Hello UART....\n");
	while (1)
	{
		data=UART_ReceiveChr();
		if (data == 'm')
		{
			Led_Toggle(LED0);
		}
		else if (data == 'n')
		{
			Led_Toggle(LED1);
		}
	}
}
