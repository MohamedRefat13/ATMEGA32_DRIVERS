/**
 * @file ICU.c
 * @author Mohamed Refat 
 * @brief 
 * @version 0.1
 * @date 2024-02-18
 * 
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/Error.h"
#include "ICU_Private.h"
#include "ICU.h"

void(*pICU_CallBackFunction)(void) = NULL_ptr;

#define Enable_ICU()              (SET_BIT(TIMSK, TIMSK_ICIE1))
#define Disable_ICU()             (CLR_BIT(TIMSK, TIMSK_ICIE1))

#define Enable_Noise_Canceler()   (SET_BIT(TCCR1B, TCCR1B_ICNC1))
#define Disable_Noise_Canceler()  (CLR_BIT(TCCR1B, TCCR1B_ICNC1))

#define Select_RisingEdge()       (SET_BIT(TCCR1B, TCCR1B_ICES1))
#define Select_FallingEdge()      (CLR_BIT(TCCR1B, TCCR1B_ICES1))


void ICU_Init(uint8_t prescaler)
{
    Enable_ICU();
    Enable_Noise_Canceler();

    /* Set the prescaler */
    TCCR1B &= ~(TIMER_CLOCK_MASK);
    prescaler &= (TIMER_CLOCK_MASK);
    TCCR1B |= prescaler;
    return 0;
}
Error_t ICU_SelectEdge(uint8_t edge)
{
    Error_t kErrorState = NoError;
    if ( ICU_FALLING_EDGE == edge)
    {
        Select_FallingEdge();

    }else if ( ICU_RISING_EDGE == edge )
    {
        Select_RisingEdge();

    }else
    {
        kErrorState = FunctioParameterError;
    }
    return kErrorState;
}


Error_t ICU_SetCallBackFunc(void (*pISR_Fun)(void))
{
    Error_t kErrorState = NoError;
    if (NULL_ptr != pISR_Fun )
    {
       pICU_CallBackFunction = pISR_Fun;

    }else
    {
        kErrorState = FunctioParameterError;
    }
    return kErrorState;
}
Error_t ICU_ReadCaptureValue(uint16 *pValue)
{
    Error_t kErrorState = NoError;
    if ( NULL_ptr != pValue )
    {
       *pValue = ICR1;

    }else
    {
        kErrorState = FunctioParameterError;
    }
    return kErrorState;
}
void ICU_Disable(void)
{
    Disable_ICU();
    Disable_Noise_Canceler();
}



/*TIMER1 ICU Mode ISR*/
void __vector_6(void) __attribute__((signal));
void __vector_6(void)
{
    if(pICU_CallBackFunction!=NULL_ptr)
    {
        pICU_CallBackFunction();
    }
}
