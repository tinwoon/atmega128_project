#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#define MOTOR_ON 0xf0
#define MOTOR_OFF 0x00

//1. 트랜지스터는 베이스에 5v를 에미터에 그라운드에 해당하는 값을주면
// 베이스와 에미터의 전위차를 증폭하여 컬렉터에 5v가 생성된다.
//2. 우리가 흔히 말하는 5v와 0v에서 + -를 정하는 기준은 전위차가 높은게 + 낮은게 -지
// 단순히 0v가 -가 아니다. 예를 들어 100v 50v가 있으면 50v가 -(gnd)이다
//3. 모터에서 다이오드의 정류작용을 병렬로 하는 이유는 모터에서 쓰고난 값을 정류하면
// 오히려 gnd값으로 주는 전류가 더 높을 수 있음.
// 예를들어 vcc에서 5v 200ma를 주고 트랜지스터를 통해 1v 50ma를 주어서 gnd로 한다하면
// 모터가 쓰고난 후 전류가 30ma가 남아버리면 오히려 역으로 트랜지스터쪽의 gnd가 +가 되어버림
// 이러한 전위차의 차이를 병렬을 통해 일정하게 트랜지스터가 gnd역할을 수행하도록 함.
// 책 158~160
int main(void){
	DDRC = 0x0f;
	DDRB = 0xf0;//트랜지스터 베이스 값
	
	while(1){
		PORTB = MOTOR_ON;//베이스에 5v를 줘서 그라운드를 만들어줌
		PORTC = 0x0f;
		_delay_ms(5000);
		PORTB = MOTOR_OFF;
		PORTC= 0x00;
		_delay_ms(3000);

		
	}
	
}