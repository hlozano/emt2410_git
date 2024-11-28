#include "mbed.h"
#include "TextLCD.h"

// Define pins for TextLCD
TextLCD lcd(D8, D9, D4, D5, D6, D7); // RS, E, D4, D5, D6, D7

// Blinking rate in milliseconds
#define BLINKING_RATE 1000ms
#define PAUSE_RATE 500ms

int main() {
    // Initialize the digital pin LED1 as an output
    DigitalOut led(LED1);

    // Variable to count seconds
    int seconds_count = 0;

    // Clear the LCD and display the initial message
    lcd.cls();
    ThisThread::sleep_for(PAUSE_RATE);
    lcd.locate(0, 0); // Set cursor to the first line, first column
    ThisThread::sleep_for(PAUSE_RATE);
   
    lcd.printf("Counting Seconds:");
    ThisThread::sleep_for(PAUSE_RATE);
   
    while (true) {
        // Blink the LED
        led = !led;

        // Update the LCD with the current seconds count
        lcd.locate(0, 1); // Set cursor to the second line, first column
        ThisThread::sleep_for(PAUSE_RATE);
   
        lcd.printf("Seconds: %d", seconds_count++); // Increment and display the count

        // Wait for 1 second
        ThisThread::sleep_for(BLINKING_RATE);
    }
}