#include <stdio.h>

main() {

   unsigned int a = 60;	/* 60 = 0011 1100 */  
   unsigned int b = 13;	/* 13 = 0000 1101 */
   
   int c = 0;           
   unsigned int d = 0;
   
   //c is signed
   c = a & b;       /* 12 = 0000 1100 */ 
   printf("Line 1 - Value of c is %d\n", c );

   c = a | b;       /* 61 = 0011 1101 */
   printf("Line 2 - Value of c is %d\n", c );

   c = a ^ b;       /* 49 = 0011 0001 */
   printf("Line 3 - Value of c is %d\n", c );

   c = ~a;          /*-61 = 1100 0011 */
   printf("Line 4 - Value of c is %d\n", c );

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