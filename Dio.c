/*
 * Dio.c
 *
 *  Created on: ???/???/????
 *      Author: adel
 */
#include"Dio.h"

Dio_tenuErrorStatus Dio_enuWriteChannel(u8 Copy_u8ChannelId , u8 Copy_u8Level)
{
	// Data validation to the inputs
	Dio_tenuErrorStatus Loc_enuReturnStatus = Dio_enuOk ;

	//Local variables area
	u8 Loc_u8PinNum ; // 0 ~ 31 --> 0 ~ 7
	u8 Loc_u8PortNum; // 0 ~ 3 ---> A ~ D

	// Data validation to the inputs
	//Check if the channel is not valid
	if((Copy_u8ChannelId > DIO_u8MAX_CHANNELS) || (Copy_u8ChannelId < DIO_u8MIN_CHANNELS)  )
	{
		Loc_enuReturnStatus = Dio_enuChannelError;
	}
	else if ((Copy_u8Level < DIO_u8LOW )|| (Copy_u8Level > DIO_u8HIGH))
	{
	    Loc_enuReturnStatus = Dio_enuLevelError ;
	}
	// Our Logic
	else
	{
		Loc_u8PinNum = Copy_u8ChannelId % DIO_u8REG_SIZE;
		Loc_u8PortNum = Copy_u8ChannelId / DIO_u8REG_SIZE ;

		switch(Loc_u8PortNum)
		{
			case DIO_u8PORTA :
				if(GET_BIT(DDRA,Loc_u8PinNum)== DIO_u8OUTPUT_PIN)
				{
					switch(Copy_u8Level)
					{
						case DIO_u8HIGH:
							SET_BIT(PORTA, Loc_u8PinNum);//0010 1000||0000 0010//0010 1010
							break;
						case DIO_u8LOW:
							CLR_BIT(PORTA, Loc_u8PinNum);//0010 1000 &&1111 1101
							break;
					}
				}
				else
				{
					Loc_enuReturnStatus = Dio_enuDirectionError;
				}
				break;
			case DIO_u8PORTB:
				if(GET_BIT(DDRB,Loc_u8PinNum)== DIO_u8OUTPUT_PIN)
				{
					switch(Copy_u8Level)
					{
						case DIO_u8HIGH:
							SET_BIT(PORTB, Loc_u8PinNum);
							break;
						case DIO_u8LOW:
							CLR_BIT(PORTB, Loc_u8PinNum);
							break;
					}
				}
				else
				{
					Loc_enuReturnStatus = Dio_enuDirectionError;
				}
				break;
			case DIO_u8PORTC:
				if(GET_BIT(DDRC,Loc_u8PinNum)== DIO_u8OUTPUT_PIN)
				{
					switch(Copy_u8Level)
					{
						case DIO_u8HIGH:
							SET_BIT(PORTC, Loc_u8PinNum);
							break;
						case DIO_u8LOW:
							CLR_BIT(PORTC, Loc_u8PinNum);
							break;
					}
				}
				else
				{
					Loc_enuReturnStatus = Dio_enuDirectionError;
				}
				break;
			case DIO_u8PORTD:
				if(GET_BIT(DDRD,Loc_u8PinNum)== DIO_u8OUTPUT_PIN)
				{
					switch(Copy_u8Level)
					{
						case DIO_u8HIGH:
							SET_BIT(PORTD, Loc_u8PinNum);
							break;
						case DIO_u8LOW:
							CLR_BIT(PORTD, Loc_u8PinNum);
							break;
					}
				}
				else
				{
					Loc_enuReturnStatus = Dio_enuDirectionError;
				}
				break;
			default:
			{
				Loc_enuReturnStatus = Dio_enuChannelError;
			}
		}
	}
	return Loc_enuReturnStatus ;
}
Dio_tenuErrorStatus Dio_enuReadChannel(u8 Copy_u8ChannelId ,up8 Add_up8ChannelId)
{
	    // Data validation to the inputs
		Dio_tenuErrorStatus Loc_enuReturnStatus = Dio_enuOk ;
		//Local variables area
		u8 Loc_u8PinNum ; // 0 ~ 31 --> 0 ~ 7
		u8 Loc_u8PortNum; // 0 ~ 3 ---> A ~ D
		// Data validation to the inputs
		//Check if the channel is not valid
		if((Copy_u8ChannelId > DIO_u8MAX_CHANNELS) || (Copy_u8ChannelId < DIO_u8MIN_CHANNELS)  )
		{
			Loc_enuReturnStatus = Dio_enuChannelError;
		}
		else if(Add_up8ChannelId == NULL)
		{
			Loc_enuReturnStatus = Dio_enuNullPointer;
		}
		// Our Logic
		else
		{
			Loc_u8PinNum = Copy_u8ChannelId % DIO_u8REG_SIZE;
			Loc_u8PortNum = Copy_u8ChannelId / DIO_u8REG_SIZE ;

			switch(Loc_u8PortNum)
			{
				case DIO_u8PORTA :
					if(GET_BIT(DDRA,Loc_u8PinNum)== DIO_u8INPUT_PIN)
					{
						*Add_up8ChannelId=GET_BIT(PINA,Loc_u8PinNum);
					}
					else
					{
						Loc_enuReturnStatus = Dio_enuDirectionError;
					}
					break;
				case DIO_u8PORTB:
					if(GET_BIT(DDRB,Loc_u8PinNum)== DIO_u8INPUT_PIN)
					{
						*Add_up8ChannelId=GET_BIT(PINB,Loc_u8PinNum);
					}
					else
					{
						Loc_enuReturnStatus = Dio_enuDirectionError;
					}
					break;
				case DIO_u8PORTC:
					if(GET_BIT(DDRC,Loc_u8PinNum)== DIO_u8INPUT_PIN)
					{
						*Add_up8ChannelId=GET_BIT(PINC,Loc_u8PinNum);
					}
					else
					{
						Loc_enuReturnStatus = Dio_enuDirectionError;
					}
					break;
				case DIO_u8PORTD:
					if(GET_BIT(DDRD,Loc_u8PinNum)== DIO_u8INPUT_PIN)
					{
						*Add_up8ChannelId=GET_BIT(PIND,Loc_u8PinNum);
					}
					else
					{
						Loc_enuReturnStatus = Dio_enuDirectionError;
					}
					break;
				default:
				{
					Loc_enuReturnStatus = Dio_enuChannelError;
				}
			}
		}
		return Loc_enuReturnStatus ;
}
Dio_tenuErrorStatus Dio_enuFlipChannel(u8 Copy_u8ChannelId )
{
	// Data validation to the inputs
		Dio_tenuErrorStatus Loc_enuReturnStatus = Dio_enuOk ;

		//Local variables area
		u8 Loc_u8PinNum ; // 0 ~ 31 --> 0 ~ 7
		u8 Loc_u8PortNum; // 0 ~ 3 ---> A ~ D

		// Data validation to the inputs
		//Check if the channel is not valid
		if((Copy_u8ChannelId > DIO_u8MAX_CHANNELS) || (Copy_u8ChannelId < DIO_u8MIN_CHANNELS)  )
		{
			Loc_enuReturnStatus = Dio_enuChannelError;
		}
		// Our Logic
		else
		{
			Loc_u8PinNum = Copy_u8ChannelId % DIO_u8REG_SIZE;
			Loc_u8PortNum = Copy_u8ChannelId / DIO_u8REG_SIZE ;

			switch(Loc_u8PortNum)
			{
				case DIO_u8PORTA :
					TGL_BIT(PORTA, Loc_u8PinNum);
					break;
				case DIO_u8PORTB:
					TGL_BIT(PORTB, Loc_u8PinNum);
					break;
				case DIO_u8PORTC:
					TGL_BIT(PORTC, Loc_u8PinNum);
					break;
				case DIO_u8PORTD:
					TGL_BIT(PORTD, Loc_u8PinNum);
					break;
				default:
				{
					Loc_enuReturnStatus = Dio_enuChannelError;
				}
			}
		}
		return Loc_enuReturnStatus ;
}
Dio_tenuErrorStatus Dio_enuWritePort(u8 Copy_u8PortId,u8 value)
{
	// Data validation to the inputs
		Dio_tenuErrorStatus Loc_enuReturnStatus = Dio_enuOk ;

		//Local variables area
		//u8 Loc_u8PinNum ; // 0 ~ 31 --> 0 ~ 7
		u8 Loc_u8PortNum; // 0 ~ 3 ---> A ~ D

		// Data validation to the inputs
		//Check if the channel is not valid
		if((Copy_u8PortId > DIO_u8MAX_PORT)||(Copy_u8PortId < DIO_u8MIN_PORT) )
		{
			Loc_enuReturnStatus = Dio_enuPortError;
		}
		else if((value<DIO_u8MIN_VALUE)||(value>DIO_u8MAX_VALUE))
		{
			Loc_enuReturnStatus = Dio_enuValueError;
		}
		// Our Logic
		else
		{
			Loc_u8PortNum = Copy_u8PortId ;

			switch(Loc_u8PortNum)
			{
				case DIO_u8PORTA :
					if(DDRA==DIO_u8OUTPUT_PORT)
					{
						ASSIGN_REG(PORTA,value);
					}
					else
					{
						Loc_enuReturnStatus = Dio_enuDirectionError;
					}
					break;
				case DIO_u8PORTB:
					if(DDRB==DIO_u8OUTPUT_PORT)
					{
						ASSIGN_REG(PORTB,value);
					}
					else
					{
						Loc_enuReturnStatus = Dio_enuDirectionError;
					}
					break;
				case DIO_u8PORTC:
					if(DDRC==DIO_u8OUTPUT_PORT)
					{
						ASSIGN_REG(PORTC,value);
					}
					else
					{
						Loc_enuReturnStatus = Dio_enuDirectionError;
					}
					break;
				case DIO_u8PORTD:
					if(DDRD==DIO_u8OUTPUT_PORT)
					{
						ASSIGN_REG(PORTD,value);
					}
					else
					{
						Loc_enuReturnStatus = Dio_enuDirectionError;
					}
					break;
				default:
				{
					Loc_enuReturnStatus = Dio_enuPortError;
				}
			}
		}
		return Loc_enuReturnStatus ;
}
Dio_tenuErrorStatus Dio_enuReadPort(u8 Copy_u8PortId ,up8 Add_up8PortId)
{
	// Data validation to the inputs
			Dio_tenuErrorStatus Loc_enuReturnStatus = Dio_enuOk ;

			//Local variables area
			u8 Loc_u8PortNum; // 0 ~ 3 ---> A ~ D

			// Data validation to the inputs
			//Check if the channel is not valid
			if((Copy_u8PortId > DIO_u8MAX_PORT) || (Copy_u8PortId < DIO_u8MIN_PORT)  )
			{
				Loc_enuReturnStatus = Dio_enuChannelError;
			}
			else if(Add_up8PortId == NULL)
			{
				Loc_enuReturnStatus = Dio_enuNullPointer;
			}
			// Our Logic
			else
			{
				Loc_u8PortNum =Copy_u8PortId ;
				switch(Loc_u8PortNum)
	            {
				case DIO_u8PORTA :
					if(DDRA==DIO_u8INPUT_PORT)
					{
					    *Add_up8PortId= PINA;
					}
					else
					{
						Loc_enuReturnStatus = Dio_enuDirectionError;
					}
					break;
				case DIO_u8PORTB:
					if(DDRB==DIO_u8INPUT_PORT)
					{
						*Add_up8PortId=PINB;
					}
					else
					{
						Loc_enuReturnStatus = Dio_enuDirectionError;
					}
					break;
				case DIO_u8PORTC:
					if(DDRC==DIO_u8INPUT_PORT)
					{
						*Add_up8PortId=PINC;
					}
					else
					{
						Loc_enuReturnStatus = Dio_enuDirectionError;
					}
					break;
				case DIO_u8PORTD:
					if(DDRD==DIO_u8INPUT_PORT)
					{
						*Add_up8PortId=PIND;
					}
					else
					{
						Loc_enuReturnStatus = Dio_enuDirectionError;
					}
					break;
					default:
					{
						Loc_enuReturnStatus = Dio_enuPortError;
					}
				}
			}
			return Loc_enuReturnStatus ;
}

