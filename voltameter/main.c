#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "HAL/LCD/LCD_interface.h"
#include "MCAL/ADC/ADC_interface.h"
#include "MCAL/EXTI/GI_interface.h"
#include <util/delay.h>

void LCD_voidDisplayFloat(f32 num)
{
    char str[10];
    u8 i = 0;

    if (num < 0)
    {
        str[i++] = '-';
        num = -num;
    }
    else
    {
        str[i++] = '+';
    }

    u16 int_part = (u16)num;
    u16 frac_part = (u16)((num - int_part) * 100 + 0.5);  // rounded

    // Integer to string
    if (int_part == 0)
        str[i++] = '0';
    else
    {
        char temp[5];
        u8 j = 0;
        while (int_part > 0)
        {
            temp[j++] = (int_part % 10) + '0';
            int_part /= 10;
        }
        while (j > 0)
            str[i++] = temp[--j];
    }

    str[i++] = '.';
    str[i++] = (frac_part / 10) + '0';
    str[i++] = (frac_part % 10) + '0';
    str[i] = '\0';

    LCD_voidSendString(str);
}

int main()
{
	DIO_voidInit();
	LCD_voidInit();
	ADC_voidInit();
	GI_voidEnable();

	u16 reading_ch0 = 0;
	u16 reading_ch1 = 0;
	s32 diff_adc = 0;
	f32 voltage = 0.0;

	while (1)
	{
		ADC_u16ConvertSynch(0b00000, &reading_ch0);
		ADC_u16ConvertSynch(0b00001, &reading_ch1);

		diff_adc = (s32)reading_ch0 - (s32)reading_ch1;

		// Convert to voltage (make sure to multiply by 5.0f to avoid integer division)
		voltage = ((f32)diff_adc * 5.0f) / 1024.0f;

		LCD_voidClearDisplay();
		LCD_voidSendString("Voltage:");
		//LCD_voidGoToXY(1, 0);
		LCD_voidDisplayFloat(voltage*10);
		LCD_voidSendString(" V");

		_delay_ms(500);
	}

	return 0;
}
