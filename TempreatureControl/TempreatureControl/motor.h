/*
 * motor.h
 *
 * Created: 08-Oct-21 6:30:36 PM
 *  Author: ezz_a
 */ 


#ifndef MOTOR_H_
#define MOTOR_H_

void Motor_vInit(unsigned char portname, unsigned char in1, unsigned char in2, unsigned char en);
void MotorON(unsigned char portname,unsigned char in1, unsigned char in2, unsigned char en, unsigned char dir);
void MotorOff(unsigned char portname, unsigned char in1, unsigned char in2);


#endif /* MOTOR_H_ */