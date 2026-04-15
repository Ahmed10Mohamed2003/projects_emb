/*
 * SPI_interface.h
 *
 *  Created on: Sep 4, 2024
 *      Author: yousef.ahmed
 */

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

#define MASTER 0
#define SLAVE 1

void SPI_voidInit(u8 Copy_eMode);

u8 SPI_u8Tranceive(u8 Copy_u8Data);



#endif /* SPI_INTERFACE_H_ */
