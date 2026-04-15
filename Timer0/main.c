/*
 * main.c
 *
 *  Created on: 27 Jul 2025
 *      Author: Ahmed Mokhtar
 */
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "HAL/LCD/LCD_interface.h"
#include "MCAL/ADC/ADC_interface.h"
#include "MCAL/EXTI/GI_interface.h"
#include "MCAL/DIO/DIO_interface.h"
#include "HAL/KPD/KPD_interface.h"
#include "MCAL/TIMER0/TIMER0_interface.h"
#include "MCAL/EXTI/EXTI_interface.h"
#include <util/delay.h>


volatile u32 counter=0;
void Start_Count(void);
void Go_Left(void);
void Go_Right(void);
void Decrement_Counter(u8* value01,u8* value02,u8* value03,u8* value04,u8* value05);
void Display_Counter(u8 value01,u8 value02,u8 value03,u8 value04,u8 value05);
void Timer0(void);
u8* value;
u8 value1=0,value2=0,value3=':',value4=0,value5=0;
u8 num=255;

int main()
{
	DIO_voidInit();
	KPD_voidInit();
	LCD_voidInit();
	DIO_u8SetPinDirection(DIO_u8_PORTD,DIO_u8_PIN2,DIO_u8_INPUT);
	DIO_u8SetPinDirection(DIO_u8_PORTD,DIO_u8_PIN3,DIO_u8_INPUT);
	DIO_u8SetPinDirection(DIO_u8_PORTB,DIO_u8_PIN2,DIO_u8_INPUT);
	EXTI_voidEnableDisable(INT0,ENABLED);
	EXTI_voidSetSenseCtrl(INT0,ON_CHANGE);
	EXTI_voidSetCallBack(INT0,Go_Left);
	EXTI_voidEnableDisable(INT1,ENABLED);
	EXTI_voidSetSenseCtrl(INT1,ON_CHANGE);
	EXTI_voidSetCallBack(INT1,Go_Right);
	EXTI_voidEnableDisable(INT2,ENABLED);
	EXTI_voidSetSenseCtrl(INT2,RISING_EDGE);
	EXTI_voidSetCallBack(INT2,Start_Count);
	GI_voidEnable();

	value=&value1;
	Display_Counter(value1,value2,value3,value4,value5);
	while(1)
	{

		while(num==255)
		{
		 num=KPD_u8GetPressedKey();}
		*value=num;
		Display_Counter(value1,value2,value3,value4,value5);
		num=255;
	}

	return 0;
}
void Start_Count(void)
{
	TIMER0_voidInit();
	TIMER0_eSetCallBackNormal(Timer0);
}
void Go_Left(void)
{
   if(value==&value2)
	   value=&value1;
   else if(value==&value4)
	   value=&value2;
   else if(value==&value5)
	   value=&value4;
}
void Go_Right(void)
{
	if(value==&value1)
		value=&value2;
	else if(value==&value2)
		value=&value4;
	else if(value==&value4)
		value=&value5;
}


void Decrement_Counter(u8* value01, u8* value02, u8* value03, u8* value04, u8* value05)
{


    if (*value05 > 0)
    {
        (*value05)--;
        return;
    }

    *value05 = 9;

    if (*value04 > 0)
    {
        (*value04)--;
        return;
    }

    *value04 = 5;

    if (*value02 > 0)
    {
        (*value02)--;
        return;
    }

    *value02 = 9;

    if (*value01 > 0)
    {
        (*value01)--;
        return;
    }

    // All zero — stay at 00:00
    *value01 = 0;
    *value02 = 0;
    *value04 = 0;
    *value05 = 0;
}

void Display_Counter(u8 value01,u8 value02,u8 value03,u8 value04,u8 value05)
{
	        LCD_voidClearDisplay();
	        LCD_voidSetPosition(0,0);
	        LCD_voidSendData(value01+'0');
			LCD_voidSendData(value02+'0');
			LCD_voidSendData(value03);
			LCD_voidSendData(value04+'0');
			LCD_voidSendData(value05+'0');
}
void Timer0(void)
{
	counter++;
	if(counter==488)
	{
		Decrement_Counter(&value1,&value2,&value3,&value4,&value5);
		Display_Counter(value1,value2,value3,value4,value5);
		counter=0;
	}
	if(value1==0&&value2==0&&value4==0&&value5==0)
		{

		LCD_voidClearDisplay();
		LCD_voidSendString("  Finished !!");
	    _delay_ms(750);
	    LCD_voidSendString("  Finished !!");}
}
