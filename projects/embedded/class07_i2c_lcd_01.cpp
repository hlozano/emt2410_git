#include "mbed.h"

// I2C Pins and Address for the PCF8574 (I2C expander used to control the LCD)
I2C i2c(I2C_SDA, I2C_SCL); // SDA on PB_9, SCL on PB_8
const int LCD_I2C_ADDR = 0x27 << 1;  // I2C address for the LCD adapter (shifted for R/W bit)

// LCD Control Constants
#define LCD_BACKLIGHT 0x08  // Backlight ON
#define LCD_NOBACKLIGHT 0x00  // Backlight OFF
#define ENABLE 0x04  // Enable bit
#define RW 0x02      // Read/Write bit (always 0 for writing)
#define RS 0x01      // Register Select bit (1 for data, 0 for command)

#define CMD_CLEAR_DISPLAY 0x01
#define CMD_RETURN_HOME 0x02
#define CMD_ENTRY_MODE_SET 0x06
#define CMD_DISPLAY_CONTROL 0x0C // Display ON, Cursor OFF, Blink OFF
#define CMD_FUNCTION_SET 0x28    // 4-bit mode, 2-line display, 5x8 dots font
#define CMD_DISPLAY_ON 0x0C

// Function prototypes
void lcd_init();
void lcd_send_command(uint8_t cmd);
void lcd_send_data(uint8_t data);
void lcd_toggle_enable(uint8_t data);
void lcd_clear();
void lcd_print(const char *str);

int main() {
    static unsigned char flip_flop = 0;
    // Set I2C frequency
    i2c.frequency(100000);  // 100 kHz is standard for I2C

    // Start serial communication
    printf("Starting LCD initialization...\n");

    // Initialize LCD
    lcd_init();

    // Clear the LCD screen
    lcd_clear();

    // Inform that initialization is complete
    printf("LCD initialization complete.\n");
    thread_sleep_for(5000);

    while (true) {
        // Print a message to the LCD
        printf("Printing to LCD: Hello, Nucleo!\n");
        if(flip_flop == 0)
        {   flip_flop = 1;
            lcd_print("Hello!");
        }
        else
        {   flip_flop = 0;
            lcd_print("Bye!");
        }
        printf("Printing to LCD: Hello, Nucleo!\n");
        
        // Wait for 2 seconds
        thread_sleep_for(5000);

        // Clear the screen
        printf("Clearing LCD screen...\n");
        lcd_clear();

        // Wait for another 2 seconds
        thread_sleep_for(5000);
    }
}

// Initialize the LCD
void lcd_init() {
    // 4-bit initialization sequence
    printf("Starting LCD initialization... 00\n");
    lcd_send_command(0x03);  // Initialization sequence for 4-bit mode
    thread_sleep_for(5);  // Wait 5ms
    printf("Starting LCD initialization... 01\n");
    lcd_send_command(0x03);  // Repeat the command
    thread_sleep_for(5);
    printf("Starting LCD initialization... 02\n");
    lcd_send_command(0x03);  // Repeat once more
    thread_sleep_for(5);
    printf("Starting LCD initialization... 03\n");
    lcd_send_command(0x02);  // Switch to 4-bit mode

    // Function set, display control, entry mode, and clear display
    lcd_send_command(CMD_FUNCTION_SET);  // 4-bit mode, 2-line display, 5x8 dots font
    lcd_send_command(CMD_DISPLAY_ON);    // Display ON, Cursor OFF, Blink OFF
    lcd_send_command(CMD_ENTRY_MODE_SET);  // Entry mode set: increment automatically
    lcd_send_command(CMD_CLEAR_DISPLAY);  // Clear display
    thread_sleep_for(5);  // Wait for the display to clear
    printf("LCD Initialized.\n");
}

// Send a command to the LCD
void lcd_send_command(uint8_t cmd) {
    // Upper nibble
    printf("LCD Send Command... 00\n");
    lcd_send_data((cmd & 0xF0) | LCD_BACKLIGHT);  
    printf("LCD Send Command... 01\n");
    lcd_toggle_enable((cmd & 0xF0) | LCD_BACKLIGHT);

    // Lower nibble
    printf("LCD Send Command... 02\n");
    lcd_send_data(((cmd << 4) & 0xF0) | LCD_BACKLIGHT);
    printf("LCD Send Command... 03\n");
    lcd_toggle_enable(((cmd << 4) & 0xF0) | LCD_BACKLIGHT);

    // Debug output
    printf("Sent command: 0x%02X\n", cmd);
}

// Send data (a character) to the LCD
void lcd_send_data(uint8_t data) {
    uint8_t upper_nibble = (data & 0xF0) | RS | LCD_BACKLIGHT;  // Upper nibble with RS set
    uint8_t lower_nibble = ((data << 4) & 0xF0) | RS | LCD_BACKLIGHT;  // Lower nibble with RS set

    // Send upper nibble
    i2c.write(LCD_I2C_ADDR, (char*)&upper_nibble, 1);  // Write the upper nibble
    lcd_toggle_enable(upper_nibble);

    // Send lower nibble
    i2c.write(LCD_I2C_ADDR, (char*)&lower_nibble, 1);  // Write the lower nibble
    lcd_toggle_enable(lower_nibble);

    // Debug output
    printf("Sent data: 0x%02X ('%c')\n", data, data);
}

// Toggle the enable bit to latch data or commands into the LCD
void lcd_toggle_enable(uint8_t data) {
    i2c.write(LCD_I2C_ADDR, (char*)&data, 1);  // Write the data
    thread_sleep_for(1);  // Wait briefly
    uint8_t enable_on = data | ENABLE;  // Set the enable bit high
    i2c.write(LCD_I2C_ADDR, (char*)&enable_on, 1);  // Enable pulse
    thread_sleep_for(1);  // Wait >450ns for the enable pulse
    uint8_t enable_off = data & ~ENABLE;  // Clear the enable bit
    i2c.write(LCD_I2C_ADDR, (char*)&enable_off, 1);  // Disable pulse
    thread_sleep_for(1);  // Command execution time
}

// Clear the LCD display
void lcd_clear() {
    lcd_send_command(CMD_CLEAR_DISPLAY);  // Send clear display command
    thread_sleep_for(2);  // Wait for the LCD to clear
    printf("LCD cleared.\n");
}

// Print a string to the LCD
void lcd_print(const char *str) {
    while (*str) {
        lcd_send_data(*str++);  // Send each character
    }
}