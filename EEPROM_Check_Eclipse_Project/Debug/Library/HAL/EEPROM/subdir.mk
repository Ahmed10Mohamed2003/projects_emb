################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/ALKING/Desktop/Library/HAL/EEPROM/EEPROM_Program.c 

OBJS += \
./Library/HAL/EEPROM/EEPROM_Program.o 

C_DEPS += \
./Library/HAL/EEPROM/EEPROM_Program.d 


# Each subdirectory must supply rules for building sources it contributes
Library/HAL/EEPROM/EEPROM_Program.o: C:/Users/ALKING/Desktop/Library/HAL/EEPROM/EEPROM_Program.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\ALKING\Desktop\Library" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


