MEMORY
{
	
    FLASH(RX) : ORIGIN = 0x00000000, LENGTH = 512M
    SRAM(RWX) : ORIGIN = 0x20000000, LENGTH = 512M

}
SECTIONS
{
	.TEXT :
	{
        *(.vectors*)
        *(.text*)
        *(.rodata)
        E_text = .;  
        . = ALIGN(4);  
	} > FLASH
    
    .DATA :
    {
        S_data = .;
        *(.data*)
        E_data = .;
        . = ALIGN(4);  


    } > SRAM AT> FLASH
    
    .BSS :
    {

        S_bss = .;
        *(.bss*)
        E_bss = .;
        . = ALIGN(4);  

    } > SRAM




}