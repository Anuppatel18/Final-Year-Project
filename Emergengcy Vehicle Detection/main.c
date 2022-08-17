#include<lpc21xx.h>
#include<Header.h>
#include<string.h>

#define IR (IOPIN1 & (1<<16))
#define TOUCH1 (IOPIN1 &(1<<17))
#define TOUCH2 (IOPIN1 &(1<<18))
#define TOUCH3 (IOPIN1 &(1<<19))   

#define RLED  28


unsigned int range=0;

void delay(unsigned int t);	 

unsigned char i=0,j,k,rec;
const char dat[6]="$GPGGA";	  
unsigned char lat[13],longi[14],time[13],lat1[10],longi1[10];
unsigned char OPTION;
extern unsigned char pno[11],SMS;
unsigned char flag;
unsigned char Gsm_Flag();


void delay(unsigned int t)
{
  	unsigned int i;
  	for(i=0;i<=t;i++);
}


void GPS_INIT();


void delay21()
{
	unsigned int g,h;
	
	for(g=0;g<65000;g++);
	for(h=0;h<65000;h++);
}

void send_msg(unsigned int m)
{
    UART0_INIT();
	lcd_cmd(0x01);
	lcd_cmd(0x80);
	lcd_string("SMS  SENDING....");
	if(m==1)
	{	 
		UART0_TX_ST("AT+CMGS=\"8529746743\"");	  // attention command for sending message to phone number 	
		UART0_TX(0X0A);
		UART0_TX(0X0D);
       	UART0_TX_ST("AMBULANCE DETECTED");
		UART0_TX(0X0A);
		UART0_TX(0X0D);
		UART0_TX_ST(lat1);
		UART0_TX_ST(",");
		UART0_TX_ST(longi1);	
	}  

		UART0_TX(0X1A);
		lcd_cmd(0x01);
		lcd_cmd(0x80);
		lcd_string("SMS SENT....");
		delay21();delay21();delay21();
		delay21();delay21();delay21();
		delay21();delay21();delay21();
		delay21();delay21();delay21();
     	delay21();delay21();
}


void send_msg1(unsigned int m)
{
    UART0_INIT();
	lcd_cmd(0x01);
	lcd_cmd(0x80);
	lcd_string("SMS  SENDING....");
	if(m==1)
	{	 
		UART0_TX_ST("AT+CMGS=\"8529746743\"");	  // attention command for sending message to phone number 	
		UART0_TX(0X0A);
		UART0_TX(0X0D);
       	UART0_TX_ST("FIRE ENGINE DETECTED");
		UART0_TX(0X0A);
		UART0_TX(0X0D);
		UART0_TX_ST(lat1);
		UART0_TX_ST(",");
		UART0_TX_ST(longi1);	
	}  

		UART0_TX(0X1A);
		lcd_cmd(0x01);
		lcd_cmd(0x80);
		lcd_string("SMS SENT....");
		delay21();delay21();delay21();
		delay21();delay21();delay21();
		delay21();delay21();delay21();
		delay21();delay21();delay21();
     	delay21();delay21();
}

void send_msg2(unsigned int m)
{
    UART0_INIT();
	lcd_cmd(0x01);
	lcd_cmd(0x80);
	lcd_string("SMS  SENDING....");
	if(m==1)
	{	 
		UART0_TX_ST("AT+CMGS=\"8529746743\"");	  // attention command for sending message to phone number 	
		UART0_TX(0X0A);
		UART0_TX(0X0D);
       	UART0_TX_ST("VVIP VEHICLE DETECTED");
		UART0_TX(0X0A);
		UART0_TX(0X0D);
		UART0_TX_ST(lat1);
		UART0_TX_ST(",");
		UART0_TX_ST(longi1);	
	}  

		UART0_TX(0X1A);
		lcd_cmd(0x01);
		lcd_cmd(0x80);
		lcd_string("SMS SENT....");
		delay21();delay21();delay21();
		delay21();delay21();delay21();
		delay21();delay21();delay21();
		delay21();delay21();delay21();
     	delay21();delay21();
}



void GPS_INIT()
{
	lcd_cmd(0x01);
	lcd_string(" GPS INITILIZING");	
	first:
	for(i=0;(RX_UART1()==dat[i])&&(i<6);i++);
	if(i<6)
	{
		goto first;
	}
	else
	{
		for(i=0;RX_UART1()!='$';i++);
		if(i<60)
		{
			goto first;
		}
	}
		  
	lcd_cmd(0x01);						
	lcd_string(" GPS INITILIZED");
} 


