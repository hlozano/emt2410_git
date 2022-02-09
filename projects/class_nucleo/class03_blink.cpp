#include "mbed.h"

Ticker toggle_led_ticker_interrupt;

DigitalOut led1(LED1);

void toggle_led(void);

int main() 
{
    // Init the ticker with the address of the function (toggle_led) to be attached and the interval (100 ms)
    toggle_led_ticker_interrupt.attach(&toggle_led, 1.0);
    while (true) 
    {
        // Do other things...
    }
}


void toggle_led(void) 
{
    //led1 = !led1;
    if (led1 == 1)
        led1 = 0;
    else
        led1 = 1;
}

