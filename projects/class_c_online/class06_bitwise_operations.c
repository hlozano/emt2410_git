// program was tested using online REPL
//https://repl.it/languages/c       <- for C language
//https://repl.it/languages/cpp  <- for C++ language

//Bitwise operators
//two inputs
//  a & b [and]
//  a | b [or]
//  a ^ b [xor]

//one input
//  ~ a   [not]
// ~0 -> 1
// ~1 -> 0

//bit shifting
//     a >> 1;
//     a << 1;




#include <stdio.h>

main() {

   unsigned char a = 60;	/* 60 = 0011 1100 */  
   unsigned char b = 13;	/* 13 = 0000 1101 */
   
   char c = 0;           
   unsigned char d = 0;
   
//--------------------------------------------------------------
//--------------------------------------------------------------
   c = a & b;       /* 12 = 0000 1100 */ 
  //c is signed
/* 
   60 = 0011 1100 
   13 = 0000 1101  &
----------------- 
        0000 1100
*/
   printf("Line 1 - Value of c is %d\n", c );
//--------------------------------------------------------------
//--------------------------------------------------------------
   c = a | b;       /* 61 = 0011 1101 */
   //c is signed
/* 
   60 = 0011 1100 
   13 = 0000 1101  |
----------------- 
        0011 1101
*/
   printf("Line 2 - Value of c is %d\n", c );
//--------------------------------------------------------------
//--------------------------------------------------------------

//--------------------------------------------------------------
//--------------------------------------------------------------
   c = a ^ b;       /* 49 = 0011 0001 */
/* 
   60 = 0011 1100 
   13 = 0000 1101  ^
----------------- 
        0011 0001
*/


   printf("Line 3 - Value of c is %d\n", c );
//--------------------------------------------------------------
//--------------------------------------------------------------

 // unsigned char a = 60;  /* 60 = 0011 1100 */
   d = ~a;                  /*195 = 1100 0011 */
   printf("Line 4a - Value of d is %d\n", d );

   c = ~a;                  /*-61 = 1100 0011 */
   printf("Line 4b - Value of c is %d\n", c );

   c = a << 2;     /* 240 = 1111 0000 */
   printf("Line 5 - Value of c is %d\n", c );

   c = a >> 2;     /* 15 = 0000 1111 */
   printf("Line 6 - Value of c is %d\n", c );

   //d is unsigned

   d = a & b;       /* ?? = 0000 1100 */ 
   printf("Line 1 - Value of d is %u\n", d );

   d = a | b;       /* ?? = 0011 1101 */
   printf("Line 2 - Value of d is %u\n", d );

   d = a ^ b;       /* ?? = 0011 0001 */
   printf("Line 3 - Value of d is %u\n", d );

   d = ~a;          /*?? = 1100 0011 */
   printf("Line 4 - Value of d is %u\n", d );

   d = a << 2;     /* ?? = 1111 0000 */
   printf("Line 5 - Value of d is %u\n", d );

   d = a >> 2;     /* ?? = 0000 1111 */
   printf("Line 6 - Value of d is %u\n", d );

}