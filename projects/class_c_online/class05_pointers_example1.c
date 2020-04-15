#include <stdio.h>

int main(void) 
{
   char x = 'M';
   char* p = &x;
   printf("Value of x is %c\n", x);
   printf("Address of x is %u\n", p);
   printf("Address of p is %u\n", &p);
   return 0;
}
