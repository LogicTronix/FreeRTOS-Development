/*
FreeRTOS application from LogicTronix.com 
for any queries on FreeRTOS development on MPSoC/7000 series of FPGA , please write us at: info@logictronix.com
Program created 5 tasks which prints iteration values
*/

/* FreeRTOS includes. */
#include "FreeRTOS.h"
#include "task.h"

/* Xilinx includes. */
#include "xil_printf.h"
#include "xparameters.h"

#define DELAY_10_SECONDS	10000UL
#define DELAY_1_SECOND		1000UL


/* The Tx and Rx tasks as described at the top of this file. */
static void prvThread1(void *pvParameter);
static void prvThread2(void *pvParameter);
static void prvThread3(void *pvParameter);
static void prvThread4(void *pvParameter);
static void prvThread5(void *pvParameter);

/*-----------------------------------------------------------*/

static TaskHandle_t xThread1;
static TaskHandle_t xThread2;
static TaskHandle_t xThread3;
static TaskHandle_t xThread4;
static TaskHandle_t xThread5;


int main( void )
{
	const TickType_t x1seconds = pdMS_TO_TICKS( DELAY_1_SECOND );
	const TickType_t x100ms = pdMS_TO_TICKS(100);

	xil_printf( "Hello from Freertos Start of the app\r\n" );

	/* Create the five tasks. */

	xTaskCreate(prvThread1,
			    (const char *) "Thread1",
				configMINIMAL_STACK_SIZE,
				NULL,
				tskIDLE_PRIORITY,
				&xThread1);

	xTaskCreate(prvThread2,
				(const char *) "Thread2",
				configMINIMAL_STACK_SIZE,
				NULL,
				tskIDLE_PRIORITY,
				&xThread2);

	xTaskCreate(prvThread3,
				(const char *) "Thread3",
				configMINIMAL_STACK_SIZE,
				NULL,
				tskIDLE_PRIORITY,
				&xThread3);

	xTaskCreate(prvThread4,
				(const char *) "Thread4",
				configMINIMAL_STACK_SIZE,
				NULL,
				tskIDLE_PRIORITY,
				&xThread4);

	xTaskCreate(prvThread5,
				(const char *) "Thread5",
				configMINIMAL_STACK_SIZE,
				NULL,
				tskIDLE_PRIORITY,
				&xThread5);


	/* Start the tasks and timer running. */
	vTaskStartScheduler();

	/* If all is well, the scheduler will now be running, and the following line
	will never be reached.  If the following line does execute, then there was
	insufficient FreeRTOS heap memory available for the idle and/or timer tasks
	to be created.  See the memory management section on the FreeRTOS web site
	for more details. */
	for( ;; );
}




static void prvThread1( void *pvParameters)
{
  unsigned int count = 0;

  while(1){
	  vTaskDelay(pdMS_TO_TICKS(DELAY_1_SECOND));
	  count++;
	  xil_printf("Task 1 counter value: %u \n", count);
  }

}


static void prvThread2( void *pvParameters)
{
  unsigned int count = 0;

  while(1){
	  vTaskDelay(pdMS_TO_TICKS(DELAY_1_SECOND));
	  count++;
	  xil_printf("Task 2 counter value: %u \n", count);
  }

}


static void prvThread3( void *pvParameters)
{
  unsigned int count = 0;

  while(1){
	  vTaskDelay(pdMS_TO_TICKS(DELAY_1_SECOND));
	  count++;
	  xil_printf("Task 3 counter value: %u \n", count);
  }

}


static void prvThread4( void *pvParameters)
{
  unsigned int count = 0;

  while(1){
	  vTaskDelay(pdMS_TO_TICKS(DELAY_1_SECOND));
	  count++;
	  xil_printf("Task 4 counter value: %u \n", count);
  }

}


static void prvThread5( void *pvParameters)
{
  unsigned int count = 0;

  while(1){
	  vTaskDelay(pdMS_TO_TICKS(DELAY_1_SECOND));
	  count++;
	  xil_printf("Task 5 counter value: %u \n", count);
  }

}
