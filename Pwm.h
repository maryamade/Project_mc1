/*
 * Pwm.h
 *
 *  Created on: ???/???/????
 *      Author: adel
 */

#ifndef PWM_H_
#define PWM_H_

#include"micro_config.h"

typedef enum
{
	Pwm_enuOk = 0 ,
    Pwm_enuValueError
}Pwm_tenuErrorStatus;

/*TCCR0_reg*/
#define FOC0  7
#define WGM00 6
#define COM01 5
#define COM00 4
#define WGM01 3
#define CS02  2
#define CS01  1
#define CS00  0

void Pmw_voidInit();
Pwm_tenuErrorStatus Pwm_enuSet_OCR0_Value(u8 value);

#endif /* PWM_H_ */
