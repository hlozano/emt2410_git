#include "mbed.h"

UnbufferedSerial uartUsb(USBTX, USBRX, 115200);
DigitalOut       led(LED1); 

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

            switch(c)
            {
                case '0':
                    led = 0; // OFF
                    break;
                case '1':
                    led = 1;// ON
                    break; 
                default:
                     print_available_commands();
                    break;

            }

        }
        
    }

    return 1;
}
void print_available_commands(void)
{
    uartUsb.write( "Press '1' to turn LED1 ON, '0' to turn it OFF\r\n",47);
}
