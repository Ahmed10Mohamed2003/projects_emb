#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H_


#include"LIB/STD_TYPES.h"

void LCD_voidInit(void);
void LCD_voidSendData(u8 Copy_u8Data);
void LCD_voidSendString(char *PcCopy_String);
void LCD_voidSetPosition(u8 Copy_u8X,u8 Copy_u8Y);
void LCD_voidClearDisplay(void);
void LCD_voidSendSpecialCharecter(u8 Copy_u8BlockNum,u8 *Pu8ArrayPattern,
		u8 Copy_u8X,
		u8 Copy_u8Y);



#endif
