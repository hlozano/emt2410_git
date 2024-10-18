#include "mbed.h"

Ticker toggle_led_ticker_interrupt;

DigitalOut led1(LED1);

void toggle_led(void);

int main() 
{
    // Init the ticker with the address of the function (toggle_led) to be attached and the interval (100 ms)
    toggle_led_ticker_interrupt.attach(&toggle_led, 1s);
    while (true) 
    {
        // Do other things...
    }
}


void toggle_led(void) 
{
    //option 1
    // led1 = !led1;

    //option 2
    if(led == 0)
        led = 1;
    else
        led = 0;

    //option 3
    //using XOR (^) command
    //led ^...



}

