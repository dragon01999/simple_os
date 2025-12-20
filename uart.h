#ifndef _UART_H
#define _UART_H

void uart_putc(const char c);

void uart_puts(const char *str);

void print_hex(uint32_t num);

void print_hex64(uint64_t num);

void panic(const char *msg);

#endif
