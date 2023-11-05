/*
 * ADC_private.h
 *
 *  Created on: Jun 27, 2023
 *      Author: Mohamed Refat
 */

#ifndef MCAL_ADC_ADC_PRIVATE_H_
#define MCAL_ADC_ADC_PRIVATE_H_



/* ADC Registers  */
#define ADMUX  *((volatile uint8_t   *)0x27 )
#define ADCSRA *((volatile uint8_t   *)0x26 )
#define ADCH   *((volatile uint8_t   *)0x25 )
#define ADCL   *((volatile uint8_t   *)0x24 )
#define ADC    *((volatile uint16_tt *)0x24 )



#define ADMUX_ADLAR             5 
#define ADMUX_REFS0             6
#define ADMUX_REFS1             7   


#define ADCSRA_ADEN             7
#define ADCSRA_ADSC             6
#define ADCSRA_ADATE            5
#define ADCSRA_ADIF             4
#define ADCSRA_ADIE             3


/* Bit Masking Macros */
#define ADC_PRESCALER_MASK 0b11111000 
#define ADC_CHANNEL_MASK   0b11100000 


#define ADC_PRESCALER_2         1
#define ADC_PRESCALER_4         2
#define ADC_PRESCALER_8         3
#define ADC_PRESCALER_16        4
#define ADC_PRESCALER_32        5       
#define ADC_PRESCALER_64        6
#define ADC_PRESCALER_128       7



#endif /* MCAL_ADC_ADC_PRIVATE_H_ */
