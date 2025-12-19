#include <stdint.h>
#include "uart.h"
#include "handler.h"

static void die(const char *fmt)
{
	panic(fmt);
}

void __handle_sync(void)
{
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

void __handle_syserror(void)
{
	/* lol not that my system might work :> */
	die("Fatal: Syserror exception trigger\n");
}

void __handle_illegal_exception(void)
{
    die("Triggering aarch-32 exception\n");
}

