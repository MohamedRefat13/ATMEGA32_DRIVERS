/*
 * LM13_Program.h
 *
 *  Created on: Jul 20, 2023
 *  Author: Mohamed Refat
 */
#ifndef _LM35_INTERFACE_H
#define _LM35_INTERFACE_H
/**
 * @brief : LM35_t is a data type for the LM35 sensor
 * 
 * @param ADC_Channel_t : Channel number [ADC_CHANNEL1 --> ADC_CHANNEL7]
 * @param LM35_VREFF    : Reference voltage 
 *                        Options:
 *                              [ADC_AVCC , ADC_AREF , ADC_INTERNAL_2_56]
 */
typedef struct 
{
	ADC_Channel_t  LM35_ChannelNumber;
    uint8_t        LM35_VREFF ;


}LM35_t;

/**
 * @note : You Must call ADC_voidInit(); before using LM35 Sensor
 */
Error_t LM35_GetTemp(LM35_t *Lm35_Config , uint8_t *pTemp);



#endif /* _LM35_INTERFACE_H */
