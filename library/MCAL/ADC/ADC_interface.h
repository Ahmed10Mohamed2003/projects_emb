#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_


void ADC_voidInit();

u8 ADC_u16ConvertSynch(u8 Copy_u8Channel,
		u16 *Pu16Reading);

u8 ADC_u16ConvertASynch(u8 Copy_u8Channel,
		u16 *Pu16Reading,void(*PtrFunc)(void));



#endif
