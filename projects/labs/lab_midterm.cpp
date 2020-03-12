#include "mbed.h"
Serial pc(SERIAL_TX, SERIAL_RX);
Ticker timers_interrupt;//name your interrupt
DigitalOut led(LED1);
//define global variables
int led_state = 0;
int old_led_state = 0;
//define global timers
int timer1 = 0;

void init_function(void);
void control_function(void);
void timers(void);
void flash_one_second(void);

int main()
{
	init_function();
	while (1)
	{
		seven_segment_control();
		digital_point_control();
	}
}

void init_function(void)
{
	timers_interrupt.attach(&timers, 0.1);//call this interrupt every 0.1s
	pc.printf("Press '1' to turn LED1 ON, '0' to turn it OFF and '2' to Blink\n");
}



void timers()
{
	//timer1 timer + 1;
	timer++;
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

