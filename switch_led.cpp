/*
 * atmega128-4.cpp
 *
 * Created: 2020-02-04 ���� 9:27:03
 * Author : ������
 */ 

#include <avr/io.h>


int main(){
	
	DDRC = 0xff;
	DDRE = 0x00;
	
	while(1){
		if((PINE&0x01)==0x00){
			PORTC=0x01;
		}
		else if((PINE&0x02)==0x00){
			PORTC=0x40;
		}
		else PORTC=0x00;
	}
	
	
	
	
}



