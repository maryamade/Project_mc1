/*
 * Project_main1.c
 *
 *  Created on: ???/???/????
 *      Author: adel
 */
#include"UART.h"
#include"Exti.h"
#include"Keypad.h"
#include"Port.h"
#include"Dio.h"
volatile u8 Counter=0;
volatile u8 Counter1=0;
u8 encrypt(u8 data)
{
	u8 key;
	key=1;
	data=data+key;
	return data;
}
u8 decrypt(u8 data)
{
	u8 key;
	key=1;
	data=data-key;
	return data;
}
int main()
{
	Uart_Init(9600);//inital
	Timer_Reg();
	Port_enuSetPinDirection(PORT_u8PIN09,PORT_u8OUTPUT);
	Port_enuSetPinDirection(PORT_u8PIN27,PORT_u8INPUT);
    Dio_enuWriteChannel(DIO_CHANNEL09,DIO_u8LOW);
	u8 Send_data=0,data;
	u8 button=0;
	while(1)
	{
		Dio_enuReadChannel(DIO_CHANNEL27,&button);
		while(button==1)
		{
			Dio_enuWriteChannel(DIO_CHANNEL09,1);
			Counter=0;
			Counter1=0;
			button=0;
		}
		while((Counter>=62)&&(Counter1==1))
		{
			Dio_enuWriteChannel(DIO_CHANNEL09,0);
			Counter=0;
			Counter1=0;
		}
		Keypad_enuKeyPressed(&Send_data);
		while((Send_data>0) && (Send_data<=9))
		{
			data=(u8)(encrypt(Send_data));
			Uart_SendData(data);
			Send_data=0;
		}
    }
	return 0;
}

ISR(TIMER0_OVF_vect)
{
	Counter++;
	if(Counter>=250)
	{
		Counter1=1;
		Counter=0;
	}
}
