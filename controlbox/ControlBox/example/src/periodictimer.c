#include <stdint.h>
#include <string.h>
#include "periodictimer.h"
#include "board.h"

#include "FreeRTOS.h"
#include "timers.h"

//set to 1000Hz=1ms
#define portTICK_PERIOD_MS		 ( 1000 / configTICK_RATE_HZ )

xTimerHandle xTimer = NULL;
volatile uint32_t g_msTicks;		/** counts 1ms timeTicks */

void vTimerCallback( xTimerHandle xTimer )
{
	g_msTicks++;
}

void periodictimer_Init()
{
	g_msTicks = 0;
	xTimer = xTimerCreate
	                   ( /* Just a text name, not used by the RTOS
	                     kernel. */
	                     (const signed char *)"Timer",
	                     /* The timer period in ticks, must be
	                     greater than 0. */
						 portTICK_PERIOD_MS,
	                     /* The timers will auto-reload themselves
	                     when they expire. */
	                     pdTRUE,
	                     /* The ID is used to store a count of the
	                     number of times the timer has expired, which
	                     is initialised to 0. */
	                     ( void * ) 0,
	                     /* Each timer calls the same callback when
	                     it expires. */
	                     vTimerCallback
	                   );

	 if( xTimer == NULL )
	 {
		 /* The timer was not created. */
	 }
	 else
	 {
		 /* Start the timer.  No block time is specified, and
		 even if one was it would be ignored because the RTOS
		 scheduler has not yet been started. */
		 if( xTimerStart( xTimer, 0 ) != pdPASS )
		 {
			 /* The timer could not be set into the Active
			 state. */
		 }
	 }
}

uint32_t periodictimer_Get()
{
	uint32_t msTicks;
	taskDISABLE_INTERRUPTS();
	msTicks = g_msTicks;
	taskENABLE_INTERRUPTS();
	return msTicks;
}

bool periodictimer_IsExpired(uint32_t actual, uint32_t period)
{
	bool status;
	taskDISABLE_INTERRUPTS();
	status = ((actual+period) <= g_msTicks);//http://stackoverflow.com/questions/3095623/how-to-deal-with-a-wrapping-counter-in-embedded-c
	taskENABLE_INTERRUPTS();
	return status;
}
