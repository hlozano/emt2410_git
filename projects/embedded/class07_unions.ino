
static union {
    unsigned char mybytes[2];   // 2 - 8 bit bytes (We could use data type "byte")
    unsigned int myinteger;       // 1 - 16 bit word
  };


void setup()
{
  Serial.begin(9600);
  myinteger = 300;
  
  Serial.print("mybytes[0]=");
  Serial.println(mybytes[0]);
  Serial.print("mybytes[1]=");
  Serial.println(mybytes[1]);
  Serial.print("myinteger=");
  Serial.println(myinteger);

}

void loop()
{

}