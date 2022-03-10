/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include "platform/mbed_thread.h"

DigitalOut led(LED1);
int timer1 = 0;
int timer2 = 0;

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
    return 0;
}

void init_function(void)
{
    timers_interrupt.attach(&timers, 0.1);//call this interrupt every 0.1s
    printf("starting...\n");
}
void control_function(void)
{
    flash_one_second();
    //Do other things...
}

void flash_one_second(void)
{
    if (timer1 < 10)//0,1,2,3,4,5,6,7,8,9,
        led = 1;
    else if (timer1 < 20)//10,11,12,13,14,15,16,17,18,19,
        led = 0;
    else //20
        timer1 = 0; //reset the variable timer 1 back to zero
}

void timers()
{//this function is called from 
 //the Ticker interrupt configuration
 // and it happens every 0.1s OR 100ms
    timer1 = timer1 + 1;
    timer2++;
    // timer1++;
    //timer variable will increase
    // 0 -> 1 -> 2 -> 3 -> 4...
}
