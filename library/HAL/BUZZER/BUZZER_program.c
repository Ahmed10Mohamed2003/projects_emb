/*
 * BUZZER_program.c

 *
 *  Created on: 2 Aug 2025
 *      Author: Ahmed Mokhtar
 */


#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "MCAL/DIO/DIO_interface.h"
#include"MCAL/DIO/DIO_private.h"
#include <util/delay.h>
#include "MCAL/DIO/DIO_interface.h"
#include "HAL/BUZZER/BUZZER_interface.h"
#include "HAL/BUZZER/BUZZER_config.h"


void Buzzer_Init(void)
{
	DIO_u8SetPinDirection(BUZZER_PORT,BUZZER_PIN,DIO_u8_OUTPUT);
}
void TurnON_Buzzer(void)
{
	DIO_u8SetPinValue(BUZZER_PORT,BUZZER_PIN,DIO_u8_HIGH);
}
void TurnOFF_Buzzer(void)
{
	DIO_u8SetPinValue(BUZZER_PORT,BUZZER_PIN,DIO_u8_LOW);
}
void Set_Alarm_Tone(void)
{
	   /* SET_BIT(BUZZER_PORT,BUZZER_PIN);
		_delay_ms(1000);
		CLEAR_BIT(BUZZER_PORT,BUZZER_PIN);
		_delay_ms(500);

		SET_BIT(BUZZER_PORT,BUZZER_PIN);
		_delay_ms(1000);
		CLEAR_BIT(BUZZER_PORT,BUZZER_PIN);
		_delay_ms(500);

		SET_BIT(BUZZER_PORT,BUZZER_PIN);
		_delay_ms(1000);
		CLEAR_BIT(BUZZER_PORT,BUZZER_PIN);
		_delay_ms(500);*/
}

