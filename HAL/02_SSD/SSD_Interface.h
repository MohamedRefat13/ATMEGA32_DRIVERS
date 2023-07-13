/*
 * SSD_Interface.h
 *
 *  Created on: Feb 15, 2023
 *      Author: Mohamed Refat
 */

#ifndef HAL_02_SSD_SSD_INTERFACE_H_
#define HAL_02_SSD_SSD_INTERFACE_H_

#include"../../LIB/STD_TYPES.h"
#include "SSD_Private.h"

#define SSD_CC 1
#define SSD_CA 0 

typedef struct 
{
    uint8_t SSD_Mode ;
    uint8_t PortNum  ;
    uint8_t CommonPin_Num  ;
    uint8_t CommonPin_PortNum ;
    
}SSD_t;

void SSD_Init(SSD_t SSD_Congfig );
void SSD_Enable(SSD_t SSD_Congfig );
void SSD_Disable(SSD_t SSD_Congfig );
void SSD_WriteNum(SSD_t SSD_config , uint8_t Number);
void SSD_WriteShape(SSD_t SSD_config , uint8_t ShapeVal );

#endif /* HAL_02_SSD_SSD_INTERFACE_H_ */
