/*
 * atmega128.cpp
 *
 * Created: 2020-02-08 오후 11:57:59
 * Author : 오찬용	
 */ 

#include <avr/io.h>
#include <stdlib.h>

#define __DELAY_BACKWARD_COMPATIBLE__//delay에 상수가 들어가도록 설정된것을 해제

#define F_CPU 16000000UL//UL은 unsigned long의 의미이며 외부 클록 값을 16000000으로 지정해줌을 의미
#include <util/delay.h>//위의 #define F_CPU


//처음 led부터 오른쪽으로 순서대로 켜진 후에 
//다시 마지막 led부터 왼쪽으로 켜지는 것

int main(void)
{
   DDRA = 255;
   volatile int i;
   while(1){
	   for(i=1;i<255;i=i<<1){
		   PORTA = i;
		   _delay_ms(1000);
	   }
	   for(i=64;i>1;i=i>>1){
		   PORTA = i;
		   _delay_ms(1000);
	   }
   }
   
   return 0;
}

