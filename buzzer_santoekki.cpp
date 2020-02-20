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
#include <avr/interrupt.h>
#define F_CPU 16000000UL
#define  __DELAY_BACKWARD_COMPATIBLE__
#include <util/delay.h>

#define DO 0
#define RE 1
#define MI 2
#define FA 3
#define SOL 4
#define RA 5
#define SI 6
#define DDO 7
#define REST 8
#define EOS -1
#define ON 0
#define OFF 1

#define N2 1250
#define N4 625
#define N8N16 469
#define N8 313
#define N16 156
#define R 1

volatile int state, tone;
char f_table[] = {17,43,66,77,97,114,117,137,255};
int song[] ={SOL,MI,REST, MI, SOL, MI, DO, RE, MI, RE, DO ,MI, SOL, DDO
			,SOL, DDO, SOL, DDO, SOL, MI, SOL , RE, FA, MI, RE, DO, EOS};
			
int time[]={N4, N8, R, N8, N8, N8, N4, N4, N8, N8, N8, N8, N4, N8N16, N16, N8, N8, N8, N8, N4, N4, N8, N8, N8, N8, N4};
			
char LED[]={0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x00};

ISR(TIMER0_OVF_vect){
	TCNT0 = f_table[tone];
	if(state == OFF){
		PORTB |= 1<<4;
		state = ON;
	}else{
		PORTB &= ~(1<<4);
		state=OFF;
	}
}

int main(){
	int i=0;
	DDRC = 0xff;
	DDRB |= 0x10;
	TCCR0 = 0x03;
	TIMSK = 0x01;
	TCNT0 = f_table[song[i]];
	sei();
	while(1){
		 i=0;
		 do{
			 tone = song[i];
			 PORTC = LED[tone];
			 _delay_ms(time[i++]);
		 }while(song[i]!= EOS);
	}
}
