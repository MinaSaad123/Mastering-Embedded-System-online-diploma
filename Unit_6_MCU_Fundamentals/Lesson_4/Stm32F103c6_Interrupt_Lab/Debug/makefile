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
Stm32F104c6_Interrupt_Lab.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Stm32F104c6_Interrupt_Lab.list \

OBJCOPY_BIN += \
Stm32F104c6_Interrupt_Lab.bin \


# All Target
all: Stm32F104c6_Interrupt_Lab.elf secondary-outputs

# Tool invocations
Stm32F104c6_Interrupt_Lab.elf: $(OBJS) $(USER_OBJS) A:\PROJECT\Stm32CubeIDE\Interrupt_Lab1\STM32F103C6TX_FLASH.ld
	arm-none-eabi-gcc -o "Stm32F104c6_Interrupt_Lab.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"A:\PROJECT\Stm32CubeIDE\Interrupt_Lab1\STM32F103C6TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="Stm32F104c6_Interrupt_Lab.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Stm32F104c6_Interrupt_Lab.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Stm32F104c6_Interrupt_Lab.list"
	@echo 'Finished building: $@'
	@echo ' '

Stm32F104c6_Interrupt_Lab.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "Stm32F104c6_Interrupt_Lab.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
