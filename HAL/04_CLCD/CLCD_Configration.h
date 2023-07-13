/*
 * CLCD_Configration.h
 *
 *  Created on: Mar 7, 2023
 *      Author: Mohamed Refat
 */

#ifndef HAL_04_CLCD_CLCD_CONFIGRATION_H_
#define HAL_04_CLCD_CLCD_CONFIGRATION_H_

//typedef struct
//{
//	uint8_t ControlPins_PortNum;
//	uint8_t RS_PinNum ;
//	uint8_t RW_PinNum ;
//	uint8_t EN_PinNum ;
//	uint8_t DATA_PortNum ;
//}CLCD_CONFIG;
/*
    Chose Port Number for Control Pins:-
    CLCD_ControlPins_PortNum ::  DIO_PORTA
                            DIO_PORTB
                            DIO_PORTC
                            DIO_PORTD
 */
#define CLCD_ControlPins_PortNum DIO_PORTA
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
#define CLCD_DATA_PortNum DIO_PORTC

#endif /* HAL_04_CLCD_CLCD_CONFIGRATION_H_ */
