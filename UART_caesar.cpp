#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>

//UART로 케이사르 암호문 
//내가 친 데이터를 아스키코드상에서 +4를 한 값을 출력

void init_uart0(){
	UCSR0B = 0x18;
	UCSR0C = 0x06;
	UBRR0H = 0;
	UBRR0L = 103;
}

void putchar0(char c){
	while(!(UCSR0A & (1<<UDRE0)));
	UDR0 = c;
}

char getchar0(){
	while(!(UCSR0A&(1<<RXC0)));
	return(UDR0);
}

int main(){
	char value;
	init_uart0();
	while(1){
		value = getchar0();
		putchar0(value);
		if((value>='A')&&(value<='Z')){
			value = value+4;
			if(value>'Z'){
				value = value -'Z'-1+'A';
			}
		}
		else if((value>='a')&&(value<='z')){
			value = value+4;
			if(value>'z'){
				value = value-'z'-1+'a';
			}
			else if(value=='\r'){
				putchar0('\n');
				
			}
			else putchar0(value);
		}
	}
}