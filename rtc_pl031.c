#include "ktypes.h"
#include "rtc_pl031.h"

#define BASE_ADDR 0x9010000
#define RTCDR 0x00
#define RTCCR 0x0c
#define RTCIMSC 0x010
#define RTCLR 0x008

/* Its not perfectly accurate but later ill do it accurately */
#define UNIX_EPOCH_YEAR 1970

#define YEAR_SEC 31556926
#define MONTH_SEC 2629743
#define DAY_SEC 86400
#define HOUR_SEC 3600
#define MINUTE_SEC 60

void init_rtc(void)
{
	volatile u32 *rtccr = (u32 *) (BASE_ADDR + RTCCR);
	*rtccr |= 1;
}

int set_interrupt_to(int state)
{
	volatile u32 *rtcimsc = (u32 *) (BASE_ADDR + RTCIMSC);
	if (state > 1 || state < 0)
		return -1;
	*rtcimsc |= state;
	return state;
}

/* This function isnt accurate for now its just a stub */
void write_time_into(struct tm *time) 
{
	volatile u32 *rtcdr = (u32 *) (BASE_ADDR + RTCDR);
    time->year =  *rtcdr / YEAR_SEC + UNIX_EPOCH_YEAR;
    // 1s are added cause there's no 0th mon, day, hr, min and sec
	time->mon  = (*rtcdr / MONTH_SEC) % 12 + 1; 
	time->day  = (*rtcdr / DAY_SEC) % 30 + 1;
	time->hr   = (*rtcdr / HOUR_SEC) % 24 + 1;
	time->min  = (*rtcdr / MINUTE_SEC) % 60 + 1;
	time->sec  =  *rtcdr % 60 + 1;
}

/* Still have not set up genric timer so we'll use this ugly manual method */
void set_time(u32 unix_epoch_sec)
{
	volatile u32 *rtclr = (u32 *) (BASE_ADDR + RTCDR);
	*rtclr = unix_epoch_sec;
}

