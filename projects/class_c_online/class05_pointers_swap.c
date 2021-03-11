// program was tested using online REPL
//https://repl.it/languages/c 		<- for C language
//https://repl.it/languages/cpp 	<- for C++ language

//&x -> means "address of" x


#include <stdio.h>

void print_2(int a, int b);
//void swap(int a, int b);//<--- broken
void swap(int *a, int *b);

int main(void)
{
   int x = 2;
   int y = 5;

   print_2(x,y);
   swap(&x,&y);
   print_2(x,y);  

   return 0;
}

void print_2(int a, int b)
{
	printf("a=%d b=%d\n", a,b);
}

void swap(int *a, int *b)
{
	int t;
	t = *a;
	*a = *b;
	*b = t;
}


//broken swap
// void swap(int a, int b)
// {
// 	int temp;
// 	temp = a;
// 	a = b;
// 	b = temp;
// 	print_2(a,b);
// }

