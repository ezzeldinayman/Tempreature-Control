/*
 * motor.c
 *
 * Created: 08-Oct-21 6:20:51 PM
 *  Author: Ezz Eldin Ayman
 */ 

#include "DIO.h"

void Motor_vInit(unsigned char portname, unsigned char in1, unsigned char in2, unsigned char en)
{
	DIO_vSetPinDir(portname,en,1);
	DIO_vSetPinDir(portname,in1,1);
	DIO_vSetPinDir(portname,in2,1);
}

void MotorON(unsigned char portname,unsigned char in1, unsigned char in2, unsigned char en, unsigned char dir)
{
	switch(dir)
	{
		case 'C':
		case 'c':
		{
			DIO_vWrite(portname,in1,1);
			DIO_vWrite(portname,in2,0);
		}
		break;
		
		case 'A':
		case 'a':
		{
			DIO_vWrite(portname,in1,0);
			DIO_vWrite(portname,in2,1);
		}
		break;
	}	
}

void MotorOff(unsigned char portname, unsigned char in1, unsigned char in2)
{
	DIO_vWrite(portname, in1, 0);
	DIO_vWrite(portname, in2, 0);
}