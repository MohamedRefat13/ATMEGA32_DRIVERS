/*
 * LED_Manipulation.c
 *
 *  Created on: Mar 9, 2023
 *      Author: Mohamed Refat
 */

#include <Util/delay.h>
#include "../../HAL/01_LED/LED_Interface.h"
#include "LED_Manipulation.h"

void FlashingEvery_1s(LED_t Leds[] )
{
	uint8_t Counter ;
	for(Counter = 0 ; Counter<8 ; Counter++ )
	{
		LED_ON(Leds[Counter]);
	}
	_delay_ms(1000);
	for(Counter = 0 ; Counter<8 ; Counter++ )
	{
		LED_OFF(Leds[Counter]);
	}
	_delay_ms(1000);
}

void ShiftingREvery_250ms(LED_t Leds[] )
{
	uint8_t Counter ;
	for(Counter = 0 ; Counter<8 ; Counter++ )
	{
		LED_ON(Leds[Counter]);
		_delay_ms(250);
		LED_OFF(Leds[Counter]);
		_delay_ms(250);

	}
}

void ShiftingLEvery_250ms(LED_t Leds[] )
{
	sint8_t Counter ;
	for(Counter = 7 ; Counter>= 0 ; Counter-- )
	{
		LED_ON(Leds[Counter]);
		_delay_ms(250);
		LED_OFF(Leds[Counter]);
		_delay_ms(250);
	}
}
void ConvergingLEvery_250ms(LED_t Leds[] )
{

	uint8_t i , j  , k ;
	for(i = 0 , j=7 ; i < j ; i++ , j-- )
	{
		LED_ON(Leds[i]);
		LED_ON(Leds[j]);
		_delay_ms(250);
	}
	for(k = 0 ; k<8 ; k++)
	{
		LED_OFF(Leds[k]);//Turn off all Leds
	}
	_delay_ms(100);
}
void DivergingLEvery_250ms(LED_t Leds[] )
{

	sint8_t i , j , k;
	for(i = 4 , j=3 ; i < 8  ; i++ , j-- )
	{
		LED_ON(Leds[i]);
		LED_ON(Leds[j]);
		_delay_ms(250);

	}
	for(k = 0 ; k<8 ; k++)
	{
		LED_OFF(Leds[k]);//Turn off all Leds
	}
	_delay_ms(100);
}

void PingPongEvery_250ms(LED_t Leds[] )
{
	uint8_t i , j  ;
	for(i = 0 , j=7 ; i < j ; i++ , j-- )
	{
		LED_ON(Leds[i]);
		LED_ON(Leds[j]);
		_delay_ms(250);
		LED_OFF(Leds[i]);
		LED_OFF(Leds[j]);
		_delay_ms(250);

	}
}
void SnakeEffectEvery_250ms(LED_t Leds[] )
{
	uint8_t i , j  ;
	for(i = 0 ; i < 8 ; i++  )
	{
		LED_ON(Leds[i]);
		_delay_ms(250);
	}
	for(j = 0 ; j<8 ; j++)
	{
		LED_OFF(Leds[j]);//Turn off all Leds
	}
	_delay_ms(250);
}
void Conv_Div_Every_250ms(LED_t Leds[] )
{
	ConvergingLEvery_250ms(Leds);
	DivergingLEvery_250ms(Leds);
}
