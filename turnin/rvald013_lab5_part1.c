/*	Author: Ryan Valdeavilla
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #5  Exercise #1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif
unsigned char tmpA;
unsigned char counter;
int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;
    /* Insert your solution below */
    while (1) {
	counter = 0;
	tmpA = ~PINA & 0x0F;
	if(tmpA >= 0x0D){
		counter = 0x3F;
	}
	else if(tmpA >= 0x0A){
		counter = 0x3E;
	}
	else if(tmpA >= 0x07){
		counter = 0x3C;
	}
	else if(tmpA >= 0x05){
		counter = 0x38;
	}
	else if(tmpA >= 0x03){
		counter = 0x70;
	}
	else if(tmpA >= 0x01){
		counter = 0x60;
	}
	else{
		counter = 0x40;
	}

	PORTC = counter;
    }
    return 1;
}
