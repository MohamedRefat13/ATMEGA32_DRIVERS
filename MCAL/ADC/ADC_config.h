/*
 * ADC_config.h
 *
 *  Created on: Jun 27, 2023
 *      Author: Mohamed Refat
 */

#ifndef MCAL_ADC_ADC_CONFIG_H_
#define MCAL_ADC_ADC_CONFIG_H_

/* Options:
            ADC_FREE_RUNNING 
            ADC_SINGLE_CONVERSION 
 */
#define ADC_MODE ADC_SINGLE_CONVERSION

/* Options:
            ADC_PRESCALER_2  
            ADC_PRESCALER_4  
            ADC_PRESCALER_8  
            ADC_PRESCALER_16 
            ADC_PRESCALER_32 
            ADC_PRESCALER_64 
            ADC_PRESCALER_128
 */
#define ADC_PRESCALER ADC_PRESCALER_128

/* Options:
            ADC_RIGHT_ADJUST
            ADC_LEFT_ADJUST
            
 */
#define ADC_ADJUSTMENT ADC_LEFT_ADJUST

/* Options:
            ADC_AVCC
            ADC_AREF
            ADC_INTERNAL_2_56
 */
#define ADC_VOLTAGE_REF ADC_AVCC

#endif /* MCAL_ADC_ADC_CONFIG_H_ */
