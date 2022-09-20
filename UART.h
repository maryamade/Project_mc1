/*
 * UART.h
 *
 *  Created on: ???/???/????
 *      Author: adel
 */

#ifndef UART_H_
#define UART_H_

#include"micro_config.h"
#define F_CPU 8000000UL

/*UCSRA*/
#define UDRE  5
#define TXC   6
#define RXC   7
/*UCSRB*/
#define UCSZ2 2
#define TXEN  3
#define RXEN  4
#define TXCIE 6
#define RXCIE 7
/*UCSRC*/
#define UCSZ0 1
#define UCSZ1 2
#define URSEL 7

void Uart_Init(u64 band);
void Uart_RcievedData(up8 data);
void Uart_SendData(u8 data);

#endif /* UART_H_ */
