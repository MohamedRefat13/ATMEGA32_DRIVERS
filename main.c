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
#include "MCAL/WDT/WDT.h"
#include "MCAL/DIO/DIO_interface.h"
#include "HAL/01_LED/LED_Interface.h"
#include "HAL/04_CLCD/CLCD_Interface.h"

int main()
{
	LED_t led={DIO_PORTB,DIO_PIN0,LED_ACTIVE_HIGH};
	LCD_Init();
	LCD_SendString("Hello");
	_delay_ms(1000);
	LCD_ClearScreen();
	LED_Init(led);
	LED_OFF(led);
	WDT_SetTimeOut(WDT_1s0);
	while(1){
		LED_ON(led);
		WDT_Enable();
		_delay_ms(2000);
		LED_OFF(led);
	}
	
}
