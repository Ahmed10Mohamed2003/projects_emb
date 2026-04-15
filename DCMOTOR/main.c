#include <HAL/DCMOTOR/DCMOTOR_interface.h>
#include "MCAL/DIO/DIO_interface.h"
#include "HAL/FAN/Fan_interface.h"
#include "util/delay.h"
#include "HAL/BUZZER/BUZZER_interface.h"
int main()
{

	 DIO_voidInit ();
	 //DCMOTOR_u8Init();
	 Fan_voidInit();
	 //Buzzer_Init();

while(1)
{
	//Fan_u8StopFan();
	Fan_u8ControlDCmotorSpeed(0);
	_delay_ms(5000);
	Fan_u8StopFan();
	_delay_ms(2000);
	Fan_u8ControlDCmotorSpeed(1);
	_delay_ms(5000);
	Fan_u8StopFan();
	_delay_ms(2000);
	Fan_u8ControlDCmotorSpeed(2);
	_delay_ms(5000);
	Fan_u8StopFan();
	_delay_ms(2000);
	Fan_u8ControlDCmotorSpeed(3);
	_delay_ms(5000);
	Fan_u8StopFan();
	_delay_ms(2000);
	//TurnON_Buzzer();



}

	return 0;
}
