################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
F:/iti_AVR/projects_emb/library/HAL/LEDS/LEDS_program.c 

OBJS += \
./library/HAL/LEDS/LEDS_program.o 

C_DEPS += \
./library/HAL/LEDS/LEDS_program.d 


# Each subdirectory must supply rules for building sources it contributes
library/HAL/LEDS/LEDS_program.o: F:/iti_AVR/projects_emb/library/HAL/LEDS/LEDS_program.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"F:\iti_AVR\projects_emb\library" -Wall -g2 -gstabs -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


