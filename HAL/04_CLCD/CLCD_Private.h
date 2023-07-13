/*
 * CLCD_Private.h
 *
 *  Created on: Mar 7, 2023
 *      Author: Mohamed Refat
 */

#ifndef HAL_04_CLCD_CLCD_PRIVATE_H_
#define HAL_04_CLCD_CLCD_PRIVATE_H_



#define LCD_CLEAR_SCREEN 0x01
#define LCD_SET_CURSOR   0x80


static void CLCD_SendFallingEndgPulse(void);
static void CLCD_SendData(uint8_t Data);
static void CLCD_SendCommand(uint8_t Command);
#endif /* HAL_04_CLCD_CLCD_PRIVATE_H_ */
