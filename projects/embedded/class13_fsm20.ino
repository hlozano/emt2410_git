
int state = 1;
// state = 1 -> red
// state = 2 -> green
// state = 3 -> yellow

unsigned int go_input_pin = 2;
unsigned int stop_input_pin = 3;

unsigned int led_green_pin = 11;
unsigned int led_yellow_pin = 12;
unsigned int led_red_pin = 13;


unsigned long timer1; 
unsigned long yellow_transition_timer; 


void timers(void);

void setup()
{

  pinMode(go_input_pin,INPUT);
  pinMode(stop_input_pin,INPUT);
  pinMode(led_green_pin,OUTPUT);
  pinMode(led_yellow_pin,OUTPUT);
  pinMode(led_red_pin,OUTPUT);

  Serial.begin(9600);
}
void loop()
{
  timers();

  finite_state_machine_control();

  print_diagnostics();
  heartbeat();
}

// void finite_state_machine_control()
// {
//     if(state == 1)
//     {
//       digitalWrite(led_red_pin,HIGH);
//       digitalWrite(led_green_pin,LOW);
//       digitalWrite(led_yellow_pin,LOW);

//       if(digitalRead(go_input_pin) == 1)
//       {
//         state = 2;
//       } 
//     }
//     else if(state == 2)
//     {
//       digitalWrite(led_red_pin,LOW);
//       digitalWrite(led_green_pin,HIGH);
//       digitalWrite(led_yellow_pin,LOW);

//       if(digitalRead(stop_input_pin) == 1)
//       {
//         state = 3;
//         yellow_transition_timer = 0;
//       }


//     }
//     else if (state == 3)
//     {
//       digitalWrite(led_red_pin,LOW);
//       digitalWrite(led_green_pin,LOW);
//       digitalWrite(led_yellow_pin,HIGH); 
//       if(yellow_transition_timer >= 50)
//       {
//         state = 1;
//       }  

//     }

// }

void finite_state_machine_control_b()
{
  switch(state)
  {
    case 1:
      digitalWrite(led_red_pin,HIGH);
      digitalWrite(led_green_pin,LOW);
      digitalWrite(led_yellow_pin,LOW);

      if(digitalRead(go_input_pin) == 1)
      {
        state = 2;
      } 
      break;
    case 2:
      digitalWrite(led_red_pin,LOW);
      digitalWrite(led_green_pin,HIGH);
      digitalWrite(led_yellow_pin,LOW);

      if(digitalRead(stop_input_pin) == 1)
      {
        state = 3;
        yellow_transition_timer = 0;
      }

      break;
    case 3:
      digitalWrite(led_red_pin,LOW);
      digitalWrite(led_green_pin,LOW);
      digitalWrite(led_yellow_pin,HIGH); 
      if(yellow_transition_timer >= 50)
      {
        state = 1;
      }  
      break;
  }
}



void timers(void)
{
  static unsigned long millis_old = 0;// track the # ms the mcu has been running
  unsigned interval = 100;  // meaning every 100ms

  if(millis() >= millis_old + interval)
  {//it falls into this section once every 100ms
    millis_old = millis_old + interval;
    timer1++;
    yellow_transition_timer++;
    //_<<--
  }

  if(millis_old > millis())//if you run for a very long time, correct overflow
    millis_old = millis();  

}
