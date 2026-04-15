#ifndef TIMER0_PRIVATE_H_
#define TIMER0_PRIVATE_H_

#define NORMAL_MODE     1
#define CTC_MODE        2
#define FAST_PWM        3


#define  DIV_8        2
#define  DIV_64       3

#define TCCR0       *((volatile u8*)0X53)
#define TCNT0       *((volatile u8*)0X52)
/*** Reg to hold the compar match in CTC mode ***/
#define OCR0        *((volatile u8*)0X5C)
#define TIMSK       *((volatile u8*)0X59)


#endif
