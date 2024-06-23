ENTRY(reset)
MEMORY
{
	
	Mem (rwx) : ORIGIN =0x00000000, LENGTH = 64M
}
SECTIONS
{
	
	. =0x10000;
	.startup . :
	{
        startup.o(.text)

	}> Mem
	.data :
	{
        *(.text)

	}> Mem
	.bss :
	{

	    *(.bss) *(COMMON)
	}> Mem
	.rodata :
	{

	    *(.rodata)
	}> Mem
	.text :
	{

	    *(.text)
	}> Mem
	. = . + 1000;
	top_stack = .;

}