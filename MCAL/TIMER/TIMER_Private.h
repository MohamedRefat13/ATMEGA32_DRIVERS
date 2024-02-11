/*
 * TIMER_Private.h
 *
 *  Created on: Oct 26, 2023
 *      Author: Mohamed Refat
 */

#ifndef MCAL_TIMER_TIMER_PRIVATE_H_
#define MCAL_TIMER_TIMER_PRIVATE_H_

#ifndef F_CPU
#define F_CPU (8000000LU)
#endif

/* Registers */
#define OCR0   ( *(volatile uint8_t *)(0X5C) ) /* Output Compare Register */
#define TIMSK  ( *(volatile uint8_t *)(0X59) ) /* Timer Interrupt Mask Register */
#define TIFR   ( *(volatile uint8_t *)(0X58) ) /* Timer Interrupt Flag Register */
#define TCCR0  ( *(volatile uint8_t *)(0X53) ) /* Timer Control Register */
#define TCNT0  ( *(volatile uint8_t *)(0X52) ) /* Timer Counter Register */

#define TCCR1A ( *(volatile uint8_t *)(0X4F) )
#define TCCR1B ( *(volatile uint8_t *)(0X4E) )
#define TCNT1H ( *(volatile uint8_t *)(0X4D) )
#define TCNT1L ( *(volatile uint8_t *)(0X4C) )
#define TCNT1  ( *(volatile uint16_tt *)(0X4C) )
#define OCR1AH ( *(volatile uint8_t *)(0X4B) )
#define OCR1AL ( *(volatile uint8_t *)(0X4A) )
#define OCR1A  ( *(volatile uint16_tt *)(0X4A) )
#define OCR1BH ( *(volatile uint8_t *)(0X49) )
#define OCR1BL ( *(volatile uint8_t *)(0X48) )
#define OCR1B  ( *(volatile uint16_tt *)(0X48) )
#define OCR1A  ( *(volatile uint16_tt *)(0X4A) )
#define ICR1BH ( *(volatile uint8_t *)(0X47) )
#define ICR1BL ( *(volatile uint8_t *)(0X46) )
#define ICR1   ( *(volatile uint16_tt *)(0X46) )

#define TCCR2  ( *(volatile uint8_t *)(0X45) )
#define TCNT2  ( *(volatile uint8_t *)(0X44) )
#define OCR2   ( *(volatile uint8_t *)(0X43) )

/* Macros */
#define TCCR0_WGM00  (6) /* Waveform  Generation Mode 0 */
#define TCCR0_WGM01  (3) /* Waveform  Generation Mode 1*/
#define TCCR0_COMM01 (5) /* Compare Match Output Mode */
#define TCCR0_COMM00 (4) /* Compare Match Output Mode */
#define TIMSK_TOIE0  (0) /* Timer0 Overflow Interrupt Enable */
#define TIMSK_OCIE0  (1) /* Output Compare Interrupt Enable */

#define TCCR2_WGM20  (6) /* Waveform  Generation Mode 0 */
#define TCCR2_WGM21  (3) /* Waveform  Generation Mode 1*/
#define TCCR2_COMM21 (5) /* Compare Match Output Mode */
#define TCCR2_COMM20 (4) /* Compare Match Output Mode */
#define TIMSK_TOIE2  (6) /* Timer2 Overflow Interrupt Enable */
#define TIMSK_OCIE2  (7) /* Output Compare Interrupt Enable */

#define TCCR1A_COM1A1 (7) /* Compare Output Mode for Channel A */
#define TCCR1A_COM1A0 (6) /* Compare Output Mode for Channel A */
#define TCCR1A_COM1B1 (5) /* Compare Output Mode for Channel B */
#define TCCR1A_COM1B0 (4) /* Compare Output Mode for Channel B */
#define TCCR1A_WGM11  (1) /* Waveform Generation Mode */
#define TCCR1A_WGM10  (0) /* Waveform Generation Mode */
#define TCCR1B_WGM13  (4) /* Waveform Generation Mode */
#define TCCR1B_WGM12  (3) /* Waveform Generation Mode */
#define TCCR1B_ICNC1  (7) /* Input Capture Noise Canceler */
#define TCCR1B_ICES1  (6) /* Input Capture Edge Select */
#define TIMSK_TOIE1   (2) /* Timer2 Overflow Interrupt Enable */
#define TIMSK_OCIE1B  (3) /* Output Compare channel B Interrupt Enable */
#define TIMSK_OCIE1A  (4) /* Output Compare channel B Interrupt Enable */
#define TIMSK_ICIE1   (5) /*  Input Capture Interrupt Enable */

/* MASK */
#define TIMER_CLOCK_MASK (0b00000111)

#define RESOLUTION_8BIT  (255)
#define RESOLUTION_10BIT (1023)
#endif /* MCAL_TIMER_TIMER_PRIVATE_H_ */
