
unsigned int timer1;
unsigned int heartbeat_timer;


const int LED1 = 13;

int door_state = 0;

unsigned long timer1; // timer1 is incremented every 100ms = 0.1s
 
 void read_encoder(void);
 void door_control(void);
 void lcd_update(void);

 int is_door_closed(void);
 int is_door_open(void);
 int is_user_detected(void);


void setup()
{
	//initilize inputs, memory, etc
}

void loop()
{
	timers();
	heartbeat();
	door_control();
	read_encoder();
	lcd_update();
}

void door_control(void)
{
	switch(door_state)
	{
		case 0: //closed
			if(is_user_detected() == 1)
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
			if(timer1 >= 50)
				door_state = 3;
			if(is_user_detected() == 1)
				timer1 = 0;
			break;

		case 3: // closing
			if(is_door_closed() == 1)
				door_state = 0;
			if(is_user_detected() == 1)
			{
				door_state = 1; // go to opening state
			}
			break;

		default:
			door_state = 0;
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
	}
	else if(ms_runtime > millis())
		ms_runtime = millis();

	if(one_ms_timer > 99) // every 100 ms
	{
		one_ms_timer = 0;
		heartbeat_timer++;
		timer1++;
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