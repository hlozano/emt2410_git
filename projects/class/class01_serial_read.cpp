#include "mbed.h"

Serial pc(SERIAL_TX, SERIAL_RX);
DigitalOut led(LED1);

int main()
{
    pc.printf("Press '1' to turn LED1 ON, '0' to turn it OFF\n");
    while(1) {
        char c = pc.getc(); // Read hyperterminal
        if (c == '0') {
            led = 0; // OFF
        }
        if (c == '1') {
            led = 1; // ON
        }
    }
}
