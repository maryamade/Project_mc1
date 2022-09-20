/*
 * Led.h
 *
 *  Created on: ???/???/????
 *      Author: adel
 */

#ifndef LED_H_
#define LED_H_
#include"micro_config.h"

/*Modes*/
#define LED_ON  1
#define LED_OFF 0

/*functions*/
void Led_SetOn(u8 Copy_u8ChannelId);
void Led_SetOff(u8 Copy_u8ChannelId);

#endif /* LED_H_ */
