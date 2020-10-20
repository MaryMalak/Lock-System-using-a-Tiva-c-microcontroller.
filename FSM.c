#include "FSM.h"
void wait_enter_key(void) {
	char key;
	while(1) {
		key = keypad_getkey();
		if(key == '*') {
			return;
		}
	}
}
void get_password(char *pw_str)  {
	
	int i, ch;
	for(i = 0; i < PASSWORD_SIZE; i++) {

		// Get char from keypad and store it in pw_str
		ch = keypad_getkey();
		
		if (ch == '*' || ch == '#') {
			i--;
			continue;
		}

		pw_str[i] = ch;
		// Delay
		
	}
}

int CheckIn_state(char *password)  {
	
	char pw_str[4];
	int correct_pw = 1;
  int i;	
	// Keypad
	// Get New Password
	get_password(pw_str);
		
	// Wait for Enter key
	wait_enter_key();
	
	// Check Password
		
	for(i = 0; i < PASSWORD_SIZE; i++) {
			 if(pw_str[i] != password[i]) { 
				 correct_pw = 0;
		 	 }
	}

		// Correct Password
		if(correct_pw) {
				// LEDs
	      LED_ON(green);	 
   			return 1;
    }	
		// Incorrect Password
		else {
			// LEDs
	      LED_ON(red);	
       	return 0;
		}
		
}		
void CheckOut_state(char *password ){
	int i;
	for(i = 0; i < PASSWORD_SIZE; i++) {			
			password[i]='0';
	}
  // LEDs
	LED_ON(red);

	
  return;
}
void RoomCleaning_state(void) {
				// LEDs
	      LED_ON(green);	
    		return ;
}