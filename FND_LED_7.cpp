//fnd 7���� ǥ���ϱ�
//���� ĳ�ҵ� ���(com�� 7������ led�� high�� ������ �� �����ϴ� gnd�� ��� ������ gnd�� com�̶� �ϰ�
//�� ����digit�� fnd�̹Ƿ� com���� 4��
//������ atmega128���� 40mA������ ������ ���� �� �ֱ⿡ led �ϳ��� 25mA�� led���� �����Ƿ�
//��� led�� 4digit���� �Ѹ�(dp����) 7*25*4�� ������ �帣�Ƿ� �̰��� �����̳� Ʈ�������͸� ���� ����
//������ ������ ���α׷����� ���� �������� ���������� �������� �����ʴ�.
//�׷��� ����ġ ������ �ϴ� Ʈ�������͸� ���� �����ϴ°� ������
//mps2222a����� �߰� ���̽��� PG0, �÷��͸� fnd�� com, �����͸� �׶��忡 ȸ�ε� �ۼ���.
//dp f e d c b a������ 8��Ʈ �� abc�� �ش��ϴ� led�� Ű�������� 0000111 => 7�� ��½�Ŵ 

#include <avr/io.h>

int main(){
	
	DDRC = 0xff;
	DDRG = 1;
	PORTC= 7;
	PORTG = 1;
}