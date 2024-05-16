#include <Adafruit_LiquidCrystal.h>

#define ENCODER_FEEDBACK 1

const int LED1 = 13;
char lcd_buffer[16];
int seconds = 0;

int door_state = 0;
int Door_is_open_pin = 8;
int Door_is_closed_pin = 9;
int Motion_detected_pin = 10;

int Motor_open_pin = 6;
int Motor_close_pin = 7;

int ch_A_pin = 4;
int ch_B_pin = 5;
unsigned int encoder_pulses_state = 0; 
unsigned int encoder_counts;


unsigned long timer1; 			// timer1 is incremented every 100ms = 0.1s
unsigned long heartbeat_timer;  // timer1 is incremented every 100ms = 0.1s
unsigned long lcd_update_timer;

Adafruit_LiquidCrystal lcd_1(0);

void door_control(void);
void motor_control(void);void timers(void);
void lcd_init(void);
void io_init(void);
void lcd_update(void);

int is_door_closed(void);
int is_door_open(void);

int is_sensor_on(void);
void encoder_read(void);


void setup()
{
	io_init();
	lcd_init();
}


void loop()
{
	timers();
	heartbeat();
	door_control();
 	motor_control();
	lcd_update();
	encoder_read();
}

void encoder_read()
{
	int current_state = 0;
	if((digitalRead(ch_B_pin) == 0) && (digitalRead(ch_A_pin) == 0))
	{
		current_state = 0;
	} 
	else if((digitalRead(ch_B_pin) == 0) && (digitalRead(ch_A_pin) == 1))
	{
		current_state = 1;
	} 
	else if((digitalRead(ch_B_pin) == 1) && (digitalRead(ch_A_pin) == 1))
	{
		current_state = 3;
	} 
	else if((digitalRead(ch_B_pin) == 1) && (digitalRead(ch_A_pin) == 0))
	{
		current_state = 2;
	} 

	if(current_state != encoder_pulses_state)
	{
		switch(encoder_pulses_state)
		{
			case 0:
				if(current_state == 1)
					encoder_counts++;
				if(current_state == 2)
					encoder_counts--;
				break;
			case 1:
				if(current_state == 3)
					encoder_counts++;

				if(current_state == 0)
					encoder_counts--;
				break;
			case 3:
				if(current_state == 2)
					encoder_counts++;
				if(current_state == 1)
					encoder_counts--;

				break;			
			case 2:
				if(current_state == 0)
					encoder_counts++;
				 if(current_state == 3)
				 	encoder_counts--;


				break;

		}
	}
	
	encoder_pulses_state = current_state;
}

void lcd_init()
{
  lcd_1.begin(16, 2);
  lcd_1.print("hello world T=");
}

void io_init()
{
  pinMode(Door_is_open_pin, INPUT);
  pinMode(Door_is_closed_pin, INPUT);
  pinMode(Motion_detected_pin, INPUT);

  pinMode(Motor_open_pin,OUTPUT);
  pinMode(Motor_close_pin,OUTPUT);

  //encoder signals
	pinMode(ch_A_pin,INPUT);
	pinMode(ch_B_pin,INPUT);

 
}
void lcd_update()
{

	if(lcd_update_timer >= 1)
	{
		lcd_update_timer = 0;
		lcd_1.setCursor(0, 0);
		sprintf(lcd_buffer,
				"State=%d Enc=%d   ",
				door_state,encoder_counts);

		lcd_1.print(lcd_buffer);
		
		lcd_1.setCursor(0, 1);
		sprintf(lcd_buffer,
				"Oi%dCi%d|X%d|Oo%dCo%d",
				is_door_open(),
				is_door_closed(),
				is_sensor_on(),
                digitalRead(Motor_open_pin),
                digitalRead(Motor_close_pin)
                );
		
		lcd_1.print(lcd_buffer);

		lcd_1.setBacklight(1);
		//lcd_1.setBacklight(0);
		seconds += 1;		
	}

}
void door_control(void)
{
	switch(door_state)
	{
		case 0: //closed
			if(is_sensor_on() == 1)
			{	//go to opening
				door_state = 1;
			}
			break;
		case 1: // opening
			if(is_door_open() == 1)
			{
				door_state = 2;
				timer1 = 0;
			}
			break;
		case 2: // open
			if(timer1>= 50)
				door_state = 3;
			if(is_sensor_on() == 1)
				timer1 = 0;			
			break;
		case 3: // closing
			if(is_door_closed() == 1)
				door_state = 0;
			if(is_sensor_on() == 1)
			{
				door_state = 1; // go to opening state
			}
			break;
		default:
			door_state = 0;
			break;
	}
}

void heartbeat() 
{
	if(heartbeat_timer<10)			//first 10 (10 times 100 ms = 1s)
		digitalWrite(LED1,HIGH); 
	else
	{
		digitalWrite(LED1,LOW);
		if(heartbeat_timer>=20) //(between 10 and 20 - another 1 s)
			heartbeat_timer = 0;	//When does the timer get cleared?
	}
}

 void motor_control(void)
 {

 	switch(door_state)
 	{
	 	case 0:
	 		digitalWrite(Motor_open_pin,0);
	 		digitalWrite(Motor_close_pin,0);
	 		break;
	 	case 1:
	 		digitalWrite(Motor_open_pin,1);
	 		digitalWrite(Motor_close_pin,0);
	 		break;
	 	case 2:
	 		digitalWrite(Motor_open_pin,0);
	 		digitalWrite(Motor_close_pin,0);
	 		break;
	 	case 3:
	 		digitalWrite(Motor_open_pin,0);
	 		digitalWrite(Motor_close_pin,1);
	 		break;
	 	default:
	 		digitalWrite(Motor_open_pin,0);
	 		digitalWrite(Motor_close_pin,0);
	 		break;



 	}
 	
 }


#if (ENCODER_FEEDBACK == 1)

 int is_door_closed(void)
 {
    return (encoder_counts <= 10);
 }
 int is_door_open(void)
 {
 		return (encoder_counts >= 100);
 }

#else
 int is_door_closed(void)
 {
    return digitalRead(Door_is_closed_pin);
 }
 int is_door_open(void)
 {
	return digitalRead(Door_is_open_pin);
 }
#endif


 int is_sensor_on(void)
 {
	return digitalRead(Motion_detected_pin);
 }
void timers(void)
{
	static unsigned long old_millis = 0; //static means it never drops the contents of this variable
	const int timers_interval = 100; // in ms

	if(millis() >= old_millis + timers_interval) // 99.99% will not go in
	{//falling inside this if statement happens every "interval # of ms
		old_millis = millis();

		timer1++; //  same as timer = timer + 1;
		heartbeat_timer++;
		lcd_update_timer++;
	}
}
sx