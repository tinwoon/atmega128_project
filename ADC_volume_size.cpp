#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 16000000UL
#include <util/delay.h>


//adc에 관한 사운드코드
//음량의 크기에 따라 아날로그의 크기가 커짐
#define S_LEVEL_8 1024*3.2/5
#define S_LEVEL_7 1024*2.8/5
#define S_LEVEL_6 1024*2.4/5
#define S_LEVEL_5 1024*2.0/5
#define S_LEVEL_4 1024*1.6/5
#define S_LEVEL_3 1024*1.2/5
#define S_LEVEL_2 1024*0.8/5
#define S_LEVEL_1 1024*0.4/5

void init_adc();
unsigned short read_adc();
void show_adc_led(unsigned short data);

int main(){
	unsigned short value;
	DDRC = 0xff;
	init_adc();
	while(1){
		value = read_adc();
		show_adc_led(value);
		_delay_ms(1000);
	}
}

void init_adc(){
	ADMUX = 0x41;
	ADCSRA = 0x87;
}

unsigned short read_adc(){
	unsigned char adc_low, adc_high;
	unsigned short value;
	ADCSRA |= 0x40;
	while((ADCSRA&0x10) != 0x10);
	adc_low = ADCL;
	adc_high = ADCH;
	value = (adc_high<<8)|adc_low;
	return value;
}

void show_adc_led(unsigned short value){
	if(value >= S_LEVEL_8)  PORTC = 0xff;
	else if(value >= S_LEVEL_7) PORTC = 0b01111111;
	else if(value >= S_LEVEL_6) PORTC = 0b00111111;
	else if(value >= S_LEVEL_5) PORTC = 0b00011111;
	else if(value >= S_LEVEL_4) PORTC = 0b00001111;
	else if(value >= S_LEVEL_3) PORTC = 0b00000111;
	else if(value >= S_LEVEL_2) PORTC = 0b00000011;
	else if(value >= S_LEVEL_1) PORTC = 0b00000001;
}

	
	