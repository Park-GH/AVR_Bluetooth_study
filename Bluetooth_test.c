#define F_CPU 16000000UL  // 16 MHz



#include<avr/io.h>

#include<util/delay.h>





int main(void)

{

	unsigned int	counter=0;

	DDRA	= 0xFF;

	PORTA	= 0x00;



	while(1)

	{

		if(counter++%2==0)

			PORTA=0x01;

		else

			PORTA=0x00;



		_delay_ms(200);

	}

	

	return 0;

}



