ENTRY(_start)

SECTIONS {
	/* Load kernel at */
	. = 0x40000000;
	.text : ALIGN(4k)
	{
		*(.text.boot)
		*(.text*)
	}
	.vectors : ALIGN(2048)
	{
		__interrupt_vect = .;
		KEEP(*(.vectors))
	}
	.rodata : ALIGN(8)
	{
		*(.rodata*)
	}
    .data : ALIGN(8)
	{
		*(.data*)
	}
	.bss : ALIGN(8)
	{
		__bss_start = .;
		*(.bss*)
		*(COMMON)
		__bss_end = .;
	}
	/* Kernel Stack */
	. = ALIGN(16);
	__kernel_top = . + 0x4000;
}

	
