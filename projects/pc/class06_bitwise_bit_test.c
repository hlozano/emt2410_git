#include <stdio.h>

int main()
{
	unsigned char bits = 0x77;
 
  //0111 0111
  //0000 1000
	if((bits & 0x08) != 0)  // this test tells if the Nth bit is on or off
											
	{
		printf("fourth bit is ON" );
	}
	else
	{
		printf("fourth bit is OFF");

	}
}
