/*
 * atmega128-4.cpp
 *
 * Created: 2020-02-04 오후 9:27:03
 * Author : 오지원
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 16000000UL
#include <util/delay.h>



//피에조부저
//pwm전용인 pb4를 이용
//| 와 & 연산을 이용함
//|=연산은 해당 비트를 1로 만들어주고 나머지것들은 그대로 유지
//&=연산은 해당 비트를 0으로 만들어주고 나머지것들은 그대로 유지
int main(){
	
	DDRB |= 0x10;
	while(1){
		PORTB |= 0x10;
		_delay_ms(1);
		PORTB &= 0xef;
		_delay_ms(1);

	}
	
	
	
	
}



