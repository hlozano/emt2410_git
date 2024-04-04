#include "mbed.h"
#include "BufferedSerial.h"
#include "Watchdog.h"
#include <cstdio>
#include "TextLCD.h"

//#define WAIT_TIME_MS 3000 

DigitalOut led(LED1);

DIgitalIn  button(USER_BUTTON); // same as in lab1
DigitalOut a(PA_10); // same as D2
DigitalOut b(PB_3);  // same as D3
DigitalOut c(PX_X);
DigitalOut d(PX_X);
DigitalOut e(PX_X);
DigitalOut f(PX_X);
DigitalOut g(PX_X);
DigitalOut dp(PX_X);

TextLCD lcd(PF_3, PD_15, PE_14, PE_11, PE_9, PG_12);

BufferedSerial serial_port(USBTX,USBRX,9600);
Ticker timers_interrupt;

// global variables
int system_state = 0;
unsigned char c;
unsigned long heartbeat_timer;
unsigned long button_timer;
unsigned long lcd_update_timer;

char line[50];
char buf[50] = {0};

char LCD_Display_Lines[2][17] = {
                                    "First LinE      ",
                                    "Second Line     ",
};

void read_inputs(void);
void heartbeat_led(void);
void control_seven_segment(void);
void lcd_update (void);
void send_status(void);
void timers(void);
void pet_dog(void);

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
    sprintf(line,"Midterm Solution\n");
    serial_port.write(line,27);
    sprintf(line,"Press button to resume counter\n");
    serial_port.write(line,27);

    // Configure the watchdog timer with a 5-second timeout
    Watchdog::get_instance().start(2000);

    //initializeLCD
    lcd.locate(0, 0);
    lcd.write(LCD_Display_Lines[0],16);
    lcd.locate(0, 1);
    lcd.write(LCD_Display_Lines[1],16);

}
void control_function(void)
{
      read_inputs();
      heartbeat_led();
      control_seven_segment();
      send_status(); 
      lcd_update(); 
      pet_dog();
}

void read_inputs(void)
{
 // read input.... and update state variable (increment)
}
void control_led()
{
  switch(system_state)
  {
    case 0:

      break;
    case 1:

      break;
      //...

    case 9:
      break;

    default:
      system_state = 0;
  }
}
void control_seven_segment()
{

}


void heartbeat_led()
{
    if (heartbeat_timer < 1)
      dp = 1;
    else if (heartbeat_timer < 2)
      dp = 0;
    else
        heartbeat_timer = 0;      
}
void timers()
{
    heartbeat_timer++;
    button_timer++;
    lcd_update_timer++;
}
void pet_dog(void)
{
    Watchdog::get_instance().kick();    
}