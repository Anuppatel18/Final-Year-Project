#include<lpc21xx.h>

void MOTION_Check1();
void MOTION_Check2();
void delay21();

void UART0_INIT();
unsigned char UART0_RECV(void);
void UART0_TX(unsigned char a);
void UART0_TX_ST(unsigned char *str);
void delay1(unsigned int it);
unsigned char UART0_RECV1();

void UART_INIT1();
void THX_UART1(unsigned char smg);
unsigned char RX_UART1();
void UART_STRING1(unsigned char *ptr);

void Gsm_Init();
void send_msg1(unsigned int m);
void Gsm_Del_Msg();
void Gsm_read();
unsigned char Gsm_Flag();

void lcd_init();
void lcd_cmd(unsigned int command);
void lcd_data(unsigned int data1);
void delay(unsigned int t);
void Delay(unsigned int k);
void lcd_string(unsigned char *Ptr);

void timer0delay(unsigned int a);
void timer1delay(unsigned int b);
void ultrasonic_init();
void send_pulse();
unsigned int get_range();


unsigned int ultrasonic_read();






