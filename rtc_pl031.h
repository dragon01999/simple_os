#ifndef _RTC_PL031_H
#define _RTC_PL031_H

#include "ktypes.h"

struct tm {
    u32 year;
    u32 mon;
    u32 day;
    u32 hr;
    u32 min;
    u32 sec;
};

void init_rtc(void);

int set_interrupt_to(int state);

void write_time_into(struct tm *time);

void set_time(uint32_t unix_epoch_sec);

#endif
