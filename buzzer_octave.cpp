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

//�������ļֶ�õ� �������� �ϴ� �ڵ�
//�ڵ� ��ü�� ������� ����.

void buzzer(int hz,int count){
	int i,millis,micros;
	millis = 1000/(2*hz);
	micros = (1000.0/(2*hz)-millis)*1000;
	for(i=0;i<count;i++){
		PORTB |= (1<<4);
		_delay_ms(millis);
		_delay_us(micros);
		PORTB &= ~(1<<4);
		_delay_ms(millis);
		_delay_us(micros);
	}
	
	
}




int main(){
	
	volatile int i;
	
	int hertz[] = {1047, 1175, 1319, 1397, 1568, 1760, 1976, 2093};
	int loop[] = {1047, 1175, 1319, 1397, 1568, 1760, 1976, 2093};
	int led[] = {1, 1<<1, 1<<2 ,1<<3, 1<<4, 1<<5, 1<<6, 1<<7};
	DDRB |= 1<<4;
	DDRC = 0xff;
	
	
	while(1){
		
		for(i=0;i<8;i++){
			PORTC = led[i];
			buzzer(hertz[i],loop[i]);
			
			_delay_ms(1000);
		}
		
	}
	
	
	
	
}



