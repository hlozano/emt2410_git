/*		TIMERS REVIEW		*/

//DEFINE ALL TIMERS AS UNSIGNED AS VARIABLES	

unsigned long timer1; 		// timer1 		is incremented every 100ms = 0.1s
unsigned long timer2; 		// timer2 		is incremented every 100ms = 0.1s
unsigned long timer3; 		// timer3 		is incremented every 100ms = 0.1s
unsigned long print_timer;  // print_timer  is incremented every 100ms = 0.1s


const int LED1 = 11;
const int LED2 = 12;
const int LED3 = 13;

void setup()
{                
    pinMode(LED1, OUTPUT);   
    pinMode(LED2, OUTPUT);   
    pinMode(LED3, OUTPUT);   

}
void loop()
{
    timers();
    debug_print();
	flash_led1();
	flash_led2();
	flash_led3();

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
    if (timer1 < 10)//0,1,2,3,4,5,6,7,8,9,
    {
		digitalWrite(LED1,HIGH); 
    }
    else if (timer1 < 20)//10,11,12,13,14,15,16,17,18,19,
	{
		digitalWrite(LED1,LOW);
	}
	else
	{
		timer1 = 0;	//When does the timer get cleared?
	}
}
void flash_led2()
{
	if(timer2<15)			//Check timer and execute action 
		digitalWrite(LED2,HIGH); 
	else
	{
		digitalWrite(LED2,LOW);
		if(timer2>=30)
			timer2 = 0;	//When does the timer get cleared?
	}
}
void flash_led3()
{
	if(timer3<50)			//Check timer and execute action 
		digitalWrite(LED3,HIGH); 
	else
	{
		digitalWrite(LED3,LOW);
		if(timer3>=100)
			timer3 = 0;	//When does the timer get cleared?
	}
}

/*
millis() function is built in the Arduino IDE/compiler
ms_runtime and one_ms_timer
were variables defined by US to help us keep track of 
timing... meaning how many milliseconds have gone by
*/

/*
lets take a look at a pseudocode to understand the function below

if one millisecond has passed then
	advance some variables to mark/count one millisecond
	*1ms counting*[programs falls in this part ~ once every 1 ms]
else if the max value of milliseconds is reached
	clear everything back to zero to avoid a overflow
else (this one is implicit)
	do nothing but wait patiently AND dont delay

if variable that increase in *1ms counting* section is more than 99
	which means that it counted 100 times 
	we use this as a tick of 100 ms 
	then


	increase all those variables that you are using to time events
	//those variables should have the word timer or letters tmr in them

else // this is not written down but just implicit
	when the if is not true, we do nothing.
	do nothing but wait patiently AND dont delay

*/


void timers(void)
{
	static unsigned long ms_runtime = 0; //static means it never drops the contents of this variable
	static int one_ms_timer = 0; 
    int i;

	if(millis() > ms_runtime) // 99.9% of the time will be the same as millis
	{//falling inside this if statement happens every one ms
		ms_runtime = ms_runtime + 1;
		one_ms_timer++;  
	}

	if(one_ms_timer > 99) //0-1-2-3-4-...98-99->0
	{ // our choice for 99 gives us increments of 100 ms
		timer1++; //  same as timer = timer + 1;
		timer2++;
		timer3++;
		print_timer++;
		one_ms_timer = 0;
	}
	// this means that
	// if timer1 is 10....... = 1s
	// if timer1 is 100...... = 10s
	// if timer1 is 1000..... = 100s
	// if timer1 is 10000.... = 1000s
	// if timer1 is 36000.... = 3600s = 1 hour
	//

}
void timers_2(void)
{
	static unsigned long old_millis = 0; //static means it never drops the contents of this variable
	const int timers_interval = 100; // in ms

	if(millis() >= old_millis + timers_interval) // 99.99% will not go in
	{//falling inside this if statement happens every "interval # of ms
		old_millis = millis();

		timer1++; //  same as timer = timer + 1;
		timer2++;
		timer3++;
		print_timer++;
	}
}

