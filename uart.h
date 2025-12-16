#ifndef _UART_H
#define _UART_H

inline void uart_putc(const char c);

void uart_puts(const char *str);

void panic(const char *msg);
#endif
