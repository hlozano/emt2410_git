#include "mbed.h"
#include "BufferedSerial.h"
#include "Watchdog.h"
#include <cstdio>

#define WAIT_TIME_MS 3000 

DigitalOut led(LED1);
DigitalOut a(PA_6);
BufferedSerial serial_port(USBTX,USBRX,9600);
Ticker timers_interrupt;

// global variables
int led_state = 2;
int old_led_state = 0;
int timer1 = 0;

char line[50];
char buf[50] = {0};
char c;
void init_function(void);
void control_function(void);
void receive_commands(void);
void control_led(void);
void flash_led(void);
void flash_led_sleeper(void);
void send_status(void);
void timers(void);
void pet_dog(void);

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
    timers_interrupt.attach(&timers,100ms);
    serial_port.set_baud(9600);
    serial_port.set_blocking(0);    
    serial_port.set_format(
        /* bits */          8,
        /* parity */        BufferedSerial::None,
        /* stop bit */      1
    );     
    sprintf(line,"Press '0' to turn LED1 ON\n");
    serial_port.write(line,27);
    sprintf(line,"Press '1' to turn LED OFF\n");
    serial_port.write(line,27);
    sprintf(line,"Press '2' to blink LED   \n");
    serial_port.write(line,27);
    sprintf(line,"Press '3' to sleep/blink \n");
    serial_port.write(line,27);
    // Configure the watchdog timer with a 5-second timeout
    Watchdog::get_instance().start(2000);

}
void control_function(void)
{
    receive_commands();
    control_led();
    send_status();
    pet_dog();
}
void receive_commands()
{
    if(serial_port.readable())
    {
        serial_port.read(buf,sizeof(buf));
        c=buf[0];
        if (c == '0')
            led_state = 0;
        else if (c == '1')
            led_state = 1;
        else if (c == '2') 
            led_state = 2;
        else if (c == '3') 
            led_state = 3;
        else
            led_state = 0;           
    }
}
void control_led()
{
    if(led_state == 0)
        led = 0;
    else if(led_state == 1)
        led = 1;
    else if(led_state == 2)
    {
        flash_led();
    }
    else if(led_state == 3)
    {
        flash_led_sleeper();
    }
}    
void flash_led()
{
    if (timer1 < 10)
        led = 1;
    else if (timer1 < 20)
        led = 0;
    else
        timer1 = 0;      
}
void flash_led_sleeper()
{
    led=!led;
    thread_sleep_for(WAIT_TIME_MS);
}

void send_status(void)
{
    if(old_led_state != led_state)
    {
        sprintf(line,"led_state=%d\n",led_state);
        serial_port.write(line,12);   
    }
    old_led_state = led_state;
}
void timers()
{
    timer1++;
}
void pet_dog(void)
{
    Watchdog::get_instance().kick();    
}