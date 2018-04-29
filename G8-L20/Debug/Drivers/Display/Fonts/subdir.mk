################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Display/Fonts/font12.c \
../Drivers/Display/Fonts/font16.c \
../Drivers/Display/Fonts/font20.c \
../Drivers/Display/Fonts/font24.c \
../Drivers/Display/Fonts/font8.c 

OBJS += \
./Drivers/Display/Fonts/font12.o \
./Drivers/Display/Fonts/font16.o \
./Drivers/Display/Fonts/font20.o \
./Drivers/Display/Fonts/font24.o \
./Drivers/Display/Fonts/font8.o 

C_DEPS += \
./Drivers/Display/Fonts/font12.d \
./Drivers/Display/Fonts/font16.d \
./Drivers/Display/Fonts/font20.d \
./Drivers/Display/Fonts/font24.d \
./Drivers/Display/Fonts/font8.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Display/Fonts/%.o: ../Drivers/Display/Fonts/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed="__attribute__((__packed__))"' -DUSE_HAL_DRIVER -DSTM32F446xx -I"/home/n0ragam1/workspace/G8-L20/Inc" -I"/home/n0ragam1/workspace/G8-L20/Drivers/Display" -I"/home/n0ragam1/workspace/G8-L20/Drivers/STM32F4xx_HAL_Driver/Inc" -I"/home/n0ragam1/workspace/G8-L20/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"/home/n0ragam1/workspace/G8-L20/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"/home/n0ragam1/workspace/G8-L20/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


