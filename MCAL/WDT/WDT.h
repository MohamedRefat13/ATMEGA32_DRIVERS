/**
 * @file WDT.h
 * @author Mohamed Refat
 * @brief
 * @version 0.1
 * @date 2024-02-22
 *
 */
#ifndef MCAL_WDT_WDT_H_
#define MCAL_WDT_WDT_H_


#define WDT_16ms3 (0)
#define WDT_32ms5 (1)
#define WDT_65ms  (2)
#define WDT_0s13  (3)
#define WDT_0s26  (4)
#define WDT_0s52  (5)
#define WDT_1s0   (6)
#define WDT_2s1   (7)
// typedef enum
// {
//     /* 16.3 ms */
//     WDT_16ms3,
//     /* 32.5 ms */
//     WDT_32ms5,
//     /* 65 ms */
//     WDT_65ms,
//     /* 0.13 s */
//     WDT_0s13,
//     /* 0.26 s */
//     WDT_0s26,
//     /* 0.52 s */
//     WDT_0s52,
//     /* 1.0 s */
//     WDT_1s0,
//     /* 2.1 s */
//     WDT_2s1

// }WDT_TimeOut;


void WDT_Enable(void);
void WDT_Disable(void);
Error_t WDT_SetTimeOut(uint8_t timeOut);

#endif /* MCAL_WDT_WDT_H_MCAL_WDT_WDT_H_ */
