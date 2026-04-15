/*
 * LM32_interface.h

 *
 *  Created on: 31 Jul 2025
 *      Author: Ahmed Mokhtar
 */

#ifndef HAL_LM35_LM35_INTERFACE_H_
#define HAL_LM35_LM35_INTERFACE_H_
#include "LIB/STD_TYPES.h"

f32 LM35_Read_Tempreture(void);
void floatToString(f32 num, u8 *str, u8 precision);
#endif /* HAL_LM35_LM35_INTERFACE_H_ */
