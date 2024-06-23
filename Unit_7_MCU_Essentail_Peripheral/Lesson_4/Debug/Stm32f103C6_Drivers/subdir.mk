################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Stm32f103C6_Drivers/Stm32f103c6_EXTI_Driver.c \
../Stm32f103C6_Drivers/Stm32f103c6_GPIO_Driver.c 

OBJS += \
./Stm32f103C6_Drivers/Stm32f103c6_EXTI_Driver.o \
./Stm32f103C6_Drivers/Stm32f103c6_GPIO_Driver.o 

C_DEPS += \
./Stm32f103C6_Drivers/Stm32f103c6_EXTI_Driver.d \
./Stm32f103C6_Drivers/Stm32f103c6_GPIO_Driver.d 


# Each subdirectory must supply rules for building sources it contributes
Stm32f103C6_Drivers/Stm32f103c6_EXTI_Driver.o: ../Stm32f103C6_Drivers/Stm32f103c6_EXTI_Driver.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/HP/STM32CubeIDE/workspace_1.4.0/Lesson_4/Stm32f103C6_Drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Stm32f103C6_Drivers/Stm32f103c6_EXTI_Driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Stm32f103C6_Drivers/Stm32f103c6_GPIO_Driver.o: ../Stm32f103C6_Drivers/Stm32f103c6_GPIO_Driver.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/HP/STM32CubeIDE/workspace_1.4.0/Lesson_4/Stm32f103C6_Drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Stm32f103C6_Drivers/Stm32f103c6_GPIO_Driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

