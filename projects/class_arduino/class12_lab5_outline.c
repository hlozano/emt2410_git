
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void update_lcd(void);
void heartbeat(void);
void timers(void);

int is_door_closed(void);
int is_door_open(void);
int is_sensor_on(void); 

const int LED_pin = 13;
const int open_signal_pin = 8;
const int closed_signal_pin = 9;
const int sensor_pin = 10;
const int close_output_pin = 7;
const int open_output_pin = 6;


int door_state = 0;

unsigned long int timer1;
unsigned long int timer2;
unsigned long int heartbeat_timer;

void setup() 
{
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("hello, world!");
  pinMode(sensor_pin,INPUT);  
  pinMode(LED_pin,OUTPUT);
}

void loop()
{
  door_control();
  update_lcd();
  heartbeat();
  timers();
}
void door_control(void)
{
  if(door_state == 0)
  {
    digitalWrite(open_output_pin,LOW);
    digitalWrite(close_output_pin,LOW);    
    if(is_sensor_on() == 1)
      door_state = 1;

  }
  else if(door_state == 1)
  {
      digitalWrite(open_output_pin,HIGH);
      digitalWrite(close_output_pin,LOW);
      if(is_door_open() == 1)
          door_state = 2;

  } 
  else if(door_state == 2)
  {
      digitalWrite(open_output_pin,LOW);
      digitalWrite(close_output_pin,LOW);
  } 
  else if(door_state == 3)
  {
      digitalWrite(open_output_pin,LOW);
      digitalWrite(close_output_pin,HIGH);

  } 
}

void update_lcd(void)
{
}

void heartbeat(void) 
{
  if(heartbeat_timer<10)      //first 10 (10 times 100 ms = 1s)
    digitalWrite(LED_pin,HIGH); 
  else
  {
    digitalWrite(LED_pin,LOW);
    if(heartbeat_timer>=20) //(between 10 and 20 - another 1 s)
      heartbeat_timer = 0;  //When does the timer get cleared?
  }
}


int is_sensor_on(void)
{
    return digitalRead(sensor_pin);
}
int is_door_open(void)
{ //pending implementation
  //return value based on input for lab 5
  //return value based on encoder count for final

}

int is_door_closed(void)
{ //pending implementation
  //return value based on input for lab 5
  //return value based on encoder count for final

}

void timers(void)
{
    static unsigned long ms_runtime = 0;
    static int one_ms_timer = 0; 

    if(millis() > ms_runtime)
    {
        ms_runtime++;
        one_ms_timer++;  
    }

    if(one_ms_timer > 99)
    { // our choice for 99 gives us increments of 100 ms
        timer1++;
        timer2++;
        heartbeat_timer++;
        one_ms_timer = 0;
    }
}
