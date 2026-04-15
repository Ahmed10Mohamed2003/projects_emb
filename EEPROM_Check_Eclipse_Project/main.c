/*
 * main.c
 *
 *  Created on: Aug 3, 2025
 *      Author: ALKING
 */

#include "LIB/STD_TYPES.h"
#include "LIB/bitMath.h"
#include "avr/io.h"
//#include "avr/delay.h"
#include "LIB/delay.h"
#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/UART/UART_interface.h"
#include "MCAL/ADC/ADC_interface.h"
#include "MCAL/EXIT_INT/EXIT_INT_interface.h"
#include "MCAL/GINT_CON/GINT_CON_interface.h"

#include "MCAL/TWI/TWI_interface.h"
#include "HAL/EEPROM/EEPROM_interface.h"

int main()
{

	DIO_voidInit();
	UART_voidInit();
	TWI_voidInitMaster(0);
	delay_ms(100);
	u8 chr = 'A';
	/*
	UART_voidTransmit('1');
	for(u32 i = 0 ;i < 50 ;++i)
	{
		EEPROM_voidSendDataByte(i,chr);
		if(chr < 'Z')
		++chr;
		else
		chr = 'A';
		delay_ms(20);
	}*/
	//EEPROM_voidSendDataByte(50,chr);
	//delay_ms(20);
	//UART_voidTransmit(EEPROM_u8ReadDataByte(50));
	while(1)
	{
		UART_voidTransmit('2');
		for(u32 i = 0 ;i < 50 ;++i)
		{
			UART_voidTransmit(EEPROM_u8ReadDataByte(i));
			delay_ms(20);
		}
		delay_ms(1000);
		UART_voidSendNewLine();
	}
	return 0;
}
