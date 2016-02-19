/* @file ports.cpp
 * brief ports driver
 * these functions are provided so that
 * the ports driver will manage the ports
 * without complaining.
 *
 * @author Alex Velásquez Meling
 * @bug no bugs known
 */

#include <stdio.h>
#include <avr/io.h>
#include "../headers/ports.h"

using namespace std;


 port::port(volatile uint8_t &nom):broche(true){
	port_name= &nom;
}

void port::set_output(int pin, bool state){	

	if(broche==true)
	{	
		if (*port_name==PORTB){
			DDRB|=1<<pin;
				if( state==true){
				PORTB|= 1<<pin;
				}
				else
				{
				PORTB&= ~(1<<pin);
				}
			}
			
		if (*port_name==PORTC){
			DDRC|=1<<pin;
				if( state==true){
				PORTC|= 1<<pin;
				}
				else
				{
				PORTC &= ~(1<<pin);
				}
			}
		
		if (*port_name==PORTD){
			DDRD|=1<<pin;

				if( state==true){
				PORTD|= 1<<pin;
				}
				else
				{
				PORTD &= ~(1<<pin);
				}
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





