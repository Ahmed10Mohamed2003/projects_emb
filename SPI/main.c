#include <HAL/LM35/LM35_interface.h>
#include "MCAL/EXTI/GI_interface.h"
#include "LIB/STD_TYPES.h"
#include <stdio.h>
#include "LIB/BIT_MATH.h"
#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/TIMER0/TIMER0_interface.h"
#include <util/delay.h>
#include "MCAL/EXTI/EXTI_interface.h"
#include "MCAL/UART/UART_interface.h"
#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/SPI/SPI_interface.h"


int main(void)
{

   DIO_voidInit();
   SPI_voidInit(MASTER);
   UART_voidInit();
   while(1)
   {
	   u8 Data=UART_u8Receive();
	   UART_voidSendData(Data);
	   SPI_u8Tranceive(Data);

   }
}



