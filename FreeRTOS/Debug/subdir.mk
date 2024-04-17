################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO_prog.c \
../croutine.c \
../heap_1.c \
../list.c \
../main.c \
../port.c \
../queue.c \
../tasks.c \
../timers.c 

OBJS += \
./DIO_prog.o \
./croutine.o \
./heap_1.o \
./list.o \
./main.o \
./port.o \
./queue.o \
./tasks.o \
./timers.o 

C_DEPS += \
./DIO_prog.d \
./croutine.d \
./heap_1.d \
./list.d \
./main.d \
./port.d \
./queue.d \
./tasks.d \
./timers.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


