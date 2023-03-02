// program was tested using online REPL
//https://repl.it/languages/c       <- for C language
//https://repl.it/languages/cpp     <- for C++ language

#include<stdio.h>

int main () {
   char c;
   printf("Enter character: ");
   c = getc(stdin);
   printf("Character entered: ");
   putc(c, stdout);
   printf("\n"); 
   printf("%d",c);
   return(0);
}