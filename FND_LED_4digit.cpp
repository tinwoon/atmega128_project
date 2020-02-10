/*
 * atmega128-4.cpp
 *
 * Created: 2020-02-04 오후 9:27:03
 * Author : 오지원
 */ 

#include <avr/io.h>

#define F_CPU 16000000UL
#include <util/delay.h>

int main(){
	
	DDRC = 0xff;
	DDRG = 0x0f;
	while(1){
		PORTC = 0x06;
		PORTG= 0x08;
		_delay_ms(5);
		PORTC = 0x5b;
		PORTG= 0x04;
		_delay_ms(5);
		PORTC = 0x4f;
		PORTG= 0x02;
		_delay_ms(5);
		PORTC = 0x66;
		PORTG= 0x01;
		_delay_ms(5);
		
		
		
	}
	
	
	
}



