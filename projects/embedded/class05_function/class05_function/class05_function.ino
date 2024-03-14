void init_ios(void);

void setup() {
  //start serial connection
  Serial.begin(9600);
  //configure pin 2 as an input and enable the internal pull-up resistor
  init_ios();

}

void init_ios(void)
{
  pinMode(2, INPUT_PULLUP);
  pinMode(13, OUTPUT);
  return;
}
void loop() {

  int sensorVal = digitalRead(2);

  Serial.println(sensorVal);


  if (sensorVal == HIGH) {
    digitalWrite(13, LOW);
  } else {
    digitalWrite(13, HIGH);
  }
}
