################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Stm32f103C6_Drivers/Stm32f103c6_EXTI_Driver.c \
../Stm32f103C6_Drivers/Stm32f103c6_GPIO_Driver.c \
../Stm32f103C6_Drivers/Stm32f103c6_I2C_Driver.c \
../Stm32f103C6_Drivers/Stm32f103c6_RCC_Driver.c \
../Stm32f103C6_Drivers/Stm32f103c6_SPI_Driver.c \
../Stm32f103C6_Drivers/Stm32f103c6_Uart_Driver.c 

OBJS += \
./Stm32f103C6_Drivers/Stm32f103c6_EXTI_Driver.o \
./Stm32f103C6_Drivers/Stm32f103c6_GPIO_Driver.o \
./Stm32f103C6_Drivers/Stm32f103c6_I2C_Driver.o \
./Stm32f103C6_Drivers/Stm32f103c6_RCC_Driver.o \
./Stm32f103C6_Drivers/Stm32f103c6_SPI_Driver.o \
./Stm32f103C6_Drivers/Stm32f103c6_Uart_Driver.o 

C_DEPS += \
./Stm32f103C6_Drivers/Stm32f103c6_EXTI_Driver.d \
./Stm32f103C6_Drivers/Stm32f103c6_GPIO_Driver.d \
./Stm32f103C6_Drivers/Stm32f103c6_I2C_Driver.d \
./Stm32f103C6_Drivers/Stm32f103c6_RCC_Driver.d \
./Stm32f103C6_Drivers/Stm32f103c6_SPI_Driver.d \
./Stm32f103C6_Drivers/Stm32f103c6_Uart_Driver.d 


# Each subdirectory must supply rules for building sources it contributes
Stm32f103C6_Drivers/Stm32f103c6_EXTI_Driver.o: ../Stm32f103C6_Drivers/Stm32f103c6_EXTI_Driver.c
	arm-none-eabi-gcc  -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"A:/Projects/Stm32CubeIDE/BlueBill_Drivers/Stm32f103C6_Drivers/Inc" -I"A:/Projects/Stm32CubeIDE/BlueBill_Drivers/HAL/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Stm32f103C6_Drivers/Stm32f103c6_EXTI_Driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Stm32f103C6_Drivers/Stm32f103c6_GPIO_Driver.o: ../Stm32f103C6_Drivers/Stm32f103c6_GPIO_Driver.c
	arm-none-eabi-gcc  -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"A:/Projects/Stm32CubeIDE/BlueBill_Drivers/Stm32f103C6_Drivers/Inc" -I"A:/Projects/Stm32CubeIDE/BlueBill_Drivers/HAL/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Stm32f103C6_Drivers/Stm32f103c6_GPIO_Driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Stm32f103C6_Drivers/Stm32f103c6_I2C_Driver.o: ../Stm32f103C6_Drivers/Stm32f103c6_I2C_Driver.c
	arm-none-eabi-gcc  -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"A:/Projects/Stm32CubeIDE/BlueBill_Drivers/Stm32f103C6_Drivers/Inc" -I"A:/Projects/Stm32CubeIDE/BlueBill_Drivers/HAL/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Stm32f103C6_Drivers/Stm32f103c6_I2C_Driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Stm32f103C6_Drivers/Stm32f103c6_RCC_Driver.o: ../Stm32f103C6_Drivers/Stm32f103c6_RCC_Driver.c
	arm-none-eabi-gcc  -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"A:/Projects/Stm32CubeIDE/BlueBill_Drivers/Stm32f103C6_Drivers/Inc" -I"A:/Projects/Stm32CubeIDE/BlueBill_Drivers/HAL/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Stm32f103C6_Drivers/Stm32f103c6_RCC_Driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Stm32f103C6_Drivers/Stm32f103c6_SPI_Driver.o: ../Stm32f103C6_Drivers/Stm32f103c6_SPI_Driver.c
	arm-none-eabi-gcc  -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"A:/Projects/Stm32CubeIDE/BlueBill_Drivers/Stm32f103C6_Drivers/Inc" -I"A:/Projects/Stm32CubeIDE/BlueBill_Drivers/HAL/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Stm32f103C6_Drivers/Stm32f103c6_SPI_Driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Stm32f103C6_Drivers/Stm32f103c6_Uart_Driver.o: ../Stm32f103C6_Drivers/Stm32f103c6_Uart_Driver.c
	arm-none-eabi-gcc  -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"A:/Projects/Stm32CubeIDE/BlueBill_Drivers/Stm32f103C6_Drivers/Inc" -I"A:/Projects/Stm32CubeIDE/BlueBill_Drivers/HAL/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Stm32f103C6_Drivers/Stm32f103c6_Uart_Driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

