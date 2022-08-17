#include<Header.h>

void UART0_INIT()
{
	PINSEL0|=0X00000005;	
	U0LCR=0X83;			 
	U0DLL=0X61;
	U0DLM=0X00;
	U0LCR=0X03;
}

 void UART_INIT1()
{
 	PINSEL0|=0X00050000;
	U1LCR=0X83;
	U1DLL=0X61;
	U1DLM=0X00;
	U1LCR=0X03;
	
}
void UART0_TX(unsigned char rec)
{
   	U0THR=rec;
	while(!(U0LSR&0X20));
}

unsigned char UART0_RECV()
{
	unsigned char a;

//	while(!(U0LSR&0X01));
	while((U0LSR & (1<<0))==0);
	a=U0RBR;
	return(a);
}

void UART0_TX_ST(unsigned char *Ptr)
{
	while(*Ptr)
	{
	UART0_TX(*Ptr);
	Ptr++;
	}
}

void THX_UART1(unsigned char smg)
{
  	U1THR = smg;
	while(!(U1LSR & 0X20));
}

 char RX_UART1()
{
//	char a;

	while((U1LSR & 0X01)==0);
	

   return  U1RBR;
}

void UART_STRING1(unsigned char *ptr)
{
	while(*ptr)
	{
		THX_UART1(*ptr);
		ptr++;
	}

}


void UART0_TX1(unsigned int rec)
{
   	U0THR=rec;
	while(!(U0LSR&0X20));
}
