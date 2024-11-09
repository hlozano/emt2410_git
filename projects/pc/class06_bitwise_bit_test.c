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



int main()
{
	unsigned char bits = 0x7F;      //0111 1111
 	//how to clear a bit 0x08 meaning 0000 1000
 	unsigned char mask = 0;

 	mask = ~0x08

	bits = bits & (mask);
     //0111 1111 < - 0x07F
//AND//1111 0111
  	 //0111 0111 - > 0x77
}
int main()
{
	unsigned char bits = 0x20;      //0010 0000
 	//how to set a bit 0x08 meaning   0000 1000
 	unsigned char mask = 0;

 	mask = 0x08

	bits = bits | mask;
     //0010 0000 <- 0x20
//OR //0000 1000 <- 0x08
  	 //0010 1000 -> 0x28
}
int main()
{
	unsigned char bits = 0x27;      //0010 0111
 	unsigned char N=1;
	unsigned char result = 0;
	result = bits << N;
	//0100 1110 -> 0x4E

}





