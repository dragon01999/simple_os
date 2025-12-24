#include "ktypes.h"
#include "uart.h"

void uart_putc(const char c)
{
    uintptr_t uart = 0x09000000;
    while ((*((volatile u32 *)(uart + 0x018)) >> 5 ) & 1)
        ;
    *(volatile u32 *)uart = c;
    return;
}

void uart_puts(const char *str)
{
    for (int i = 0; str[i]; i++)
        uart_putc(str[i]);
    return;
}

void print_hex(u32 num)
{
    char *hex = "0123456789abcdef";
    int size = sizeof(u32) * 2;
    char str_hex[size + 1];
    str_hex[size] = '\0';
    int r = 0;
    for (int i = size - 1; i >= 0; i--) {
        r = num & 0xf;
        num >>= 4;
        str_hex[i] = hex[r];
    }
    uart_puts("0x");
    uart_puts(str_hex);
}

void print_hex64(u64 num)
{
    char *hex = "0123456789abcdef";
    int size = sizeof(u64) * 2;
    char str_hex[size + 1];
    str_hex[size] = '\0';
    int r = 0;
    for (int i = size - 1; i >= 0; i--) {
    	r = num & 0xf;
        num >>= 4;
        str_hex[i] = hex[r];
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