void GPS_READ()
{	
	UART_INIT1();
	lcd_cmd(0x01);
	lcd_string("GPS READING...");	
    first:

	for(i=0;(RX_UART1()==dat[i])&&(i<6);i++);	// getting lat,long,time values from gps

	if(i<6)
	{
		goto first;

	}
	else
	{
		i=0;j=0;k=0;
		while(i<=34)
		{
			if(i<10)
			{
				rec=RX_UART1();
				time[i]=rec;
			}
			
			else if(i>=10&&i<=22) 
			{
				rec=RX_UART1();
				lat[j]=rec;
				j++;
			} 
			
			else if(i>22)
			{
				rec=RX_UART1();
				longi[k]=rec;
				k++;
			}
			
			i++;
		}	 
		
		i=0;
	}
  		
	lat[j]='\0';
	longi[k]='\0';
	//lat1[0]=lat[1];
	lat1[0]=lat[0];
	lat1[1]=lat[1];
	lat1[2]='.';
	lat1[3]=lat[2];
	lat1[4]=lat[3];
	lat1[5]=lat[4];
	lat1[6]=lat[5];
	lat1[7]=lat[6];
	lat1[8]=lat[7];
	lat1[9]='\0';
    
	longi1[0]=longi[1];
	longi1[1]=longi[2];
	longi1[2]='.';
	longi1[3]=longi[3];
	longi1[4]=longi[4];
	longi1[5]=longi[6];
	longi1[6]=longi[7];
	longi1[7]=longi[8];
	longi1[8]=longi[9];
	longi1[9]='\0';	

	
	delay21();delay21();
	lcd_cmd(0x01);				 //To display on LCD(lat,long)
	lcd_string("LATITUDE:");
	lcd_cmd(0xc0);
	lcd_string(lat1);
	delay21();delay21();delay21();
	lcd_cmd(0x01);
	lcd_string("LONGITUDE:");
	lcd_cmd(0xc0);
	lcd_string(longi1);
	delay21();delay21();delay21();															 
} 

void main()
{	

	IODIR1=0X00fF0000;	   
	PINSEL2=0X00000000;
	IOSET1=0X00100000; //RLED


	lcd_init();
	lcd_cmd(0x01);
	lcd_cmd(0x80);
	lcd_string("LCD INIT");

	UART0_INIT();
	lcd_cmd(0x01);
	lcd_cmd(0x80);
	lcd_string("UART0 INIT");

	UART_INIT1();
	lcd_cmd(0x01);
	lcd_cmd(0x80);
	lcd_string("UART1 INIT");

	Gsm_Init();
	lcd_cmd(0x01);
	lcd_cmd(0x80);
	lcd_string("GSM INIT");

	GPS_INIT();
	lcd_cmd(0x01);
	lcd_cmd(0x80);
	lcd_string("GPS INIT");	
	Gsm_Del_Msg();

	while(1)
	{		  
		 if(IR==0)
		 {
			
			lcd_cmd(0x01);
			delay(300000);
		 }
		 else
		 {
		 	lcd_cmd(0x01);
			lcd_cmd(0x80);
			lcd_string("NORMAL VEHICLE");
			lcd_cmd(0x90);
			lcd_string("DETECTED");
		 }
	

		delay(300000);delay(300000);
		delay(300000);delay(300000);
		delay(300000);delay(300000);
		delay(300000);delay(300000);
		delay(300000);delay(300000);
		delay(300000);delay(300000);

		 if(TOUCH1==0)
		 {
		 	lcd_cmd(0x01);
			delay(50000);
		 }
		 else
		 {
		 	lcd_init();
		 	IODIR1=0X0CF00000;
		 	IOCLR1=0X00100000;
		 	IOSET1=0X00600000;
		 	lcd_cmd(0x01);
			lcd_cmd(0x80);
			lcd_string("AMBULANCE");
			lcd_cmd(0xC0);
			lcd_string("DETECTED");
			GPS_READ();
		    send_msg(1);
			delay(300000);delay(300000);
			delay(300000);delay(300000);
			IOCLR1=0X00600000;
			IOSET1=0X00100000;
		 }
		 delay(300000);delay(300000);
		 delay(300000);delay(300000);
		 delay(300000);delay(300000);delay(300000);delay(300000);
		 delay(300000);delay(300000);
		 delay(300000);delay(300000);

		 if(TOUCH2==0)
		 {
		 	lcd_cmd(0x01);
			delay(50000);
		 }
		 else
		 {
		 	lcd_init();
			IODIR1=0X0CF00000;
		 	IOCLR1=0X00100000;
		 	IOSET1=0X00600000;
		 	lcd_cmd(0x01);
			lcd_cmd(0x80);
			lcd_string("FIRE ENGINE");
			lcd_cmd(0xC0);
			lcd_string("DETECTED");
			GPS_READ();
		    send_msg1(1);
			delay(300000);delay(300000);
			delay(300000);delay(300000);
			IOCLR1=0X00600000;
		 	IOSET1=0X00100000;
		 }
		 delay(300000);delay(300000);
		delay(300000);delay(300000);
		delay(300000);delay(300000);delay(300000);delay(300000);
		delay(300000);delay(300000);
		delay(300000);delay(300000);

		 if(TOUCH3==0)
		 {
		 	lcd_cmd(0x01);
			delay(50000);
		 }
		 else
		 {
		 	lcd_init();
			IODIR1=0X0CF00000;
		 	IOCLR1=0X00100000;
		 	IOSET1=0X00600000;
		 	lcd_cmd(0x01);
			lcd_cmd(0x80);
			lcd_string("VVIP VEHICLE");
			lcd_cmd(0xC0);
			lcd_string("DETECTED");
			GPS_READ();
		    send_msg2(1);
			delay(300000);delay(300000);
			delay(300000);delay(300000);
			IOCLR1=0X00600000;
		 	IOSET1=0X00100000;
		 }
		 delay(300000);delay(300000);
		delay(300000);delay(300000);
		delay(300000);delay(300000);delay(300000);delay(300000);
		delay(300000);delay(300000);
		delay(300000);delay(300000);
  	}
}


