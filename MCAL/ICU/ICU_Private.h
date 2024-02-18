/**
 * @file ICU_Private.h
 * @author Mohamed Refat 
 * @brief 
 * @version 0.1
 * @date 2024-02-18
 * 
 */

#define TCCR1B  ( *(volatile uint8_t *)(0X4E) )
#define TCNT1H  ( *(volatile uint8_t *)(0X4D) )
#define TCNT1L  ( *(volatile uint8_t *)(0X4C) )
#define TCNT1   ( *(volatile uint16  *)(0X4C) )
#define ICR1BH  ( *(volatile uint8_t *)(0X47) )
#define ICR1BL  ( *(volatile uint8_t *)(0X46) )
#define ICR1    ( *(volatile uint16  *)(0X46) )
#define TIMSK   ( *(volatile uint8_t *)(0X59) ) /* Timer Interrupt Mask Register */


#define TCCR1B_ICNC1  (7) /* Input Capture Noise Canceler */
#define TCCR1B_ICES1  (6) /* Input Capture Edge Select */
#define TIMSK_ICIE1   (5) /*  Input Capture Interrupt Enable */