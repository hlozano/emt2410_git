#define rgb_pin_green 0
#define rgb_pin_blue 1
#define rgb_pin_red 2

void setup()
{
  pinMode(rgb_pin_green, OUTPUT);
  pinMode(rgb_pin_blue, OUTPUT); 
  pinMode(rgb_pin_red, OUTPUT);
}

void loop()
{
  digitalWrite(rgb_pin_green, HIGH);
  digitalWrite(rgb_pin_blue, LOW);
  digitalWrite(rgb_pin_red, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(rgb_pin_green, LOW);
  digitalWrite(rgb_pin_blue, HIGH);
  digitalWrite(rgb_pin_red, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(rgb_pin_green, LOW);
  digitalWrite(rgb_pin_blue, LOW);
  digitalWrite(rgb_pin_red, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
}

/*

R   G   B
0   0   0  (off)
0   0   1  (blue)
0   1   0  (green)
1   0   0  (red)
1   1   0  (???)
0   1   1  (???)
1   0   1  (???)





*/

