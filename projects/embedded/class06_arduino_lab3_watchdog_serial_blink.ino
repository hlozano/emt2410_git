#include <avr/wdt.h>


// global variables
const int input_pin=12;

int led_state = 2;
unsigned char c;
unsigned long timer1;

void init_function (void);
void control_function(void);
void receive_commands(void);
void control_led(void);
void flash_led(void);
void flash_led_sleeper(void);
void send_status(void);
void timers(void);
void pet_dog(void);

void setup() 
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(input_pin,INPUT_PULLUP);
  Serial.begin(9600);
  Serial.println("booting up..");
  Serial.println("Press '0' to turn LED1 ON");
  Serial.println("Press '1' to turn LED OFF");
  Serial.println("Press '2' to blink LED   ");
  Serial.println("Press '3' to sleep/blink ");  
   // Configure the watchdog timer with a 2-second timeout
  wdt_enable(WDTO_2S); 
}

void loop() 
{
  receive_commands();
  control_led();
  send_status();  
  pet_dog();
  timers();
}

void receive_commands(void)
{
  // send data only when you receive data:
  if (Serial.available() > 0) 
  {
    // read the incoming byte:
    c = Serial.read();

    // say what you got:
    Serial.print("I received: ");
    Serial.println(c, DEC);
    if (c == '0')
        led_state = 0;
    else if (c == '1')
        led_state = 1;
    else if (c == '2') 
        led_state = 2;
    else if (c == '3') 
        led_state = 3;
    else
        led_state = 0;


  }  
}
void control_led()
{
  //pending
}
void flash_led()
{
    if (timer1 < 10)
      digitalWrite(LED_BUILTIN, HIGH);
    else if (timer1 < 20)
      digitalWrite(LED_BUILTIN, LOW);
    else
        timer1 = 0;      
}

void flash_led_sleeper()
{
  delay(5000);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(5000);
  digitalWrite(LED_BUILTIN, LOW);

}


void pet_dog(void)
{
  wdt_reset(); // Reset the watchdog timer (works as "kick" a.k.a. 'pet')
}
void timers(void)
{
  static unsigned long old_millis = 0; //static means it never drops the contents of this variable
  const int timers_interval = 100; // in ms

  if(millis() >= old_millis + timers_interval) // 99.99% will not go in
  {//falling inside this if statement happens every "interval # of ms
    old_millis = millis();

    timer1++; //  same as timer = timer + 1;

  }
}
