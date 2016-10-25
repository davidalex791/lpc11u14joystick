#ifndef PERIODIC_TIMER_H_INCLUDED_
#define PERIODIC_TIMER_H_INCLUDED_

#include <stdbool.h>
void periodictimer_Init();
uint32_t periodictimer_Get();
bool periodictimer_IsExpired(uint32_t actual, uint32_t period);

#endif
