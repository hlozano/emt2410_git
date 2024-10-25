#include <stdio.h>

void print_value(int x);
int square(int x);


int main(void) 
{
  int a,b;
  a = 3;
  b = square(a);
  print_value(a); 
  print_value(b);
  
   return 1;
}

void print_hw(void)
{
     printf("Hello world"); 
     return;
}
void print_value(int x) {
    printf("value=%d\n", x);
}
int square(int x) {
    x = x * x;
    return x;
}





