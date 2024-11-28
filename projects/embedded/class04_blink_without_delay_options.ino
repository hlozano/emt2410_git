// constants won't change. Used here to set pin numbers for each LED:
const int ledPin1 = 9;  // the number of the first LED pin
const int ledPin2 = 10; // the number of the second LED pin
const int ledPin3 = 11; // the number of the third LED pin

// Variables will change:
int ledState1 = LOW; // ledState1 used to set the first LED
int ledState2 = LOW; // ledState2 used to set the second LED
int ledState3 = LOW; // ledState3 used to set the third LED

// Generally, you should use "unsigned long" for variables that hold time
// These variables will store the last time each LED was updated
unsigned long previousMillis1 = 0; 
unsigned long previousMillis2 = 0;
unsigned long previousMillis3 = 0;

// constants won't change:
const long interval1 = 1000;  // interval at which to blink LED1 (milliseconds)
const long interval2 = 500;   // interval at which to blink LED2 (milliseconds)
const long interval3 = 200;   // interval at which to blink LED3 (milliseconds)

void setup() {
  // set the digital pins as outputs:
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
}

void loop() {
  // get the current time
  unsigned long currentMillis = millis();

  // check to see if it's time to blink the first LED
  if (currentMillis - previousMillis1 >= interval1) {
    // save the last time you blinked the first LED
    previousMillis1 = currentMillis;

    // if the first LED is off turn it on and vice-versa:
    if (ledState1 == LOW) {
      ledState1 = HIGH;
    } else {
      ledState1 = LOW;
    }

    // set the first LED with the ledState1 of the variable:
    digitalWrite(ledPin1, ledState1);
  }

  // check to see if it's time to blink the second LED
  if (currentMillis - previousMillis2 >= interval2) {
    // save the last time you blinked the second LED
    previousMillis2 = currentMillis;

    // if the second LED is off turn it on and vice-versa:
    if (ledState2 == LOW) {
      ledState2 = HIGH;
    } else {
      ledState2 = LOW;
    }

    // set the second LED with the ledState2 of the variable:
    digitalWrite(ledPin2, ledState2);
  }

  // check to see if it's time to blink the third LED
  if (currentMillis - previousMillis3 >= interval3) {
    // save the last time you blinked the third LED
    previousMillis3 = currentMillis;

    // if the third LED is off turn it on and vice-versa:
    if (ledState3 == LOW) {
      ledState3 = HIGH;
    } else {
      ledState3 = LOW;
    }

    // set the third LED with the ledState3 of the variable:
    digitalWrite(ledPin3, ledState3);
  }
}
