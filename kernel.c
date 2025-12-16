/* Headers which idont have for now :) */
#include <stdint.h>
#include "uart.h"

void kernel_main(void) {
    /* Perhaps write to uart? */
    char *str = "hi";
    uart_puts("Hello World! From my kernel!");
    uart_putc('\n');
    uart_puts(str);
    panic("Next instruction not found");
}
