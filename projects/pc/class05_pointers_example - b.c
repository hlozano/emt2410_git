#include <stdio.h>

int main(void) 
{
    int n;
    const int m =3;
    
    n = 217;
    
    n = n+9;
    
    //m = n;
    
    printf("&n %u\n", (int)(&n));
    printf("&m %u\n", &m);
    printf("&n %d\n", *(&n));
    
    

    return 1;
}
