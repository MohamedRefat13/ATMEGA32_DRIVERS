/*
 * LED_Manipulation.h
 *
 *  Created on: Mar 9, 2023
 *      Author: Mohamed Refat
 */

#ifndef APP_LED_MANIPULATION_LED_MANIPULATION_H_
#define APP_LED_MANIPULATION_LED_MANIPULATION_H_

/* Anumation [1] Flashing every 1 second */
void FlashingEvery_1s(LED_t Leds[] );

/* Anumation [2] Shifting right every 250 ms */
void ShiftingREvery_250ms(LED_t Leds[] );

/* Anumation [3] Shifting Left every 250 ms */
void ShiftingLEvery_250ms(LED_t Leds[] );

/* Anumation [4] Converging  every 250 ms */
void ConvergingLEvery_250ms(LED_t Leds[] );

/* Anumation [5] Diverging   every 250 ms */
void DivergingLEvery_250ms(LED_t Leds[] );

/* Anumation [6] Ping Pong Effect Every 250 ms */
void PingPongEvery_250ms(LED_t Leds[] );

/* Anumation [7] Incrementing (Snake Effect) every 250 ms */
void SnakeEffectEvery_250ms(LED_t Leds[] );

/* Anumation [8] Two LEDs Converging /Diverging every 250 ms */
void Conv_Div_Every_250ms(LED_t Leds[] );

#endif /* APP_LED_MANIPULATION_LED_MANIPULATION_H_ */
