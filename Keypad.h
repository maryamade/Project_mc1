/*
 * Keypad.h
 *
 *  Created on: ???/???/????
 *      Author: adel
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_

#include"micro_config.h"

typedef enum{
	Keypad_Ok ,
	Keypad_ErrorNullPointer
} Keypad_tenuErrorStatus;

/*NULL*/
#define NULL (void*)0

/*cols/rows*/
#define KEYPAD_u8ROWS 4
#define KEYPAD_u8COLS 4

#define INITIAL_ZERO  0

#define KEYPAD_u8ROW0_PIN		DIO_CHANNEL00//PA0
#define KEYPAD_u8ROW1_PIN		DIO_CHANNEL01
#define KEYPAD_u8ROW2_PIN		DIO_CHANNEL02
#define KEYPAD_u8ROW3_PIN		DIO_CHANNEL03//OUTPUT_HIGH

#define KEYPAD_u8COL0_PIN		DIO_CHANNEL04//INPUT_PULLUP
#define KEYPAD_u8COL1_PIN		DIO_CHANNEL05
#define KEYPAD_u8COL2_PIN		DIO_CHANNEL06
#define KEYPAD_u8COL3_PIN		DIO_CHANNEL07

#define KEYPAD_u8ROW0_COL0		 7
#define KEYPAD_u8ROW0_COL1		 8
#define KEYPAD_u8ROW0_COL2		 9
#define KEYPAD_u8ROW0_COL3		'/'

#define KEYPAD_u8ROW1_COL0		 4
#define KEYPAD_u8ROW1_COL1		 5
#define KEYPAD_u8ROW1_COL2		 6
#define KEYPAD_u8ROW1_COL3		 '*'

#define KEYPAD_u8ROW2_COL0		 1
#define KEYPAD_u8ROW2_COL1		 2
#define KEYPAD_u8ROW2_COL2		 3
#define KEYPAD_u8ROW2_COL3		'-'

#define KEYPAD_u8ROW3_COL0		'C'
#define KEYPAD_u8ROW3_COL1		 0
#define KEYPAD_u8ROW3_COL2	    'E'
#define KEYPAD_u8ROW3_COL3		'+'

static u8 KeypadeOutput[]={KEYPAD_u8ROW0_COL0,KEYPAD_u8ROW0_COL1,KEYPAD_u8ROW0_COL2,KEYPAD_u8ROW0_COL3,KEYPAD_u8ROW1_COL0,KEYPAD_u8ROW1_COL1,KEYPAD_u8ROW1_COL2,KEYPAD_u8ROW1_COL3,KEYPAD_u8ROW2_COL0,KEYPAD_u8ROW2_COL1,KEYPAD_u8ROW2_COL2,KEYPAD_u8ROW2_COL3,KEYPAD_u8ROW3_COL0,KEYPAD_u8ROW3_COL1,KEYPAD_u8ROW3_COL2,KEYPAD_u8ROW3_COL3};
/*function*/
static void vidSetRowPattern(u8 Copy_u8Row);
Keypad_tenuErrorStatus Keypad_enuKeyPressed(up8 Add_up8PressedKey);

#endif /* KEYPAD_H_ */
