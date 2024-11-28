//based on FSM0-a.vsd drawing of an FSM
int light_state = 0; // 0 = OFF ;  1 = ON

const int button_pin = 2;
const int led_pin = 13;

bool OK_to_read = 0;

long int timer1 = 0;
long int timer2 = 0;

void timers(void);

void turn_light_on(void)
{
  digitalWrite(led_pin,1);
}
void turn_light_off(void)
{
  digitalWrite(led_pin,0);
}
bool button_pressed(void)
{
  return (digitalRead(button_pin) == 0);
}
void setup()
{
  pinMode(led_pin,OUTPUT);
  pinMode(button_pin,INPUT_PULLUP);
  Serial.begin(9600);
}
void loop()
{
  timers();
  light_control();
}
void light_control(void)
{
  if(button_pressed() == 0)
  { // button is not pressed
    timer1 = 0;
    OK_to_read = 1;
  }

  switch(light_state)
  {
    case 0:
      turn_light_off();

      if(OK_to_read && (button_pressed() == 1) && (timer1 >=5))
      {
        timer2 = 0;
        OK_to_read = 0;   
        light_state = 1;
      }
      break;
    case 1: 
      turn_light_on();

      if(OK_to_read && (button_pressed() == 1) && (timer1 >=5))
      {
        OK_to_read = 0;   
        light_state = 0;
      }

      if(timer2 >= 200)
      {
        light_state = 0;
      }

      break;
    default:
      light_state = 0;
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
    timer2++;
    //_<<--
  }

  if(millis_old > millis())//if you run for a very long time, correct overflow
    millis_old = millis();  
}