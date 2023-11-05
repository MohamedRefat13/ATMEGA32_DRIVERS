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
            ADC_AVCC  --> internal Voltage reference (connect AVCC pin to the Vcc same as the controller)
            ADC_AREF  --> External Voltage reference (connect ADC_AREF pin to the Vcc[0 , 5v])
            ADC_INTERNAL_2_56 --> internal voltage
 */
#define ADC_VOLTAGE_REF ADC_INTERNAL_2_56

#endif /* MCAL_ADC_ADC_CONFIG_H_ */
