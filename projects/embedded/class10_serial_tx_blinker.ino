/*		MCU # 1 		MASTER			*/
//DEFINE ALL TIMERS AS UNSIGNED AS VARIABLES	
#define USE_I2C_LCD 1

#if USE_I2C_LCD == 1
	#include <Adafruit_LiquidCrystal.h>
	Adafruit_LiquidCrystal lcd_1(0);
#endif

unsigned long master_tx_timer; // master_tx_timer is incremented every 100ms = 0.1s
unsigned long update_lcd_timer; // update_lcd_timer is incremented every 100ms = 0.1s
unsigned long helper_second_timer;


int blink_rate = 0;
char tx_data = '0';

int send_first_packet = 1;
int seconds;

#if USE_I2C_LCD == 1
	void update_lcd(void)
	{ 
		if(update_lcd_timer > 9)
		{
		  lcd_1.setCursor(0, 1);
		  lcd_1.print(seconds);
		  lcd_1.setCursor(10, 1);
		  lcd_1.print(tx_data);
		  update_lcd_timer = 0;
		}
	}
#else
	void update_lcd(void){}
#endif

void setup()
{              
#if USE_I2C_LCD	== 1
	lcd_1.setBacklight(1);
	lcd_1.begin(16, 2);
	lcd_1.print("hello world");
#endif
	Serial.begin(9600);  
}
void loop()
{
    timers();
	if((master_tx_timer>100) || (send_first_packet == 1)) // every 10 seconds.... 0 ,1,2,3,4,5,0,1,2,3,4,5
	{
		send_first_packet = 0;
		master_send_command();
	}
	master_receive_reponse();
	update_lcd();
}

void master_receive_reponse()
{
	if (Serial.available() > 0) 
	{
		//process the data recieved from the slave
	}
}

void master_send_command(void)
{
	master_tx_timer = 0;
	tx_data = '0'+ blink_rate;
	Serial.print(tx_data);// '0', '1' , '2' .. '5' '0'
	blink_rate++;
	if(blink_rate>5)
		blink_rate = 0;
}

void timers(void)
{
	static unsigned long ms_runtime;
	static int one_ms_timer;

	if(millis() > ms_runtime)
	{
		ms_runtime++;
		one_ms_timer++;  
	}
	else if(ms_runtime > millis())
		ms_runtime = millis();

	if(one_ms_timer > 99)
	{
		master_tx_timer++;
		update_lcd_timer++;
		helper_second_timer++;
		one_ms_timer = 0;
	}
	if(helper_second_timer > 9)
	{
		seconds++;
		helper_second_timer = 0;

	}

}



/*
#include <Adafruit_LiquidCrystal.h>

int seconds = 0;

Adafruit_LiquidCrystal lcd_1(0);

void setup()
{
  lcd_1.begin(16, 2);

  lcd_1.print("hello world");
}

void loop()
{
  lcd_1.setCursor(0, 1);
  lcd_1.print(seconds);
  lcd_1.setBacklight(1);
  delay(500); // Wait for 500 millisecond(s)
  //lcd_1.setBacklight(0);
  delay(500); // Wait for 500 millisecond(s)
  seconds += 1;
}

*/
