/*
 * EXTI_Interface.h
 *
 *  Created on: Apr 10, 2023
 *      Author: Mohamed Refat
 */

#ifndef MCAL_EXTI_EXTI_INTERFACE_H_
#define MCAL_EXTI_EXTI_INTERFACE_H_

#define EXTI_INT0 0 
#define EXTI_INT1 1 
#define EXTI_INT2 2 

/*@brief: This function used to initiate the External Interrupt initial state 
*          To control the inintial state for each EXTI --> Do that from Configration file
* @param : void
* @return: void  
*/
void EXTI_Init(void);
/**
 * @brief             : This fuction is used to Enable a specific External interrupt 
 * @param copy_IntNum : copy from EXTI Number   --> [ EXTI_INT0 , EXTI_INT0 , EXTI_INT0 ] 
 * @return  Error_t   :  NoError                --> if function passed parameter is Correct
*					     FunctioParameterError  --> if function passed parameter is wrong	
 */
Error_t EXTI_InterruptEnable (uint8_t copy_IntNum);
/**
 * @brief 
 * 
 * @param copy_IntNum :
 * @return  Error_t   :  NoError                --> if function passed parameter is Correct
*					     FunctioParameterError  --> if function passed parameter is wrong	 
 */
Error_t EXTI_InterruptDisable(uint8_t copy_IntNum);
/**
 * @brief                  : : This fuction is used to Diable a specific External interrupt 
 * 
 * @param copy_IntNum      : copy from EXTI Number  --> [ EXTI_INT0 , EXTI_INT0 , EXTI_INT0 ] 
 * @param copy_SenceContol : coy From Sense control -->
 *                           [ EXTI_FALLING_EDGE ,  EXTI_RISING_EDGE , EXTI_LOW_LEVEL ,  EXTI_ANY_CHANGE ]
 * @return  Error_t        :  NoError               --> if function passed parameter is Correct
 *					          FunctioParameterError --> if function passed parameter is wrong	
 */
Error_t EXTI_SetSenseControl (uint8_t copy_IntNum , uint8_t copy_SenceContol);
/**
 * @brief             : This function is used to set call back function 
 * 
 * @param copy_IntNum : copy from EXTI Number --> [ EXTI_INT0 , EXTI_INT0 , EXTI_INT0 ] 
 * @param pFun        : pFun is a pointer to the function that will be passed to ISR
 * @return  Error_t   : NoError                --> if function passed parameter is Correct
*					    FunctioParameterError  --> if function passed parameter is wrong	
 */
Error_t EXTI_SetCallBackFun  (uint8_t copy_IntNum ,void (*pFun)(void));
#endif /* MCAL_EXTI_EXTI_INTERFACE_H_ */
