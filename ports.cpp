/* code source pour les ports */

#include <stdio.h>
#include <avr/io.h>
#include "ports.h"

using namespace std;

 port::port(volatile uint8_t &nom):broche(true){
	port_name= nom;
}

void port::set_output(int pin, bool state){	

	if(broche==true)
	{	
		if (port_name==PORTB){
			DDRB|=1<<pin;
				if( state==true){
				PORTB|= state<<pin;
				}
				else
				{
				PORTB &= state<<pin;
				}
				output=true;
			}
			
		if (port_name==PORTC){
			DDRC|=1<<pin;
				if( state==true){
				PORTC|= state<<pin;
				}
				else
				{
				PORTC &= state<<pin;
				}
				output=true;
			}
		
		if (port_name==PORTD){
			DDRD|=1<<pin;
				if( state==true){
				PORTD|= state<<pin;
				}
				else
				{
				PORTD &= state<<pin;
				}
				output=true;
			}
			else
			{
			printf ("such port doesn't exist on this platform\n");
			}
		}
	
			else
			{
			printf ("You must first create a port instance\n"); 
			}
	

}





