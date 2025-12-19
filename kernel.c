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
	uint64_t bss, bss_end, vect, stp, vec;
	__asm__ __volatile("ldr %x0, =__bss_start \n"
            "ldr %x2, =__bss_end \n"
            "ldr %x1, =__interrupt_vect \n"
            "ldr %x4, =_vec \n"
            "ldr %x3, =__kernel_top \n"
            :"=r"(bss), "=r"(vect), "=r"(bss_end), "=r"(stp), "=r"(vec)
            :
            );
    uart_puts("\n __bss_top: ");
    print_hex64(bss);
    uart_puts("\n __bss_end: ");
    print_hex64(bss_end);
    uart_puts("\n stp: ");
    print_hex64(stp);
    uart_puts("\n vect: ");
    print_hex64(vect);
    uart_puts("\n vec: ");
    print_hex64(vec);
    __asm__ __volatile__ (".inst 0x00000000");

	panic("Next instruction not found!\n");
}
