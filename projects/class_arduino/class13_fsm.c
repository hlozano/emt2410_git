
/*
System:
vending machine that dispenses a product if 4 coins are inserted.
There will be a cancel button to return the change if user decides not to
stop the purchase
*/
int state = 0;
int N = 0;
bool coin_detected = 0;
bool abort_request = 0;
unsigned long timer1; 


void setup()
{

  Serial.begin(9600);
}
void loop()
{

  timers();
  read_inputs(); // monitor coins and cancel button
  machine_control();
  print_diagnostics();
  heartbeat();



  
}

void machine_control()
{
  switch(state)
  {
    case 0:
      if(coin_detected == 1)
        state = 1;
      if (N == 4)
      {
        state = 2;
        timer1 = 0;
      }
      if (abort_request == 1)
      {
        state = 3;
        timer1 = 0;
      }

      break;
    case 1:
      N++;
      state = 0;
      break;
    case 2:
      dispense_control();
      if (timer1 > = 50)
      {
        state = 0;
        N = 0;
      }
      break;
    case 3:
      return_money_control();
      if(timer1 > 50)
      {
        state = 0;
        N = 0;
      }
      break;
}


void timers(void)
{
  static unsigned long millis_old = 0;// track the # ms the mcu has been running
  unsigned interval = 100;  // meaning every 100ms

  if(millis() >= millis_old + interval)
  {//it falls into this section once every 100ms
    millis_old = millis_old + interval;
    timer1++;
    //_<<--
  }

  if(millis_old > millis())//if you run for a very long time, correct overflow
    millis_old = millis();  

}
/*
possible states:
waiting for user - iddle state    --> 0
verify coin      - verify state   --> 1
dispense product - dispense state --> 2
return money     - abort state    --> 3



*/