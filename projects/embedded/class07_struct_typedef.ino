// Define the struct first
struct LED_t {
  int pin;
  bool state;
};

// Use typedef to create an alias
typedef struct LED_t LED;

// Create multiple LED instances using the typedef alias
LED led1 = {13, false};  // Pin 13, initial state OFF
LED led2 = {12, false};  // Pin 12, initial state OFF
LED led3 = {11, false};  // Pin 11, initial state OFF

void setup() {
  // Initialize the pins as outputs
  pinMode(led1.pin, OUTPUT);
  pinMode(led2.pin, OUTPUT);
  pinMode(led3.pin, OUTPUT);

  // Ensure all LEDs start off
  digitalWrite(led1.pin, LOW);
  digitalWrite(led2.pin, LOW);
  digitalWrite(led3.pin, LOW);
}

void loop() {
  // Toggle the states of each LED
  led1.state = !led1.state;
  led2.state = !led2.state;
  led3.state = !led3.state;

  // Set the LEDs based on their states
  digitalWrite(led1.pin, led1.state ? HIGH : LOW);
  digitalWrite(led2.pin, led2.state ? HIGH : LOW);
  digitalWrite(led3.pin, led3.state ? HIGH : LOW);

  // Wait for a second
  delay(1000);
}