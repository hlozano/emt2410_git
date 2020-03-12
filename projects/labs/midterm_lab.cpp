#include "mbed.h"
Serial pc(SERIAL_TX, SERIAL_RX);
Ticker timers_interrupt;//name your interrupt
DigitalOut led(LED1);
//define global variables
int display_state = 0;
//define global timers
int timer1 = 0; // timer to be used for seven_segment_control()
int timer2 = 0; // timer to be used for digital_point_control()
int timer3 = 0;
int timer4 = 0;

void initialization_function(void);
void seven_segment_control(void);
void digital_point_control(void);
void timers_control(void);

void display_character_0(void);
void display_character_1(void);
void display_character_2(void);
void display_character_3(void);
void display_character_4(void);
void display_character_5(void);
void display_character_6(void);
void display_character_7(void);
void display_character_8(void);
void display_character_9(void);

int main()
{
	initialization_function();
	while (1)
	{
		seven_segment_control();
		digital_point_control();
		//debug_serial_print_control();
	}
}

void initialization_function(void)
{
	timers_interrupt.attach(&timers_control, 0.1);//call this interrupt every 0.1s
	//pc.printf("Press '1' to turn LED1 ON, '0' to turn it OFF and '2' to Blink\n");
}
void seven_segment_control(void)
{

	//use timer1 to change display_state every 1s
	// display_state = 0 1 2.. 9 ...0

	if(display_state == 0)
		display_character_0();
	else if(display_state == 1)
		display_character_1();
	//...
	else //if(display_state == 9)
		display_character_9();
	 

}



void digital_point_control(void)
{
	if (timer2 < 10)
		led = 1;
	else if (timer2 < 20)
		led = 0;
	else
		timer2 = 0;
}

void timers_control()
{
	//timer1=timer + 1;
	timer1++;
	timer2++;
	timer3++;
	timer4++;
}
