#include <stdio.h>
#include <util/delay.h>
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "CLCD_Interface.h"
#include "CLCD_Configration.h"
#include "CLCD_Private.h"


void CLCD_Init(void)
{
	/* SET Direction for LCD pins --> OUTPUT */
	DIO_SetPinDirection(CLCD_ControlPins_PortNum , RS_PinNum , DIO_OUTPUT_PIN );
	DIO_SetPinDirection(CLCD_ControlPins_PortNum , RW_PinNum , DIO_OUTPUT_PIN );
	DIO_SetPinDirection(CLCD_ControlPins_PortNum , EN_PinNum , DIO_OUTPUT_PIN );
	DIO_SetPortDirection(CLCD_DATA_PortNum , DIO_OUTPUT_PORT);

	_delay_ms(100);
	/* Function Set */
	CLCD_SendCommand(0b00111000);
	_delay_ms(5);
	/*   Display ON/OFF Control */
	CLCD_SendCommand(0b00001110);
	_delay_ms(5);
	/*  Clear Screen */
	CLCD_SendCommand(LCD_CLEAR_SCREEN);
	_delay_ms(5);
	/* Entry mode set */
	CLCD_SendCommand(0b00000110);
}


static void CLCD_SendData( uint8_t Data)
{
	/* Set RS to 1 and RW to 0  */
	DIO_SetPinValue(CLCD_ControlPins_PortNum , RS_PinNum, DIO_HIGH_PIN );
	DIO_SetPinValue(CLCD_ControlPins_PortNum , RW_PinNum, DIO_LOW_PIN  );
	DIO_SetPortValue(CLCD_DATA_PortNum, Data);

	/* Send Data to the LCD Port */

	CLCD_SendFallingEndgPulse();
}
static void CLCD_SendCommand(uint8_t Command)
{
	/* Set RS to 0 and RW to 0  */
	DIO_SetPinValue(CLCD_ControlPins_PortNum , RS_PinNum , DIO_LOW_PIN );
	DIO_SetPinValue(CLCD_ControlPins_PortNum , RW_PinNum , DIO_LOW_PIN );

	/* Send Command to the LCD Port */
	DIO_SetPortValue(CLCD_DATA_PortNum , Command);

	CLCD_SendFallingEndgPulse();
}
static void CLCD_SendFallingEndgPulse(void)
{
	DIO_SetPinValue(CLCD_ControlPins_PortNum , EN_PinNum, DIO_HIGH_PIN );
	_delay_ms(1);
	DIO_SetPinValue(CLCD_ControlPins_PortNum , EN_PinNum, DIO_LOW_PIN );
	_delay_ms(1);
	DIO_SetPinValue(CLCD_ControlPins_PortNum , EN_PinNum, DIO_HIGH_PIN );
}
void CLCD_ClearScreen(void)
{
	CLCD_SendCommand(LCD_CLEAR_SCREEN);
	_delay_ms(1);
}
void CLCD_SendtChar(uint8_t Ch)
{
	CLCD_SendData(Ch);
}
void CLCD_SendString(uint8_t *str)
{
	uint8_t Iterator =  0 ; 
	while(str[Iterator]!= '\0')
	{
		CLCD_SendData(str[Iterator++]);
	}
}
void CLCD_SetPosition(uint8_t Row_Num ,uint8_t Column_Num)
{
	uint8_t LocCommand ;
	/* if the user enter invaled location AC will point to the firist place in DDRAM (0 , 0 )  */
	if( Row_Num>LCD_ROW_2 || Row_Num < LCD_ROW_1 || Column_Num > LCD_COL_16 || Column_Num < LCD_COL_1 )
	{
		LocCommand =  LCD_SET_CURSOR ;
	}
	else if(Row_Num == LCD_ROW_1 )
	{
		LocCommand = LCD_SET_CURSOR + Column_Num -1 ;
	}
	else if(Row_Num == LCD_ROW_2 )
	{
		LocCommand = LCD_SET_CURSOR + 64 +  Column_Num -1 ;
	}
	CLCD_SendCommand(LocCommand);
	_delay_ms(1);
}
void CLCD_SendNumber(sint16_t Num)
{
	sint16_t Loc_Temp = Num ; 
	uint8_t Iterator = 0 ;
	uint8_t Iterator_2 = 0 ;
	uint8_t Negative_Flag = 0 ;
	char Num_Arr[5] = {};
	/* Store Number in Num_Arr as a string 
		but the number will be stored in reverse order in the array so we need to reverse this array again 
	 */
	if(Num==0)
	{
		CLCD_SendtChar('0');
		return;
	}
	if(Num<0)
	{
		Num = Num * (-1) ;  
		Negative_Flag = 1 ; 
	}
	while(Num != 0 )
	{
		Loc_Temp = Num % 10 ; 
		Num_Arr[Iterator++] = ( Loc_Temp + '0' ) ;
		Num = Num / 10 ;
	}
	/* Revers Num_arr */
	for(Iterator_2 = 0 ; Iterator_2 < Iterator/2 ; Iterator_2++)
	{
		char temp = Num_Arr[Iterator_2];
		Num_Arr[Iterator_2 ] = Num_Arr[Iterator-Iterator_2-1];
		Num_Arr[Iterator-Iterator_2-1] = temp;
	}

	for(Iterator_2 = 0 ; Iterator_2 < Iterator ; Iterator_2++ )
	{
		if(Negative_Flag)
		{
			CLCD_SendtChar('-');
			Negative_Flag = 0 ; 
		}
		CLCD_SendtChar(Num_Arr[Iterator_2]);
	}
}


