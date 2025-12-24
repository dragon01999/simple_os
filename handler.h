#ifndef _HANDLER_H
#define _HANDLER_H

#include "ktypes.h"

static void die(const char *fmt);

void __handle_sync(void);

void __handle_irq(void);

void __handle_fiq(void);

void __handle_sys_err(void);

void __handle_illegal_exception(void);

#endif
