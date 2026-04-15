/*
 * DCMOTOR_interface.h

 *
 *  Created on: 22 Jul 2025
 *      Author: Amr Elomda
 */
#include"LIB/STD_TYPES.h"
#ifndef HAL_DCMOTOR_DCMOTOR_INTERFACE_H_
#define HAL_DCMOTOR_DCMOTOR_INTERFACE_H_

void DCMOTOR_Toggle(void);
void DCMOTOR_OperateCW(u32 steps);
void DCMOTOR_OperateCCW(u32 steps);


#endif /* HAL_DCMOTOR_DCMOTOR_INTERFACE_H_ */
