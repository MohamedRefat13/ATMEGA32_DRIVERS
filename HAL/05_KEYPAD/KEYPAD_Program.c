/*
 * KEYPAD_Program.c
 *
 *  Created on: Apr 8, 2023
 *      Author: Mohamed Refat
 */

#include <util/delay.h>
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "KEYPAD_Interface.h"
#include "KEYPAD_Config.h"
#include "KEYPAD_Private.h"

void KEYPAD_Init(void)
{
	/*Define KeyPad Rows Pin as Input Pull Up*/
	/* PIN-->0 (INPUT) */
	DIO_SetPinDirection(KEYPAD_Port , KEYPAD_R1 , DIO_INPUT_PIN);
	DIO_SetPinDirection(KEYPAD_Port , KEYPAD_R2 , DIO_INPUT_PIN);
	DIO_SetPinDirection(KEYPAD_Port , KEYPAD_R3 , DIO_INPUT_PIN);
	DIO_SetPinDirection(KEYPAD_Port , KEYPAD_R4 , DIO_INPUT_PIN);
	/* PORT->1 (Active Pull Up) */
	DIO_SetPinValue(KEYPAD_Port , KEYPAD_R1 , DIO_HIGH_PIN);
	DIO_SetPinValue(KEYPAD_Port , KEYPAD_R2 , DIO_HIGH_PIN);
	DIO_SetPinValue(KEYPAD_Port , KEYPAD_R3 , DIO_HIGH_PIN);
	DIO_SetPinValue(KEYPAD_Port , KEYPAD_R4 , DIO_HIGH_PIN);

	/*Define KeyPad Column Pin as OUTPUT Pins*/
	DIO_SetPinDirection(KEYPAD_Port , KEYPAD_C1 , DIO_OUTPUT_PIN);
	DIO_SetPinDirection(KEYPAD_Port , KEYPAD_C2 , DIO_OUTPUT_PIN);
	DIO_SetPinDirection(KEYPAD_Port , KEYPAD_C3 , DIO_OUTPUT_PIN);
	DIO_SetPinDirection(KEYPAD_Port , KEYPAD_C4 , DIO_OUTPUT_PIN);

	/*Set KeyPad Column Pin HIGH Pins*/
	DIO_SetPinValue(KEYPAD_Port , KEYPAD_C1 , DIO_HIGH_PIN);
	DIO_SetPinValue(KEYPAD_Port , KEYPAD_C2 , DIO_HIGH_PIN);
	DIO_SetPinValue(KEYPAD_Port , KEYPAD_C3 , DIO_HIGH_PIN);
	DIO_SetPinValue(KEYPAD_Port , KEYPAD_C4 , DIO_HIGH_PIN);
}
uint8_t KEYPAD_GetPressedKey(void)
{
	uint8_t LocReturnKey  = KEYPAD_NOTPRESSED ;
	uint8_t LocPressedVal ;
	uint8_t Col_Iterator ; 
	uint8_t Row_Iterator;
	for(Col_Iterator = KEYPAD_C1 ; Col_Iterator<= KEYPAD_C4 ; Col_Iterator++ ){

		DIO_SetPinValue(KEYPAD_Port ,  Col_Iterator , DIO_LOW_PIN );

		for(Row_Iterator=KEYPAD_R1 ; Row_Iterator<=KEYPAD_R4 ; Row_Iterator++ ){

			DIO_GetPinValue(KEYPAD_Port , Row_Iterator , &LocPressedVal);
			if(LocPressedVal == DIO_LOW_PIN ){
				_delay_ms(50); // Sovle Depouncing issue by sw
				if(LocPressedVal==DIO_LOW_PIN){
					LocReturnKey = KEYPAD_Bottons[Row_Iterator][Col_Iterator-4];
				}
			 	/* IF the key still pressed this function will return the same data again
					so we need to make a delay 200 ms or insted of this we do as the following --> 
				 */
				DIO_GetPinValue(KEYPAD_Port , Row_Iterator , &LocPressedVal);
				while(LocPressedVal == DIO_LOW_PIN){//Button still pressed
					DIO_GetPinValue(KEYPAD_Port ,  Row_Iterator , &LocPressedVal);
				}
				return LocReturnKey ;
			}
		}
		DIO_SetPinValue(KEYPAD_Port ,  Col_Iterator , DIO_HIGH_PIN );
	}

	return LocReturnKey ;
}
