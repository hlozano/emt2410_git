unsigned long timer1;
unsigned long timer2;

void setup()
{
    unsigned char bits;
	Serial.begin(9600);
    pinMode(13,OUTPUT);

	bits = 0xFF; //0b 1111 1111
	Serial.println(bits);
	bits = bits ^ 0x04; // high bit flips bit
    //0b 1111 1111
    //0b 0000 0100 <-mask
    //0b 1111 1011 <-0xFB
  Serial.println(bits); //0xFB
  bits = bits ^ 0x04; // high bit flips bit
  Serial.println(bits); //0x??

	bits = bits ^ 0x04;  //high bit flips bit
    Serial.println(bits);
  
  
  // A XOR 0 = A
  // A XOR 1 = NOT A


}
void loop()
{
  static bool A;
	timers();
    if(timer1 >=10)
    {
      digitalWrite(13,A);
      timer1 = 0;
      A = A ^ 1;
    }
}

void timers(void)
{
  static unsigned long millis_old = 0;
  unsigned interval = 100; 

  if(millis() >= millis_old + interval)
  {//it falls into this section once every 100ms
    millis_old = millis_old + interval;
    timer1++;
    timer2++;
    //_<<--
  }

  if(millis_old > millis())
    millis_old = millis();  

}