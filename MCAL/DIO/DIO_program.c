/*
 * DIO_program.c
 *
 *  Created on: Feb 9, 2023
 *  Author: Mohamed Refat
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/Error.h"
#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"


Error_t DIO_SetPinDirection(uint8_t PortNumber , uint8_t PinNumber , uint8_t Direction)
{
	Error_t LocReturnError = NoError ;
	/* Make sure that the Port number and Pin nuber are in the valid range */
	if(PortNumber <= DIO_PORTD && PinNumber <= DIO_PIN7 ) 
	{
		if(Direction == DIO_OUTPUT_PIN)
		{
			switch(PortNumber)
			{
				case DIO_PORTA : SET_BIT(DDRA_REG , PinNumber); break;
				case DIO_PORTB : SET_BIT(DDRB_REG , PinNumber); break;
				case DIO_PORTC : SET_BIT(DDRC_REG , PinNumber); break;
				case DIO_PORTD : SET_BIT(DDRD_REG , PinNumber); break;
			}
		}
		else if (Direction == DIO_INPUT_PIN)
		{
			switch(PortNumber)
			{
				case DIO_PORTA : CLR_BIT(DDRA_REG , PinNumber); break;
				case DIO_PORTB : CLR_BIT(DDRB_REG , PinNumber); break;
				case DIO_PORTC : CLR_BIT(DDRC_REG , PinNumber); break;
				case DIO_PORTD : CLR_BIT(DDRD_REG , PinNumber); break;
			}
		}
	}else
	{
		LocReturnError = FunctioParameterError  ; 
	} 

	return LocReturnError ; 
}

Error_t DIO_SetPinValue(uint8_t PortNumber , uint8_t PinNumber , uint8_t PintVoltageLevel)
{
	/* Make sure that the Port number and Pin nuber are in the valid range */
	Error_t LocReturnError = NoError ;
	if(PortNumber <= DIO_PORTD && PinNumber <= DIO_PIN7 ) 
	{
		if(PintVoltageLevel ==DIO_HIGH_PIN)
		{
			switch(PortNumber)
			{
				case DIO_PORTA : SET_BIT(PORTA_REG , PinNumber); break;
				case DIO_PORTB : SET_BIT(PORTB_REG , PinNumber); break;
				case DIO_PORTC : SET_BIT(PORTC_REG , PinNumber); break;
				case DIO_PORTD : SET_BIT(PORTD_REG , PinNumber); break;
			}
		}
		else if (PintVoltageLevel ==DIO_LOW_PIN)
		{
			switch(PortNumber)
			{
				case DIO_PORTA : CLR_BIT(PORTA_REG , PinNumber); break;
				case DIO_PORTB : CLR_BIT(PORTB_REG , PinNumber); break;
				case DIO_PORTC : CLR_BIT(PORTC_REG , PinNumber); break;
				case DIO_PORTD : CLR_BIT(PORTD_REG , PinNumber); break;
			}
		}
	}else
	{
		LocReturnError = FunctioParameterError  ; 
	}
	return LocReturnError ; 
}

Error_t DIO_GetPinValue(uint8_t PortNumber , uint8_t PinNumber , uint8_t *PinVal)
{
	Error_t LocReturnError = NoError ; 
	if(PortNumber <= DIO_PORTD && PinNumber <= DIO_PIN7 ) 
	{
		switch(PortNumber)
		{

			case DIO_PORTA :   *PinVal =  GET_BIT(PINA_REG ,PinNumber);break;
			case DIO_PORTB :   *PinVal =  GET_BIT(PINB_REG ,PinNumber);break;
			case DIO_PORTC :   *PinVal =  GET_BIT(PINC_REG ,PinNumber);break;
			case DIO_PORTD :   *PinVal =  GET_BIT(PIND_REG ,PinNumber);break;
		}

	}else
	{
		LocReturnError = FunctioParameterError  ; 
	}
	return LocReturnError ; 
}


