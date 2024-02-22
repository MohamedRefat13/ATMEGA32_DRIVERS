/**
 * @file WDT_Private.h
 * @author Mohamed Refat
 * @brief
 * @version 0.1
 * @date 2024-02-22
 *
 */
#ifndef MCAL_WDT_WDT_PRIVATE_H_
#define MCAL_WDT_WDT_PRIVATE_H_

#define WDTCR	*((volatile uint8_t*) 0x41)

#define WDTCR_WDTOE		4
#define WDTCR_WDE 		3
#define WDTCR_WDP2 		2
#define WDTCR_WDP1 		1
#define WDTCR_WDP0		0

#endif /* MCAL_WDT_WDT_PRIVATE_H_ */
