## look at pretty trick in 36
LIBS=-I .
cpu=-mcpu=cortex-m3 -mthumb
debug=-gdwarf-2
TOTAL_C=$(wildcard *.c)
OBJ=$(TOTAL_C:.c=.o)
TOTAL_S=$(wildcard *.s)
SOBJ=$(TOTAL_S:.s=.o)
OUT=led_toggle

#make all
all: $(OUT).bin
#########################################################################

#get .o from .s
%.o: %.s
	arm-none-eabi-as.exe $(debug) $(cpu) $< -o $@
#########################################################################

#get .o from .c
%.o: %.c
	arm-none-eabi-gcc.exe -c $(LIBS) $(debug) $(cpu) $< -o $@
#########################################################################

#get .bin
$(OUT).bin: $(OUT).elf
	arm-none-eabi-objcopy.exe -O binary $< $@
#########################################################################

#get .elf
$(OUT).elf: $(OBJ) $(SOBJ)
	arm-none-eabi-ld.exe -T linkerscript.ld $(OBJ) $(SOBJ) -o $@ -Map=$(OUT).map
#########################################################################

##.....................................   ##
##    passing variable name in terminal   ##
##.....................................   ##


#get symbols and details
show: $(name).o
	arm-none-eabi-objdump.exe -h $<

show: $(name).o
	arm-none-eabi-objdump.exe -D $<

symbols: $(name).o
	arm-none-eabi-nm.exe  $<
#########################################################################

#read .elf
readelf: $(OUT).elf
	arm-none-eabi-readelf.exe -a  $<
#########################################################################

#clean all
clean_all:
	rm *.o *.elf
#########################################################################

#particular clean
clean:
	rm *.o	
#########################################################################
