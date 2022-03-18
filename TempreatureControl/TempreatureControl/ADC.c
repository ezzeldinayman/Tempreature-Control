/*
 * ADC.c
 *
 * Created: 18-Mar-22 10:33:21 AM
 *  Author: ezz_a
 */ 
#include "std_macros.h"
#include <avr/io.h>

void ADC_vInit(void)
{
	//Vref=2.56v
	SET_BIT(ADMUX, REFS0);
	SET_BIT(ADMUX, REFS1);
	//Enable ADC
	SET_BIT(ADCSRA, ADEN);
	//CLK=125kHz
	SET_BIT(ADCSRA, ADPS2);
	SET_BIT(ADCSRA, ADPS1);
	//Vin is the difference between ADC0 and ADC1
	SET_BIT(ADMUX,MUX4);
}

unsigned short ADC_u16Read(void)
{
	unsigned short readval;
	//Start of Conversion
	SET_BIT(ADCSRA, ADSC);
	while(READ_BIT(ADCSRA, ADIF)==0);
	readval = (ADCL);
	readval |= (ADCH<<8);
	return readval;
	
}