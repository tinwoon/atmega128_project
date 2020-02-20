/*
 * atmega128-4.cpp
 *
 * Created: 2020-02-04 ���� 9:27:03
 * Author : ������
 */ 

//buzzer�Ҹ��� Ÿ�̸�ī���͸� ���� ����
//���ֺ�(pre-scaler)�� �ǹ̺��� ����
//atmega128�� 16000000�� hz�� ����
//�� 1�ʿ� 16000000�� ����� ����
//�̶� pre-scaler�� 32�� �ϸ� 32/16000000= 1/500000���� Ŭ���� ī���͸� ������Ŵ
//�̶� Ŭ���� ���� 8��Ʈ�� 256�ε� ���ֺ񸶴� 1�������ϴ� �����̴�.
//�̸� �̿��Ͽ� �����÷����ͷ�Ʈ�� �߻� ��ų �� �ִµ�
//Ÿ�̸� Ŭ������ 256�̹Ƿ� 255���� 1�� �����ϸ� 0���� �ʱ�ȭ�ǰ�, �̶� �����÷ο찡 �߻��Ͽ�
//�����÷ο����ͷ�Ʈ �Լ��� �߻� ��Ų��.
//�� 32���ֺ��϶� 1/500000���� 1�� �����ϹǷ� ���� 478/1000000���� �Լ��� �߻���Ű�� �ʹٸ�
// (478/1000000)/(1/500000) = 239�� Ŭ���� ������ �� �߻���Ű�� �ȴ�.
//�̴� ��ó�� Ŭ������ 17���� �����ϸ� 17+239 = 256�̹Ƿ� �����÷ο찡 �߻�
//�� ���ֺ� 32���Ͽ� Ÿ�̸�Ŭ������ 17���� ���۽�Ű�� �ȴ�.

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
