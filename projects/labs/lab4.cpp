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
		control_function();
	}
}

void init_function(void)
{
	timers_interrupt.attach(&timers, 0.1);//call this interrupt every 0.1s
	pc.printf("Press '1' to turn LED1 ON, '0' to turn it OFF and '2' to Blink\n");
}

void control_function(void)
{
	char c = 0;
	if (pc.readable())
	{
		c = pc.getc(); // Read hyperterminal

		if (c == '0')
			led_state = 0;
		if (c == '1')
			led_state = 1;
		if (c == '2')
			led_state = 2;
	}
	if (led_state == 0)
		led = 0;
	else if (led_state == 1)
		led = 1;
	else if (led_state == 2)
	{
		flash_one_second();
	}
	if (old_led_state != led_state)
		pc.printf("State = %d\n", led_state);
	old_led_state = led_state;
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

