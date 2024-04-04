#include <avr/wdt.h>
#include <Adafruit_LiquidCrystal.h>
int hundred_milliseconds = 0;
int seconds = 0;
// global variables
const int input_pin=12;
// Common Cathode 7-segment pins
const int pin_A = 2;
const int pin_B = 3;
const int pin_C = 4;
const int pin_D = 5;
const int pin_E = 6;
const int pin_F = 7;
const int pin_G = 8;
const int pin_DP = 13;


int system_state = 0;
unsigned char c;
unsigned long heartbeat_timer;
unsigned long button_timer;
unsigned long lcd_update_timer;

Adafruit_LiquidCrystal lcd_1(0);

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


void setup() 
{
  pinMode(pin_DP, OUTPUT);
  //init all output pins
  pinMode(input_pin,INPUT_PULLUP);
  Serial.begin(9600);
  Serial.println("midterm solution");
  Serial.println("Press button to resume counter");

  wdt_enable(WDTO_120MS); //120ms
  //lcd setup
  lcd_1.begin(16, 2);
  lcd_1.print("seconds=");
  lcd_1.setCursor(0, 1);
  lcd_1.print("system_state=");
  
  lcd_1.setBacklight(1);
}

void loop() 
{
  read_inputs();
  heartbeat_led();
  control_seven_segment();
  send_status(); 
  lcd_update(); 
  pet_dog();
  timers();
}

void read_inputs(void)
{
 // read input.... and update state variable
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
      system_state = 0;s
  }
}
void heartbeat_led()
{
    if (heartbeat_timer < 1)
      digitalWrite(pin_DP, HIGH);
    else if (heartbeat_timer < 2)
      digitalWrite(pin_DP, LOW);
    else
        heartbeat_timer = 0;      
}

void control_seven_segment()
{

}

void lcd_update (void)
{
  if(lcd_update_timer >= 10)
  {
    lcd_update_timer = 0;
   lcd_1.setCursor(13, 0);
   lcd_1.print(seconds);    
   lcd_1.setCursor(13, 1);
   lcd_1.print(system_state);    
  }

}
void send_status(void)
{

}

void pet_dog(void)
{
  wdt_reset(); // Reset the watchdog timer (works as "kick" a.k.a. 'pet')
}
void timers(void)
{
  static unsigned long old_millis = 0; //static means it never drops the contents of this variable
  const int timers_interval = 100; // in ms

  if(millis() >= old_millis + timers_interval) // 99.99% will not go in
  {//falling inside this if statement happens every "interval # of ms
    old_millis = millis();

    heartbeat_timer++; //  same as timer = timer + 1;
    button_timer++;
    hundred_milliseconds++;
    lcd_update_timer++;
    seconds = hundred_milliseconds / 10;
  }


}

void display_character_0(void)
{
  digitalWrite(pin_A,HIGH);
  digitalWrite(pin_B,HIGH);
  digitalWrite(pin_C,HIGH);
  digitalWrite(pin_D,HIGH);
  digitalWrite(pin_E,HIGH);
  digitalWrite(pin_F,HIGH);
  digitalWrite(pin_G,LOW);
}
void display_character_1(void)
{
  //to be completed by students
}
void display_character_2(void)
{
  //to be completed by students
}
void display_character_3(void)
{
  //to be completed by students
}
void display_character_4(void)
{
  //to be completed by students
}
void display_character_5(void)
{
  //to be completed by students
}
void display_character_6(void)
{
  //to be completed by students
}
void display_character_7(void)
{
  //to be completed by students
}
void display_character_8(void)
{
  //to be completed by students
}
void display_character_9(void)
{
  //to be completed by students
}

s