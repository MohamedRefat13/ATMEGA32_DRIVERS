/*
 * KEYPAD_Interface.h
 *
 *  Created on: Apr 8, 2023
 *      Author: Mohamed Refat
 */

#ifndef HAL_05_KEYPAD_KEYPAD_INTERFACE_H_
#define HAL_05_KEYPAD_KEYPAD_INTERFACE_H_


#define KEYPAD_NOTPRESSED 0XFF
void KEYPAD_Init(void);
uint8_t KEYPAD_GetPressedKey(void);

#endif /* HAL_05_KEYPAD_KEYPAD_INTERFACE_H_ */
