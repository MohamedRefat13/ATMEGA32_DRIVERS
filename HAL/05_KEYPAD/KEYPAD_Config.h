/*
 * KEYPAD_Config.h
 *
 *  Created on: Apr 8, 2023
 *      Author: Mohamed Refat
 */

#ifndef HAL_05_KEYPAD_KEYPAD_CONFIG_H_
#define HAL_05_KEYPAD_KEYPAD_CONFIG_H_

/*Options:
 * 			DIO_PORTA
 * 			DIO_PORTB
 * 			DIO_PORTC
 * 			DIO_PORTD
 * */
#define KEYPAD_Port DIO_PORTD

#define KEYPAD_R1 DIO_PIN0
#define KEYPAD_R2 DIO_PIN1
#define KEYPAD_R3 DIO_PIN2
#define KEYPAD_R4 DIO_PIN3

#define KEYPAD_C1 DIO_PIN4
#define KEYPAD_C2 DIO_PIN5
#define KEYPAD_C3 DIO_PIN6
#define KEYPAD_C4 DIO_PIN7

uint8_t KEYPAD_Bottons[4][4] = 
{
	{'7','8','9','/'},
	{'4','5','6','X'},
	{'1','2','3','-'},
	{'C','0','=','+'}
		
};



#endif /* HAL_05_KEYPAD_KEYPAD_CONFIG_H_ */
