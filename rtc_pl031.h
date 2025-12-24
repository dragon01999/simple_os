#ifndef _RTC_PL031_H
#define _RTC_PL031_H

#include "ktypes.h"

struct time {
    u32 year;
    u32 month;
    u32 day;
    u32 hr;
    u32 min;
    u32 sec;
};

void init_rtc(void);

int set_interrupt_to(int state);

void set_time(uint32_t unix_epoch_sec);

#endif
