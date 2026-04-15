/*
 * delay.c

 *
 *  Created on: 21 Jul 2025
 *      Author: Amr Elomda
 */
#include "delay.h"
void delay_ms(u32 ms)
{
	for(u32 i=0;i<ms;i++)
	{
		for(u32 j=0;j<800;j++)
			asm("NOP");
	}
}

