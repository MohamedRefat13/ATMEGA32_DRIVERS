/*
 * EXTI_Private.h
 *
 *  Created on: Apr 10, 2023
 *      Author: Mohamed Refat
 */

#ifndef MCAL_EXTI_EXTI_PRIVATE_H_
#define MCAL_EXTI_EXTI_PRIVATE_H_


// #define SREG_REG   *((volatile uint8_t *)0X5F)  //STATUS REG                     --> GIE --> Globel Interrupt Enable 
#define GICR_REG   *((volatile uint8_t *)0X5B)  //GENERAL INTERRUPT CONTROL REG  --> PIE --> Peripheral Interrupt Enable
#define GIFR_REG   *((volatile uint8_t *)0X5A)  //GENERAL INTERRUPT FLAG REG     --> --- --> Flag Fliered after Interrupt Happend
#define MCUCR_REG  *((volatile uint8_t *)0X55)  //MCU AND CONTROL REG            --> Set Interrupt Sense Control For INT0 INT1 
#define MCUCSR_REG *((volatile uint8_t *)0X54)  //MCU AND CONTROL AND STATUS REG --> Set Interrupt Sense Control For INT2

#define GICR_INT0     6
#define GICR_INT1     7
#define GICR_INT2     5


#define MCUCR_ISC00   0
#define MCUCR_ISC01   1
#define MCUCR_ISC10   2
#define MCUCR_ISC11   3

#define MCUCSR_ISC2   6

#define EXTI_FALLING_EDGE 4
#define EXTI_RISING_EDGE  5
#define EXTI_LOW_LEVEL    6
#define EXTI_ANY_CHANGE   7

#define EXTI_ENABLED  8 
#define EXTI_DISABLED 9 
#endif /* MCAL_EXTI_EXTI_PRIVATE_H_ */
