################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include library/MCAL/UART/subdir.mk
-include library/MCAL/TWI/subdir.mk
-include library/MCAL/TIMER1/subdir.mk
-include library/MCAL/TIMER0/subdir.mk
-include library/MCAL/SPI/subdir.mk
-include library/MCAL/EXTI/subdir.mk
-include library/MCAL/DIO/subdir.mk
-include library/MCAL/ADC/subdir.mk
-include library/LIB/subdir.mk
-include library/HAL/SSD/subdir.mk
-include library/HAL/MQ2/subdir.mk
-include library/HAL/LM35/subdir.mk
-include library/HAL/LEDS/subdir.mk
-include library/HAL/LDR/subdir.mk
-include library/HAL/LCD/subdir.mk
-include library/HAL/KPD/subdir.mk
-include library/HAL/FAN/subdir.mk
-include library/HAL/EEPROM/subdir.mk
-include library/HAL/DOOR/subdir.mk
-include library/HAL/DCMOTOR/subdir.mk
-include library/HAL/BUZZER/subdir.mk
-include library/HAL/BLUETOOTH/subdir.mk
-include library/APP/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Ctc.lss \

FLASH_IMAGE += \
Ctc.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Ctc.elf secondary-outputs

# Tool invocations
Ctc.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Ctc.map -mmcu=atmega32 -o "Ctc.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Ctc.lss: Ctc.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Ctc.elf  >"Ctc.lss"
	@echo 'Finished building: $@'
	@echo ' '

Ctc.hex: Ctc.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Ctc.elf  "Ctc.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Ctc.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Ctc.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Ctc.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
