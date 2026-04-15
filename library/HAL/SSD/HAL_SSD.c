/*
 * HAL_SSD.c

 *
 *  Created on: 21 Jul 2025
 *      Author: Amr Elomda
 */
#include "HAL_SSD.h"

const u8 digits[10] = {
    0b11000000, // 0
    0b11111001, // 1
    0b10100100, // 2
    0b10110000, // 3
    0b10011001, // 4
    0b10010010, // 5
    0b10000010, // 63
    0b11111000, // 7
    0b10000000, // 8
    0b10010000  // 9
};
void init_ssd(void)
{
	DIO_voidInit();
}

u8 write_ssd(u8 value)
{
	if(value >9||value<0)
		return 1;
	DIO_u8SetPortValue(DIO_u8_PORTA,digits[value]);
	return 0;
}
void enable_ssd(u8 Copy_u8PortId, u8 Copy_u8PinId,u8 AN_CATH)
{
	if(AN_CATH==ANODE)
	    DIO_u8SetPinValue(Copy_u8PortId,Copy_u8PinId,DIO_u8_HIGH);
	else
		DIO_u8SetPinValue(Copy_u8PortId,Copy_u8PinId,DIO_u8_LOW);
}

void disable_ssd(u8 Copy_u8PortId, u8 Copy_u8PinId,u8 AN_CATH)
{
	if(AN_CATH==ANODE)
		    DIO_u8SetPinValue(Copy_u8PortId,Copy_u8PinId,DIO_u8_LOW);
    else
			DIO_u8SetPinValue(Copy_u8PortId,Copy_u8PinId,DIO_u8_HIGH);
}
