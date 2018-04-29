################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/gpio.c \
../Src/main.c \
../Src/stm32f4xx_hal_msp.c \
../Src/stm32f4xx_it.c 

OBJS += \
./Src/gpio.o \
./Src/main.o \
./Src/stm32f4xx_hal_msp.o \
./Src/stm32f4xx_it.o 

C_DEPS += \
./Src/gpio.d \
./Src/main.d \
./Src/stm32f4xx_hal_msp.d \
./Src/stm32f4xx_it.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo %cd%
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed="__attribute__((__packed__))"' -DUSE_HAL_DRIVER -DSTM32F446xx -I"C:/Users/alexa/OneDrive/Documents/!hardware!/STM32/stm32f446nucleo/helloled/Inc" -I"C:/Users/alexa/OneDrive/Documents/!hardware!/STM32/stm32f446nucleo/helloled/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/alexa/OneDrive/Documents/!hardware!/STM32/stm32f446nucleo/helloled/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"C:/Users/alexa/OneDrive/Documents/!hardware!/STM32/stm32f446nucleo/helloled/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/alexa/OneDrive/Documents/!hardware!/STM32/stm32f446nucleo/helloled/Drivers/CMSIS/Include"  -Os -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


