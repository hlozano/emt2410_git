#include "mbed.h"

DigitalOut led(LED1);              // same as D13 or PA_5
DigitalIn  mybutton(USER_BUTTON);  // same as        PC_13

Ticker timers_interrupt;//name your interrupt

unsigned int timer1; // dp LED timer used to blink dp in 7-segment
unsigned int timer2; // timer used for up counter in 7-segment display



//variable to control state of 7-segment display
unsigned int seven_segment_state; // 0,1,2,3,4,5,6,7,8,9,0,1,2...



void init_function(void);
void control_function(void);
void dp_led_control(void);
void seven_segment_control(void);
void timers(void);

int main(void)
{
    init_function(); // equivelant to arduino "setup()"
    while(1)
    {
        control_function(); // equivelant to arduino "loop()"
        dp_led_control();
        seven_segment_control();
    }
    return 1;
}
void init_function(void)
{
    printf("Setting up device\n");
    timers_interrupt.attach(&timers, 0.1);//call this interrupt every 0.1s
    printf("starting...\n");
}

void control_function(void)
{
    if(mybutton == 1)
    {//button is not pressed

    }
    else if(mybutton == 0)
    {//button is pressed

    }
}


void dp_led_control(void)
{
   if (timer1 < ??)
        led = 1;
    else if (timer1 < ??)
        led = 0;
    else 
        timer1 = 0; 
}


void seven_segment_control(void)
{
    if(mybutton == 1)
    {//button is not pressed
        timer2 = 0;
    }

    if(timer2 > 9)
    {
        timer2 = 0;
        if(seven_segment_state < 9)
            seven_segment_state++;
        else
            seven_segment_state = 0;
    }

    //control the segments based on seven_segment_state 

    if(seven_segment_state == 0)
        display_character_0();
    else if(seven_segment_state == 1)
        display_character_1();
    else if(seven_segment_state == 2)
        display_character_2();
    else if(seven_segment_state == 2)
        display_character_2();
    else if(seven_segment_state == 3)
        display_character_3();
    else if(seven_segment_state == 4)
        display_character_4();
    else if(seven_segment_state == 5)
        display_character_5();
    else if(seven_segment_state == 6)
        display_character_6();
    else if(seven_segment_state == 7)
        display_character_7();
    else if(seven_segment_state == 8)
        display_character_8();
    else if(seven_segment_state == 9)
        display_character_9();

}




void timers()
{
    timer1++;
    timer2++;
}

