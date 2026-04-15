################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
F:/iti_AVR/projects_emb/library/APP/APP_program.c 

OBJS += \
./library/APP/APP_program.o 

C_DEPS += \
./library/APP/APP_program.d 


# Each subdirectory must supply rules for building sources it contributes
library/APP/APP_program.o: F:/iti_AVR/projects_emb/library/APP/APP_program.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"F:\iti_AVR\projects_emb\library" -Wall -g2 -gstabs -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


