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
#include "Eeprom14C16.h"
int main(void)
{
	u8 data=0;
	Lcd_Init();
	Lcd_Cmd(_LCD_CURSOR_OFF);
	Eeprom14C32_Init();
	Eeprom14C32_WriteByte(0x00, 'A');
//	_delay_ms(1000);
	data = Eeprom14C32_ReadByte(0x00);
	Lcd_GotoRowColumn(0, 0);
	Lcd_DisplayChr(data);
	while (1)
	{
		;
	}
}
