MEMORY
{
	
FLASH(RX) : ORIGIN = 0x08000000, LENGTH = 128K
SRAM(RWX) : ORIGIN = 0x20000000, LENGTH = 20K

}

SECTIONS
{
	.TEXT :
	{
        *(.VECTORS*)
        *(.text*)
        *(.rodata)
        E_TEXT = .;  
	} > FLASH
    
    .DATA :
    {
        S_DATA = .;
        *(.data*)
        E_DATA = .;


    } > SRAM AT> FLASH
    
    .BSS :
    {

        S_BSS = .;
        *(.bss*)
        E_BSS = .;
        . = . + 1000;
        STACK_TOP = .;
    } > SRAM




}	