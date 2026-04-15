/*
 * SPI_program.c
 *
 *  Created on: Sep 4, 2024
 *      Author: yousef.ahmed
 */
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "MCAL/DIO/DIO_interface.h"
#include "SPI_interface.h"
#include "SPI_config.h"
#include "SPI_private.h"



void SPI_voidInit(u8 Copy_eMode)
{


	SET_BIT(SPCR,5);
	SET_BIT(SPSR,1);
	if(Copy_eMode==MASTER)
		{
		SET_BIT(SPCR,4);
		DIO_u8SetPinDirection(SPI_PORT,SCK,DIO_u8_OUTPUT);
		DIO_u8SetPinDirection(SPI_PORT,MOSI,DIO_u8_OUTPUT);
		DIO_u8SetPinDirection(SPI_PORT,MISO,DIO_u8_INPUT);
		}

	else
	{
		CLR_BIT(SPCR,4);
		DIO_u8SetPinDirection(SPI_PORT,SCK,DIO_u8_INPUT);
		DIO_u8SetPinDirection(SPI_PORT,MOSI,DIO_u8_INPUT);
		DIO_u8SetPinDirection(SPI_PORT,MISO,DIO_u8_OUTPUT);
		DIO_u8SetPinDirection(SPI_PORT,SS,DIO_u8_INPUT);


	}

	SET_BIT(SPCR,6);

}

u8 SPI_u8Tranceive(u8 Copy_u8Data)
{

	SPDR=Copy_u8Data;
	while(!GET_BIT(SPSR,7));

	return SPDR;
}
