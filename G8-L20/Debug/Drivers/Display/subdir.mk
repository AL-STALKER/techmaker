################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Display/lcd.c 

OBJS += \
./Drivers/Display/lcd.o 

C_DEPS += \
./Drivers/Display/lcd.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Display/%.o: ../Drivers/Display/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed="__attribute__((__packed__))"' -DUSE_HAL_DRIVER -DSTM32F446xx -I"/home/n0ragam1/workspace/G8-L20/Inc" -I"/home/n0ragam1/workspace/G8-L20/Drivers/Display" -I"/home/n0ragam1/workspace/G8-L20/Drivers/STM32F4xx_HAL_Driver/Inc" -I"/home/n0ragam1/workspace/G8-L20/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"/home/n0ragam1/workspace/G8-L20/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"/home/n0ragam1/workspace/G8-L20/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


