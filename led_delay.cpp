/*
 * atmega128-4.cpp
 *
 * Created: 2020-02-04 ���� 9:27:03
 * Author : ������
 */ 

//led delay�Լ��� ���� ����
#include <avr/io.h>



void delay_sec(int sec){
	volatile int i,j,k;
	for(k=0;k<sec;k++){
		for(i=0;i<1000;i++){
			for(j=0;j<900;j++){
				
			}
		}
	}
}






int main(void)
{
   DDRA = 0xff;
  
   
   while(1){
	   for(int i=0x80;i>=0x01;i>>1){
		   PORTA = i;
		   delay_sec(1);
	   }
   }
}


