/*
 * main.c
 *
 *  Created on: Aug 2, 2025
 *      Author: Ahmed
 */
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/DIO/DIO_Private.h"
#include "HAL/DOOR/DOOR_interface.h"
#include "MCAL/TIMER1/TIMER1_interface.h"
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>

int main(void)
{
    DIO_voidInit();
    TWI_voidInitMaster(0);
    u8 x=0;
   for(u32 i=0;i<1023;i++)
   {
	   EEPROM_voidSendDataByte(i,x);
	   x++;
			   if(x==255)
				   x=0;
   }
   while(1);
}
