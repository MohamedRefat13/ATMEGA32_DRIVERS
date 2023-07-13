/*
 * ADC_program.c
 *
 *  Created on: Jun 27, 2023
 *      Author: Mohamed Refat
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/Error.h"
#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"


void ADC_voidInit(void)
{
    /* Select ADC Volatage Reference */
    #if ADC_VOLTAGE_REF   == ADC_AVCC
        CLR_BIT(ADMUX , ADMUX_REFS1);
        SET_BIT(ADMUX , ADMUX_REFS0);
    #elif ADC_VOLTAGE_REF == ADC_AREF
        CLR_BIT(ADMUX , ADMUX_REFS1);
        CLR_BIT(ADMUX , ADMUX_REFS0);
    #elif ADC_VOLTAGE_REF == ADC_INTERNAL_2_56
        SET_BIT(ADMUX , ADMUX_REFS1);
        SET_BIT(ADMUX , ADMUX_REFS0);
    #endif

    

    /* Right/Left Adjust */
    #if ADC_ADJUSTMENT == ADC_LEFT_ADJUST
        SET_BIT(ADMUX , ADMUX_ADLAR);
    #elif ADC_ADJUSTMENT == ADC_RIGHT_ADJUST 
        CLR_BIT(ADMUX , ADMUX_ADLAR);
    #endif    

    /* Select Prescaler */
    ADCSRA &= ADC_PRESCALER_MASK;
    ADCSRA |= ADC_PRESCALER; 

    /* Slect ADC Mode --> [Free Running (INT) , Single Conversion(Polling)]  */
    #if ADC_MODE == ADC_FREE_RUNNING 
        SET_BIT(ADCSRA , ADCSRA_ADIE); //Enable Interrupt

    #elif ADC_MODE == ADC_SINGLE_CONVERSION 
        CLR_BIT(ADCSRA , ADCSRA_ADIE); //Disable Interrupt   
    #else 
        #error "Wrong ADC Mode"
    #endif        

    /* Enable ADC */
    SET_BIT(ADCSRA , ADCSRA_ADEN);
}

Error_t ADC_GetDigitalValue(uint8_t u8Channel , uint16_tt *pDigitalValue)
{
    Error_t LocErrorReturn = NoError; 
    if( u8Channel > ADC_CHANNEL0 && u8Channel<ADC_CHANNEL7  &&  pDigitalValue != NULL_ptr){
        /* Select Channel */
        ADMUX &= ADC_CHANNEL_MASK;
        ADMUX |= u8Channel;

        /* Start Conversion */
        SET_BIT(ADCSRA , ADCSRA_ADSC);


        while ( (GET_BIT(ADCSRA , ADCSRA_ADIF) == 0) );
        #if ADC_MODE == ADC_SINGLE_CONVERSION 
            SET_BIT(ADCSRA , ADCSRA_ADIF);
        #endif    


        #if ADC_ADJUSTMENT == ADC_LEFT_ADJUST
            *pDigitalValue =  (ADCL>>8) | (ADCH<<2)  ;
            //*pDigitalValue = (ADCH<<2) //Error will be very low (3 only)
        #elif  ADC_ADJUSTMENT == ADC_RIGHT_ADJUST
            *pDigitalValue = (ADCL) | (ADCH<<8);
        #endif
    }else{
        LocErrorReturn = FunctioParameterError;
    }
    
    return LocErrorReturn;
}
