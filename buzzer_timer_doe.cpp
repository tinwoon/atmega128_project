/*
 * atmega128-4.cpp
 *
 * Created: 2020-02-04 오후 9:27:03
 * Author : 오지원
 */ 

//buzzer소리를 타이머카운터를 통해 구현
//분주비(pre-scaler)의 의미부터 이해
//atmega128은 16000000의 hz를 가짐
//즉 1초에 16000000의 계산이 가능
//이때 pre-scaler를 32로 하면 32/16000000= 1/500000마다 클락의 카운터를 증가시킴
//이때 클락의 값은 8비트로 256인데 분주비마다 1씩증가하는 원리이다.
//이를 이용하여 오버플로인터럽트를 발생 시킬 수 있는데
//타이머 클락값이 256이므로 255에서 1이 증가하면 0으로 초기화되고, 이때 오버플로우가 발생하여
//오버플로우인터럽트 함수를 발생 시킨다.
//즉 32분주비일때 1/500000마다 1씩 증가하므로 만약 478/1000000마다 함수를 발생시키고 싶다면
// (478/1000000)/(1/500000) = 239의 클락이 지나간 후 발생시키면 된다.
//이는 맨처음 클락값이 17부터 시작하면 17+239 = 256이므로 오버플로우가 발생
//즉 분주비를 32로하여 타이머클락값을 17부터 시작시키면 된다.

#include <avr/io.h>
#define F_CPU 16000000UL
#include <avr/interrupt.h>
#include <util/delay.h>

	

volatile int state= 0;

ISR(TIMER0_OVF_vect){
	TCNT0 = 17;//타이머 0의 카운터를 17로 시작
	if(state==0){
		PORTB |= 0x10;
		state = 1;
	}
	else {
		PORTB &= 0xef;
		state = 0;
	}
}




int main(){
	
	DDRB |= 0x10;
	TCCR0 = 0x03;//타이머 컨트롤 레지스터0로 뒤의 세비트는 분주비를 의미함 011은 분주비 32를 의미
	TIMSK = 0x01;//timer0를 쓰겠다는 레지스터
	sei();
	TCNT0=17;
	
	while(1){	
	}
	
	
}


