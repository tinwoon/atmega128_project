/*
 * atmega128-4.cpp
 *
 * Created: 2020-02-04 오후 9:27:03
 * Author : 오지원
 */ 


//인터럽트에 대한 공부
//스위치 상태를 풀업으로 둠
#include <avr/io.h>
#include <avr/interrupt.h>


ISR(INT4_vect){
	PORTC = 0x40;
	
}

ISR(INT5_vect){
	PORTC = 0x01;
}



int main(){
	
	DDRC = 0xff;
	DDRE = 0x00;
	SREG |= 0x80;//인터럽트를 사용하겠다는 내용
	EIMSK = 0x30;//인터럽트 서비스 루틴인 4,5번이 들어가게 함
	EICRB = 0x00;//스위치 상태가 풀업이기에 눌렀을때 ground인 0이 들어감
	
	
	while(1){
		PORTC=0x00;//평소에는 led를 키지 않음
	}
	
	
	
}



