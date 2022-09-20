/*
 * Interrupt.c
 *
 *  Created on: ???/???/????
 *      Author: adel
 */
#include "Exti.h"
#include"Led.h"
#include"Port.h"
#include"Dio.h"
void Timer_Reg(void)
{
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
   // TCCR0|=(1<<CS00)|(1<<CS02);//1024
	SET_BIT(TIMSK,TOIE0);
	//TIMSK|=(1<<TOIE0);
	SET_BIT(SREG,I);
}
static void Interrypt_Reg(void)
{
	Port_enuSetPinDirection(INT0_PIN,PORT_u8INPUT);
	Port_enuSetPinDirection(INT1_PIN,PORT_u8INPUT);
	Port_enuSetPinDirection(INT2_PIN,PORT_u8INPUT);
	SET_BIT(SREG,I);
}
Exti_tenuErrorStatus Exti_errorIntDisable(u8 Copy_u8Idx)
{
	Exti_tenuErrorStatus Local_Error = Exti_enuOk;
	Interrypt_Reg();
	  switch (Copy_u8Idx)
	  {
	    case EXTI_u8_INT0: CLR_BIT(GICR,GICR_INT0); break;
	    case EXTI_u8_INT1: CLR_BIT(GICR,GICR_INT1); break;
	    case EXTI_u8_INT2: CLR_BIT(GICR,GICR_INT2); break;
	    default: Local_Error = Exti_enuIdxlError;
	  }

	  return Local_Error;
}
Exti_tenuErrorStatus Exti_errorIntEnable(u8 Copy_u8Idx)
{
	Exti_tenuErrorStatus Local_Error = Exti_enuOk;
	Interrypt_Reg();

  switch (Copy_u8Idx)
  {
    case EXTI_u8_INT0: SET_BIT(GICR,GICR_INT0); break;
    case EXTI_u8_INT1: SET_BIT(GICR,GICR_INT1); break;
    case EXTI_u8_INT2: SET_BIT(GICR,GICR_INT2); break;
    default: Local_Error = Exti_enuIdxlError;
  }

  return Local_Error;
}
Exti_tenuErrorStatus EXTI_errorSetSenseLevel(u8 Copy_u8Idx , u8 Copy_u8SenseLevel)
{
	Exti_tenuErrorStatus Local_Error = Exti_enuOk;
	Interrypt_Reg();
	  switch (Copy_u8Idx)
	  {
	    case EXTI_u8_INT0:
	    	switch(Copy_u8SenseLevel)
	    	{
	    	case EXTI_u8_LOW_LEVEL:
	    		CLR_BIT(MCUCR,MCUCR_ISC00);
	    		CLR_BIT(MCUCR,MCUCR_ISC01);
	    		break;
	    	case EXTI_u8_ON_CHANGE:
	    		SET_BIT(MCUCR,MCUCR_ISC00);
				CLR_BIT(MCUCR,MCUCR_ISC01);
				break;
	    	case EXTI_u8_FALLING_EDGE:
				CLR_BIT(MCUCR,MCUCR_ISC00);
				SET_BIT(MCUCR,MCUCR_ISC01);
				break;
			case EXTI_u8_RISING_EDGE:
				SET_BIT(MCUCR,MCUCR_ISC00);
				SET_BIT(MCUCR,MCUCR_ISC01);
				break;
			default:
				Local_Error = Exti_enuSenseLevelError;
	    	}
	    	break;
	    case EXTI_u8_INT1:
	    	switch(Copy_u8SenseLevel)
			{
			case EXTI_u8_LOW_LEVEL:
				CLR_BIT(MCUCR,MCUCR_ISC10);
				CLR_BIT(MCUCR,MCUCR_ISC11);
				break;
			case EXTI_u8_ON_CHANGE:
				SET_BIT(MCUCR,MCUCR_ISC10);
				CLR_BIT(MCUCR,MCUCR_ISC11);
				break;
			case EXTI_u8_FALLING_EDGE:
				CLR_BIT(MCUCR,MCUCR_ISC10);
				SET_BIT(MCUCR,MCUCR_ISC11);
				break;
			case EXTI_u8_RISING_EDGE:
				SET_BIT(MCUCR,MCUCR_ISC10);
				SET_BIT(MCUCR,MCUCR_ISC11);
				break;
			default:
				Local_Error = Exti_enuSenseLevelError;
			}
	    	break;
	    case EXTI_u8_INT2:
	    	switch(Copy_u8SenseLevel)
			{
			case EXTI_u8_FALLING_EDGE:
				CLR_BIT(MCUCSR,MCUCSR_ISC2);
				break;
			case EXTI_u8_RISING_EDGE:
				SET_BIT(MCUCSR,MCUCSR_ISC2);
				break;
			default:
				Local_Error = Exti_enuSenseLevelError;
	    	}
	    	break;
	    default: Local_Error = Exti_enuIdxlError;
	  }

	  return Local_Error;
}
