#ifndef DOOR_INTERFACE_H
#define DOOR_INTERFACE_H


void TIMER1_voidSetCompareValue(u16 Copy_u16Value);
void Servo_voidSetAngle(u8 Copy_u8Angle);
void Open_voidDoor();
void Close_voidDoor();
void Func(void);

void Door_voidinit();

#endif
