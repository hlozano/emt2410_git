//example of a blinking led
/*
this is a 
multiline
comment
*/

#include "mbed.h"
#define SLEEP_TIME_MS 1000 
DigitalOut myled(LED1);

int main() 
{
    printf("This is the bare metal blinky example running on Mbed OS %d.%d.%d.\n", MBED_MAJOR_VERSION, MBED_MINOR_VERSION, MBED_PATCH_VERSION);
    while(1) //1 == 1 is a boolean expression -> true
    {
        myled = 1; // LED is ON
        thread_sleep_for(SLEEP_TIME_MS ); // 1 sec 
        myled = 0; // LED is OFF
        thread_sleep_for(SLEEP_TIME_MS ); // 1 sec
/*
        //older version
        myled = 1; // LED is ON
        wait(1.0); // 1 s
        myled = 0; // LED is OFF
        wait(1.0); // 1 sec
*/        
    }
}
