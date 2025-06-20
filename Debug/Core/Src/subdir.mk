################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/i2c_lcd.c \
../Core/Src/main.c \
../Core/Src/mq2_sensor.c \
../Core/Src/relay.c \
../Core/Src/rgb_led.c \
../Core/Src/servo.c \
../Core/Src/stm32f4xx_hal_msp.c \
../Core/Src/stm32f4xx_it.c \
../Core/Src/switch.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_config.c \
../Core/Src/system_stm32f4xx.c \
../Core/Src/uart.c 

OBJS += \
./Core/Src/i2c_lcd.o \
./Core/Src/main.o \
./Core/Src/mq2_sensor.o \
./Core/Src/relay.o \
./Core/Src/rgb_led.o \
./Core/Src/servo.o \
./Core/Src/stm32f4xx_hal_msp.o \
./Core/Src/stm32f4xx_it.o \
./Core/Src/switch.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_config.o \
./Core/Src/system_stm32f4xx.o \
./Core/Src/uart.o 

C_DEPS += \
./Core/Src/i2c_lcd.d \
./Core/Src/main.d \
./Core/Src/mq2_sensor.d \
./Core/Src/relay.d \
./Core/Src/rgb_led.d \
./Core/Src/servo.d \
./Core/Src/stm32f4xx_hal_msp.d \
./Core/Src/stm32f4xx_it.d \
./Core/Src/switch.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_config.d \
./Core/Src/system_stm32f4xx.d \
./Core/Src/uart.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/i2c_lcd.cyclo ./Core/Src/i2c_lcd.d ./Core/Src/i2c_lcd.o ./Core/Src/i2c_lcd.su ./Core/Src/main.cyclo ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/mq2_sensor.cyclo ./Core/Src/mq2_sensor.d ./Core/Src/mq2_sensor.o ./Core/Src/mq2_sensor.su ./Core/Src/relay.cyclo ./Core/Src/relay.d ./Core/Src/relay.o ./Core/Src/relay.su ./Core/Src/rgb_led.cyclo ./Core/Src/rgb_led.d ./Core/Src/rgb_led.o ./Core/Src/rgb_led.su ./Core/Src/servo.cyclo ./Core/Src/servo.d ./Core/Src/servo.o ./Core/Src/servo.su ./Core/Src/stm32f4xx_hal_msp.cyclo ./Core/Src/stm32f4xx_hal_msp.d ./Core/Src/stm32f4xx_hal_msp.o ./Core/Src/stm32f4xx_hal_msp.su ./Core/Src/stm32f4xx_it.cyclo ./Core/Src/stm32f4xx_it.d ./Core/Src/stm32f4xx_it.o ./Core/Src/stm32f4xx_it.su ./Core/Src/switch.cyclo ./Core/Src/switch.d ./Core/Src/switch.o ./Core/Src/switch.su ./Core/Src/syscalls.cyclo ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.cyclo ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_config.cyclo ./Core/Src/system_config.d ./Core/Src/system_config.o ./Core/Src/system_config.su ./Core/Src/system_stm32f4xx.cyclo ./Core/Src/system_stm32f4xx.d ./Core/Src/system_stm32f4xx.o ./Core/Src/system_stm32f4xx.su ./Core/Src/uart.cyclo ./Core/Src/uart.d ./Core/Src/uart.o ./Core/Src/uart.su

.PHONY: clean-Core-2f-Src

