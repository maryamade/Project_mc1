/*
 * Interrupt.h
 *
 *  Created on: ???/???/????
 *      Author: adel
 */

#ifndef EXTI_H_
#define EXTI_H_

#include"micro_config.h"

typedef enum
{
	 Exti_enuOk = 0 ,
	 Exti_enuIdxlError ,
	 Exti_enuSenseLevelError
}Exti_tenuErrorStatus;

/*types interrupt*/
#define EXTI_u8_INT0 0
#define EXTI_u8_INT1 1
#define EXTI_u8_INT2 2

/*sense level*/
#define EXTI_u8_LOW_LEVEL     0
#define EXTI_u8_ON_CHANGE     1
#define EXTI_u8_FALLING_EDGE  2
#define EXTI_u8_RISING_EDGE   3

/*Bits_Reg*/
#define I             7
#define MCUCR_ISC00   0
#define MCUCR_ISC01   1
#define MCUCR_ISC10   2
#define MCUCR_ISC11   3
#define MCUCSR_ISC2   6
#define GICR_INT1     7
#define GICR_INT0     6
#define GICR_INT2     5
#define TCCR0_CS00    0
#define TCCR0_CS01    1
#define TCCR0_CS02    2
#define TCCR0_WGM01   3
#define WTCCR0_GM00   6
#define TIMSK_TOIE0   0

#define INT0_LED 0
#define INT1_LED 8
#define INT2_LED 2


#define INT0_PIN 26
#define INT1_PIN 27
#define INT2_PIN 10
void Timer_Reg(void);
static void Interrypt_Reg(void);
Exti_tenuErrorStatus Exti_errorIntEnable(u8 Copy_u8Idx);
Exti_tenuErrorStatus Exti_errorIntDisable(u8 Copy_u8Idx);
Exti_tenuErrorStatus EXTI_errorSetSenseLevel(u8 Copy_u8Idx , u8 Copy_u8SenseLevel);

#endif /* EXTI_H_ */
