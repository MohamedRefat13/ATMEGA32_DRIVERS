/*
 * main.c
 *
 *  Created on: Oct 21, 2023
 *      Author: Mohamed Refat
 */

#include <Util/delay.h>
#include <util/twi.h>
#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/GIE/GIE_Interface.h"
#include "MCAL/I2C/I2C_Interface.h"
#include "HAL/01_LED/LED_Interface.h"
#include "HAL/04_CLCD/CLCD_Interface.h"
#include "LIB/STD_TYPES.h"
LED_t led = {DIO_PORTB, DIO_PIN5, LED_ACTIVE_HIGH};


//  Master Receiver Code
int main()
{

	LCD_Init();
	I2C_MasterInit(400000, 0x13);
	uint8_t data ;
	LCD_SendString("Received: ");
	while (1)
	{
		I2C_SendStartCondition();
		I2C_SendSlaveAddressWithRead(2);
		I2C_MasterReadByte(&data);
		I2C_SendStopCondition();
		LCD_SendtChar(data);
		if ( data == 'v'){
			LCD_SendString(" ST");
			break;
		}
	}
}

//  // Slave Transmitter Code
//  int main()
//  {
//  	LED_Init(led);
//  	LCD_Init();
//  	I2C_SlaveInit(2);
//  	LCD_SendString("Transmit:");
//  	uint8_t data = 'r';
//  	i2c_error_t error;
//  	while (1)
//  	{
//		LCD_SendtChar(data);
//  		error = I2C_SlaveWriteByte(data++);
//  		if (error == SlaveWriteByteError){
//  			LCD_SendString(" DR");
//  		}
//
//  	}
//  }
