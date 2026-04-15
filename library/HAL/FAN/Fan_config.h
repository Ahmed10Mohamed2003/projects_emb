/*
 * Fan_config.h

 *
 *  Created on: Aug 2, 2025
 *      Author: Osama Abdelmonem
 */

#ifndef HAL_FAN_FAN_CONFIG_H_
#define HAL_FAN_FAN_CONFIG_H_

#define DUTY_CYCLE_0      255
#define DUTY_CYCLE_30     178
#define DUTY_CYCLE_50     128
#define DUTY_CYCLE_100    0


typedef enum
{
	SPEED_0 = 0,
	SPEED_1,
	SPEED_2,
	SPEED_3

}_spedd_t;

#endif /* HAL_FAN_FAN_CONFIG_H_ */
