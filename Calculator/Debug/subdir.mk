################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Calculatorprog.c \
../DIO_prog.c \
../KPD_prog.c \
../LCD_prog.c \
../test.c 

OBJS += \
./Calculatorprog.o \
./DIO_prog.o \
./KPD_prog.o \
./LCD_prog.o \
./test.o 

C_DEPS += \
./Calculatorprog.d \
./DIO_prog.d \
./KPD_prog.d \
./LCD_prog.d \
./test.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


