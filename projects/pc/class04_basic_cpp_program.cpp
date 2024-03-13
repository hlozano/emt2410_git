#include <iostream>
using namespace std;

int number = 10;

void displayValue(int); //prototype

int main() 
{
    int number = 3;
    cout << "Hello, world!\n";
    cout << "Programming # " ;
    {
        // int nunmber = 99;
        displayValue(number);
    }
    cout << " is " ;
    cout << "fun!";
  
  return 0;
}

void displayValue(int number)
{
  coud<< "%d"<<number;   
}