// C++ code
//
#include <Adafruit_LiquidCrystal.h>

// timers is incremented every 100ms = 0.1s
unsigned long heartbeat_timer;
unsigned long update_encoder_timer_in_ms;
unsigned long print_timer;
unsigned long lcd_update_timer;

int seconds = 0;
char lcd_buffer[16];

Adafruit_LiquidCrystal lcd_1(0);
 
void encoder_output(void);
void lcd_init(void);
void lcd_update(void);

//define pins
#define motor_M1 3
#define motor_M2 2

#define ch_A_pin 4
#define ch_B_pin 5
#define heartbeat_LED 13

unsigned int encoder_state = 0; //0 = stop, 1 = UP, 2 = DOWN
unsigned long encoder_pulse_duration_in_ms;
unsigned char encoder_counts;

void setup()
{
	lcd_init();
	Serial.begin(9600); 
	pinMode(motor_M1,INPUT);
	pinMode(motor_M2,INPUT);
	pinMode(ch_A_pin,OUTPUT);
	pinMode(ch_B_pin,OUTPUT);
	pinMode(heartbeat_LED,OUTPUT);
}

void loop()
{
	timers();
	heartbeat();
	encoder_control();
	encoder_output();
	lcd_update();
}


void lcd_init()
{
	lcd_1.begin(16, 2);
 	lcd_1.print("hello!");

}
void lcd_update()
{
	if(lcd_update_timer >= 1)
	{
		lcd_update_timer = 0;
		//lcd_1.setCursor(0, 14);
		//lcd_1.print(seconds/10);
		lcd_1.setCursor(0, 0);
		sprintf(lcd_buffer,
				"EncCnt=%d",
				encoder_counts);

		lcd_1.print(lcd_buffer);

		lcd_1.setBacklight(1);
	
		seconds += 1;		
	}

}

void encoder_control(void)
{

	// Serial.print(digitalRead(motor_M1));
	// Serial.print(digitalRead(motor_M2));

	switch(encoder_state)
	{
		case 0:
			if((digitalRead(motor_M1) == 1) && (digitalRead(motor_M2) == 0))
				encoder_state = 1;
			if((digitalRead(motor_M1) == 0) && (digitalRead(motor_M2) == 1))
				encoder_state = 2;
			break;
		case 1://GO UP
			if(digitalRead(motor_M1) == 0)
				encoder_state = 0;
			if(digitalRead(motor_M2) == 1)
				encoder_state = 0;
			break;
		case 2://GO DN
			if(digitalRead(motor_M2) == 0)
				encoder_state = 0;
			if(digitalRead(motor_M1) == 1)
				encoder_state = 0;
			break;
		default:
			encoder_state = 0;
			break;

	}

}




void timers(void)
{
	static unsigned long ms_runtime;
	static unsigned int one_ms_timer;

	if(millis() > ms_runtime)
	{
		ms_runtime++;
		one_ms_timer++;  
		update_encoder_timer_in_ms++;//this is ms timer
	}
	else if(ms_runtime > millis())
		ms_runtime = millis();

	if(one_ms_timer > 99) // every 100 ms
	{
		one_ms_timer = 0;
		heartbeat_timer++;
		print_timer++;
		lcd_update_timer++;
	}
}

void heartbeat(void) 
{
	if(heartbeat_timer<10)			//first 10 (10 times 100 ms = 1s)
		digitalWrite(heartbeat_LED,HIGH); 
	else
	{
		digitalWrite(heartbeat_LED,LOW);
		if(heartbeat_timer>=20) //(between 10 and 20 - another 1 s)
			heartbeat_timer = 0;	//When does the timer get cleared?
	}
}

void encoder_output(void)
{

	static unsigned char encoder_pulses_state;

	unsigned long MOTOR_RPM = 60;
	unsigned long ENCDR_PPR = 4;
	//								1000 (ms)
	encoder_pulse_duration_in_ms = (1000 * MOTOR_RPM) / 60 / ENCDR_PPR;
	//
	//encoder_pulse_duration_in_ms = 1000 * (60/60) / 20
	//						 	   = 1000 *   1 rps / 20

	if(print_timer > 10)
	{	
		print_timer = 0;
		Serial.print("encoder_pulse_duration_in_ms  ");
		Serial.println(encoder_pulse_duration_in_ms);
		Serial.print("update_encoder_timer_in_ms  ");
		Serial.println(update_encoder_timer_in_ms);
		Serial.print("encoder_state  ");
		Serial.println(encoder_state);
		Serial.print("encoder_counts  ");
		Serial.println(encoder_counts);
		Serial.println("------------------------------------------");
	}

	if(encoder_state == 0)
	{
		update_encoder_timer_in_ms = 0;
	}

	if(update_encoder_timer_in_ms >= encoder_pulse_duration_in_ms)
	{
		update_encoder_timer_in_ms = 0;
		if(encoder_state == 1)
		{
			encoder_counts++;
		}
		else if(encoder_state == 2)
		{
			encoder_counts--;
		}
	}

	encoder_pulses_state = encoder_counts % 4;


	switch(encoder_pulses_state)
	{
		case 0:
			digitalWrite(ch_A_pin,LOW);
			digitalWrite(ch_B_pin,LOW);
			break;
		case 1:
			digitalWrite(ch_A_pin,HIGH);
			digitalWrite(ch_B_pin,LOW);
			break;
		case 2:
			digitalWrite(ch_A_pin,HIGH);
			digitalWrite(ch_B_pin,HIGH);
			break;
		case 3:
			digitalWrite(ch_A_pin,LOW);
			digitalWrite(ch_B_pin,HIGH);
			break;
	}


}