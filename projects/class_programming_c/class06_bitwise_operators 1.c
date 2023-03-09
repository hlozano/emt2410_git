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
  // part 1 - how to set a bit
  e = e | 0x02;  // 0 OR 2 
            //0b 0000 0000 <-all bits off
            //0b 0000 0010 <-bit to be turned on
            //0b 0000 0010 <- result is e with bit 2 on 
  e = e | 0x40;
            //0b 0000 0010 <-e starting at
            //0b 0100 0000 <-bit to be turned on
            //0b 0100 0010 <- result is e with bit 7 and 2 on 

  //e=0x42
   // part 2 - how to clear a bit
     e = e & ~(0x02); // use and  ->  1111 1101 

    //  ~(0x02) ->  ~(0b 0000 0010)
    //                0b 1111 1101

     // so this becomes
            //0b 0100 0010 <-e starting at
            //0b 1111 1101 <-bit to be turned off
            //0b 0100 0000 <- result is e with bit 4 only 

  printf("Line 1 - Value of a is %u\n", a);
  printf("Line 2 - Value of b is %u\n", b);
  printf("Line 3 - Value of c is %u\n", c);
  printf("Line 4 - Value of d is %u\n", d);
  printf("Line 5 - Value of e is %u\n", e);
  return 1;
}
