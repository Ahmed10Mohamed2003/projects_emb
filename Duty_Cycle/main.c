#include "MCAL/EXTI/GI_interface.h"
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/TIMER0/TIMER0_interface.h"
#include <util/delay.h>
#include "MCAL/EXTI/EXTI_interface.h"
#include "MCAL/TIMER1/Timer1_interface.h"
#include "MCAL/TIMER1/Timer1_private.h"
void Servo_voidSetAngle(u8 Copy_u8Angle); // 0 to 180

volatile u8 flag=0;
volatile u16 ONN;
volatile u16 OFF;
volatile u8 str[10];
void EXT_int(void)
{
    if(flag == 0) {
        TCNT1 = 0;
        flag = 1;
        EXTI_voidSetSenseCtrl(INT0, FALLING_EDGE); // next detect falling
    }
    else if(flag == 1) {
        ONN = TCNT1;
        TCNT1 = 0;
        flag = 2;
        EXTI_voidSetSenseCtrl(INT0, RISING_EDGE); // next detect rising
    }
    else if(flag == 2) {
        OFF = TCNT1;
        flag = 3; // measurement complete
    }
}


int main(void)
{
    DIO_voidInit();
    LCD_voidInit();

    // Set OC0 (usually PB3) as output
    DIO_u8SetPinDirection(DIO_u8_PORTB, DIO_u8_PIN3, DIO_u8_OUTPUT);
    DIO_u8SetPinDirection(DIO_u8_PORTD,DIO_u8_PIN2,DIO_u8_INPUT);
    EXTI_voidEnableDisable(INT0,ENABLED);
    EXTI_voidSetSenseCtrl(INT0,RISING_EDGE);
    EXTI_voidSetCallBack(INT0,EXT_int);
    // Init Timer0 in Fast PWM mode first
    TIMER0_voidInit();
    FASTPWM_voidInvOrNoninv(NON_INV);
    TIMER0_voidSetOcrTicks(127);

    TIMER1_voidInit();
    GI_voidEnable();

    while (1)
    {
    	if(flag == 3)
    	{
    	    LCD_voidClearDisplay();
    	    sprintf(str, "ON:%u", ONN);
    	    LCD_voidSendString(str);
    	    _delay_ms(500);

    	    LCD_voidClearDisplay();
    	    sprintf(str, "T:%u", ONN + OFF);
    	    LCD_voidSendString(str);
    	    _delay_ms(500);

    	    flag = 0;
    	}

    }
}



