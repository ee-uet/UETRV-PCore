/*
 * FreeRTOS V202212.00
 * Copyright (C) 2020 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * https://www.FreeRTOS.org
 * https://github.com/FreeRTOS
 *
 */

/* FreeRTOS kernel includes. */
#include <FreeRTOS.h>
#include <task.h>
#include <queue.h>
#include <timers.h>
#include <stdio.h>
#include "riscv-virt.h"

/* Priorities used by the tasks. */
#define mainQUEUE_RECEIVE_TASK_PRIORITY    ( tskIDLE_PRIORITY + 3 )
#define mainQUEUE_SEND_TASK_PRIORITY       ( tskIDLE_PRIORITY + 2 )
#define mainTIMER_TASK_PRIORITY            ( tskIDLE_PRIORITY + 4 )
#define mainTIME_SLICING_TASK_PRIORITY     ( tskIDLE_PRIORITY + 4 )
#define mainPRINT_HELLO_TASK_PRIORITY      ( tskIDLE_PRIORITY + 1 )

/* The rate at which data is sent to the queue. */
#define mainQUEUE_SEND_FREQUENCY_MS        pdMS_TO_TICKS( 1000 )
#define mainTIMER_PRINT_FREQUENCY_MS       pdMS_TO_TICKS( 2000 )
#define mainHELLO_PRINT_FREQUENCY_MS       pdMS_TO_TICKS( 5000 )  // Increased time for Hello task

/* The maximum number of items the queue can hold. */
#define mainQUEUE_LENGTH                   ( 1 )

/* The queue used by both tasks. */
static QueueHandle_t xQueue = NULL;

static void prvQueueSendTask( void * pvParameters )
{
    TickType_t xNextWakeTime;
    unsigned long ulValueToSend = 0UL;

    ( void ) pvParameters;

    xNextWakeTime = xTaskGetTickCount();

    for( ; ; )
    {
        vTaskDelayUntil( &xNextWakeTime, mainQUEUE_SEND_FREQUENCY_MS );

        ulValueToSend++;
        char buf[ 40 ];
        sprintf( buf, "%d: %s: send %ld", xGetCoreID(),
                 pcTaskGetName( xTaskGetCurrentTaskHandle() ),
                 ulValueToSend );
        vSendString( buf );

        xQueueSend( xQueue, &ulValueToSend, 0U );
    }
}

static void prvQueueReceiveTask( void * pvParameters )
{
    ( void ) pvParameters;

    for( ; ; )
    {
        unsigned long ulReceivedValue;
        xQueueReceive( xQueue, &ulReceivedValue, portMAX_DELAY );

        char buf[ 40 ];
        sprintf( buf, "%d: %s: received %ld", xGetCoreID(),
                 pcTaskGetName( xTaskGetCurrentTaskHandle() ),
                 ulReceivedValue );
        vSendString( buf );
    }
}

static void prvPrintHelloTask( void * pvParameters )
{
    ( void ) pvParameters;

    for( ; ; )
    {
        vSendString( "Hello FreeRTOS!" );
        vTaskDelay(mainHELLO_PRINT_FREQUENCY_MS);  // Delay for 5 seconds
    }
}

static void prvTimerTask( void * pvParameters )
{
    TickType_t xNextWakeTime;
    static unsigned long ulTimerCount = 0;  // Timer counter to change each time

    ( void ) pvParameters;

    xNextWakeTime = xTaskGetTickCount();

    for( ; ; )
    {
        vTaskDelayUntil( &xNextWakeTime, mainTIMER_PRINT_FREQUENCY_MS );
        
        ulTimerCount++;  // Increment the timer count each time it runs
        char buf[50];  // Buffer to store the message
        sprintf(buf, "Timer running after 2 seconds: Count %lu", ulTimerCount);
        vSendString(buf);  // Print the timer count each time
    }
}


static void prvTimeSlicingTask( void * pvParameters )
{
    ( void ) pvParameters;

    for( ; ; )
    {
        vSendString( "Time-slicing task is executing..." );
        taskYIELD();
        vTaskDelay(mainTIMER_PRINT_FREQUENCY_MS);  // Delay to make time slicing visible
    }
}

int main_blinky( void )
{
    vSendString( "Starting FreeRTOS Scheduler" );

    /* Create the queue. */
    xQueue = xQueueCreate( mainQUEUE_LENGTH, sizeof( unsigned long ) );

    if( xQueue != NULL )
    {
        /* Start the tasks. */
        xTaskCreate( prvQueueReceiveTask, "Rx", configMINIMAL_STACK_SIZE * 2U, NULL,
                     mainQUEUE_RECEIVE_TASK_PRIORITY, NULL );
        xTaskCreate( prvQueueSendTask, "Tx", configMINIMAL_STACK_SIZE * 2U, NULL,
                     mainQUEUE_SEND_TASK_PRIORITY, NULL );
        xTaskCreate( prvPrintHelloTask, "Hello", configMINIMAL_STACK_SIZE * 2U, NULL,
                     mainPRINT_HELLO_TASK_PRIORITY, NULL );
        xTaskCreate( prvTimerTask, "Timer", configMINIMAL_STACK_SIZE * 2U, NULL,
                     mainTIMER_TASK_PRIORITY, NULL );
        xTaskCreate( prvTimeSlicingTask, "TimeSlicing", configMINIMAL_STACK_SIZE * 2U, NULL,
                     mainTIME_SLICING_TASK_PRIORITY, NULL );
    }

    vTaskStartScheduler();

    return 0;
}
