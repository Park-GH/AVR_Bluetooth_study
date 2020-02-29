#define F_CPU 16000000UL // �ܺ� ũ����Ż 16MHz
#include <avr/io.h>
#include <util/delay.h>
 
char rx_char(void)
{
    while(!(UCSR1A & 0x80));
    return UDR1;
}
 
void tx_char(uint8_t bData)
{
    while((UCSR1A&0x20) == 0)
    UDR1 = bData;    
}
 
 int main(void)
 {
    uint8_t bData = 'A';
    
    UCSR1A=0x00; //flag �������͸� ������� ����
    UCSR1B=0x18; //���� enable, �۽� enable, ���ۺ�Ʈ 8bit
    UCSR1C=0x06; //�񵿱�� ���
    UBRR1H=0;
    UBRR1L=103; //9600bps
     
    /* Replace with your application code */
    while (1)
    {
        tx_char(bData);
        _delay_ms(2000);
    }
     
     return 0;
 }
