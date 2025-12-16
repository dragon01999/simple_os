#include <stdint.h>
#include "uart.h"

void uart_putc(const char c)
{
    uintptr_t uart = 0x09000000;
    while ((*((volatile uint32_t *)(uart + 0x018)) >> 5 ) & 1)
        ;
    *(volatile uint32_t *)uart = c;
    return;
}

void uart_puts(const char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        uart_putc(str[i]);
    return;
}


/* For now panic will reside here */
void panic(const char *msg)
{
	uart_putc('\n');
    uart_puts(msg);
    for (;;);
}

