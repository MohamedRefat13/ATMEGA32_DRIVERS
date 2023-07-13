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
int main()
{
	/* ADC_voidInit();
	CLCD_Init();
	GIE_VoidGlobalInterruptControl(GLOBAL_INTERRUPT_ENABLE);
	uint16_tt Digital_Val ;
	uint16_tt Analog_Val ;

	while(1)
	{
		ADC_GetDigitalValue(ADC_CHANNEL4 , &Digital_Val);
		Analog_Val = ( Digital_Val *5000.0) /1024;
		CLCD_SendNumber(Analog_Val);
		CLCD_SetPosition(LCD_ROW_1 , LCD_COL_6);
		CLCD_SendString("(mv)");
		_delay_ms(100);
		CLCD_ClearScreen();
	} */
	
	CLCD_Init();
	SWITCH_t sw = {DIO_PORTB , DIO_PIN2 , SW_PULL_UP};
	SWITCH_Init(sw);
	uint8_t i =0 ; 
	uint16_tt  pressed_Val ;
	while (1)
	{
		pressed_Val = SWITCH_GetPressed(sw);
		if(pressed_Val == SW_PRESSED){
			i++;
			CLCD_SendNumber(i);
		}
	}
	


}

