#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#define NULL 0

//송신만 하는 코드
//수신값을 표현하는 터미널 에뮬레이터는 TERA TERM을 사용
void init_uart0(){
	UCSR0B = 0x08;
	UCSR0C = 0x06;
	UBRR0H = 0;
	UBRR0L = 103;
}

void putchar0(char c){
	while(!(UCSR0A & (1<<UDRE0)));//
	UDR0 = c;
}

void puts0(char *ptr){
	while(1)
	{
		if(*ptr != NULL)
			putchar0(*ptr++);
		else
			return;
	}
}

int main(){
	char prompt[]="JCnet !";
	char *ptr;
	
	init_uart0();
	ptr = prompt;
	
	while(1){
		putchar0('H');
		putchar0('i');
		putchar0('~');
		putchar0(' ');
		puts0(ptr);
		putchar0('\n');
		putchar0('\r');
	}
}