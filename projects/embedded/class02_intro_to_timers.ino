	// CALCULATE LOOP CYCLE USING A COUNTER - Works for over a month
unsigned long ms_runtime = 0; // record the # ms the mcu has been running
unsigned long one_ms_timer = 0; //will help me track one ms intervals
								// this one keeps track of one ms intervals
								// it changes from 0 -> 999
unsigned long counter = 0;
unsigned long one_sec_counter = 0;
const int myled = 13;
void setup()
{
    Serial.begin(9600);
    pinMode(myled,OUTPUT);
}
void loop()
{
    counter++;
  
    if(millis() > ms_runtime)
	{//goes in this "if" because one millisecond has passed!
		ms_runtime = ms_runtime + 1;
		one_ms_timer = one_ms_timer + 1; //one_ms_timer++;  
	}


	 if(one_ms_timer>=1000)
	//if(one_ms_timer>=100)
	{	one_sec_counter++;
     
        if(one_sec_counter % 2 == 1) //Check if one_sec_counter is an ODD number
          digitalWrite(myled,HIGH); // 5V
		else
          digitalWrite(myled,LOW); // 0V
          
          
		one_ms_timer = 0;
		Serial.print("counter ------->  ");
        Serial.println(counter);
    	
		Serial.print("one second counter  ");
        Serial.println(one_sec_counter); 

        Serial.print("millis() returns  ");
        Serial.println(millis());
		counter = 0;
	}
}





/* Special Note
pinted 
counter 248146
millis() returns 1000 ms

If we want to calculate loop time based on these numbers:


loop time = time interval / number of cycles

=1s / 248146

= 4.029 e-6 s = 4.029 us (microseconds!!!!!!)


*/
