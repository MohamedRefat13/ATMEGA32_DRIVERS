/*
 * SSD_Program.c
 *
 *  Created on: Feb 15, 2023
 *      Author: Mohamed Refat
 */
#include"../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include"SSD_Private.h"
#include"SSD_Interface.h"
#include"SSD_Config.h"

uint8_t SSD_u8Numbers[] = SSD_NUM ;
void SSD_Init(SSD_t SSD_Congfig )
{
    DIO_SetPortDirection ( SSD_Congfig.PortNum , DIO_OUTPUT_PORT );
    DIO_SetPinDirection(SSD_Congfig.CommonPin_PortNum , SSD_Congfig.CommonPin_Num , DIO_OUTPUT_PIN);
  
}

void SSD_Enable(SSD_t SSD_Congfig )
{

    if( SSD_Congfig.SSD_Mode == SSD_CC )
    {
        DIO_SetPinValue(SSD_Congfig.CommonPin_PortNum , SSD_Congfig.CommonPin_Num , DIO_LOW_PIN);
    }else if( SSD_Congfig.SSD_Mode == SSD_CA )
    {
        DIO_SetPinValue(SSD_Congfig.CommonPin_PortNum , SSD_Congfig.CommonPin_Num , DIO_HIGH_PIN);
    }  
}
void SSD_Disable(SSD_t SSD_Congfig )
{
    if( SSD_Congfig.SSD_Mode == SSD_CC )
    {
        DIO_SetPinValue(SSD_Congfig.CommonPin_PortNum , SSD_Congfig.CommonPin_Num , DIO_HIGH_PIN);
    }else if( SSD_Congfig.SSD_Mode == SSD_CA )
    {
        DIO_SetPinValue(SSD_Congfig.CommonPin_PortNum , SSD_Congfig.CommonPin_Num , DIO_HIGH_PIN);
    }  
}

void SSD_WriteNum(SSD_t SSD_config , uint8_t Number)
{
    if( SSD_config.SSD_Mode == SSD_CC )
    {
        DIO_SetPortValue(SSD_config.PortNum , SSD_u8Numbers[Number] );
    }else if( SSD_config.SSD_Mode == SSD_CA )
    {
        DIO_SetPortValue(SSD_config.PortNum , ~SSD_u8Numbers[Number] );
    }    
}

void SSD_WriteShape(SSD_t SSD_config , uint8_t ShapeVal )
{
	 DIO_SetPortValue(SSD_config.PortNum , ShapeVal );
}

