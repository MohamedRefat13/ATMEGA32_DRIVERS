/*
 * LM13_Program.h
 *
 *  Created on: Jul 20, 2023
 *  Author: Mohamed Refat
 */
#ifndef _LM35_INTERFACE_H
#define _LM35_INTERFACE_H

typedef struct 
{
	ADC_Channel_t  LM35_ChannelNumber;
    uint8_t        LM35_VREFF ;


}LM35_t;


Error_t LM35_GetTemp(LM35_t *Lm35_Config , uint8_t *pTemp);



#endif /* _LM35_INTERFACE_H */
