#include <stdio.h>

#define number 42

int main(void) 
{
    int x = number;
    printf("Value of x is %d\n", x);

   return 0;
}
/*
after the precompiler is done with this code, 
the code will look like this


int main(void) 
{
    int x = 42*;
    printf("Value of x is %d\n", x);

   return 0;
}*/