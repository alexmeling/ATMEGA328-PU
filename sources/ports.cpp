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
#include <util/delay.h>
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

void port::set_input(int pin)
{


	if(broche==true)
	{	
		if (*port_name==PORTB){
			DDRB&=~(1<<pin); // set the pin data direction as input 
			PORTB&= ~(1<<pin); // disables the pull-up resistor
		}
			
		if (*port_name==PORTC){
		        DDRC&=~(1<<pin);
			PORTC&=~(1<<pin); 
		}

			
		if (*port_name==PORTD){
			DDRD&=~(1<<pin);
			PORTD&= ~(1<<pin);
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

void port::set_input_PUE(int pin){

if(broche==true)
	{	
		if (*port_name==PORTB){
			DDRB&=~(1<<pin); // set the pin data direction as input 
			PORTB |= 1<<pin; // disables the pull-up resistor
		}
			
		if (*port_name==PORTC){
		        DDRC&=~(1<<pin);
			PORTC |= 1<<pin; 
		}

			
		if (*port_name==PORTD){
			DDRD&=~(1<<pin);
			PORTD |= 1<<pin;
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


bool  port::get_state(int pin){

	bool value=false;
	
	if(broche==true)
	{	
		if (*port_name==PORTB){

			value = PINB;
			value = (value>>pin)&~(0xFE);			
		}
			
		if (*port_name==PORTC){

			value = PINC;
			value = (value>>pin)&~(0xFE);
		}

			
		if (*port_name==PORTD){
			
			value= PIND;
			value = (value>>pin)&~(0xFE);

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
	return(value);
}

void port::invert(const int &time){

	if(broche==true)
	{	
		if (*port_name==PORTB){
				DDRB=0xFF;			     
				PORTB=0x55; // set the default value at 10101010

				_delay_ms(time);

				PORTB^=0xFF; //  xor instruction to invert the pins
				_delay_ms(time);					}
			
		if (*port_name==PORTC){
				
				PORTC|=0x55; // set the default value at 10101010
				_delay_ms(time);
				PORTC^=0xFF; //  xor instruction to invert the pins
				_delay_ms(time);			

			}

		if (*port_name==PORTD){
				
				PORTD|=0x55; // set the default value at 10101010
				_delay_ms(time);
				
				PORTD^=0xFF; //  xor instruction to invert the pins
				_delay_ms(time);

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






