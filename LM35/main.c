#include "MCAL/EXTI/GI_interface.h"
#include "LIB/STD_TYPES.h"
#include <stdio.h>
#include "LIB/BIT_MATH.h"
#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/TIMER0/TIMER0_interface.h"
#include <util/delay.h>
#include "MCAL/EXTI/EXTI_interface.h"
#include "HAL/UART/UART_interface.h"
#include "MCAL/DIO/DIO_interface.h"
#include "HAL/LM32/LM32_interface.h"


int main(void)
{
	DIO_voidInit();
	UART_voidInit();
	LCD_voidInit();
   while(1)
   {

/*
	  u8 data= UART_u8Receive();
	  UART_voidSendData(data);*/

	   f32 num=LM32_Read_Tempreture();
	   u8 str[10];
	       u8 i = 0;

	       if (num < 0)
	       {
	           str[i++] = '-';
	           num = -num;
	       }
	       else
	       {
	           str[i++] = '+';
	       }

	       u16 int_part = (u16)num;
	       u16 frac_part = (u16)((num - int_part) * 100 + 0.5);  // rounded

	       // Integer to string
	       if (int_part == 0)
	           str[i++] = '0';
	       else
	       {
	           u8 temp[5];
	           u8 j = 0;
	           while (int_part > 0)
	           {
	               temp[j++] = (int_part % 10) + '0';
	               int_part /= 10;
	           }
	           while (j > 0)
	               str[i++] = temp[--j];
	       }

	       str[i++] = '.';
	       str[i++] = (frac_part / 10) + '0';
	       str[i++] = (frac_part % 10) + '0';
	       str[i] = '\0';

	       LCD_voidSendString(str);


	   /*for (u8 i = 0; str[i] != '\0'; i++) {
		   UART_voidSendData(str[i]);
	   }*/
_delay_ms(1000);
LCD_voidClearDisplay();

   }
}



