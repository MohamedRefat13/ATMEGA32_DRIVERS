/*
 * main.c
 *
 *  Created on: Mar 7, 2023
 *      Author: Mohamed Refat
 */


#include <Util/delay.h>
#include "LIB/STD_TYPES.h"
#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/GIE/GIE_Interface.h"
#include "MCAL/EXTI/EXTI_Interface.h"
#include "MCAL/ADC/ADC_interface.h"
#include "HAL/04_CLCD/CLCD_Interface.h"
#include "HAL/01_LED/LED_Interface.h"
#include "HAL/05_KEYPAD/KEYPAD_Interface.h"
#include "HAL/03_SWITCH/SWITCH_Interface.h"
#include "HAL/02_SSD/SSD_Interface.h"
#include "APP/SSD_APPLICATIONS/SSD_APP.h"
#include "HAL/06_LM35/LM35_Interface.h"

int main()
{
	LM35_t lm35 = {ADC_CHANNEL7  ,5};

	LCD_Init();
	ADC_voidInit();
	uint8_t temp ;
	 while(1)
	 {
		LM35_GetTemp(&lm35 , &temp);
		LCD_SendNumber(temp);
		_delay_ms(100);
		LCD_ClearScreen();

	 }


}

