/*
 * main.c
 *
 *  Created on: Mar 7, 2023
 *      Author: Mohamed Refat
 */


#include <Util/delay.h>
#include "LIB/STD_TYPES.h"
#include "HAL/04_CLCD/CLCD_Interface.h"



int main()
{


	LCD_Init();
	 while(1)
	 {

		 LCD_SendNumber(5);
		 LCD_Display_On();
		 _delay_ms(500);
		 LCD_Display_Off();
		 _delay_ms(500);

		//LCD_SendNumber(5);

	 }



}

