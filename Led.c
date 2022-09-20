/*
 * Led.c
 *
 *  Created on: ???/???/????
 *      Author: adel
 */
#include"Led.h"
#include"Dio.h"
#include"Port.h"
void Led_SetOn(u8 Copy_u8ChannelId)
{
	Port_enuSetPinDirection(Copy_u8ChannelId,PORT_u8OUTPUT);
	Dio_enuWriteChannel(Copy_u8ChannelId , LED_ON);
}
void Led_SetOff(u8 Copy_u8ChannelId)
{
	Port_enuSetPinDirection(Copy_u8ChannelId,PORT_u8OUTPUT);
	Dio_enuWriteChannel(Copy_u8ChannelId , LED_OFF);
}
