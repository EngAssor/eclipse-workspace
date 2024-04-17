################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include DIO/subdir.mk
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
Seven_Segment_AVR.lss \

FLASH_IMAGE += \
Seven_Segment_AVR.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Seven_Segment_AVR.elf secondary-outputs

# Tool invocations
Seven_Segment_AVR.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Seven_Segment_AVR.map -mmcu=atmega32 -o "Seven_Segment_AVR.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Seven_Segment_AVR.lss: Seven_Segment_AVR.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Seven_Segment_AVR.elf  >"Seven_Segment_AVR.lss"
	@echo 'Finished building: $@'
	@echo ' '

Seven_Segment_AVR.hex: Seven_Segment_AVR.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Seven_Segment_AVR.elf  "Seven_Segment_AVR.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Seven_Segment_AVR.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Seven_Segment_AVR.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Seven_Segment_AVR.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
