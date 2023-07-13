/*
 * SWITCH_Program.c
 *
 *  Created on: Mar 1, 2023
 *      Author: Mohamed Refat
 */
#include <Util/delay.h>
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/Error.h" 
#include "../../MCAL/DIO/DIO_interface.h"
#include "SWITCH_Interface.h"
#include "SWITCH_Private.h"
#include "SWITCH_Config.h"

Error_t SWITCH_Init(SWITCH_t Switch_Config )
{
    Error_t return_ErrorState = NoError ; 
    return_ErrorState  = DIO_SetPinDirection(Switch_Config.SW_PortNum , Switch_Config.SW_PinNum , DIO_INPUT_PIN);
    return return_ErrorState;
}

Error_t SWITCH_GetPressed(SWITCH_t Switch_Config , SWITCH_STATE_t *pPressedValue)
{
    Error_t return_ErrorState = NoError ; 
    uint8_t loc_PinVal = DIO_HIGH_PIN;
    return_ErrorState  = DIO_GetPinValue(Switch_Config.SW_PortNum , Switch_Config.SW_PinNum ,&loc_PinVal);

    if(Switch_Config.SW_State == SW_PULL_UP)
    {
        if(loc_PinVal == DIO_HIGH_PIN)
        {
            *pPressedValue = SW_NOT_PRESSED ; 

        }else if (loc_PinVal == DIO_LOW_PIN)
        {
        	_delay_ms(50);
        	return_ErrorState  = DIO_GetPinValue(Switch_Config.SW_PortNum , Switch_Config.SW_PinNum ,&loc_PinVal);
        	if (loc_PinVal == DIO_LOW_PIN)
        	{
        		*pPressedValue = SW_PRESSED ;
        	}

        }
    }
    else if(Switch_Config.SW_State == SW_PULL_DOWN)
    {

        if(loc_PinVal == DIO_HIGH_PIN)
        {
            *pPressedValue = SW_PRESSED ; 

        }else if (loc_PinVal == DIO_LOW_PIN)
        {
            *pPressedValue = SW_NOT_PRESSED ; 
        }
    }
    return return_ErrorState ; 
}
//_delay_ms(50);
//DIO_GetPinValue(Switch_Config.SW_PortNum , Switch_Config.SW_PinNum ,&loc_PinVal);
//if (loc_PinVal == DIO_HIGH_PIN)
//{
//	Loc_SW_State = SW_PRESSED ;
//}
