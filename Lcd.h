/*
 * Lcd.h
 *
 *  Created on: ???/???/????
 *      Author: adel
 */

#ifndef LCD_H_
#define LCD_H_
#include"micro_config.h"

/*instruction port*/
#define RS 30 //PD6
#define E  31 //PD7

/*Data Port*/
#define LCD_u8DataPort PORTC

/*ROWS*/
#define ROW_ONE 0
#define ROW_TWO 1

#define Port_output 0xff

void Lcd_Int();
void Lcd_vidSendData(u8 Copy_u8Data);
void Lcd_vidDisplayCharacter(u8 Copy_u8Character);
void Lcd_vidDisplayString(up8 Add_up8String);
void Lcd_vidSendCommand(u8 Copy_u8Command);
void Lcd_vidGoTo(u8 Copy_u8Row , u8 Copy_u8Column);
void Lcd_vidClean();
#endif /* LCD_H_ */
