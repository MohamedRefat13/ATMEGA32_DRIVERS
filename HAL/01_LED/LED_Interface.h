/*
 * LED_Interface.h
 *
 *  Created on: Feb 13, 2023
 *      Author: Mohamed Refat
 */
#ifndef LED_INTERFACE_H
#define	LED_INTERFACE_H

#include "../../LIB./STD_TYPES.h"
#include "../../LIB/Error.h"
#define LED_ACTIVE_HIGH 1 
#define LED_ACTIVE_LOW 0

typedef struct 
{
    uint8_t  PortNumber;  
    uint8_t  PinNumber ; 
    uint8_t  Active_Status ; 
}LED_t;

/**
 * @brief                   :This function used to  initiate led and sets the configration of it
 * 
 * @param LedConfigration   :LLedConfigration is a struct from type Led_t
 * 
 * @note                    :You mast call this function before you start using the Led
 */
Error_t LED_Init      (LED_t LedConfigration);

/**
 * @brief                   :This function used turn  the led on
 * 
 * @param LedConfigration   :LLedConfigration is a struct from type Led_t
 */
Error_t LED_ON        (LED_t LedConfigration);

/**
 * @brief                   :This function used turn  the led off
 * 
 * @param LedConfigration   :LLedConfigration is a struct from type Led_t
 */
Error_t LED_OFF       (LED_t LedConfigration);


/**
 * @brief                   :This function used toggle the Led Statuss
 * 
 * @param LedConfigration   :LLedConfigration is a struct from type Led_t
 */
Error_t LED_Toggle    (LED_t LedConfigration);

#endif /* LED_INTERFACE_H */
