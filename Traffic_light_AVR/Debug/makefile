################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include app/subdir.mk
-include MCAL/DIO/subdir.mk
-include HAL/Switch/subdir.mk
-include HAL/SSD/subdir.mk
-include HAL/LED/subdir.mk
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
Traffic_light_AVR.lss \

FLASH_IMAGE += \
Traffic_light_AVR.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Traffic_light_AVR.elf secondary-outputs

# Tool invocations
Traffic_light_AVR.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Traffic_light_AVR.map -mmcu=atmega32 -o "Traffic_light_AVR.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Traffic_light_AVR.lss: Traffic_light_AVR.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Traffic_light_AVR.elf  >"Traffic_light_AVR.lss"
	@echo 'Finished building: $@'
	@echo ' '

Traffic_light_AVR.hex: Traffic_light_AVR.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Traffic_light_AVR.elf  "Traffic_light_AVR.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Traffic_light_AVR.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Traffic_light_AVR.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Traffic_light_AVR.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
