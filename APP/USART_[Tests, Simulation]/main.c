///*
// * main.c
// *
// *  Created on: Oct 21, 2023
// *      Author: Mohamed Refat
// */
//
//#include <Util/delay.h>
//#include "MCAL/DIO/DIO_interface.h"
//#include "MCAL/GIE/GIE_Interface.h"
//#include "MCAL/USART/USART_Interface.h"
//#include "HAL/01_LED/LED_Interface.h"
//#include "HAL/04_CLCD/CLCD_Interface.h"
//#include "LIB/STD_TYPES.h"
//LED_t led = {DIO_PORTB, DIO_PIN5, LED_ACTIVE_HIGH};
//char str[50] = {};
//
//	char data;
//void Receive_ISR(char *Data)
//{
//	LCD_ClearScreen();
//	LCD_SendString("Data :: ");
//	LCD_SetPosition(LCD_ROW_2,LCD_COL_1);
//	LCD_SendString(Data);
//}
//
//void Transmit_ISR(char *Data)
//{
//	LCD_ClearScreen();
//	LCD_SendString("Data :: ");
//	LCD_SetPosition(LCD_ROW_2,LCD_COL_1);
//	LCD_SendString(Data);
//}
//int main()
//{
//	USART_Init(9600);
//	USART_EnableTransmitter();
//	USART_EnableReceiver();
//	LED_Init(led);
//	LCD_Init();
//
//
//	USART_RxInterruptControl(USART_RX_INTERRUPT_ENABLE);
//	GIE_voidGlobalInterruptControl(GLOBAL_INTERRUPT_ENABLE);
//	//USART_SendStringAsyn(str,Transmit_ISR );
//	USART_ReceiveStringAsyn(str,10,Receive_ISR);
//	//USART_ReceiveCharAsyn(&data , Receive_ISR);
//	while (1)
//	{
//		LED_Toggle(led);
//		_delay_ms(600);
//	}
//
//}
