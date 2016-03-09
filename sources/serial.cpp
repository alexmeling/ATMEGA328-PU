/* @file serial.cpp
 * @brief serial communication driver
 * these functions are provided so that the serial communication driver will manage the serial interface without complaining.
 *
 * @author Alex Velásquez Meling
 * @bug no bugs known
 */

#include <stdio.h>
#include <avr/io.h>


#define F_CPU 20000000L
#define BAUD 9600
//#define BAUD_RATE FOSC/16/BAUD-1
//
#include <util/setbaud.h>
#include "../headers/serial.h"



using namespace std;



serial::serial(){
}



void serial::init(){

	/* set baud rate */
	UBRR0H=UBRRH_VALUE; // lower register baud rate set 
	UBRR0L=UBRRL_VALUE; // higher register baud rate set 
	
	UCSR0C =  _BV(UCSZ00) | _BV(UCSZ01); // 8 bits data

	UCSR0B = _BV(RXEN0) | _BV(TXEN0); // Receiver and transmiser enabled

}

void serial::write(char& data){

	while(!(UCSR0A & _BV(UDRE0))); //  true if buffer empty
	UDR0=data; //  data written into the usart data register

}

char serial::read(){
 
	while(!(UCSR0A & _BV(RXC0))); // true if buffer not empty 
	return UDR0; // buffer value 


}

char serial::data_received(){

	return(UCSR0A & _BV(RXC0)); // true if data received
}





