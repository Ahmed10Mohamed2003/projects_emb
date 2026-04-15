/*
 * TIMER0_interface.h
 *
 *  Created on: Jul 28, 2025
 *      Author: Osama Abdelmonem
 */

#ifndef MCAL_TIMER0_TIMER0_INTERFACE_H_
#define MCAL_TIMER0_TIMER0_INTERFACE_H_

#include "Lib/STD_TYPES.h"
#include "Lib/BIT_MATH.h"

#include "TIMER0_private.h"
#include "TIMER0_config.h"

typedef enum
{
	NON_INV = 0,
	INV
}PWM_mode_e;

void TIMER0_voidInit();
void TIMER0_voidSetPreLoadTicks(u8 Copy_u8Ticks);
void TIMER0_voidSetOcrTicks(u8 Copy_u8Ticks);

u8 TIMER0_eSetCallBackNormal(void (*Pfunc)(void));
u8 TIMER0_eSetCallBackCompare(void (*Pfunc)(void));
void FASTPWM_voidInvOrNoninv(PWM_mode_e Copy_Mode);

#endif /* MCAL_TIMER0_TIMER0_INTERFACE_H_ */
