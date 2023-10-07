#include<stdio.h>  
int main()  
{  
    char myarray[10];  
    int ix;  
    for (ix = 0; ix < 10; ix++)  
    {  
        myarray[ix] = ix + 10;
        printf("*"); 
    }  
    printf("\nprinting array\n");
    for (ix = 0; ix < 10; ix++)  
    {  
        printf("myarray[%d] = %d\n",ix,myarray[ix]);
    }  
    
    return 1;
}  