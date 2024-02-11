///*
// * main.c
// *
// *  Created on: Oct 21, 2023
// *      Author: Mohamed Refat
// */
//
//#include <Util/delay.h>
//#include <util/twi.h>
//#include "MCAL/DIO/DIO_interface.h"
//#include "MCAL/GIE/GIE_Interface.h"
//#include "MCAL/I2C/I2C_Interface.h"
//#include "HAL/01_LED/LED_Interface.h"
//#include "HAL/04_CLCD/CLCD_Interface.h"
//#include "LIB/STD_TYPES.h"
//LED_t led = {DIO_PORTB, DIO_PIN5, LED_ACTIVE_HIGH};
//
//
////  Master Code
//int main()
//{
//
//	LCD_Init();
//	I2C_MasterInit(400000, 0x13);
//	uint8_t data = 'r';
//	LCD_SendString("Transmit: ");
//	while (1)
//	{
//		LCD_SendtChar(data);
//		I2C_SendStartCondition();
//		I2C_SendSlaveAddressWithWrite(2);
//		I2C_MasterWriteByte(data++);
//		I2C_SendStopCondition();
//		if ( data == 'v'){
//			break;
//		}
//	}
//}
//
////  // Slave Code
////  int main()
////  {
////  	LED_Init(led);
////  	LCD_Init();
////  	I2C_SlaveInit(2);
////  	LCD_SendString("Data:");
////  	uint8_t data;
////  	while (1)
////  	{
////  		I2C_SlaveReadByte(&data);
////  		LCD_SendtChar(data);
////  	}
////  }
