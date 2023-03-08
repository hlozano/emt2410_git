#include <stdio.h>

int main() 
{

   unsigned char a = 60;   /* 60 = 0011 1100 */  
  /*                              1110 0111 -> 0xE7*/   
  /*                              0001 1000 -> 0x18*/   
  /*                              1000 0001 -> 0x81*/    
  unsigned char b = 0;           
  unsigned char c = 0;
  unsigned char d = 0;
  unsigned char e = 0;

  b = a | 0x81;
  c = a & 0xE7;
  d = a & ~(0x18);
  
  e = 0x02; //0b 0000 0010
            // in order to set this one bit
            //0b 0100 0000
            //use the OR bitwise
  e = e | 0x40;  // e=0b0100 0010

  //e=0x42
  //in order to clear bit 2... meaning 0x02 use AND bitwise
  e = e & ~(0x02); // use and  ->  1111 1101 


  printf("Line 1 - Value of a is %u\n", a);
  printf("Line 2 - Value of b is %u\n", b);
  printf("Line 3 - Value of c is %u\n", c);
  printf("Line 4 - Value of d is %u\n", d);
  return 1;
}
