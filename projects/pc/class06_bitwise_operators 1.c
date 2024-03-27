// program was tested using online REPL
//https://repl.it/languages/c       <- for C language
//https://repl.it/languages/cpp     <- for C++ language
//
#include <stdio.h>

int main() 
{

   unsigned char a = 60;   /*     0011 1100 -> 0x3C*/  
  /*                              1110 0111 -> 0xE7*/   
  /*                              0001 1000 -> 0x18*/   
  /*                              1000 0001 -> 0x81*/    
  unsigned char b = 0;           
  unsigned int c = 0;
  unsigned char d = 0;
  unsigned char e = 0;

  b = a | ~0x81;
  c = a | ~0x81;
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

   unsigned char a = 60;   /*     0011 1100 -> 0x3C*/  
  /*                              1110 0111 -> 0xE7*/   
  /*                              0001 1000 -> 0x18*/   
  /*                              1000 0001 -> 0x81*/ 
/*
  b = a | ~0x81;
  as bytes
  b = 0x3C | ~0x81
  b = 0b 0011 1100 | ~ 0b 1000 0001
  b = 0b 0011 1100 |   0b 0111 1110

  b = 0b 0011 1100 |
      0b 0111 1110 

  b = 0b 0111 1110
      0x 7E
      b = 126








  c = a | ~0x81;
  as a 32 bit integer
  c = 0x 0000003C                                | ~ 0x 0000081
  c = 0b 0000 0000 0000 0000 0000 0000 0011 1100 | ~ 0b 0000 0000 0000 0000 0000 0000 1000 0001
  c = 0b 0000 0000 0000 0000 0000 0000 0011 1100 |   0b 1111 1111 1111 1111 1111 1111 0111 1110
  c = 0b 0000 0000 0000 0000 0000 0000 0011 1100 |
      0b 1111 1111 1111 1111 1111 1111 0111 1110

  c = 0b 1111 1111 1111 1111 1111 1111 0111 1110
    = 0x F    F    F    F    F    F    7    E




  c = a | ~0x81;
*/