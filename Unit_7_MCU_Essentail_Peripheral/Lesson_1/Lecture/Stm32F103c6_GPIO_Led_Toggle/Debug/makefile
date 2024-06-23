################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
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
EXECUTABLES += \
Stm32F103c6_GPIO_Led_Toggle.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Stm32F103c6_GPIO_Led_Toggle.list \

OBJCOPY_HEX += \
Stm32F103c6_GPIO_Led_Toggle.hex \

OBJCOPY_BIN += \
Stm32F103c6_GPIO_Led_Toggle.bin \


# All Target
all: Stm32F103c6_GPIO_Led_Toggle.elf secondary-outputs

# Tool invocations
Stm32F103c6_GPIO_Led_Toggle.elf: $(OBJS) $(USER_OBJS) A:\PROJECT\Stm32CubeIDE\Stm32F103c6\STM32F103C6TX_FLASH.ld
	arm-none-eabi-gcc -gdwarf-2 -o "Stm32F103c6_GPIO_Led_Toggle.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"A:\PROJECT\Stm32CubeIDE\Stm32F103c6\STM32F103C6TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="Stm32F103c6_GPIO_Led_Toggle.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Stm32F103c6_GPIO_Led_Toggle.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Stm32F103c6_GPIO_Led_Toggle.list"
	@echo 'Finished building: $@'
	@echo ' '

Stm32F103c6_GPIO_Led_Toggle.hex: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "Stm32F103c6_GPIO_Led_Toggle.hex"
	@echo 'Finished building: $@'
	@echo ' '

Stm32F103c6_GPIO_Led_Toggle.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "Stm32F103c6_GPIO_Led_Toggle.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_HEX) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
