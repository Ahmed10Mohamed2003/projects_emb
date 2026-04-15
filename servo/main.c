#include "MCAL/EXTI/GI_interface.h"
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/TIMER0/TIMER0_interface.h"
#include <util/delay.h>

void Servo_voidSetAngle(u8 Copy_u8Angle); // 0 to 180


long map(long x, long in_min, long in_max, long out_min, long out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
int main(void)
{
    DIO_voidInit();
    ADC_voidInit();

    // Set OC0 (usually PB3) as output
    DIO_u8SetPinDirection(DIO_u8_PORTB, DIO_u8_PIN3, DIO_u8_OUTPUT);

    // Init Timer0 in Fast PWM mode first
    TIMER0_voidInit();

    // Set PWM mode: Non-Inverting
    FASTPWM_voidInvOrNoninv(NON_INV);

    // Set initial OCR0 (duty cycle) to 90 degrees
    TIMER0_voidSetOcrTicks(125); // ~1.5ms pulse

    GI_voidEnable();
   // Servo_voidSetAngle(120);

    while (1)
    {
        volatile u16 value;
        ADC_u16ConvertSynch(1, &value);

        // Map 0–1023 ADC to 0–180 degrees
        u8 angle = (value * 180UL) / 1023;
       Servo_voidSetAngle(angle/*map(value,0,1024,125,250)*/);
        _delay_ms(50);
    }
}

void Servo_voidSetAngle(u8 Copy_u8Angle)
{

    u8 Local_u8OCR =(Copy_u8Angle * (250.0 - 125) / 180.0) + 125;
    TIMER0_voidSetOcrTicks(Local_u8OCR);

}

