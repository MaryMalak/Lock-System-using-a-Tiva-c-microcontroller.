#include "LEDs.h"

#include "keypad.h"

#define PASSWORD_SIZE 4
typedef enum State {
	
	CheckOut 		= 0,
	CheckIn 	= 1,
	RoomCleaning 		= 2
} State;

void safe_lockout			(void);
void wait_enter_key		(void);
void get_password			(char *pw_str);
int CheckIn_state(char *password) ;
void CheckOut_state(char *password );
void RoomCleaning_state (void);

