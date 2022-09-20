/*
 * Port.c
 *
 *  Created on: ???/???/????
 *      Author: adel
 */

#include"Port.h"
Port_tenuErrorStatus Port_enuSetPinDirection(u8 Copy_u8PinNum , u8 Copy_u8PinDirection)
{
	// Data validation to the inputs
	Port_tenuErrorStatus Loc_enuReturnStatus = Port_enuOk ;
	//Local variables area
		u8 Loc_u8PinNum ; // 0 ~ 31 --> 0 ~ 7
		u8 Loc_u8PortNum; // 0 ~ 3 ---> A ~ D
	//Check if the channel is not valid
	if((Copy_u8PinNum > PORT_u8MAX_Pin) || (Copy_u8PinNum < PORT_u8MIN_Pin)  )
	{
		Loc_enuReturnStatus = Port_enuPinError;
	}
	else if ((Copy_u8PinDirection < PORT_u8LOW )|| (Copy_u8PinDirection > PORT_u8HIGH))
	{
		Loc_enuReturnStatus = Port_enuDirectionError ;
	}
	// Our Logic
	else
	{
		Loc_u8PinNum = Copy_u8PinNum % PORT_u8REG_SIZE;
		Loc_u8PortNum = Copy_u8PinNum / PORT_u8REG_SIZE ;
		switch(Loc_u8PortNum)
		{
			case PORT_u8PORTA :
				switch(Copy_u8PinDirection)
				{
					case PORT_u8OUTPUT:
						SET_BIT(DDRA, Loc_u8PinNum);
						break;
					case PORT_u8INPUT:
						CLR_BIT(DDRA, Loc_u8PinNum);
						break;
				}
				break;
			case PORT_u8PORTB:
				switch(Copy_u8PinDirection)
				{
					case PORT_u8OUTPUT:
						SET_BIT(DDRB, Loc_u8PinNum);
						break;
					case PORT_u8INPUT:
						CLR_BIT(DDRB, Loc_u8PinNum);
						break;
				}
				break;
			case PORT_u8PORTC:
				switch(Copy_u8PinDirection)
				{
					case PORT_u8OUTPUT:
						SET_BIT(DDRC, Loc_u8PinNum);
						break;
					case PORT_u8INPUT:
						CLR_BIT(DDRC, Loc_u8PinNum);
						break;
				}
				break;
			case PORT_u8PORTD:
				switch(Copy_u8PinDirection)
				{
					case PORT_u8OUTPUT:
						SET_BIT(DDRD, Loc_u8PinNum);
						break;
					case PORT_u8INPUT:
						CLR_BIT(DDRD, Loc_u8PinNum);
						break;
				}
				break;
			default:
			{
				Loc_enuReturnStatus = Port_enuPinError;
			}
		    }
		}
	return Loc_enuReturnStatus;
}
Port_tenuErrorStatus Port_enuSetPinMode(u8 Copy_u8PinNum, u8 Copy_u8PinMode)
{
	// Data validation to the inputs
		Port_tenuErrorStatus Loc_enuReturnStatus = Port_enuOk ;
		//Local variables area
			u8 Loc_u8PinNum ; // 0 ~ 31 --> 0 ~ 7
			u8 Loc_u8PortNum; // 0 ~ 3 ---> A ~ D
		//Check if the channel is not valid
		if((Copy_u8PinNum > PORT_u8MAX_Pin) || (Copy_u8PinNum < PORT_u8MIN_Pin)  )
		{
			Loc_enuReturnStatus = Port_enuPinError;
		}
		else if ((Copy_u8PinMode < PORT_u8MIN_Mode )|| (Copy_u8PinMode > PORT_u8MAX_Mode))
		{
			Loc_enuReturnStatus = Port_enuModeError ;
		}
		// Our Logic
		else
		{
			Loc_u8PinNum = Copy_u8PinNum % PORT_u8REG_SIZE;
			Loc_u8PortNum = Copy_u8PinNum / PORT_u8REG_SIZE ;
			switch(Copy_u8PinMode)
			{
			case PORT_u8INPUT_FLOATING:
				switch(Loc_u8PortNum)
				{
				case PORT_u8PORTA :
					if(GET_BIT(DDRA,Loc_u8PinNum)==PORT_u8INPUT)
					{
						CLR_BIT(PORTA, Loc_u8PinNum);
					}
					else
					{
						Loc_enuReturnStatus = Port_enuDirectionError;
					}
					break;
				case  PORT_u8PORTB:
					if(GET_BIT(DDRB,Loc_u8PinNum)==PORT_u8INPUT)
					{
						CLR_BIT(PORTB, Loc_u8PinNum);
					}
					else
					{
						Loc_enuReturnStatus = Port_enuDirectionError;
					}
					break;
				case PORT_u8PORTC:
					if(GET_BIT(DDRC,Loc_u8PinNum)==PORT_u8INPUT)
					{
						CLR_BIT(PORTC, Loc_u8PinNum);
					}
					else
					{
						Loc_enuReturnStatus = Port_enuDirectionError;
					}
					break;
				case PORT_u8PORTD:
					if(GET_BIT(DDRD,Loc_u8PinNum)==PORT_u8INPUT)
					{
						CLR_BIT(PORTD, Loc_u8PinNum);
					}
					else
					{
						Loc_enuReturnStatus = Port_enuDirectionError;
					}
					break;
				default:
				{
					Loc_enuReturnStatus = Port_enuDirectionError;
				}
				}
				break;
			case PORT_u8INPUT_PULLUP:
				switch(Loc_u8PortNum)
				{
				case PORT_u8PORTA :
					if(GET_BIT(DDRA,Loc_u8PinNum)==PORT_u8INPUT)
					{
						SET_BIT(PORTA, Loc_u8PinNum);
					}
					else
					{
						Loc_enuReturnStatus = Port_enuDirectionError;
					}
					break;
				case  PORT_u8PORTB:
					if(GET_BIT(DDRB,Loc_u8PinNum)==PORT_u8INPUT)
					{
						SET_BIT(PORTB, Loc_u8PinNum);
					}
					else
					{
						Loc_enuReturnStatus = Port_enuDirectionError;
					}
					break;
				case PORT_u8PORTC:
					if(GET_BIT(DDRC,Loc_u8PinNum)==PORT_u8INPUT)
					{
						SET_BIT(PORTC, Loc_u8PinNum);
					}
					else
					{
						Loc_enuReturnStatus = Port_enuDirectionError;
					}
					break;
				case PORT_u8PORTD:
					if(GET_BIT(DDRD,Loc_u8PinNum)==PORT_u8INPUT)
					{
						SET_BIT(PORTD, Loc_u8PinNum);
					}
					else
					{
						Loc_enuReturnStatus = Port_enuDirectionError;
					}
					break;
				default:
				{
					Loc_enuReturnStatus = Port_enuDirectionError;
				}
				}
				break;
			case PORT_u8OUTPUT_LOW:
				switch(Loc_u8PortNum)
				{
				case PORT_u8PORTA :
					if(GET_BIT(DDRA,Loc_u8PinNum)==PORT_u8OUTPUT)
					{
						CLR_BIT(PORTA, Loc_u8PinNum);
					}
					else
					{
						Loc_enuReturnStatus = Port_enuDirectionError;
					}
					break;
				case  PORT_u8PORTB:
					if(GET_BIT(DDRB,Loc_u8PinNum)==PORT_u8OUTPUT)
					{
						CLR_BIT(PORTB, Loc_u8PinNum);
					}
					else
					{
						Loc_enuReturnStatus = Port_enuDirectionError;
					}
					break;
				case PORT_u8PORTC:
					if(GET_BIT(DDRC,Loc_u8PinNum)==PORT_u8OUTPUT)
					{
						CLR_BIT(PORTC, Loc_u8PinNum);
					}
					else
					{
						Loc_enuReturnStatus = Port_enuDirectionError;
					}
					break;
				case PORT_u8PORTD:
					if(GET_BIT(DDRD,Loc_u8PinNum)==PORT_u8OUTPUT)
					{
						CLR_BIT(PORTD, Loc_u8PinNum);
					}
					else
					{
						Loc_enuReturnStatus = Port_enuDirectionError;
					}
					break;
				default:
				{
					Loc_enuReturnStatus = Port_enuDirectionError;
				}
				}
				break;
			case PORT_u8OUTPUT_HIGH:
				switch(Loc_u8PortNum)
				{
				case PORT_u8PORTA :
					if(GET_BIT(DDRA,Loc_u8PinNum)==PORT_u8OUTPUT)
					{
						SET_BIT(PORTA, Loc_u8PinNum);
					}
					else
					{
						Loc_enuReturnStatus = Port_enuDirectionError;
					}
					break;
				case  PORT_u8PORTB:
					if(GET_BIT(DDRB,Loc_u8PinNum)==PORT_u8OUTPUT)
					{
						SET_BIT(PORTB, Loc_u8PinNum);
					}
					else
					{
						Loc_enuReturnStatus = Port_enuDirectionError;
					}
					break;
				case PORT_u8PORTC:
					if(GET_BIT(DDRC,Loc_u8PinNum)==PORT_u8OUTPUT)
					{
						SET_BIT(PORTC, Loc_u8PinNum);
					}
					else
					{
						Loc_enuReturnStatus = Port_enuDirectionError;
					}
					break;
				case PORT_u8PORTD:
					if(GET_BIT(DDRD,Loc_u8PinNum)==PORT_u8OUTPUT)
					{
						SET_BIT(PORTD, Loc_u8PinNum);
					}
					else
					{
						Loc_enuReturnStatus = Port_enuDirectionError;
					}
					break;
				default:
				{
					Loc_enuReturnStatus = Port_enuDirectionError;
				}
				}
				break;
			default :
			{
				Loc_enuReturnStatus = Port_enuModeError;
			}
		}
	}
	return Loc_enuReturnStatus;
}
