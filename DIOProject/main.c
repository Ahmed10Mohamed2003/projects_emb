#include "LIB/STD_TYPES.h"
#include "HAL/SSD/HAL_SSD.h"
#include "HAL/LCD/LCD_interface.h"
#include "HAL/KPD/KPD_interface.h"
#include "HAL/DCMOTOR/DCMOTOR_interface.h"
#include <util/delay.h>

int main()
{

	DIO_voidInit();
	KPD_voidInit();
	LCD_voidInit();



while(1)
{
		u8 value=255,value1=255,value2=255,value3=255;
		LCD_voidSendString("1DCmo2Stepper");

		while(value==255)
			{value=KPD_u8GetPressedKey();}
		LCD_voidClearDisplay();
		_delay_ms(50);
		LCD_voidSendData(value+'0');
		if(value==1)
		{
			//DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN0,DIO_u8_HIGH);//DC motor on
		}
		else if(value==2)
		{
			LCD_voidSendString("Enter steps      ");
			while(value1==255)
						{ value1=KPD_u8GetPressedKey();}
			LCD_voidSendData(value1+'0');
			while(value2==255)
						{ value2=KPD_u8GetPressedKey();}
			LCD_voidSendData(value2+'0');
			while(value3==255)
						{ value3=KPD_u8GetPressedKey();}
			LCD_voidSendData(value3+'0');
			u32 val=(value1*100+value2*10+value3);

			_delay_ms(100);
			LCD_voidClearDisplay();
			_delay_ms(50);
			LCD_voidSendString("Enterdir");

			u8 dir=255;
			while(dir==255)
			{
			dir=KPD_u8GetPressedKey();}
			LCD_voidSendData(dir+'0');

			if(dir==1)
			DCMOTOR_OperateCW(val);
			else
			DCMOTOR_OperateCCW(val);


	    }
		else
		{
			LCD_voidSendString("wrong entry!");
		}

		_delay_ms(2000);
		LCD_voidClearDisplay();
}

	return 0;
}
