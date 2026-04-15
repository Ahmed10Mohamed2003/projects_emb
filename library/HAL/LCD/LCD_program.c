#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"

#include "MCAL/DIO/DIO_interface.h"
#include <util/delay.h>

#include "HAL/LCD/LCD_config.h"
#include "HAL/LCD/LCD_interface.h"
#include "HAL/LCD/LCD_private.h"

static void LCD_voidSendCommand(u8 Copy_u8Command)
{
    // Send higher nibble
    DIO_u8SetPinValue(CTRL_PORT, RS, DIO_u8_LOW);
    DIO_u8SetPinValue(CTRL_PORT, RW, DIO_u8_LOW);

    DIO_u8SetPinValue(DATA_PORT, DIO_u8_PIN4, GET_BIT(Copy_u8Command, 4));
    DIO_u8SetPinValue(DATA_PORT, DIO_u8_PIN5, GET_BIT(Copy_u8Command, 5));
    DIO_u8SetPinValue(DATA_PORT, DIO_u8_PIN6, GET_BIT(Copy_u8Command, 6));
    DIO_u8SetPinValue(DATA_PORT, DIO_u8_PIN7, GET_BIT(Copy_u8Command, 7));

    DIO_u8SetPinValue(CTRL_PORT, EN, DIO_u8_HIGH);
    _delay_ms(1);
    DIO_u8SetPinValue(CTRL_PORT, EN, DIO_u8_LOW);
    _delay_ms(1);

    // Send lower nibble
    DIO_u8SetPinValue(DATA_PORT, DIO_u8_PIN4, GET_BIT(Copy_u8Command, 0));
    DIO_u8SetPinValue(DATA_PORT, DIO_u8_PIN5, GET_BIT(Copy_u8Command, 1));
    DIO_u8SetPinValue(DATA_PORT, DIO_u8_PIN6, GET_BIT(Copy_u8Command, 2));
    DIO_u8SetPinValue(DATA_PORT, DIO_u8_PIN7, GET_BIT(Copy_u8Command, 3));

    DIO_u8SetPinValue(CTRL_PORT, EN, DIO_u8_HIGH);
    _delay_ms(1);
    DIO_u8SetPinValue(CTRL_PORT, EN, DIO_u8_LOW);
    _delay_ms(2);
}

void LCD_voidSendData(u8 Copy_u8Data)
{
    // Send higher nibble
    DIO_u8SetPinValue(CTRL_PORT, RS, DIO_u8_HIGH);
    DIO_u8SetPinValue(CTRL_PORT, RW, DIO_u8_LOW);

    DIO_u8SetPinValue(DATA_PORT, DIO_u8_PIN4, GET_BIT(Copy_u8Data, 4));
    DIO_u8SetPinValue(DATA_PORT, DIO_u8_PIN5, GET_BIT(Copy_u8Data, 5));
    DIO_u8SetPinValue(DATA_PORT, DIO_u8_PIN6, GET_BIT(Copy_u8Data, 6));
    DIO_u8SetPinValue(DATA_PORT, DIO_u8_PIN7, GET_BIT(Copy_u8Data, 7));

    DIO_u8SetPinValue(CTRL_PORT, EN, DIO_u8_HIGH);
    _delay_ms(1);
    DIO_u8SetPinValue(CTRL_PORT, EN, DIO_u8_LOW);
    _delay_ms(1);

    // Send lower nibble
    DIO_u8SetPinValue(DATA_PORT, DIO_u8_PIN4, GET_BIT(Copy_u8Data, 0));
    DIO_u8SetPinValue(DATA_PORT, DIO_u8_PIN5, GET_BIT(Copy_u8Data, 1));
    DIO_u8SetPinValue(DATA_PORT, DIO_u8_PIN6, GET_BIT(Copy_u8Data, 2));
    DIO_u8SetPinValue(DATA_PORT, DIO_u8_PIN7, GET_BIT(Copy_u8Data, 3));

    DIO_u8SetPinValue(CTRL_PORT, EN, DIO_u8_HIGH);
    _delay_ms(1);
    DIO_u8SetPinValue(CTRL_PORT, EN, DIO_u8_LOW);
    _delay_ms(2);
}

void LCD_voidInit(void)
{
    _delay_ms(40);

    LCD_voidSendCommand(0x33); // Init sequence for 4-bit
    LCD_voidSendCommand(0x32);
    LCD_voidSendCommand(0x28); // Function set: 4-bit, 2 lines, 5x8 dots
    LCD_voidSendCommand(0x0C); // Display on, cursor off
    LCD_voidSendCommand(0x01); // Clear display
    _delay_ms(2);
    LCD_voidSendCommand(0x06); // Entry mode
}

void LCD_voidClearDisplay(void)
{
    LCD_voidSendCommand(0x01);
    _delay_ms(2);
}

void LCD_voidSendString(char *PcCopy_String)
{
    while (*PcCopy_String != '\0')
    {
        LCD_voidSendData(*PcCopy_String);
        PcCopy_String++;
    }
}

void LCD_voidSetPosition(u8 Copy_u8X, u8 Copy_u8Y)
{
    u8 Address;

    if (Copy_u8X == 0)
    {
        Address = 0x00 + Copy_u8Y;
    }
    else if (Copy_u8X == 1)
    {
        Address = 0x40 + Copy_u8Y;
    }

    LCD_voidSendCommand(Address + 0x80);
}

void LCD_voidSendSpecialCharecter(u8 Copy_u8BlockNum, u8 *Pu8ArrayPattern, u8 Copy_u8X, u8 Copy_u8Y)
{
    u8 Local_u8CGRAMAddress = Copy_u8BlockNum * 8;

    LCD_voidSendCommand(Local_u8CGRAMAddress + 64); // Set CGRAM address

    for (u8 i = 0; i < 8; i++)
    {
        LCD_voidSendData(Pu8ArrayPattern[i]);
    }

    LCD_voidSetPosition(Copy_u8X, Copy_u8Y);
    LCD_voidSendData(Copy_u8BlockNum);
}
