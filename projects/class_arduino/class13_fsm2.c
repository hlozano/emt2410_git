// C++ code
//

int L1 = 10;
int L2 = 11;
int L3 = 12;
const int TRANSTION_TIME = 20;
const int TRANSTION_TIME_LONG = 40;
const int TRANSTION_TIME_QUICK = 10;


int state = 0;

unsigned long timer1 = 0;
unsigned long heartbeat_timer = 0;

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(L3, OUTPUT);
}

void loop()
{
  timers();
  heartbeat();
  
  switch (state)
  {


/*    case 0:
      digitalWrite(L1, HIGH);
      digitalWrite(L2, LOW);
      digitalWrite(L3, LOW);
    
      if (timer1 >= TRANSTION_TIME)
      {
        state = 1;
        timer1 = 0;
      }
      break;*/

      /*
    case 0:
      digitalWrite(L1, HIGH);
      digitalWrite(L2, LOW);
      digitalWrite(L3, LOW);
    
      if (traffic_sensor == 1) // digitalRead required here
      {
        if (timer1 >= TRANSTION_TIME_LONG)
        {
          state = 1;
          timer1 = 0;
        }
      }
      else if (pedestrian_request == 1) // digitalRead required here
      {
        if (timer1 >= TRANSTION_TIME_QUICK)
        {
          state = 1;
          timer1 = 0;
        }
      }
      else
      {
        if (timer1 >= TRANSTION_TIME)
        {
          state = 1;
          timer1 = 0;
        }
      }
      break;

      */

     
    case 0:
      digitalWrite(L1, HIGH);
      digitalWrite(L2, LOW);
      digitalWrite(L3, LOW);
    
      if ( ((traffic_sensor == 1) && /*(pedestrian_request == 0)  && */ (timer1 >= TRANSTION_TIME_LONG))  ||
           ((traffic_sensor == 0) && (pedestrian_request == 1)  && (timer1 >= TRANSTION_TIME_QUICK)) ||
           ((traffic_sensor == 0) && (pedestrian_request == 0)  && (timer1 >= TRANSTION_TIME)))
      {
          state = 1;
          timer1 = 0;   
      }

      break;

      */
    case 1:
      digitalWrite(L1, LOW);
      digitalWrite(L2, HIGH);
      digitalWrite(L3, LOW);
       if (timer1 >= TRANSTION_TIME)
      {
        state = 2;
        timer1 = 0;
      }   
    
      break;

    case 2:
      digitalWrite(L1, LOW);
      digitalWrite(L2, LOW);
      digitalWrite(L3, HIGH);
       if (timer1 >= TRANSTION_TIME)
      {
        state = 0;
        timer1 = 0;
      }
      break;
  }

}

void heartbeat(void)
{
  if (heartbeat_timer < 2)
    digitalWrite(13,0);
  else if (heartbeat_timer < 5)
    digitalWrite(13,1);
  else
    heartbeat_timer = 0;
  
}

void timers(void)
{
  static unsigned long millis_old = 0;// track the # ms the mcu has been running
  unsigned interval = 100;  // meaning every 100ms

  if(millis() >= millis_old + interval)
  {//it falls into this section once every 100ms
    millis_old = millis_old + interval;
    timer1++;
    heartbeat_timer++;
    //_<<--
  }

  if(millis_old > millis())//if you run for a very long time, correct overflow
    millis_old = millis();  

}