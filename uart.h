#include <stdint.h>

#include "tm4c123gh6pm.h"
void uart_Init			(void);
char UART_READ_CHAR   (void);
int UART_AVAILABLE    (void);
void UART_READ_STRING (int number_of_char,char*uart_str);