Error_t DIO_SetPortDirection(uint8_t PortNumber , uint8_t Direction)
 {
	Error_t LocReturnError = NoError ;
	if(PortNumber <= DIO_PORTD)
	{
 		switch( PortNumber )
 		{
			case DIO_PORTA : DDRA_REG = Direction ;  break;
			case DIO_PORTB : DDRB_REG = Direction ;  break;
			case DIO_PORTC : DDRC_REG = Direction ;  break;
			case DIO_PORTD : DDRD_REG = Direction ;  break;
 		}	
	}else
	{
		LocReturnError = FunctioParameterError  ; 
	}
	return LocReturnError ;
 }


 Error_t DIO_SetPortValue(uint8_t PortNumber , uint8_t PortValue )
 {
	Error_t LocReturnError = NoError ;
	if(PortNumber <= DIO_PORTD)
	{
 		switch( PortNumber )
 		{
 			case DIO_PORTA : PORTA_REG = PortValue ;  break;
 			case DIO_PORTB : PORTB_REG = PortValue ;  break;
 			case DIO_PORTC : PORTC_REG = PortValue ;  break;
 			case DIO_PORTD : PORTD_REG = PortValue ;  break;

 		}
	}else
	{
		LocReturnError = FunctioParameterError  ; 
	}

	return LocReturnError ;	
 }


Error_t DIO_TogglePinValue(uint8_t PortNumber , uint8_t PinNumber)
{

	Error_t LocReturnError = NoError ;
	if(PortNumber <= DIO_PORTD)
	{
 		switch( PortNumber )
 		{
			case DIO_PORTA : TOG_BIT(PORTA_REG , PinNumber ) ;  break;
			case DIO_PORTB : TOG_BIT(PORTB_REG , PinNumber ) ;  break;
			case DIO_PORTC : TOG_BIT(PORTC_REG , PinNumber ) ;  break;
			case DIO_PORTD : TOG_BIT(PORTD_REG , PinNumber ) ;  break;
 		}	
	}else
	{
		LocReturnError = FunctioParameterError  ; 
	}
	return LocReturnError ;

}

Error_t DIO_SetLowNibbleValue(uint8_t PortNumber , uint8_t Value)
{
	Error_t LocReturnError = NoError ;
	/* This line to make sure that the high nibble in port value will not change */
	Value &= 0X0F;
	switch (PortNumber)
	{
		case DIO_PORTA : PORTA_REG &= 0XF0 ; PORTA_REG |= Value ;  break;
		case DIO_PORTB : PORTB_REG &= 0XF0 ; PORTB_REG |= Value ;  break;
		case DIO_PORTC : PORTC_REG &= 0XF0 ; PORTC_REG |= Value ;  break;
		case DIO_PORTD : PORTD_REG &= 0XF0 ; PORTD_REG |= Value ;  break;
		default        : LocReturnError = FunctioParameterError ;break;
	}
	return LocReturnError ;
}
Error_t DIO_SetHighNibbleValue(uint8_t PortNumber , uint8_t Value)
{
	Error_t LocReturnError = NoError ;
	/* This line to make sure that the Low nibble in port value will not change */
	Value &= 0XF0;
	switch (PortNumber)
	{
		case DIO_PORTA : PORTA_REG &= 0X0F ; PORTA_REG |= Value ;  break;
		case DIO_PORTB : PORTB_REG &= 0X0F ; PORTB_REG |= Value ;  break;
		case DIO_PORTC : PORTC_REG &= 0X0F ; PORTC_REG |= Value ;  break;
		case DIO_PORTD : PORTD_REG &= 0X0F ; PORTD_REG |= Value ;  break;
		default        : LocReturnError = FunctioParameterError ;break;
	}
	return LocReturnError ;
}
/*
EX OF LOW NIBBLE:
	ASSUME DATA 0b1010 1101  -->4MSB bit have garbage  
	[1]  DATA   &= 0X0F ; --> DATA  = 0b0000 1101
	[2]  PORTA  &= 0XF0 ; --> PORTA = 0bxxxx 0000
	[2]  PORTA_ |= DATA ; --> PORTA = 0bxxxx 1101
 */