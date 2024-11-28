#include "mbed.h"
#include "TextLCD.h"

// Define the pins for the TextLCD
TextLCD lcd(D8, D9, D4, D5, D6, D7, TextLCD::LCD16x2); // RS, E, D4, D5, D6, D7

#define SLEEP_TIME_MS 500
DigitalOut myled(PA_5);

int main() 
{
    // Initialize the LCD
    char buffer[16]; // Assuming a 16-character wide display
    lcd.write("Initializing...", 15); // Write "Initializing..." to LCD
    
    thread_sleep_for(2000); // Delay to display initialization text

    int counter = 0;

    while (1) 
    {
        // Blink the LED
        myled = 1; // LED is ON
        thread_sleep_for(SLEEP_TIME_MS);
        myled = 0; // LED is OFF
        thread_sleep_for(SLEEP_TIME_MS);

        // Write to the LCD using a buffer
        lcd.cls();               // Clear the screen
        snprintf(buffer, sizeof(buffer), "LED is %s", myled ? "ON" : "OFF");
        lcd.write(buffer, strlen(buffer)); // Write first line
        
        lcd.locate(0, 1);        // Move to the second line
        snprintf(buffer, sizeof(buffer), "Count: %d", counter++);
        lcd.write(buffer, strlen(buffer)); // Write second line

        thread_sleep_for(SLEEP_TIME_MS * 2); // Wait a moment
    }
}
