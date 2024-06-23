MEMORY
{
   	
    flash(RX) : ORIGIN = 0x08000000, LENGTH = 128K
    sram(RWX) : ORIGIN = 0x20000000, LENGTH = 20K
}

SECTIONS
{
	
    .text :
    {

        *(.vectors*)
        *(.text*)
    } > flash

    .data :
        {
        *(.data)

        } > flash

    .bss :
    {
       *(.bss*)
       . = . + 1000;
    stack_top = .;
    } > sram

}
