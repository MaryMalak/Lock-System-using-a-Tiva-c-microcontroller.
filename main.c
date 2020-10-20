#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "LEDs.h"
#include "keypad.h"
#include "FSM.h"
#include "uart.h"
void SystemInit() {};
// Global Variables
  State state ;
  int RoomStatus[10]={0,0,0,0,0,0,0,0,0,0};
  char ROOMS_Pass[10][4];
int main(void) {
	int RoomNumber;
	int i;
	LEDs_init();
	keypad_Init();
	uart_Init	();
	
	while(1) {		
			while(UART_AVAILABLE()){
				  char PASSWORD[4];
	        RoomNumber= (int)UART_READ_CHAR();
	       UART_READ_STRING(4,PASSWORD);
         RoomStatus[RoomNumber]= (int)UART_READ_CHAR();
			 
	      if((RoomStatus[RoomNumber] == 0)){
					state=CheckOut;
				}
				if((RoomStatus[RoomNumber]== 1)  ){
						state=CheckIn;
				     for(i=0;i<4;i++){
						 ROOMS_Pass[RoomNumber][i]=PASSWORD[i];
						 }
				}      
				if((RoomStatus[RoomNumber] == 2)){
					state=RoomCleaning;
				}
     					 
			}   					 
		switch(state) {
			case CheckOut:
		
				  CheckOut_state(ROOMS_Pass[RoomNumber] );
				   break;
				
			case CheckIn:
				
				  CheckIn_state(ROOMS_Pass[RoomNumber] );
				  break;
				
			
			case RoomCleaning:
				
			   	RoomCleaning_state();
					break;
		}
		
	}
	
}
