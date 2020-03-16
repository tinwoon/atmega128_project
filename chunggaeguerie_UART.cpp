#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>

//UART로 청개구리 응답기
//내가 친 데이터를 putchar를 통해 바로 보내고 그다음
//친 데이터를 소문자면 대문자 대문자면 소문자 등등의 형 변환으로 통신을 보내줌
//tera term을 이용
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
		if((value >= 'A')&&(value<='Z'))
			value = value +('a'-'A');
		else if((value>='a')&&(value <='z'))
			value = value + ('A'-'a');
		else if((value>='0')&&(value<='9'))
			value = '*';
		else if(value == '\r')
			putchar0('\n');
		else ;
		putchar0(value);
	}
}