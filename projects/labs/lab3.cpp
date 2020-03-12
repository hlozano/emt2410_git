#include "mbed.h"

Serial pc(SERIAL_TX, SERIAL_RX);
DigitalOut led(LED1);
int led_state = 0;

void init_function(void);
void control_function(void);

int main(void)
{
    init_function();
    while(1)
    {
        control_function();
    }
    return 1;
}
void init_function(void)
{
    pc.printf("Press '1' to turn LED1 ON, '0' to turn it OFF and '2' to Blink\n");
}

void control_function(void)
{
    static int old_led_state;
    char c = 0;
    if(pc.readable())
    {
        c = pc.getc(); // Read hyperterminal
        
        if (c == '0')
            led_state = 0;
        if (c == '1')
            led_state = 1;
        if (c == '2') 
            led_state = 2;
    }
    if(led_state == 0)
        led = 0;
    else if(led_state == 1)
        led = 1;
    else if(led_state == 2)
    {
         wait(0.5);
         led = 1;
         wait(0.5);
         led = 0;
    }
    if(old_led_state != led_state)
        pc.printf("State = %d\n",led_state);   
    old_led_state = led_state;
}
