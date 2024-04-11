const int LED1 = 13;

int door_state = 0;

unsigned long timer1; 			// timer1 is incremented every 100ms = 0.1s
unsigned long heartbeat_timer;  // timer1 is incremented every 100ms = 0.1s

void door_control(void);
int is_door_closed(void);
int is_door_open(void);
int is_sensor_on(void);
int lcd_control(void);
void timers(void)
void setup()
{
	//initilize inputs, memory, etc
}

void loop()
{
	timers();
	heartbeat();
	door_control();
	lcd_control();
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

 void door_control(void)
 {
 //pending implementation
 }
 int is_door_closed(void)
 {
 //pending implementation
 }
 int is_door_open(void)
 {
 //pending implementation
 }
 int is_sensor_on(void)
 {
 //pending implementation
 }
 void timers(void)
{
	//pending implementation
}
