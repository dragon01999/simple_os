#include <stdint.h>
#include "uart.h"

void memset(char *buffer, char c, int size)
{
    for (int i = 0; i < size; i++) {
        buffer[i] = c;
    }
    return;
} 
char buff[9] = {'H', 'E', 'F', 'O', 't', '6', '7', '\0', '9'};
void kernel_main(void) {
	uart_puts("Hello, World. From my kernel!\n");
    for (int i = 0; i < 9; i++) {
        uart_putc('\n');
        print_hex((int)&buff[i]);
    }
	panic("Next instruction not found!\n");
}
