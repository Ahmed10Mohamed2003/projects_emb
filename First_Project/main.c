/*
 * main.c


 *
 *  Created on: 15 Jul 2025
 *      Author: Amr Elomda
 */
#include"avr/delay.h"
#include"bitmath.h"
#include"type.h"

#define PORTA *((char*)0x3B)
#define PORTB *((char*)0x38)
#define PORTC *((char*)0x35)
#define PORTD *((char*)0x32)

#define DDRA *((char*)0x3A)
#define DDRB *((char*)0x37)
#define DDRC *((char*)0x34)
#define DDRD *((char*)0x31)

#define OUTPUT 1
#define INPUT 0

#define HIGH 1
#define LOW 0

#define BIT0 0
#define BIT1 1
#define BIT2 2
#define BIT3 3
#define BIT4 4
#define BIT5 5
#define BIT6 6
#define BIT7 7

#define PORTA_A 0
#define PORTB_B 1
#define PORTC_C 2
#define PORTD_D 3
#define PORTE_E 4



u8 DIO_u8SetPinDirection(u8 port,u8 bit,u8 direction)
{
	volatile u8 *port1;
	switch (port)
			{
			case 0:port1=&DDRA;break;
			case 1:port1=&DDRB;break;
			case 2:port1=&DDRC;break;
			case 3:port1=&DDRD;;break;

			}
	if(direction==OUTPUT)
		set_bit(*port1,bit);
	else if(direction==INPUT)
		reset_bit(*port1,bit);
	else
		return -1;

	return 0;
}
u8 DIO_u8SetPinValue(u8 port,u8 bit,u8 value)
{
	volatile u8 *port1;
	switch( port)
				{
				case 0:port1=&PORTA;break;
				case 1:port1=&PORTB;break;
				case 2:port1=&PORTC;break;
				case 3:port1=&PORTD;break;

				}
	if(value==HIGH)
	set_bit(*port1,bit);
	else if(value==LOW)
		reset_bit(*port1,bit);
	else
		return -1;

	return 0;
}

int main()
{
	DIO_u8SetPinDirection(PORTA_A,BIT0,OUTPUT);
	DIO_u8SetPinDirection(PORTA_A,BIT1,OUTPUT);
	DIO_u8SetPinDirection(PORTA_A,BIT2,OUTPUT);
	DIO_u8SetPinDirection(PORTA_A,BIT3,OUTPUT);

	while(1)
	{
		DIO_u8SetPinValue(PORTA_A,BIT0,HIGH);
		_delay_ms(10);
		DIO_u8SetPinValue(PORTA_A,BIT0,LOW);
		_delay_ms(10);


	}

	return 0;
}

