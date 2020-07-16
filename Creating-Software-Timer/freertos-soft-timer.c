/* For more support and information on our FreeRTOS tutorials
Please write us at: info@logictronix.com or visit: www.LogicTronix.com */

/* FreeRTOS includes. */
#include "FreeRTOS.h"
#include "timers.h"
/* Xilinx includes. */
#include "xil_printf.h"
#include "xparameters.h"

#define TIMER_ID	1
#define DELAY_10_SECONDS	10000UL
#define DELAY_1_SECOND		1000UL


/*-----------------------------------------------------------*/
static void vTimer1Callback( TimerHandle_t pxTimer );


/*-----------------------------------------------------------*/

static TimerHandle_t xTimer1 = NULL;
unsigned int count = 0;

int main( void )
{
	const TickType_t x1seconds = pdMS_TO_TICKS( DELAY_1_SECOND );
	const TickType_t x100ms = pdMS_TO_TICKS(100);

	xil_printf( "Hello from Freertos Soft Timer Example App\r\n" );

	xTimer1 = xTimerCreate( (const char *) "Timer1",
							x1seconds,
							pdTRUE,
							1,
							vTimer1Callback);



	/* start the timer with a block time of 0 ticks. This means as soon
	   as the schedule starts the timer will start running and will expire after
	   defined seconds */
	xTimerStart( xTimer1, 0 );

	/* Start the tasks and timer running. */
	vTaskStartScheduler();

	/* If all is well, the scheduler will now be running, and the following line
	will never be reached.  If the following line does execute, then there was
	insufficient FreeRTOS heap memory available for the idle and/or timer tasks
	to be created.  See the memory management section on the FreeRTOS web site
	for more details. */
	for( ;; );
}

/*-----------------------------------------------------------*/
static void vTimer1Callback( TimerHandle_t pxTimer )
{
	count++;
	xil_printf("Timer1 Callback event for %u times \r\n", count);

}
