/*
 * TempreatureControl.c
 *
 * Created: 18-Mar-22 10:27:16 AM
 *  Author: ezz_a
 */ 


#include "ADC.h"
#include "LCD.h"
#include "motor.h"


char displayTemp(void);

int main(void)
{
	LCD_vInit();
	ADC_vInit();
	Motor_vInit('D',1,2,0);
	Motor_vInit('D',6,7,5);
	LCD_vSend_string("Temp: ");
	char temperature;
    while(1)
    {
        //TODO:: Please write your application code 
		temperature = displayTemp();
		if(temperature>=30)
		{
			MotorON('D',1,2,0,'C');
		}
		else if(temperature>15)
		{
			MotorOff('D',6,7);
			MotorOff('D',1,2);
		}
		else if(temperature<=15)
		{
			MotorON('D',6,7,5,'C');
		}
		
    }
}

char displayTemp(void)
{
	unsigned short volt;
	unsigned char temp;
	volt = 2.5*ADC_u16Read();
	if(volt<1000)
	{
		temp = (1000-volt)/10;
		
		if(temp<10)
		{
			LCD_movecursor(1,7);
			LCD_vSend_char('-');
			LCD_vSend_char(temp+48);
			LCD_vSend_char(0xDF);
			LCD_vSend_char('C');
			LCD_vSend_char(0x20);
		}
		else if(temp<100)
		{
			LCD_movecursor(1,7);
			LCD_vSend_char('-');
			LCD_vSend_char((temp/10)+48);
			LCD_vSend_char((temp%10)+48);
			LCD_vSend_char(0xDF);
			LCD_vSend_char('C');
			
		}
		else
		{
			
		}
	}
	else if(volt>=1000)
	{
		temp = (volt-1000)/10;
		
		if(temp<10)
		{
			LCD_movecursor(1,7);
			LCD_vSend_char(temp+48);
			LCD_vSend_char(0xDF);
			LCD_vSend_char('C');
			LCD_vSend_char(0x20);
			LCD_vSend_char(0x20);
		}
		else if(temp<100)
		{
			LCD_movecursor(1,7);
			LCD_vSend_char((temp/10)+48);
			LCD_vSend_char((temp%10)+48);
			LCD_vSend_char(0xDF);
			LCD_vSend_char('C');
			LCD_vSend_char(0x20);
		}
		else
		{
			
		}
	}
	else
	{
		
	}
	
	return temp;
}