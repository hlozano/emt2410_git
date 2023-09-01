#include "mbed.h"

/*------------------------------------------------------------------------------
Before to use this example, ensure that you an hyperterminal installed on your
computer. More info here: https://developer.mbed.org/handbook/Terminals
-------------------------------------------------------------------------------*/

#define WAIT_TIME_MS 500 
DigitalOut led1(LED1);

int main()
{
    int i = 1;
    printf("This is the bare metal blinky example running on Mbed OS %d.%d.%d.\n", MBED_MAJOR_VERSION, MBED_MINOR_VERSION, MBED_PATCH_VERSION);


    printf("Hello World !\n");

    while(1) {
        led1 = 0;
        thread_sleep_for(WAIT_TIME_MS);
        printf("This program runs for %d seconds.\n", i++);
        led1 = 1;
        thread_sleep_for(WAIT_TIME_MS);  
        printf("This program runs for %d seconds.\n", i++);
    }
}
