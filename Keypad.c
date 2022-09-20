/*
 * Keypad.c
 *
 *  Created on: ???/???/????
 *      Author: adel
 */

#include"Keypad.h"
#include"Dio.h"
#include"Port.h"
static void vidSetRowPattern(u8 Copy_u8Row)
{
	u8 Loc_u8RowIterator = INITIAL_ZERO;
	u8 Loc_u8ArrRow[KEYPAD_u8ROWS] ={ KEYPAD_u8ROW0_PIN , KEYPAD_u8ROW1_PIN ,KEYPAD_u8ROW2_PIN, KEYPAD_u8ROW3_PIN };

	for (Loc_u8RowIterator = INITIAL_ZERO; Loc_u8RowIterator< KEYPAD_u8ROWS ;Loc_u8RowIterator++)
	{
		Dio_enuWriteChannel(Loc_u8ArrRow[Loc_u8RowIterator] , DIO_u8HIGH);
	}
	Dio_enuWriteChannel(Loc_u8ArrRow[Copy_u8Row] , DIO_u8LOW);
}


Keypad_tenuErrorStatus Keypad_enuKeyPressed(up8 Add_up8PressedKey)
{
	    //Data validation
		Keypad_tenuErrorStatus Loc_enuReturnStatus = Keypad_Ok ;

		u8 Loc_u8PinStatus = DIO_u8HIGH;
		u8 Loc_u8RowIterator = INITIAL_ZERO;
		u8 Loc_u8ColIterator = INITIAL_ZERO;

		/*DDRB=0x0f;*/
		Port_enuSetPinDirection(DIO_CHANNEL00,PORT_u8OUTPUT);
		Port_enuSetPinDirection(DIO_CHANNEL01,PORT_u8OUTPUT);
		Port_enuSetPinDirection(DIO_CHANNEL02,PORT_u8OUTPUT);
		Port_enuSetPinDirection(DIO_CHANNEL03,PORT_u8OUTPUT);

		/*PULLUP_MODE*/
		Port_enuSetPinMode(DIO_CHANNEL04,PORT_u8INPUT_PULLUP);
		Port_enuSetPinMode(DIO_CHANNEL05,PORT_u8INPUT_PULLUP);
		Port_enuSetPinMode(DIO_CHANNEL06,PORT_u8INPUT_PULLUP);
		Port_enuSetPinMode(DIO_CHANNEL07,PORT_u8INPUT_PULLUP);

		u8 Loc_u8ArrCol[KEYPAD_u8COLS] ={ KEYPAD_u8COL0_PIN , KEYPAD_u8COL1_PIN ,KEYPAD_u8COL2_PIN, KEYPAD_u8COL3_PIN };
		if(Add_up8PressedKey == NULL)
		{
			Loc_enuReturnStatus = Keypad_ErrorNullPointer ;
		}
		else
		{

			for(Loc_u8RowIterator = INITIAL_ZERO; Loc_u8RowIterator < KEYPAD_u8ROWS ; Loc_u8RowIterator++)
			{
				//setRowPattern(row);//pass the row that you want to set by zero
				vidSetRowPattern(Loc_u8RowIterator);
				for(Loc_u8ColIterator = INITIAL_ZERO; Loc_u8ColIterator< KEYPAD_u8COLS &&Loc_u8PinStatus ; Loc_u8ColIterator++)
				{
					Dio_enuReadChannel(Loc_u8ArrCol[Loc_u8ColIterator],&Loc_u8PinStatus);

				}
				if(Loc_u8PinStatus == DIO_u8LOW)
				{
					//*Add_pu8PressedKey = .........;
					*Add_up8PressedKey = KeypadeOutput[(Loc_u8RowIterator * KEYPAD_u8ROWS) + Loc_u8ColIterator -1];
					break;//0*4+2-1=1
				}
			}
		}
		return Loc_enuReturnStatus ;
}
