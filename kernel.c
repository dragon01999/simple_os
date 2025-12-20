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
	uint64_t bss, bss_end, vect, stp, spsel, vbar;
	__asm__ __volatile("ldr %x0, =__bss_start \n"
            "ldr %x2, =__bss_end \n"
            "ldr %x1, =__interrupt_vect \n"
            "ldr %x3, =__kernel_top \n"
            "mrs %x4, spsel \n"
            "mrs %x5, vbar_el1\n"
            :"=r"(bss), "=r"(vect), "=r"(bss_end), "=r"(stp), "=r"(spsel), "=r"(vbar)
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
    uart_puts("\n spsel: ");
    print_hex64(spsel);
    uart_puts("\n vbar: ");
    print_hex64(vbar);
    __asm__ __volatile__ ("brk #1");
    uart_puts("\n back here");
    __asm__ __volatile__(".inst 00000000");
    __asm__ __volatile__("svc #0");

	panic("Next instruction not found!\n");
}
