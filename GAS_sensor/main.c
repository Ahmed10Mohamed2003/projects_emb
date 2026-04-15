#include "MCAL/EXTI/GI_interface.h"
#include "LIB/STD_TYPES.h"
#include <stdio.h>
#include "LIB/BIT_MATH.h"
#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/TIMER0/TIMER0_interface.h"
#include <util/delay.h>
#include "MCAL/EXTI/EXTI_interface.h"
#include "MCAL/UART/UART_interface.h"
#include "MCAL/DIO/DIO_interface.h"
#include "HAL/LM35/LM35_interface.h"
#include <HAL/MQ2/MQ2_interface.h>

int main(void)
{
	DIO_voidInit();
	UART_voidInit();
	LCD_voidInit();
   while(1)
   {

	 if( MQ2_IsThierGasLeakage())
	 { DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN7,DIO_u8_HIGH);
		 LCD_voidSendString("Warning!!");
	 }


_delay_ms(4000);
DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN7,DIO_u8_LOW);
//LCD_voidClearDisplay();

   }
}



