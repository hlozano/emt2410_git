#include <stdio.h>
#include <math.h>


void doublemyvalue(int  * var); 

int main(void) 
{
    int x =10;
    printf("x=%d\n",x);
    doublemyvalue(&x);
    printf("x=%d\n",x);
    return 1;
}


void doublemyvalue(int * var)
{
   ( *var) = 2  * (* var);
}
    

    
    

 
