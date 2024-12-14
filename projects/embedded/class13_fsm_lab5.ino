// C++ code


int state = 0;
// input definitions (pins or DigitalIn)
unsigned int obstacle_input_pin = 2; // pull-up configured


// signal routines work with inputs
unsigned char obstacle_detected(void);
unsigned char go_to_destination_A(void);
unsigned char go_to_destination_B(void);
unsigned char arrived_to_A(void);
unsigned char arrived_to_B(void);
unsigned char load_command(void);
unsigned char unload_command(void);
unsigned char finished_loading(void);
unsigned char finished_unloading(void);


//control routines for vehicle
void driving_to_destination_A(void);
void driving_to_destination_B(void);
void stop_vehicle(void);

//control routines for loading system
void loading_cargo(void);
void unloading_cargo(void);



unsigned long timer1 = 0;
unsigned long heartbeat_timer = 0;

void setup()
{
  pinMode(obstacle_input_pin, INPUT_PULLUP);
}

void loop()
{
  timers();
  heartbeat();
  lcd_update();
  vehicle_control();  


}

void vehicle_control(void)
{
  switch (state)
  {


     
    case 0:
      stop_vehicle();
      if((go_to_destination_A() == 1) && (go_to_destination_B() == 0))
        state = 1;
      if((go_to_destination_B() == 1) && (go_to_destination_A() == 0))
        state = 2;
      break;

      
    case 1:
        driving_to_destination_A();
        if(obstacle_detected() == 1)
          state = 6;
        if(arrived_to_A() == 1)
          state = 3;


      break;

    case 2:

      break;
    case 3:

      break;
    case 4:

      break;
    case 5:

      break;
    case 6:
      stop_vehicle();
      if(obstacle_detected() == 0)
          state = 0;
      break;
  }
}

unsigned char obstacle_detected(void)
{
  if(digitalRead(obstacle_input_pin) == 0)
    return 1;

  return 0;
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