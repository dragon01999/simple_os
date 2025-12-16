/* Headers which idont have for now :) */
#include <stdint.h>

static inline void uart_putc(const char c)
{
    uintptr_t uart = 0x09000000;
    while ((*((volatile uint32_t *)(uart + 0x018)) >> 5 ) & 1)
        ;
    *(volatile uint32_t *)uart = c;
    return;

}

static void uart_puts(const char *__nul_terminated_str)
{
    for (int i = 0; __nul_terminated_str[i] != '\0'; i++) 
        uart_putc(__nul_terminated_str[i]);
    
    return;
}

static void panic(const char *msg)
{
    uart_putc('\n');
    uart_puts(msg);
    for (; ;) ;
}

void kernel_main(void) {
    /* Perhaps write to uart? */
   // char *str = "hi";
    uart_putc('a');
   // uart_puts("Hello World! From my shashi bitch kernel!");
    //uart_putc('\n');
//    uart_puts(str);
  //  panic("Next instruction not found");
}
