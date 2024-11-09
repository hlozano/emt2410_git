struct LED {
  int pin;
  bool state;
};

// Create an instance of the struct
LED myLED = {13, false};  // Pin 13 is often used for onboard LEDs

void setup() {
  // Initialize the pin as an output
  pinMode(myLED.pin, OUTPUT);
  digitalWrite(myLED.pin, LOW);  // Ensure the LED starts off
}

void loop() {
  // Toggle the LED state
  myLED.state = !myLED.state;
  
  // Set the LED based on the struct's state
  digitalWrite(myLED.pin, myLED.state ? HIGH : LOW);
  
  // Wait for a second
  delay(1000);
}
