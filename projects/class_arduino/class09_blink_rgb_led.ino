#define Pin0 0
#define Pin1 1
#define Pin2 2

void setup()
{
  pinMode(Pin0, OUTPUT);
  pinMode(Pin1, OUTPUT); 
  pinMode(Pin2, OUTPUT);


}

void loop()
{
  digitalWrite(Pin0, HIGH);
  digitalWrite(Pin1, LOW);
  digitalWrite(Pin2, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(Pin0, LOW);
  digitalWrite(Pin1, HIGH);
  digitalWrite(Pin2, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(Pin0, LOW);
  digitalWrite(Pin1, LOW);
  digitalWrite(Pin2, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
}