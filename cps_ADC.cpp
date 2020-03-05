/*
 * atmega128.cpp
 *
 * Created: 2020-03-05 오후 9:18:24
 * Author : pc1
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>

#define CDS_10 341
#define CDS_20 450
#define CDS_50 550
#define CDS_80 650
#define CDS_100 731

void init_adc();
unsigned short read_adc();
void show_adc_led(unsigned short data);


int main(void)
{
    unsigned short value;
	DDRC = 0xff;
	DDRF = 0x00;
	init_adc();
	while(1){
		value = read_adc();
		show_adc_led(value);
	}
}

void init_adc(){
	ADMUX  = 0x40;
	ADCSRA = 0x87;
	
}

unsigned short read_adc(){
	unsigned char adc_low, adc_high;
	unsigned short value;
	ADCSRA |= 0x40;
	while(ADCSRA & 0x10 != 0x10){
		
	}
	adc_low = ADCL;
	adc_high = ADCH;
	value = (adc_high<<8)| adc_low;
	return value; 
}

void show_adc_led(unsigned short value){
	if(value<= CDS_10) PORTC = 0xff;
	else if(value<= CDS_20) PORTC = 0x77;
	else if(value<= CDS_50) PORTC = 0x55;
	else if(value<= CDS_80) PORTC = 0x11;
	else if(value<= CDS_100) PORTC = 0x01;
	else PORTC = 0x00;

	
}

