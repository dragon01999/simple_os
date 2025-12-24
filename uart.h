#ifndef _UART_H
#define _UART_H

#include "ktypes.h"

void uart_putc(const char c);

void uart_puts(const char *str);

void print_hex(u32 num);

void print_hex64(u64 num);

void panic(const char *msg);

#endif
