#include<lpc21xx.h>
#include<Header.h>

void lcd_init()
{
	unsigned char i,cmd[6]={0x02,0x28,0x08,0x0E,0x06,0x01}; 
    IODIR0=0X0000f000;
	IODIR1=0X0c000000;
	for(i=0;i<6;i++)
	{
		lcd_cmd(cmd[i]);
		Delay(50000);
	}
}

void lcd_cmd(unsigned int command)
{
	unsigned int x;
  	x=command;
  	x=x & 0xf0;
  	x=x<<8;
  	IOCLR0 = 0x0000f000;
  	IOSET0=x;
  	IOCLR1=0x0c000000;		//register select and enable
  	IOSET1=0x08000000;		//rs=0 n en=1 pin 22 rs
  	Delay(50000);
  	IOCLR1=0x08000000;
  	Delay(50000);
  	
	x=command;
  	x=x & 0x0f;
  	IOCLR0 = 0x0000f000;
  	x=x<<12;
  	IOSET0=x;
  	IOCLR1=0x0c000000;		//register select and enable
  	IOSET1=0x08000000;
  	Delay(50000);
  	IOCLR1=0x08000000;
  	Delay(50000);
}

void lcd_data(unsigned int data1)
{
  	unsigned int value;
  	value=data1;
  
  	value=value & 0xf0;
  
  	value=value<<8;
  	IOCLR0 = 0x0000f000;
  	IOSET0=value;
  	IOCLR1=0x0c000000;
  	IOSET1=0x0C000000;
  	Delay(50000);
  	IOCLR1=0x08000000;
  	Delay(50000);
  
  	value=data1;
  	value=value & 0x0f;
  	IOCLR0 = 0x0000f000;
  	value=value<<12;
  	IOSET0=value;
  	IOCLR1=0x0C000000;
  	IOSET1=0x0C000000;
  	Delay(50000);
  	IOCLR1=0x08000000;
  	Delay(50000);
}




void Delay(unsigned int k)
{
	unsigned int i,j;
	for(i=0;i<k;i++);
	for(j=0;j<100;j++);
}

void lcd_string(unsigned char *Ptr)
{
  	while(*Ptr)
  	{
  		lcd_data(*Ptr);
  		Ptr++;
  	}
}
