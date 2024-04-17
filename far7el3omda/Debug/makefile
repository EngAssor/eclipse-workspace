################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
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
far7el3omda.lss \

FLASH_IMAGE += \
far7el3omda.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: far7el3omda.elf secondary-outputs

# Tool invocations
far7el3omda.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,far7el3omda.map -mmcu=atmega32 -o "far7el3omda.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

far7el3omda.lss: far7el3omda.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S far7el3omda.elf  >"far7el3omda.lss"
	@echo 'Finished building: $@'
	@echo ' '

far7el3omda.hex: far7el3omda.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex far7el3omda.elf  "far7el3omda.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: far7el3omda.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 far7el3omda.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) far7el3omda.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
