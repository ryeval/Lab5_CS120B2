/*	Author: Ryan Valdeavilla
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #5  Exercise 2#
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif
enum States{start,increment, decrement, reset, wait, extraWait} state;
unsigned char btn0;
unsigned char btn1;
unsigned char counter;

void Tick(){
	btn0 = ~PINA & 0x01;
	btn1 = (~PINA & 0x02) >> 1;
	switch(state){
		case start:
			counter = 7;
			state = wait;
			break;
		case wait:
			if(btn0 && btn1){
				state = reset;
				break;
			}
			else if(btn0){
				state = increment;
				break;
			}
			else if(btn1){
				state = decrement;
				break;
		}	else{
				state = wait;
				break;
			}
			break;
		case extraWait:
			if(btn0 && btn1){
				state = reset;
				break;
			}
			state =	!(btn0||btn1) ? wait : extraWait;
		case reset:
			state = wait;
			break;
		case increment:
			if(btn0 && btn1){
				state = reset;
				break;
			}
			state = extraWait;
			break;
		case decrement:
			if(btn0 && btn1){
				state = reset;
				break;
			}
			state = extraWait;
			break;
		}
	switch(state){
		case start:
			break;
		case wait:
			break;
		case extraWait:
			break;
		case reset:
			counter = 0;
			break;
		case increment:
			if(counter <= 9){
				counter+=1;
			}
			break;
		case decrement:
			if(counter >= 0){
				counter-=1;
			}
			break;
		}
	PORTC = counter & 0x0F;
}

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;
    /* Insert your solution below */
    state = start;
    counter = 7;
    while (1) {
	Tick();
    }
    return 1;
}
