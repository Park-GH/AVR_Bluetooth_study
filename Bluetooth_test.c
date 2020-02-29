#define F_CPU 16000000
#define BAUD 9600
#define MYUBRR F_CPU/16/BAUD-1

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

void USART_Init(unsigned int ubrr)
{
 /* Set baud rate - 9600 */
 UBRR0H = (unsigned char) (ubrr>>8);
 UBRR0L = (unsigned char) ubrr;
 
 /* Enable receiver and transmitter */
 UCSR0B = (1<<RXEN)|(1<<TXEN);
 /* Set frame format: 8-bit data, 1 stop bit */
 UCSR0C = (1<<UCSZ01)|(1<<UCSZ00);
}

void USART_Transmit(char data)
{
 /* Wait for empty transmit buffer */
 while ( !( UCSR0A & (1<<UDRE0)) );
 /* Put data into buffer, sends the data */
 UDR0 = data;
}

int main(void)
{
 USART_Init(MYUBRR);
 
 /* Replace with your application code */
 while (1) {
  
  USART_Transmit(75);
 }
 
 return 0;
}
