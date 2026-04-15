#ifndef BLUETOOTH_INTERFACE_H_
#define BLUETOOTH_INTERFACE_H_

#include "LIB/STD_TYPES.h"

void Bluetooth_Init(void);
void Bluetooth_SendByte(u8 data);
void Blutooth_SendString(char* string);
u8 Bluetooth_Receive(void);

#endif
