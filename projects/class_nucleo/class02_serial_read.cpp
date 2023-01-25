#include "mbed.h"

UnbufferedSerial uartUsb(USBTX, USBRX, 115200);

DigitalOut led(LED1); 
// DigitalOut led(PA_5);
// same effect as line before
void print_available_commands(void);

int main()
{
    while(1)
    {
        char c = '\0';
        if(uartUsb.readable())
        {
            uartUsb.read(&c,1);
            if (c == '0') {
                led = 0; // OFF
            }
            if (c == '1') {
                led = 1; // ON
            }
            if (c != '0' && c != '1') {
                print_available_commands();
            }

        }
        
    }
}
void print_available_commands(void)
{
    uartUsb.write( "Press '1' to turn LED1 ON, '0' to turn it OFF\r\n",47);
}
