/*
 * atmega128-4.cpp
 *
 * Created: 2020-02-04 ���� 9:27:03
 * Author : ������
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 16000000UL
#include <util/delay.h>



//�ǿ�������
//pwm������ pb4�� �̿�
//| �� & ������ �̿���
//|=������ �ش� ��Ʈ�� 1�� ������ְ� �������͵��� �״�� ����
//&=������ �ش� ��Ʈ�� 0���� ������ְ� �������͵��� �״�� ����
int main(){
	
	DDRB |= 0x10;
	while(1){
		PORTB |= 0x10;
		_delay_ms(1);
		PORTB &= 0xef;
		_delay_ms(1);

	}
	
	
	
	
}



