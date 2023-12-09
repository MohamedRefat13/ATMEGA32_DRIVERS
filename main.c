/*
 * main.c
 *
 *  Created on: Oct 21, 2023
 *      Author: Mohamed Refat
 */

#include <Util/delay.h>
#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/GIE/GIE_Interface.h"
#include "MCAL/TIMER/TIMER_Interface.h"
#include "HAL/01_LED/LED_Interface.h"
#include "LIB/STD_TYPES.h"
LED_t led = {DIO_PORTB, DIO_PIN5, LED_ACTIVE_HIGH};
volatile uint32_t OverflowNumber = 0 ;
void Timer1_ISR(void){
	if(OverflowNumber == 16){
		OverflowNumber = 0;
		LED_Toggle(led);
		TIMER1_SetPreload(48576);
	}
	OverflowNumber++;
}
int main()
{
	
	//TIMER1_SetCallBackFun(TIMER1_INTERRUPT_OVERFLOW ,Timer1_ISR);
	LED_Init(led);
	DIO_SetPinDirection(DIO_PORTD, DIO_PIN5, DIO_OUTPUT_PIN);
	//GIE_voidGlobalInterruptControl(GLOBAL_INTERRUPT_ENABLE);
	TIMER1_Init(TIMER_PWM_MODE, TIMER1_PRESCALER_1);
	while(1){
		for( int i=0 ; i<=10 ;i++)
		{
			TIMER1_SetDutyCycle(i*10);
			_delay_ms(300);
		}
	}
}
