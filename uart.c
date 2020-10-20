#include "uart.h"
void uart_Init			(void){
	  SYSCTL_RCGCUART_R |=0x01; //Enable clock to UART
	  SYSCTL_RCGCGPIO_R |=0X01;  //Enable clock to GPIO
	  UART0_CTL_R &=~0X01;
	  UART0_IBRD_R =520;
	  UART0_FBRD_R =53;
    UART0_LCRH_R = 0X0070;
    UART0_CTL_R=0X301;
	  GPIO_PORTA_AFSEL_R |=0X03;
	  GPIO_PORTA_PCTL_R= (GPIO_PORTA_PCTL_R&0XFFFFFF00)|0X11;
    GPIO_PORTA_DEN_R |=0X03;
	  GPIO_PORTA_AMSEL_R &=~0X03;	
}
char UART_READ_CHAR   (void){
	   while((UART0_FR_R&0X0010)!=0);
	   return (char)(UART0_DR_R&0XFF);
}
void UART_READ_STRING   (int number_of_char,char*uart_str){
	int i;
	for( i=0 ; i< number_of_char ; i++){
		uart_str[i]|=UART_READ_CHAR();
	}
}
int UART_AVAILABLE (void){
	return((UART0_FR_R&0X0010)!=0)?0:1;
}
