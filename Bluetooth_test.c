#define F_CPU 16000000UL // 외부 크리스탈 16MHz
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
    
    UCSR1A=0x00; //flag 레지스터를 사용하지 않음
    UCSR1B=0x18; //수신 enable, 송신 enable, 전송비트 8bit
    UCSR1C=0x06; //비동기식 통신
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
