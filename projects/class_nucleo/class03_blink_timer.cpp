/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include "platform/mbed_thread.h"
int timer1 = 0;
DigitalOut led(LED1);

void init_function(void);
void control_function(void);
void timers(void);
void flash_one_second(void);

Ticker timers_interrupt;//name your interrupt

int main()
{
    init_function();
    while (1)
    {
        control_function();
    }
}

void init_function(void)
{
    timers_interrupt.attach(&timers, 0.1);//call this interrupt every 0.1s
    printf("starting...\n");
}
void control_function(void)
{
    flash_one_second();
}
void flash_one_second(void)
{
    if (timer1 < 10)
        led = 1;
    else if (timer1 < 20)
        led = 0;
    else
        timer1 = 0;
}

void timers()
{
    //timer1 timer + 1;
    timer1++;
}
