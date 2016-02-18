#include <avr/io.h>
#include <stdio.h> 
#include <util/delay.h>
#include "ports.h" 

#define HIGH true
#define LOW false
#define low LOW
#define high HIGH 

using namespace std;

int main (void)
{


port  PB(PORTB);
port  PC(PORTC);
port  PD(PORTD);

PB.set_output(PINB5,low);
PB.set_output(PINB4,high);

PC.set_output(PIN0,HIGH); 
PC.set_output(PIN2,HIGH);


 return 0;
}
