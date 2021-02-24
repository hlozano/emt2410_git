#include "mbed.h"

DigitalOut myled(LED1);

int main() 
{
    while(1) //1 == 1 is a boolean expression -> true
    {
        myled = 1; // LED is ON
        wait(1.0); // 1 s
        myled = 0; // LED is OFF
        wait(1.0); // 1 sec
    }
}
