#include<Header.h>
#include<string.h>

unsigned char cmd_1[]="AT";			  				//attention command
unsigned char cmd_2[]="ATE0";						//charecters not echoed
unsigned char cmd_3[]="AT+CNMI=2,1,0,0,0";	         //procedure for message reception from the n/w 	    
unsigned char cmd_4[]="AT+CMGF=1";					//set text mode
unsigned char cmd_6[]="AT&W";	 					//modification saving in eeprom

unsigned char pno[11],SMS;



void Gsm_Init()
{
unsigned char i;
for(i=0;cmd_1[i]!='\0';i++)
{
UART0_TX(cmd_1[i]);                             // attention command
}
UART0_TX(0X0D);
while(UART0_RECV()!='K');

for(i=0;cmd_6[i]!='\0';i++)
{
UART0_TX(cmd_6[i]);                             // at&w,modification saving in eeprom
}
UART0_TX(0X0D);
while(UART0_RECV()!='K');


for(i=0;cmd_2[i]!='\0';i++)
{
UART0_TX(cmd_2[i]);                             // attention command for echo
}
UART0_TX(0X0D);
while(UART0_RECV()!='K');


for(i=0;cmd_3[i]!='\0';i++)
{
UART0_TX(cmd_3[i]);               //procedure for message reception from the n/w 
}
UART0_TX(0X0D);
while(UART0_RECV()!='K');


for(i=0;cmd_4[i]!='\0';i++)
{
UART0_TX(cmd_4[i]);                 // attention command for message in text mode
}
UART0_TX(0X0D);
while(UART0_RECV()!='K');

//lcd_cmd(0x01);
 //lcd_cmd(0x80);
 //lcd_string("gsm initialised");		   
}

 void Gsm_Del_Msg()
{
UART0_TX_ST("AT+CMGDA=\"del all\"");                           
UART0_TX(0X0D);
	//		lcd_cmd(0x01);
	//		lcd_cmd(0xc0);
	//		lcd_cmd('*');			  // * shows message deleted
}
