#include <avr/io.h>
#include <stdio.h> 
#include <util/delay.h>
#include "ports.h" 

#define HIGH true
#define LOW false
using namespace std;

int main (void)
{


port  PB(PORTB);

PB.set_output(PIN5,HIGH);
   
 return 0;
}
