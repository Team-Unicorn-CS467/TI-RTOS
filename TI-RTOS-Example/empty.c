/*
 * Copyright (c) 2015, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 *  ======== empty.c ========
 */
/* XDCtools Header files */
#include <xdc/std.h>
#include <xdc/runtime/System.h>

/* BIOS Header files */
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>
#include <ti/sysbios/hal/Core.h>
#include <ti/sysbios/hal/Hwi.h>
#include <ti/sysbios/knl/Idle.h>

/* TI-RTOS Header files */
#include <ti/drivers/GPIO.h>
// #include <ti/drivers/I2C.h>
// #include <ti/drivers/SDSPI.h>
// #include <ti/drivers/SPI.h>
// #include <ti/drivers/UART.h>
// #include <ti/drivers/Watchdog.h>
// #include <ti/drivers/WiFi.h>

/* Board Header file */
#include "Board.h"

#define TASKSTACKSIZE   512

Task_Struct task1Struct, task2Struct, task3Struct, task4Struct, task5Struct, task6Struct;
Char task1Stack[TASKSTACKSIZE], task2Stack[TASKSTACKSIZE], task3Stack[TASKSTACKSIZE],
task4Stack[TASKSTACKSIZE], task5Stack[TASKSTACKSIZE], task6Stack[TASKSTACKSIZE];

Task_Handle task1Handle, task2Handle, task3Handle, task4Handle, task5Handle, task6Handle;

Void Idle_blink(UArg arg0, UArg arg1)
{
        GPIO_toggle(Board_GREEN);
        GPIO_toggle(Board_GREEN);

}
/*
 *  ======== blinky1 ========
 *  Toggle the Board_LED0. The Task_sleep is determined by arg0 which
 *  is configured for the heartBeat Task instance.
 */
Void blinky1(UArg arg0, UArg arg1)
{
    while (1) {
        Task_sleep((UInt)arg0);
        GPIO_toggle(Board_PC6);
    }
}

Void blinky2(UArg arg0, UArg arg1)
{
    while (1) {
        Task_sleep((UInt)arg0);
        GPIO_toggle(Board_PC7);
    }
}

Void blinky3(UArg arg0, UArg arg1)
{
    while (1) {
        Task_sleep((UInt)arg0);

        GPIO_toggle(Board_PC5);
    }
}

Void blinky4(UArg arg0, UArg arg1)
{
    while (1) {
        Task_sleep((UInt)arg0);
        GPIO_toggle(Board_PB3);
    }
}

Void blinky5(UArg arg0, UArg arg1)
{
    while (1) {
        Task_sleep((UInt)arg0);
        GPIO_toggle(Board_PC4);
    }
}

Void blinky6(UArg arg0, UArg arg1)
{
    while (1) {

        Task_sleep((UInt)arg0);
        GPIO_toggle(Board_RED);
    }
}

/*
 *  ======== main ========
 */
int main(void)
{
    Task_Params taskParams;

    /* Call board init functions */
    Board_initGeneral();
    Board_initGPIO();
    // Board_initI2C();
    // Board_initSDSPI();
    // Board_initSPI();
    // Board_initUART();
    // Board_initUSB(Board_USBDEVICE);
    // Board_initWatchdog();
    // Board_initWiFi();

    Task_Params_init(&taskParams);
    taskParams.arg0 = 1000;
    taskParams.stackSize = TASKSTACKSIZE;
    taskParams.stack = &task1Stack;
    taskParams.priority = 1;
    Task_construct(&task1Struct, (Task_FuncPtr)blinky1, &taskParams, NULL);
    task1Handle = Task_handle(&task1Struct);

    taskParams.stack = &task2Stack;
    taskParams.priority = 2;
    taskParams.arg0 = 1000;
    Task_construct(&task2Struct, (Task_FuncPtr)blinky2, &taskParams, NULL);
    task2Handle = Task_handle(&task2Struct);

    taskParams.stack = &task3Stack;
    taskParams.priority = 3;
    taskParams.arg0 = 1000;
    Task_construct(&task3Struct, (Task_FuncPtr)blinky3, &taskParams, NULL);
    task3Handle = Task_handle(&task3Struct);

    taskParams.stack = &task4Stack;
    taskParams.priority = 4;
    taskParams.arg0 = 1000;
    Task_construct(&task4Struct, (Task_FuncPtr)blinky4, &taskParams, NULL);
    task4Handle = Task_handle(&task4Struct);

    taskParams.stack = &task5Stack;
    taskParams.priority = 5;
    taskParams.arg0 = 1000;
    Task_construct(&task5Struct, (Task_FuncPtr)blinky5, &taskParams, NULL);
    task5Handle = Task_handle(&task5Struct);

    taskParams.stack = &task6Stack;
    taskParams.priority = 6;
    taskParams.arg0 = 1000;
    Task_construct(&task6Struct, (Task_FuncPtr)blinky6, &taskParams, NULL);
    task6Handle = Task_handle(&task6Struct);

    /* SysMin will only print to the console when you call flush or exit */
    System_flush();

    /* Start BIOS */
    BIOS_start();

    return (0);
}
