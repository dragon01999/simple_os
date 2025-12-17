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
    for (int i = 0; str[i]; i++)
        uart_putc(str[i]);
    return;
}

void print_hex(int hex)
{
    int size = sizeof(int) * 2;
    char buff[size + 1];
    buff[size] = '\0';
    int q = hex, r = 0, i = size - 1;
    while (i >= 0) {
        r = q % 16;
        q /= 16;
        buff[i] = (r < 10) ? r + 48 : (r - 10) + 65;
        i--;
    }
    uart_puts("0x");
    uart_puts(buff);
}

/* For now panic will reside here */
void panic(const char *msg)
{
    uart_putc('\n');
    uart_puts(msg);
    for (;;);
}

