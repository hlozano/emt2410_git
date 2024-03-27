//USING MACROS

#define myLEDpin   13
#define TIME1000ms 1000

void setup()
{ 
  pinMode(myLEDpin,OUTPUT);
}
// loop
void loop()
{// loop
   digitalWrite(myLEDpin,HIGH); // 5V
   delay(TIME1000ms);
   digitalWrite(myLEDpin,LOW); // 0V
   delay(TIME1000ms);
}


