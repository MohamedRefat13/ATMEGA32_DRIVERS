/*
 * ADC_interface.h
 *
 *  Created on: Jun 27, 2023
 *      Author: Mohamed Refat
 */

#ifndef MCAL_ADC_ADC_INTERFACE_H_
#define MCAL_ADC_ADC_INTERFACE_H_


typedef enum {  
    ADC_CHANNEL0,
    ADC_CHANNEL1,
    ADC_CHANNEL2,
    ADC_CHANNEL3,
    ADC_CHANNEL4,
    ADC_CHANNEL5,
    ADC_CHANNEL6,
    ADC_CHANNEL7
}ADC_Channel_t;

/* enum ADC_VREFF{
    ADC_AVCC ,
    ADC_AREF ,
    ADC_INTERNAL_2_56
}; */


#define ADC_AVCC          0
#define ADC_AREF          1
#define ADC_INTERNAL_2_56 2 

#define ADC_FREE_RUNNING        0
#define ADC_SINGLE_CONVERSION   1

#define ADC_RIGHT_ADJUST        0
#define ADC_LEFT_ADJUST         1



void ADC_voidInit(void);
/**
 * @brief This function used to get the digital value that is equivelent to the input voltage to the ADC channel
 * 
 * @param u8Channel  ADC in ATmega has 8 channel in Port A [ ADC_CHANNEL0 -->  ADC_CHANNEL0 ]
 * @param pDigitalValue 
 * @return Error_t 
 */
Error_t ADC_GetDigitalValue(uint8_t u8Channel , uint16_tt *pDigitalValue);




#endif /* MCAL_ADC_ADC_INTERFACE_H_ */
