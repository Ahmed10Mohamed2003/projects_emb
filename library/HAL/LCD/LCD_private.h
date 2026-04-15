#ifndef CLCD_PRIVATE_H_
#define CLCD_PRIVATE_H_
#include"LIB/STD_TYPES.h"


#define LINE1_BASE         0X40
#define DDRAM_MSB          0x80
#define CGRAM_MSB           64

//static void LCD_voidSendData(u8 Copy_u8Data);
static void LCD_voidSendCommand(u8 Copy_u8Command);



#endif
