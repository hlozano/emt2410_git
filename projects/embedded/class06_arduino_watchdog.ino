#include <avr/wdt.h>
const int input_pin=12;
void setup() 
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(input_pin,INPUT_PULLUP);
  wdt_enable(WDTO_2S); 
  Serial.begin(9600);
  Serial.println("rebooting..");
}

void loop() 
{
  
  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);
  while(0);
  wdt_reset(); // Reset the watchdog timer (works as "kick" a.k.a. 'pet')
}

