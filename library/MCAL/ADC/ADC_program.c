#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ADC_interface.h"
#include "ADC_config.h"
#include "ADC_private.h"

static u16 *Global_ptr=NULL;
static void(*GlobalPtrFunc)(void)=NULL;
static u8 ADC_STATE=IDLE;
void ADC_voidInit()
{
	//No interrupt
	CLR_BIT(ADCSRA,3);
	//Ref = AVCC
	SET_BIT(ADMUX,6);
	CLR_BIT(ADMUX,7);
	//PreScaler->64
	CLR_BIT(ADCSRA,0);
	SET_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,2);
	//Enable Circuit
	SET_BIT(ADCSRA,7);
}
u8 ADC_u16ConvertSynch(u8 Copy_u8Channel,u16 *Pu16Reading)
{
	u8 Local_eErrState=OK;
	u16 Local_u16Counter=0;
	//pointer validation
	if(Pu16Reading!=NULL)
	{
		//Write Channel Num -> ADMUX
		ADMUX&=0b11100000;
		ADMUX|=Copy_u8Channel;
		//Enable Conversion
		SET_BIT(ADCSRA,6);
		//Wait -> Flag
		while((!GET_BIT(ADCSRA,4))&&(Local_u16Counter<TIME_OUT))
		{
			Local_u16Counter++;
		}
		if(Local_u16Counter==TIME_OUT)
		{
			Local_eErrState=TIME_OUT_ERR;
		}
		else
		{
			//Clear Flag
			SET_BIT(ADCSRA,4);
			*Pu16Reading=ADC;
		}
	}
	else
	{
		Local_eErrState=NOK;
	}
	return Local_eErrState;
}

u8 ADC_u16ConvertASynch(u8 Copy_u8Channel,
		u16 *Pu16Reading,void(*PtrFunc)(void))
{
	u8 Local_eErrState=OK;
	if(ADC_STATE==IDLE)
	{
		if((Pu16Reading!=NULL)&&(PtrFunc!=NULL))
		{
			ADC_STATE=BUSY;
			Global_ptr=Pu16Reading;
			GlobalPtrFunc=PtrFunc;
			//Write Channel Num -> ADMUX
			ADMUX&=0b11100000;
			ADMUX|=Copy_u8Channel;
			//Enable Conversion
			SET_BIT(ADCSRA,6);
			//Enable ADC interrupt pin
			SET_BIT(ADCSRA,3);
		}
		else
		{
			Local_eErrState=NOK;
		}
	}
	else
	{
		Local_eErrState=BUSY_STATE;
	}
	return Local_eErrState;
}

void __vector_16(void)   __attribute__((signal));
void __vector_16(void)
{
	//Return Reading
	*Global_ptr=ADC;
	//Invoke func
	GlobalPtrFunc();
	//disable int
	CLR_BIT(ADCSRA,3);
	//back to idle
	ADC_STATE=IDLE;
}
