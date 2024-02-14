/**
 * @file main.c
 * @author Mohamed Refat 
 * @brief 
 * @version 0.1
 * @date 2024-02-12
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <Util/delay.h>
#include "LIB/STD_TYPES.h"
#include "MCAL/DIO/DIO_interface.h"
#include "HAL/01_LED/LED_Interface.h"
#include "HAL/08_SERVO/SERVO_Interface.h"
int main()
{
	SERVO_Init(SERVO_OC1B_PIN);

	while(1){
		for (int i = 0; i <= 180 ; i+=10)
		{
			SERVO_SetAngle(i,SERVO_OC1B_PIN);
			_delay_ms(500);
		}
		for (int i = 180; i >= 0 ; i-=10)
		{
			SERVO_SetAngle(i,SERVO_OC1B_PIN);
			_delay_ms(500);
		}
	}
}