/*
 * atmega128-4.cpp
 *
 * Created: 2020-02-04 ���� 9:27:03
 * Author : ������
 */ 


//���ͷ�Ʈ�� ���� ����
//����ġ ���¸� Ǯ������ ��
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
	SREG |= 0x80;//���ͷ�Ʈ�� ����ϰڴٴ� ����
	EIMSK = 0x30;//���ͷ�Ʈ ���� ��ƾ�� 4,5���� ���� ��
	EICRB = 0x00;//����ġ ���°� Ǯ���̱⿡ �������� ground�� 0�� ��
	
	
	while(1){
		PORTC=0x00;//��ҿ��� led�� Ű�� ����
	}
	
	
	
}



