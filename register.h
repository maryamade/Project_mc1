/*
 * register.h
 *
 *  Created on: ???/???/????
 *      Author: adel
 */

#ifndef REGISTER_H_
#define REGISTER_H_

#define DDRA   *(unsigned char*)(0x3A)
#define PINA   *(unsigned char*)(0x39)
#define PORTA  *(unsigned char*)(0x3B)

#define DDRB   *(unsigned char*)(0x37)
#define PINB   *(unsigned char*)(0x36)
#define PORTB  *(unsigned char*)(0x38)

#define DDRC   *(unsigned char*)(0x34)
#define PINC   *(unsigned char*)(0x33)
#define PORTC  *(unsigned char*)(0x35)

#define DDRD   *(unsigned char*)(0x31)
#define PIND   *(unsigned char*)(0x30)
#define PORTD  *(unsigned char*)(0x32)
/*Interrupt*/
#define SREG   *(unsigned char*)(0x5F)
#define MCUCR  *(unsigned char*)(0x55)
#define MCUCSR *(unsigned char*)(0x54)
#define GICR   *(unsigned char*)(0x5B)
#define GIFR   *(unsigned char*)(0x5A)
/*Timer*/
#define TIMSK  *(unsigned char*)(0x59)
#define TCCR0  *(unsigned char*)(0x53)
/*Uart*/
#define UDR    *(unsigned char*)(0x2C)
#define UCSRA  *(unsigned char*)(0x2B)
#define UCSRB  *(unsigned char*)(0x2A)
#define UCSRC  *(unsigned char*)(0x40)
#define UBRRH  *(unsigned char*)(0x40)
#define UBRRL  *(unsigned char*)(0x29)
/*Spi*/
#define SPDR   *(unsigned char*)(0x2F)
#define SPSR   *(unsigned char*)(0x2E)
#define SPCR   *(unsigned char*)(0x2D)
/*Pwm*/
#define TCCR0  *(unsigned char*)(0x53)
#define OCR0   *(unsigned char*)(0x5C)

#define ADCSRA *(unsigned char*)(0x26)
#define ADMUX  *(unsigned char*)(0x27)

#endif /* REGISTER_H_ */
