/*
 * LED_Program.c
 *
 *  Created on: Feb 13, 2023
 *      Author: Mohamed Refat
 */

#include"../../LIB./STD_TYPES.h"
#include"../../MCAL./DIO./DIO_interface.h"
#include "../01_LED/LED_Interface.h"

Error_t LED_Init(LED_t LedConfigration)
{
    Error_t ret_ErrorState = NoError ; 
    ret_ErrorState = DIO_SetPinDirection(LedConfigration.PortNumber , LedConfigration.PinNumber , DIO_OUTPUT_PIN);
    return ret_ErrorState ; 
}

Error_t LED_ON(LED_t LedConfigration)
{
    Error_t ret_ErrorState = NoError ; 
    if(LED_ACTIVE_HIGH ==LedConfigration.Active_Status)
    {
       ret_ErrorState = DIO_SetPinValue(LedConfigration.PortNumber , LedConfigration.PinNumber , DIO_HIGH_PIN); 
    }else if(LED_ACTIVE_LOW ==LedConfigration.Active_Status)
    {
       ret_ErrorState = DIO_SetPinValue(LedConfigration.PortNumber , LedConfigration.PinNumber , DIO_LOW_PIN);
    }else{
        ret_ErrorState = FunctioParameterError ; 
    }
    return ret_ErrorState ; 
} 
    

Error_t LED_OFF(LED_t LedConfigration)
{
    Error_t ret_ErrorState = NoError ; 
    if(LED_ACTIVE_HIGH ==LedConfigration.Active_Status)
    {
       ret_ErrorState = DIO_SetPinValue(LedConfigration.PortNumber , LedConfigration.PinNumber , DIO_LOW_PIN); 
    }else if(LED_ACTIVE_LOW ==LedConfigration.Active_Status)
    {
        ret_ErrorState = DIO_SetPinValue(LedConfigration.PortNumber , LedConfigration.PinNumber , DIO_HIGH_PIN);
    }else{
        ret_ErrorState = FunctioParameterError ; 
    }
    return ret_ErrorState ; 
}

Error_t LED_Toggle(LED_t LedConfigration)
{   
    Error_t ret_ErrorState = NoError ; 
    ret_ErrorState = DIO_TogglePinValue(LedConfigration.PortNumber , LedConfigration.PinNumber);
    return ret_ErrorState ; 
}

