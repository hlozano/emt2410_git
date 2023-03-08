// program was tested using online REPL
//https://repl.it/languages/c 		<- for C language
//https://repl.it/languages/cpp 	<- for C++ language
#include <stdio.h>
#define sum(a,b) (a+b)

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
int main(void) 
{
    int x;
    //without parenthesis
    x = 1+2 * 4+2;
    //with parenthesis
    x = (1+2) * (4+2);

    printf("Value of x is %d\n", x);

   return 0;
}*/




/*
int sum(int a , int b)
{
  return a+b;
}
*/
