/*
 * L2.0.2.c
 *
 * Created: 2018/9/6/周四 19:00:39
 * Author : Administrator
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>


int extraTime = 0;

int main(void)
{
	DDRD |= 0x40;            //set PD6 to output
	TCCR0A = (1 << WGM01);  // set to CTC mode
	OCR0A = 195;
	TIMSK0 = (1 << OCIE0A); //Timer/Counter0 Output Compare Match A Interrupt Enable
	
	sei();                  //Global Interrupt Enable SREG
	
	TCCR0B = (1 << CS02 | (1<< CS00)); //1024 prescale
	
    while (1) 
    {
		
    }
}
	
ISR(TIMER0_COMPA_vect)
{
	extraTime++;
	
	if (extraTime > 100)
	{
		extraTime = 0;
		PORTD ^= (1 << PORTD6);
		
	}
		
	
}


