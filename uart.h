#ifndef _UART_H
#define _UART_H

void uart_putc(const char c);

void uart_puts(const char *str);

void print_hex(int hex);

void panic(const char *msg);
#endif
