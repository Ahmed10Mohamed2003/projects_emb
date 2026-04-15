#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_


#define ADMUX             *((volatile u8*)0x27)
#define ADCSRA            *((volatile u8*)0x26)
#define ADC               *((volatile u16*)0x24)

#define IDLE    1
#define BUSY    2

#endif
