################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include HAL/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
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
LSS += \
ATmega32_LCD&Keypad.lss \

FLASH_IMAGE += \
ATmega32_LCD&Keypad.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: ATmega32_LCD&Keypad.elf secondary-outputs

# Tool invocations
ATmega32_LCD&Keypad.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,ATmega32_LCD&Keypad.map -mmcu=atmega32 -o "ATmega32_LCD&Keypad.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

ATmega32_LCD&Keypad.lss: ATmega32_LCD&Keypad.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S ATmega32_LCD&Keypad.elf  >"ATmega32_LCD&Keypad.lss"
	@echo 'Finished building: $@'
	@echo ' '

ATmega32_LCD&Keypad.hex: ATmega32_LCD&Keypad.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex ATmega32_LCD&Keypad.elf  "ATmega32_LCD&Keypad.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: ATmega32_LCD&Keypad.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=berkeley -t ATmega32_LCD&Keypad.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) ATmega32_LCD&Keypad.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
