################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Library/MCAL/WATCHDOG/subdir.mk
-include Library/MCAL/UART/subdir.mk
-include Library/MCAL/TWI/subdir.mk
-include Library/MCAL/TIMER1/subdir.mk
-include Library/MCAL/TIMER/subdir.mk
-include Library/MCAL/SPI/subdir.mk
-include Library/MCAL/GINT_CON/subdir.mk
-include Library/MCAL/EXIT_INT/subdir.mk
-include Library/MCAL/DIO/subdir.mk
-include Library/MCAL/ADC/subdir.mk
-include Library/LIB/subdir.mk
-include Library/HAL/STEPPER/subdir.mk
-include Library/HAL/SSD/subdir.mk
-include Library/HAL/LCD/subdir.mk
-include Library/HAL/KEYPAD/subdir.mk
-include Library/HAL/EEPROM/subdir.mk
-include Library/HAL/DC/subdir.mk
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
EEPROM_Check_Eclipse_Project.lss \

FLASH_IMAGE += \
EEPROM_Check_Eclipse_Project.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: EEPROM_Check_Eclipse_Project.elf secondary-outputs

# Tool invocations
EEPROM_Check_Eclipse_Project.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,EEPROM_Check_Eclipse_Project.map -mmcu=atmega32 -o "EEPROM_Check_Eclipse_Project.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

EEPROM_Check_Eclipse_Project.lss: EEPROM_Check_Eclipse_Project.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S EEPROM_Check_Eclipse_Project.elf  >"EEPROM_Check_Eclipse_Project.lss"
	@echo 'Finished building: $@'
	@echo ' '

EEPROM_Check_Eclipse_Project.hex: EEPROM_Check_Eclipse_Project.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex EEPROM_Check_Eclipse_Project.elf  "EEPROM_Check_Eclipse_Project.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: EEPROM_Check_Eclipse_Project.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 EEPROM_Check_Eclipse_Project.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) EEPROM_Check_Eclipse_Project.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
