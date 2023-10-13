#include <stdio.h>
#define times(a,b) (a*b) //bad
//#define times(a,b) ((a)*(b)) //good
int TIMES(int a,int b);

int main(void) 
{
    int x,y;
    x = times(3+2,1+9);
    y = TIMES(3+2,1+9);
    printf("Value of x is %d \nValue of y is %d\n",x,y);
    return 0;
}

int TIMES(int a,int b)
{
  return a*b;
}