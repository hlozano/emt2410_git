#include <Adafruit_LiquidCrystal.h>
// C++ code
//
#include <Adafruit_LiquidCrystal.h>

unsigned long timer1; 
unsigned long timer2; 	
unsigned long timer3; 	

unsigned long serial_print_timer; 	
unsigned long lcd_update_timer; 	
unsigned long one_second_timer_helper;


void init_lcd(void);
void timers(void);
void init_serial_port();
void serial_port_debug();


int seconds = 0;

Adafruit_LiquidCrystal lcd_1(0);

void setup()
{
  init_lcd();
  init_serial_port();
}


void init_lcd(void)
{
  lcd_1.begin(16, 2);
  lcd_1.print("hello world");
  lcd_1.setBacklight(1);
}  

void update_lcd(void)
{
  if(lcd_update_timer >= 1)
  {
    lcd_update_timer = 0;
    lcd_1.setCursor(0, 1);
    lcd_1.print(seconds);
    lcd_1.print('.');
    lcd_1.print(one_second_timer_helper);
  }
}

void loop()
{
  update_lcd();
  timers();
  serial_port_debug();
}


void init_serial_port()
{
	Serial.begin(9600);
}
void serial_port_debug(void)
{
  if(serial_print_timer>=5)
  {
    serial_print_timer = 0;
	Serial.print("Input=");
  	Serial.println(0);
  }
}


void timers(void)
{
	static unsigned long old_millis = 0; //static means it never drops the contents of this variable
	const int timers_interval = 100; // in ms

	if(millis() >= old_millis + timers_interval) // 99.99% will not go in
	{//falling inside this if statement happens every "interval # of ms
		old_millis = millis();

		timer1++; //  same as timer = timer + 1;
		timer2++;
		timer3++;
		one_second_timer_helper++;
        lcd_update_timer++;
      	serial_print_timer++;
	}
  
  if(one_second_timer_helper >= 10)
  {
    one_second_timer_helper = 0;
    seconds++;
  }
}
