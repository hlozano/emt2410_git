// program was tested using online REPL
//https://repl.it/languages/c       <- for C language
//https://repl.it/languages/cpp     <- for C++ language


// #pragma commands are utilzed for sending directions to the compiler
// using #pragma allows developer to tell compiler how to act for 
// specific sections of the source code

#include <stdio.h>

#define USE_SUM_MACRO_VERSION 0

#if USE_SUM_MACRO_VERSION == 1
    #define sum(a,b) a+b // broken definition (missing parenthesis)
#else
    int sum(int a , int b)
    {
      return a+b;
    }
#endif

int main(void) 
{
    int x;
    x = sum(1,2) * sum(4,2);
    printf("Value of x is %d\n", x);
    return 0;
}
/*
after the precompiler is done with this code, 
the code will look like this


int sum(int a , int b)
{
  return a+b;
}

int main(void) 
{
    int x;
    x = sum(1,2) * sum(4,2);
    printf("Value of x is %d\n", x);
    return 0;
}*/




