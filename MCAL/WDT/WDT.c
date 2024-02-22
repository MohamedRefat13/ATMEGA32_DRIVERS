/**
 * @file WDT.c
 * @author Mohamed Refat
 * @brief
 * @version 0.1
 * @date 2024-02-22
 *
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/Error.h"

#include "WDT_Private.h"
#include "WDT.h"

/* Helper Function Like Macros */
#define Enable_WDT() (SET_BIT(WDTCR, WDTCR_WDE))

#define Disable_WDT() (WDTCR |= 0b00011000);\
                      (WDTCR = 0)


/* Static Function To Set the time out value of WDT */
static Error_t helper_SetTimeOut(uint8_t timeOut)
{
    Error_t kErrorState = NoError;
    switch (timeOut)
    {
        case WDT_16ms3:
        CLR_BIT(WDTCR,WDTCR_WDP0);
        CLR_BIT(WDTCR,WDTCR_WDP1);
        CLR_BIT(WDTCR,WDTCR_WDP2);
        break;

        case WDT_32ms5:
        SET_BIT(WDTCR,WDTCR_WDP0);
        CLR_BIT(WDTCR,WDTCR_WDP1);
        CLR_BIT(WDTCR,WDTCR_WDP2);
        break;

        case WDT_65ms:
        CLR_BIT(WDTCR,WDTCR_WDP0);
        SET_BIT(WDTCR,WDTCR_WDP1);
        CLR_BIT(WDTCR,WDTCR_WDP2);
        break;

        case WDT_0s13:
        SET_BIT(WDTCR,WDTCR_WDP0);
        SET_BIT(WDTCR,WDTCR_WDP1);
        CLR_BIT(WDTCR,WDTCR_WDP2);
        break;

        case WDT_0s26:
        CLR_BIT(WDTCR,WDTCR_WDP0);
        CLR_BIT(WDTCR,WDTCR_WDP1);
        SET_BIT(WDTCR,WDTCR_WDP2);
        break;

        case WDT_0s52:
        SET_BIT(WDTCR,WDTCR_WDP0);
        CLR_BIT(WDTCR,WDTCR_WDP1);
        SET_BIT(WDTCR,WDTCR_WDP2);
        break;

        case WDT_1s0:
        CLR_BIT(WDTCR,WDTCR_WDP0);
        SET_BIT(WDTCR,WDTCR_WDP1);
        SET_BIT(WDTCR,WDTCR_WDP2);
        break;

        case WDT_2s1:
        SET_BIT(WDTCR,WDTCR_WDP0);
        SET_BIT(WDTCR,WDTCR_WDP1);
        SET_BIT(WDTCR,WDTCR_WDP2);
        break;

        default: kErrorState = FunctioParameterError;
    }
    return kErrorState;
}

/* WDT Function Implementation */

Error_t WDT_SetTimeOut(uint8_t timeOut)
{
    Error_t kErrorState = NoError;
    kErrorState = helper_SetTimeOut(timeOut);
    return kErrorState;

}

void WDT_Enable(void)
{
    Enable_WDT();
}


void WDT_Disable(void)
{
    Disable_WDT();
}



