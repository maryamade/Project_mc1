/*
 * Pwm.c
 *
 *  Created on: ???/???/????
 *      Author: adel
 */
#include"Pwm.h"
#include"Port.h"

void Pmw_voidInit()
{
	SET_BIT(TCCR0,WGM00);//Pwm_fast
	SET_BIT(TCCR0,WGM01);//Pwm_fast
	SET_BIT(TCCR0,COM01);//NonInvator
	SET_BIT(TCCR0,CS00);//prescaler
	SET_BIT(TCCR0,CS02);//prescaler_1024
	Port_enuSetPinDirection(PORT_u8PIN11,PORT_u8OUTPUT);
}
Pwm_tenuErrorStatus Pwm_enuSet_OCR0_Value(u8 value)
{
	Pwm_tenuErrorStatus Loc_enuReturnStatus = Pwm_enuOk ;
	if((value<0)||(value>255))
	{
		Loc_enuReturnStatus=Pwm_enuValueError;
	}
	else
	{
		ASSIGN_REG(OCR0,value);
	}
	return Loc_enuReturnStatus;
}
