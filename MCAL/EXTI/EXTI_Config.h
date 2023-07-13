/*
 * EXTI_Config.h
 *
 *  Created on: Apr 10, 2023
 *      Author: Mohamed Refat
 */

#ifndef MCAL_EXTI_EXTI_CONFIG_H_
#define MCAL_EXTI_EXTI_CONFIG_H_

/* OPTIONS:
*           EXTI_ENABLED
*           EXTI_DISABLED  
*/
#define INT0_INITIAL_STATE  EXTI_DISABLED
#define INT1_INITIAL_STATE  EXTI_DISABLED 
#define INT2_INITIAL_STATE  EXTI_ENABLED


/* OPTIONS:
*            EXTI_FALLING_EDGE
*            EXTI_RISING_EDGE 
*            EXTI_LOW_LEVEL   
*            EXTI_ANY_CHANGE        
*/
#define  INT0_SENSE_STATE  EXTI_FALLING_EDGE 
#define  INT1_SENSE_STATE  EXTI_FALLING_EDGE 

/* OPTIONS:
*            EXTI_FALLING_EDGE
*            EXTI_RISING_EDGE        
*/
#define  INT2_SENSE_STATE  EXTI_FALLING_EDGE

#endif /* MCAL_EXTI_EXTI_CONFIG_H_ */
