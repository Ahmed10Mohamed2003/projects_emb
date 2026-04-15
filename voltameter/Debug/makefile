################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include library/MCAL/EXTI/subdir.mk
-include library/MCAL/DIO/subdir.mk
-include library/MCAL/ADC/subdir.mk
-include library/LIB/subdir.mk
-include library/HAL/SSD/subdir.mk
-include library/HAL/LCD/subdir.mk
-include library/HAL/KPD/subdir.mk
-include library/HAL/DCMOTOR/subdir.mk
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
voltameter.lss \

SIZEDUMMY += \
sizedummy \


# All Target
all: voltameter.elf secondary-outputs

# Tool invocations
voltameter.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,voltameter.map -mmcu=atmega32 -o "voltameter.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

voltameter.lss: voltameter.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S voltameter.elf  >"voltameter.lss"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: voltameter.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 voltameter.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) voltameter.elf
	-@echo ' '

secondary-outputs: $(LSS) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
