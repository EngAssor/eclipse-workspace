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
-include HAL/LCD/subdir.mk
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
line_slider_EN_and_AR_Uesing_LCD.lss \

FLASH_IMAGE += \
line_slider_EN_and_AR_Uesing_LCD.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: line_slider_EN_and_AR_Uesing_LCD.elf secondary-outputs

# Tool invocations
line_slider_EN_and_AR_Uesing_LCD.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,line_slider_EN_and_AR_Uesing_LCD.map -mmcu=atmega32 -o "line_slider_EN_and_AR_Uesing_LCD.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

line_slider_EN_and_AR_Uesing_LCD.lss: line_slider_EN_and_AR_Uesing_LCD.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S line_slider_EN_and_AR_Uesing_LCD.elf  >"line_slider_EN_and_AR_Uesing_LCD.lss"
	@echo 'Finished building: $@'
	@echo ' '

line_slider_EN_and_AR_Uesing_LCD.hex: line_slider_EN_and_AR_Uesing_LCD.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex line_slider_EN_and_AR_Uesing_LCD.elf  "line_slider_EN_and_AR_Uesing_LCD.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: line_slider_EN_and_AR_Uesing_LCD.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 line_slider_EN_and_AR_Uesing_LCD.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) line_slider_EN_and_AR_Uesing_LCD.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
