/*
 * CLCD_Interface.h
 *
 *  Created on: Mar 7, 2023
 *      Author: Mohamed Refat
 */

#ifndef HAL_04_CLCD_CLCD_INTERFACE_H_
#define HAL_04_CLCD_CLCD_INTERFACE_H_

#define LCD_ROW_1  1
#define LCD_ROW_2  2

#define LCD_COL_1  1
#define LCD_COL_2  2 
#define LCD_COL_3  3
#define LCD_COL_4  4
#define LCD_COL_5  5
#define LCD_COL_6  6
#define LCD_COL_7  7
#define LCD_COL_8  8
#define LCD_COL_9  9
#define LCD_COL_10 10 
#define LCD_COL_11 11
#define LCD_COL_12 12
#define LCD_COL_13 13
#define LCD_COL_14 14
#define LCD_COL_15 15
#define LCD_COL_16 16

void CLCD_Init(void);
void CLCD_ClearScreen(void);
void CLCD_SendtChar(uint8_t Ch);
void CLCD_SendString(uint8_t *str);
/**
 * @brief             :this function used to set cursor position to display your data in s specific posotion 
 * 
 * @param Row_Num     :Row_Num    --> [LCD_ROW_1 , LCD_ROW_2]
 * @param Column_Num  :Column_Num --> [LCD_COL_1 , LCD_COL_2 ... LCD_COL_16]
 */
void CLCD_SetPosition(uint8_t Row_Num ,uint8_t Column_Num);
void CLCD_SendNumber(sint16_t Num);

#endif /* HAL_04_CLCD_CLCD_INTERFACE_H_ */
