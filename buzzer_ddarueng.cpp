/*
 * atmega128-4.cpp
 *
 * Created: 2020-02-04 ���� 9:27:03
 * Author : ������
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 16000000UL
#define __DELAY_BACKWARD_COMPATIBLE__
#include <util/delay.h>

//���� ª�� �Ҹ����� ����
//~������ ���� ���� ���� ����
//us=(10000UL*1000)/hz/2;
void buzzer(int hz,int count){
	int i,us;
	us=(1000UL)*1000/hz/2;
	for(i=0;i<count;i++){
		PORTB |= 1<<4;
		_delay_us(us);
		PORTB &= ~(1<<4);
		_delay_us(us);
		
	}
	
	
}




int main(){
	
	volatile int i;
	DDRB |= 1<<4;
	
	while(1){
		
		for(i=0;i<20;i++){
			buzzer(480,12);
			buzzer(320,8);
			_delay_ms(2000);
		}
		
	}
	
	
	
	
}



