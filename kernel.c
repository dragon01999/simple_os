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
    int k = 27008299;
    for (int i = 0; i < 9; i++) {
        uart_putc('\n');
        print_hex((int)&buff[i]);
    }
	uart_putc('\n');
    print_hex((uint32_t )&kernel_main);
    uart_putc('\n');
    print_hex((uint32_t)&buff);
    uart_putc('\n');
    print_hex((uint32_t)&k);
    uart_putc('\n');
    print_hex64((uint64_t)&h);
	uint64_t bss, _stp;
	__asm__ __volatile("ldr %x0, =__bss_start \n"
            :"=r"(bss)
            :
            );
    uart_puts("\n __bss_top: ");
    print_hex64(bss);
	panic("Next instruction not found!\n");
}
