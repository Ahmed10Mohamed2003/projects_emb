#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "MCAL/DIO/DIO_interface.h"
#include "HAL/KPD/KPD_interface.h"
#include "HAL/KPD/KPD_config.h"
#include "HAL/KPD/KPD_private.h"
#include"MCAL/DIO/DIO_private.h"
#include <util/delay.h>

void KPD_voidInit()
{
	//COLUMSNS OUTPUT HIGH
	DIO_u8SetPinDirection(KPD_PORT,C0,DIO_u8_OUTPUT);
	DIO_u8SetPinDirection(KPD_PORT,C1,DIO_u8_OUTPUT);
	DIO_u8SetPinDirection(KPD_PORT,C2,DIO_u8_OUTPUT);

	DIO_u8SetPinValue(KPD_PORT,C0,DIO_u8_HIGH);
	DIO_u8SetPinValue(KPD_PORT,C1,DIO_u8_HIGH);
	DIO_u8SetPinValue(KPD_PORT,C2,DIO_u8_HIGH);

	//Rows input pulled up
	DIO_u8SetPinDirection(KPD_PORT,R0,DIO_u8_INPUT);
	DIO_u8SetPinDirection(KPD_PORT,R1,DIO_u8_INPUT);
	DIO_u8SetPinDirection(KPD_PORT,R2,DIO_u8_INPUT);
	DIO_u8SetPinDirection(KPD_PORT,R3,DIO_u8_INPUT);

	DIO_u8SetPinValue(KPD_PORT,R0,DIO_u8_HIGH);
	DIO_u8SetPinValue(KPD_PORT,R1,DIO_u8_HIGH);
	DIO_u8SetPinValue(KPD_PORT,R2,DIO_u8_HIGH);
	DIO_u8SetPinValue(KPD_PORT,R3,DIO_u8_HIGH);

}

u8 KPD_u8GetPressedKey()
{
	u8 Local_u8Button=NO_PRESSED_KEY;
	static u8 KPD_ARR[MAX_ROW_NUM][MAX_COL_NUM]=KPD_VALUES;
	u8 Local_u8PinState;
	static u8 Local_u8ColArr[MAX_COL_NUM]={C0,C1,C2};
	static u8 Local_u8RowArr[MAX_ROW_NUM]={R0,R1,R2,R3};
	//OUTER for loop to columns
	for(u8 Local_u8ColIter=0;Local_u8ColIter<MAX_COL_NUM;Local_u8ColIter++)
	{
		//Activate col
		DIO_u8SetPinValue(KPD_PORT,Local_u8ColArr[Local_u8ColIter],DIO_u8_LOW);
		for(u8 Local_u8RowIter=0;Local_u8RowIter<MAX_ROW_NUM;Local_u8RowIter++)
		{
			DIO_u8GetPinValue(KPD_PORT,Local_u8RowArr[Local_u8RowIter],&Local_u8PinState);
			if(Local_u8PinState==DIO_u8_LOW)
			{
				DIO_u8GetPinValue(KPD_PORT,Local_u8RowArr[Local_u8RowIter],&Local_u8PinState);
				_delay_ms(20);
				if(Local_u8PinState==DIO_u8_LOW)
				{
					Local_u8Button=KPD_ARR[Local_u8RowIter][Local_u8ColIter];
					//Polling
					while(Local_u8PinState==DIO_u8_LOW)
					{
						DIO_u8GetPinValue(KPD_PORT,Local_u8RowArr[Local_u8RowIter],&Local_u8PinState);
					}
				}
			}

		}

		//Deactivate col
		DIO_u8SetPinValue(KPD_PORT,Local_u8ColArr[Local_u8ColIter],DIO_u8_HIGH);
	}
	return Local_u8Button;
}
