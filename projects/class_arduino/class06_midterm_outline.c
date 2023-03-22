
#define LEDpin 13
#define USER_BUTTON 2

unsigned long timer1; // dp LED timer used to blink dp in 7-segment
unsigned long timer2; // timer used for up counter in 7-segment display

//variable to control state of 7-segment
unsigned int seven_segment_state; // 0,1,2,3,4,5,6,7,8,9,0,1,2...


void control_function(void);
void dp_led_control(void);
void seven_segment_control(void);

void timers(void);

void setup()
{
  Serial.begin(9600);
  pinMode(LEDpin, OUTPUT);
  pinMode(USER_BUTTON, INPUT_PULLUP);
}

void loop()
{
    timers();
    dp_led_control();
    seven_segment_control();
}


void dp_led_control(void)
{
   if (timer1 < ?)
        digitalWrite(LEDpin,0);
    else if (timer1 < /?)
        digitalWrite(LEDpin,1);
    else 
        timer1 = 0; 
}

void seven_segment_control(void)
{
    if(digitalRead(USER_BUTTON) == 1)
    {//button is not pressed
        timer2 = 0;
    }

    if(timer2 >= 10)
    {   
        timer2 = 0;
        Serial.println(seven_segment_state); 
        if(seven_segment_state < 9)
            seven_segment_state++;
        else
            seven_segment_state = 0;

    }
    //control the segments based on seven_segment_state 

}


void timers(void)
{
  static unsigned long millis_old = 0;// track the # ms the mcu has been running
  unsigned interval = 100;  // meaning every 100ms

  if(millis() >= millis_old + interval)
  {//it falls into this section once every 100ms
    millis_old = millis_old + interval;
    timer1++;
    timer2++;
    //_<<--
  }

  if(millis_old > millis())//if you run for a very long time, correct overflow
    millis_old = millis();  

}



     