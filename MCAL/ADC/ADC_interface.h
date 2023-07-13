/*
 * ADC_interface.h
 *
 *  Created on: Jun 27, 2023
 *      Author: Mohamed Refat
 */

#ifndef MCAL_ADC_ADC_INTERFACE_H_
#define MCAL_ADC_ADC_INTERFACE_H_


#define ADC_CHANNEL0            0
#define ADC_CHANNEL1            1
#define ADC_CHANNEL2            2
#define ADC_CHANNEL3            3
#define ADC_CHANNEL4            4
#define ADC_CHANNEL5            5
#define ADC_CHANNEL6            6
#define ADC_CHANNEL7            7

#define ADC_FREE_RUNNING        0
#define ADC_SINGLE_CONVERSION   1

#define ADC_RIGHT_ADJUST        0
#define ADC_LEFT_ADJUST         1


#define         ADC_AVCC            0   
#define         ADC_AREF            1   
#define         ADC_INTERNAL_2_56   2


void ADC_voidInit(void);
Error_t ADC_GetDigitalValue(uint8_t u8Channel , uint16_tt *pDigitalValue);




#endif /* MCAL_ADC_ADC_INTERFACE_H_ */
