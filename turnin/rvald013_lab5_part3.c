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
enum States{start, first, firstWait, second, secondWait, third, thirdWait, fourth, fourthWait} state;
unsigned char btn0;
//unsigned char btn1;
unsigned char counter;

void Tick(){
	btn0 = ~PINA & 0x01;
//	btn1 = (~PINA & 0x02) >> 1;
	switch(state){
		case start:
			state = first;
			break;
//		case wait:
//			break;
		case first:
			state = btn0 ? firstWait : first;
			break;
		case firstWait:
			state = !btn0 ? second : firstWait;
		case second:
			state = btn0 ? secondWait : second;
			break;
		case secondWait:
			state = !btn0 ? third : secondWait;
			break;
		case third:
			state = btn0 ? thirdWait : third;
			break;
		case thirdWait:
			state = !btn0 ? fourth : thirdWait;
			break;
		case fourth:
			state = btn0 ? fourthWait : fourth;
			break;
		case fourthWait:
			state = !btn0 ? first : fourthWait;
			break;
		}
	switch(state){
		case start:
			break;
//		case wait:
//			break;
		case first:
			counter = 0x71;
			break;
		case firstWait:
			break;
		case secondWait:
			break;
		case thirdWait:
			break;
		case fourthWait:
			break;
		case second:
			counter = 0x43;
			break;
		case third:
			counter = 0x2A;
			break;
		case fourth:
			counter = 0x12;
			break;
		}
	PORTC = counter;
}

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;
    /* Insert your solution below */
    state = start;
  //  counter = 7;
    while (1) {
	Tick();
    }
    return 1;
}
