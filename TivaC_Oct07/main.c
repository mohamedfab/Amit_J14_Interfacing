
/**
 * main.c
 */
#include "Dio.h"

void delay_ms(u32 delayMs)
{
    u32 delay;
    u32 count;
    for (delay = 0;delay <delayMs; delay++)
    {
        for (count =0;count<1590;count++)
        {
            ;  /*   delay for 1 MS */
        }
    }
}
void main(void)

 {
    Dio_EnableClock(DIO_PORTF);
    Dio_EnableDigitalChannel(DIO_PORTF,DIO_CHANNEL3);
    Dio_ConfigureChannel(DIO_PORTF, DIO_CHANNEL3, OUTPUT);
    while (1)
    {
        Dio_WriteChannel(DIO_PORTF, DIO_CHANNEL3, HIGH);
        delay_ms(1000);
        Dio_WriteChannel(DIO_PORTF, DIO_CHANNEL3, LOW);
        delay_ms(1000);
    }
}
