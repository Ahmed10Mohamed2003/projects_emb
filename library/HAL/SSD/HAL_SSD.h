/*
 * HAL_SSD.h
 *
 *  Created on: 21 Jul 2025
 *      Author: Amr Elomda
 */

#ifndef HAL_SSD_HAL_SSD_H_
#define HAL_SSD_HAL_SSD_H_

#include "LIB/STD_TYPES.h"
#include "MCAL/DIO/DIO_interface.h"

#define ANODE 0
#define CATHODE 1



void init_ssd(void);

u8 write_ssd(u8 value);

void enable_ssd(u8 Copy_u8PortId, u8 Copy_u8PinId,u8 AN_CATH);

void disable_ssd(u8 Copy_u8PortId, u8 Copy_u8PinId,u8 AN_CATH);



#endif /* HAL_SSD_HAL_SSD_H_ */
