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

void print_hex(uint32_t num)
{
        int size = sizeof(uint32_t) * 2;
        char str_hex[size + 1];
        str_hex[size] = '\0';
        int r = 0;
        for (int i = size - 1; i >= 0; i--) {
                r = num % 16;
                num >>= 4;
                str_hex[i] = (r < 10) ? r + '0' : (r - 10) + 'a';
        }
        uart_puts("0x");
        uart_puts(str_hex);
}

void print_hex64(uint64_t num)
{
        int size = sizeof(uint64_t) * 2;
        char str_hex[size + 1];
        str_hex[size] = '\0';
        int r = 0;
        for (int i = size - 1; i >= 0; i--) {
                r = num % 16;
                num >>= 4;
                str_hex[i] = (r < 10) ? r + '0' : (r - 10) + 'a';
        }
        uart_puts("0x");
        uart_puts(str_hex);
}
/* For now panic will reside here */
void panic(const char *msg)
{
    uart_putc('\n');
    uart_puts(msg);
    for (;;);
}
