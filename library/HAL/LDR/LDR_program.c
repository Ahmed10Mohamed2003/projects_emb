#include "Lib/STD_TYPES.h"
#include "Lib/BIT_MATH.h"

#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/ADC/ADC_interface.h"

#include "HAL/LDR/LDR_interface.h"
#include "HAL/LDR/LDR_config.h"

void LDR_voidInit(void)
{
    // LED as output
	//DIO_u8SetPinDirection(LDR_LED_PORT, LDR_LED_PIN, DIO_u8_OUTPUT);

    // ADC already initialized outside, just make sure channel exists
}

void LDR_voidUpdate(void)
{
	ADC_voidInit();
    u16 lightLevel = 0;

    // Read from ADC synchronously
    ADC_u16ConvertSynch(LDR_ADC_CHANNEL, &lightLevel);

    if (lightLevel > LDR_LIGHT_THRESHOLD)
    {
        // Too much light LED OFF
    	DIO_u8SetPinValue(LDR_LED_PORT, LDR_LED_PIN, DIO_u8_HIGH);
    }
    else
    {
        // Low light LED ON
    	DIO_u8SetPinValue(LDR_LED_PORT, LDR_LED_PIN, DIO_u8_LOW);
    }
}
