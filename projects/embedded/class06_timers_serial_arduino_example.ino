unsigned long timer1; 		// timer1 		is incremented every 100ms = 0.1s
unsigned long print_timer;  // print_timer  is incremented every 100ms = 0.1s
const int LED1 = 13;
void setup()
{                
    pinMode(LED1, OUTPUT);  

}
void loop()
{
    timers();
    debug_print();
	flash_led1();
}
void debug_print()
{
	static int counter = 0;
	if(print_timer >= 20)
	{	print_timer = 0;
		//do something
		Serial.print("debugging=>");
	    Serial.println(counter);
		//reset timer
	}
}
void flash_led1() 
{
    if (timer1 < 10)
		digitalWrite(LED1,HIGH); 
    else if (timer1 < 20)
		digitalWrite(LED1,LOW);
	else
		timer1 = 0;	//When does the timer get cleared?
}
void timers(void)
{
	static unsigned long old_millis = 0; //static means it never drops the contents of this variable
	const int timers_interval = 100; // in ms

	if(millis() >= old_millis + timers_interval) // 99.99% will not go in
	{//falling inside this if statement happens every "interval # of ms
		old_millis = millis();

		timer1++; //  same as timer = timer + 1;
		print_timer++;
	}
}

