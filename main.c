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
int main()
{
	TIMER1_SetPWM_Channel_Mode(PWM1_OC1B, PWM1_INVERTING);
	TIMER1_SetPWM_Freq(50, 64);
	TIMER1_SetDutyCycle(50,PWM1_OC1B);
	TIMER1_Init(TIMER_PWM_MODE, TIMER1_PRESCALER_64);
	while(1){

	}
}
   