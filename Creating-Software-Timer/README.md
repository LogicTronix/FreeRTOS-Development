<i> In this section we will have detailed steps for how to create Software timer on FreeRTOS so you can implement timer based pplications. </i>

# Software Timers
Timers are clock driven counters whose value increases depending upon clock signal. Unlike hardware timers, FreeRToS provides hardware independent software timers function. These FreeRTOS Software timers can be use used to trigger an event periodically with a fixed frequency or creatain tasks in future.

There are two types of timer. One-Shot, which need to be started manually an do not restart after timer expires. The second is Auto Reload, which each time timer expires. When timer expires, it can trigger an event through a callback function.

## Main FreeRToS Software Timer API functions
### Creating Software Timer
Software timer are created by calling xTimerCreate() funtion. This function helps to create and set the timer period, type and callback function. It returns the handle to the timer object which is further passed to functions for starting and stopping the timer. Fuctiion prototype and its parameters are shown below:

<B> Fuction Prototype: </B>

<i> 
  xTimerCreate(const char *pcTimerName,
  
             const TickType_t xTimerPeriod,
             
             const UBaseType_t uxAutoReload,
             
             void * const pvTimerID,
             
             TimerCallbackFunction_t pxCallbackFunction);
             
</i>
<B> Fuction parameters: </B>

<i> pcTimerName : A plain text name for the timer
  
xTimerPeriod : Time period for timer specified in multiple of tick type.

uxAutoReload : Set to pdTrue creates Auto-reload timer and to pdFalse creates One-shot timer.

pvTimerId : Identifier for the timer

pxCallbackFunction : The function to call when the timer expiers
</i> 
This function will only create a software timer but does not start the timer.

### Starting the software timer
<i> xTimerStart() /<i> function is used to start the timer. To start the timer created, one has to pass the handle of timer object.

<B> Function Prototype: </B>

<i> xTimerStart(TimerHandle_t xTimer, TickType_t xTicksToWait); </i>

<B> Function Parameters: </B>

<i> xTimer : handle to timer object
  
xTicksToWait : maximum delay timer task could wait in Blocked state queue
</i>

### Example
Lets see an example for creating a software timer which prints a status message every second. First to create a timer, timer handle must be declared. In the example application, you can find following statement before main function:

<i> static TimerHandle_t xTimer1 = NULL; </i>


Then in <i> main() </i> function <i> xTimerCreate()</i>  is used to create auto reload timer with 1 second time period.

<i> xTimer1 = xTimerCreate((const char *) "Timer1",
  
                                   x1seconds,
                                   
                                     pdTRUE,
                                     
                                     1,
                                     
                                     vTimer1Callback
                            )
</i>

In the above code snippet, <i> x1seconds </i> variable is obtained from <i> pdMS_TO_TICKS(DELAY_1_SECOND) </i> , which returns the value of FreeRToS system tick required for 1000 milli seconds.

Now to run the timer created, <i> xTimerStart( xTimer1, 0) </i> function is called with <i> xTimer1 </i> , handle for the timer created by <i> xTimerCreate </i>

Later when timer expires after 1 second, <i> vTimer1Callback </i>  is called. Here timer callback is assigned to print the counter value which increments in every seconds.

<i> static void vTimer1Callback( TimerHandle_t pxTimer )
  
{

  count++;
  
   xil_printf("Timer1 Callback event for %u times\r\n", count);
   
}
</i>


### Example Code: Complete
[Software Timer-FreeRTOS Example Code](https://github.com/LogicTronix/FreeRTOS-Development/blob/master/Creating-Software-Timer/freertos-soft-timer.c)
### Output of the example application:

![FreeRTOS Software Timer Output](https://github.com/LogicTronix/FreeRTOS-Development/blob/master/Creating-Software-Timer/FreeRTOS_software_timer_output.PNG)
