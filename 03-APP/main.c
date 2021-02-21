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

int main(void)
{
	Led_Init();
	WDG_ON();  /*	WDG starts with window 2.1 Second	*/
	Led_TurnON(LED0);
	_delay_ms(500);
	Led_TurnOFF(LED0);
	_delay_ms(500);
	while(1)
	{
		WDG_Refresh();
	 Led_TurnON(LED1);
	 _delay_ms(500);
	 Led_TurnOFF(LED1);
	 _delay_ms(500);
	}
}
