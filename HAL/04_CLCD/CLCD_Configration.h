/*
 * CLCD_Configration.h
 *
 *  Created on: Mar 7, 2023
 *      Author: Mohamed Refat
 */

#ifndef HAL_04_CLCD_CLCD_CONFIGRATION_H_
#define HAL_04_CLCD_CLCD_CONFIGRATION_H_

/**
 * Chose Mode [4bit or 8bit]
 * 
 * options:
 *          LCD_8Bit
 *          LCD_4Bit
 */
#define LCD_MODE  LCD_8Bit
/**
 * Chose Nibble [High , Low]
 * options : LCD_HIGH_NIBBLE
 *           LCD_LOW_NIBBLE
 * Not Valid in 8 bit Mode
 */
/* TO DO :
    Debug High Nibble it doent work
*/
#define LCD_4_BIT_DATA_PIN  LCD_LOW_NIBBLE

/*
    Chose Port Number for Control Pins:-
    CLCD_ControlPins_PortNum ::  DIO_PORTA
                            DIO_PORTB
                            DIO_PORTC
                            DIO_PORTD
 */
#define LCD_ControlPins_PortNum DIO_PORTA
/* Control Pins From DIO_PIN0 --> DIO_PIN7 */
#define RS_PinNum DIO_PIN0
#define RW_PinNum DIO_PIN1
#define EN_PinNum DIO_PIN2

/*
    Chose Port Number for Data Pins:-
    CLCD_DATA_PortNum ::  DIO_PORTA
                            DIO_PORTB
                            DIO_PORTC
                            DIO_PORTD
 */
#define LCD_DATA_PortNum DIO_PORTC


#endif /* HAL_04_CLCD_CLCD_CONFIGRATION_H_ */


//typedef struct
//{
//	uint8_t ControlPins_PortNum;
//	uint8_t RS_PinNum ;
//	uint8_t RW_PinNum ;
//	uint8_t EN_PinNum ;
//	uint8_t DATA_PortNum ;
//}CLCD_CONFIG;
