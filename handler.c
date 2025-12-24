#include "ktypes.h"
#include "uart.h"
#include "handler.h"

static void die(const char *fmt)
{
	panic(fmt);
}

void __handle_sync(void)
{
    uart_puts("\n esr_el1: ");
    u64 esr_val;
    __asm__ volatile("mrs %0, esr_el1" : "=r" (esr_val));
    print_hex(((u32)esr_val) >> 26);
    return;
	die("Sync exception triggered\n");
}

void __handle_irq(void)
{
	die("Irq exception triggered\n");
}

void __handle_fiq(void)
{
	die("Fiq exception triggered\n");
}

void __handle_sys_err(void)
{
	/* lol not that my system might work :> */
	die("Fatal: Syserror exception trigger\n");
}

void __handle_illegal_exception(void)
{
    die("Triggering aarch-32 exception\n");
}

