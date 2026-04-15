/*
 * APP_interface.h
 *
 *  Created on: 5 Aug 2025
 *      Author: Amr Elomda
 */

#ifndef APP_APP_INTERFACE_H_
#define APP_APP_INTERFACE_H_
/*****************************Includes section********************************************************/
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "HAL/EEPROM/EEPROM_Interface.h"
#include "HAL/DOOR/DOOR_interface.h"
#include "HAL/BLUETOOTH/BLUETOOTH_interface.h"
#include "HAL/BUZZER/BUZZER_interface.h"
#include "HAL/FAN/Fan_interface.h"
#include "HAL/KPD/KPD_interface.h"
#include "HAL/LCD/LCD_interface.h"
#include "HAL/LEDS/LEDS_interface.h"
#include "HAL/LM35/LM35_interface.h"
#include "HAL/MQ2/MQ2_interface.h"
#include "HAL/LDR/LDR_interface.h"


void APP_voidInit(void);
u8 APP_voidLogin(void);

#endif /* APP_APP_INTERFACE_H_ */
