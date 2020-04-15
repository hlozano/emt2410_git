

int main()
{
/*	
//BOOLEAN OPERATIONS
	if((button == 1) && (button2 == 1))// is button1 and 2 value equal to 1?
	{
	 	LED = 1;
	}
	 else
	{
	 	LED = 0;		
	}

	if((button == 1) || (button2 == 1))// is button1 and 2 value equal to 1?
	{
	 	LED = 1;
	}
	 else
	{
	 	LED = 0;		
	}	
*/
	//BITWISE OPERATION
	unsigned char seven_segment_status = 0; // one byte
	//0b 0000 0000
	//0x    0    0
	seven_segment_status = seven_segment_status + 1;
	//0b 0000 0001
	seven_segment_status = seven_segment_status + 1;
	//0b 0000 0010 // same as 2 decimal or 0x02 as hexadecimal
	seven_segment_status = seven_segment_status + 1;
	//0b 0000 0011 // same as 3 decimal or 0x03 as hexadecimal
	seven_segment_status = seven_segment_status + 16;
	//0b 0001 0011 // same as 19 decimal or 0x13 as hexadecimal


	//     seven_segment_status & 0x02   = 
	//     0b 0001 0011 & 
	//     0b 0000 0010
	//----------------------
	//     0b 0000 0010

	if((seven_segment_status & 0x02) != 0)  // this test tells 
											//me the second bit is ON
	{
		printf("second bit is ON" );
	}
	else
	{
		printf("second bit is OFF");

	}
}
