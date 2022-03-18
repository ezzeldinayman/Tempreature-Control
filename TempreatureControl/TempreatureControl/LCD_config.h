/*
 * LCD_config.h
 *
 * Created: 04-Mar-22 10:39:32 AM
 *  Author: ezz_a
 */ 


#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_


//This is a configuration file for LCD
#define LCD_PORT 'C' //PORT that LCD Data Lines Connected to.
#define CTRL_PORT 'C' //PORT That LCD Enable,Read Write, Register Selecrt Pins are Connected to.
#define FOUR_BITS_MODE //Mode of operation of LCD (FOUR_BITS_MODE ==> 4 bits / EIGHT_BITS_MODE ==> 8 bits)
#define EN 1
#define RW 2
#define RS 3



#endif /* LCD_CONFIG_H_ */