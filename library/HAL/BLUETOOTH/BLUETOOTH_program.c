#include "BLUETOOTH_interface.h"
#include "BLUETOOTH_config.h"
#include "MCAL/UART/UART_interface.h"
#include <util/delay.h>

void Bluetooth_Init(void)
{
    UART_voidInit();
}

void Bluetooth_SendByte(u8 data)
{
    UART_voidSendData(data);
}

void Blutooth_SendString(char* string)
{
    while (*string != '\0')
    {
        UART_voidSendData(*string);
        string++;
        _delay_ms(20); // Optional delay to avoid overloading serial terminal
    }
}

u8 Bluetooth_Receive(void)
{
    return UART_u8Receive();
}
