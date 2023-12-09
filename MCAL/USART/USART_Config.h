/**
 * @file USART_Config.h
 * @author Mohamed Refat 
 * @brief 
 * @version 0.1
 * @date 2023-11-10
 * 
 */

#ifndef USART_CONFIGURATION_H
#define USART_CONFIGURATION_H

#ifndef F_CPU
#define F_CPU (8000000UL)
#endif


/**
 * @brief This macro used to set the USART Mode
 *          Options:[
 *                  USART_ASYNCHRONOUS_MODE
 *                  USART_SYNCHRONOUS_MODE]
 */
#define USART_MODE USART_ASYNCHRONOUS_MODE 

/**
 * @brief This macro used to set the speed of USART in Asynchronous mode
 *          Options:
 *                  USART_ASYN_NORMAL_SPEED
 *                  USART_ASYN_DOUBLE_SPEED
 * 
 */
#define USART_ASYN_SPEED USART_ASYN_NORMAL_SPEED

/**
 * @brief This macro used to set the USART Data Size
 *          Options:
 *                  USART_DATA_SIZE_5_BIT
 *                  USART_DATA_SIZE_6_BIT
 *                  USART_DATA_SIZE_5_BIT
 *                  USART_DATA_SIZE_8_BIT
 *                  USART_DATA_SIZE_9_BIT
 * 
 * Note:: 9 bit data not implemented yet
 */

/**
 * @brief This macro used to set the USART Baud Rate
 *          Options:
 *                  USART_BAUD_RATE_2400
 *                  USART_BAUD_RATE_4800
 *                  USART_BAUD_RATE_9600
 */
#define USART_BAUD_RATE USART_BAUD_RATE_9600

#define USART_DATA_SEIZE USART_DATA_SIZE_8_BIT

/**
 * @brief This macro used to set the Stop bits Number
 *             Options:
 *                  USART_STOP_BITS_ONE
 *                  USART_STOP_BITS_TWO
 * 
 */
#define USART_STOP_BITS USART_STOP_BITS_ONE

/**
 * @brief This macro used to set the parity Check type
 *             Options:
 *                  USART_EVEN_PARITY
 *                  USART_ODD_PARITY
 *                  USART_NO_PARITY 
 * 
 */
#define USART_PARITY_TYPE USART_NO_PARITY


/* Not Implemented in Init Function yet */
/**
 * @brief This macro used to set the Clock polarity
 *             Options:
 *                      USART_POLARITY_RISING_EDGE
 *                      USART_POLARITY_FALLING_EDGE
 */
#define USART_CLOCK_POLARITY USART_POLARITY_RISING_EDGE


#endif /* USART_CONFIGURATION_H */
