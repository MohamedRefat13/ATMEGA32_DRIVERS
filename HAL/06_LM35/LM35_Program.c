/*
 * LM13_Program.c
 *
 *  Created on: Jul 20, 2023
 *  Author: Mohamed Refat
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/Error.h" 
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/ADC/ADC_interface.h"
#include "LM35_Interface.h"



Error_t LM35_GetTemp(LM35_t *Lm35_Config , uint8_t *pTemp){
    Error_t Ret_ErrorState = NoError ; 
    uint16_tt DigitalVal ;
    uint16_tt AnalogVal  ;
    uint16_tt Voltage_mv ;
    if(LM35_GetTemp != NULL_ptr && pTemp != NULL_ptr){
        if(Lm35_Config->LM35_VREFF == ADC_AVCC || Lm35_Config->LM35_VREFF == ADC_AREF){
        Voltage_mv = 5000LU;
        }else if (Lm35_Config->LM35_VREFF == ADC_INTERNAL_2_56){
            Voltage_mv = 2560LU;
        }else{
            Ret_ErrorState = FunctioParameterError ; 
        }
        if(Lm35_Config->LM35_ChannelNumber >= ADC_CHANNEL0 && Lm35_Config->LM35_ChannelNumber >= ADC_CHANNEL7 ){
            Ret_ErrorState = ADC_GetDigitalValue(Lm35_Config->LM35_ChannelNumber,  &DigitalVal);
            AnalogVal =( ( (uint32_t)DigitalVal * Voltage_mv) /1024 ) ;
            *pTemp =  AnalogVal/10;
        }else{
            Ret_ErrorState = FunctioParameterError ;
        }
    }
    
    return Ret_ErrorState ;

}
