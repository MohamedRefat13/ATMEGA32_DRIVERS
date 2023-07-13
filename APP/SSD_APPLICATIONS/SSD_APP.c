/*
 * SSD_APP.c
 *
 *  Created on: May 2, 2023
 *      Author: mo7am
 */

#ifndef APP_SSD_APPLICATIONS_SSD_APP_C_
#define APP_SSD_APPLICATIONS_SSD_APP_C_
#include <Util/delay.h>
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../HAL/02_SSD/SSD_Interface.h"

#include "SSD_APP.h"
void SSD_DrowAnimation(SSD_t SSD_Config )
{
	uint8_t Animation_Arr[6] = {0b0000001,0b0000010 ,0b0000100 , 0b0001000, 0b0010000 ,0b0100000 };
	uint8_t i=0 ;
	for(i = 0  ; i < 6 ; i++)
	{
		SSD_WriteShape(SSD_Config ,Animation_Arr[i] );
		_delay_ms(250);
	}
}
void SSD_CountUpWithBotton(SSD_t SSD_Config , uint8_t BottomPort , uint8_t BottomPin)
{
	sint8_t i = 0 ;
	uint8_t ButtomVal;
	while(i<=9)
	{
		SSD_WriteNum(SSD_Config , i );
		DIO_GetPinValue(BottomPort , BottomPin , &ButtomVal);
		if(ButtomVal == DIO_HIGH_PIN)
		{
			_delay_ms(50);
			DIO_GetPinValue(BottomPort , BottomPin , &ButtomVal);
			if(ButtomVal == DIO_HIGH_PIN){
				i++;
				ButtomVal = 0 ;
			}
		}
	}
}
void SSD_CountFrom1To99(SSD_t SSD_Right , SSD_t SSD_Left)
{
	sint8_t i=0  , j=0 ;
	while(j<=9)
	{
		SSD_WriteNum(SSD_Left,j);
		for(i = 0  ; i <= 9 ; i++)
		{
			SSD_WriteNum(SSD_Right,i);
			_delay_ms(200);
		}
		j++;
	}
}
void SSD_CountUpDpown(SSD_t SSD_Config)
{
	sint8_t i ;
	for(i = 0  ; i <= 9 ; i++)
	{
		SSD_WriteNum(SSD_Config,i);
		_delay_ms(500);
	}
	for(i = 8  ; i >= 0 ; i--)
	{
		SSD_WriteNum(SSD_Config,i);
		_delay_ms(500);
	}
}


#endif /* APP_SSD_APPLICATIONS_SSD_APP_C_ */
