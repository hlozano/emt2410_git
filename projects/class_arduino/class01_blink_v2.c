//blink.ino
/*
  This program blinks pin 13 of the Arduino 
  (pin 13 the built-in LED)
  Using a variable simplifies code
  provides clarity
*/

//const int myled = 13;

#define myled 13

void setup()
{ 
  pinMode(myled,OUTPUT);
}
// loop
void loop()
{// loop
   digitalWrite(myled,HIGH); // 5V
   delay(1000);
   digitalWrite(myled,LOW); // 0V
   delay(1000);
}


/*
in c programming you have
int main()
{

}


//arduino did this to make things 'easier' on programmers
int main()
{
	setup();
	while(1) //loop based on a condition
	{
		loop();
	}
}
*/

void another_function(void)
{

}