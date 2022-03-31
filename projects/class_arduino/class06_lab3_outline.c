//global variables
unsigned long timer1 = 0;
unsigned long timer2 = 0;

//prototypes
void timers(void);
void flash(void);  

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
    timers();
    flash_led();
}

void flash_led()
{
  if((timer1 >=0) && (timer1 <10))
     digitalWrite(LED_BUILTIN, HIGH);
  if((timer1 >=10) && (timer1 <20))
    digitalWrite(LED_BUILTIN, LOW);
  
  if(timer1 >= 20)
    timer1 = 0;

}

void timers(void)
{
    static unsigned long ms_runtime = 0;
    static int one_ms_timer = 0; 

    if(millis() > ms_runtime)
    {
        ms_runtime++;
        one_ms_timer++;  
    }

    if(one_ms_timer > 99)
    { // our choice for 99 gives us increments of 100 ms
        timer1++;
        timer2++;
        one_ms_timer = 0;
    }
}