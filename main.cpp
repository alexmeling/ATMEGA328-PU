#include <avr/io.h>
#include <stdio.h> 
#include <util/delay_basic.h>
#include "headers/ports.h" 
#include "headers/serial.h"

#define HIGH true
#define LOW false
#define low LOW
#define high HIGH 
using namespace std;

int main (void)
{

port  PB(PORTB);
serial USART;

USART.init();
//port  PC(PORTC);
//port  PD(PORTD);

//do{
//PB.invert(9000);
//}while(1);

//PB.set_input(PIN0);


//PB.set_output(PINB5,HIGH);
//PB.set_output(PINB4,low);
//PB.set_output(PINB3,HIGH);
//PB.set_output(PINB2,LOW);

//PC.set_output(PIN0,LOW); 
//PC.set_output(PIN2,LOW);


 return 0;
}
