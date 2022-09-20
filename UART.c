/*
 * UART.C
 *
 *  Created on: ???/???/????
 *      Author: adel
 */
#include"UART.h"
//#include"Led.c"
void Uart_Init(u64 band)//9600
{

  u16 UBRR;
  UBRR=(F_CPU/(16*band))-1;//normal asynch mode
  //UBRR=(F_CPU/(8*band))-1;//asynch doubel speed mode
  UBRRH =(u8)(UBRR>>8);//first
  UBRRL =(u8)(UBRR);//second
  //
  SET_BIT(UCSRB,TXEN);//RX Complete Interrupt Enable
  SET_BIT(UCSRB,RXEN);//TX Complete Interrupt Enable
  SET_BIT(UCSRB,UCSZ2);//Character Size with UCSZ0:1
  //8bit
  SET_BIT(UCSRC,URSEL);
  SET_BIT(UCSRC,UCSZ0);
  SET_BIT(UCSRC,UCSZ1);
  //Register Select
  //The URSEL must be one when writing the UCSRC
  //UCSRC|=(1<<UCSZ0)|(1<<UCSZ1)|(1<<URSEL);//8bit
  //sei();
}

void Uart_RcievedData(up8 data)
{
	while(GET_BIT(UCSRA,RXC)==0);//while until Receive is Complete
	*data=UDR;
	/*
	 * 1--> RXC received+ unread
	 * 0--> RXC received+ read
	 * */
}

void Uart_SendData(u8 data)
{
	while(GET_BIT(UCSRA,UDRE)==0);//while until Send is Complete
		UDR=data;
		/*
		 * 1--> UDRE is empty
		 * 0--> UDRE is contain data
		 * */
}
