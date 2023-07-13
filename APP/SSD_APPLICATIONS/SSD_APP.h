/*
 * SSD_APP.h
 *
 *  Created on: May 2, 2023
 *      Author: mo7am
 */

#ifndef APP_SSD_APPLICATIONS_SSD_APP_H_
#define APP_SSD_APPLICATIONS_SSD_APP_H_

/* Count Up and Down From 0 to 9 */
void SSD_CountUpDpown(SSD_t SSD_Config);
/* display numbers from 0:99 */
void SSD_CountFrom1To99(SSD_t SSD_Right , SSD_t SSD_Left);

/* Using button to count up from 0:9, One count with one click */
void SSD_CountUpWithBotton(SSD_t SSD_Config , uint8_t BottomPort , uint8_t BottomPin);

/* Make Animation as one led on a 7S move from a to */
void SSD_DrowAnimation(SSD_t SSD_Config );

#endif /* APP_SSD_APPLICATIONS_SSD_APP_H_ */
