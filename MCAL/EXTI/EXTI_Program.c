/*
 * EXTI_Program.c
 *
 *  Created on: Apr 10, 2023
 *      Author: Mohamed Refat
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/Error.h"
#include "EXTI_Interface.h"
#include "EXTI_Private.h"
#include "EXTI_Config.h"

void (*EXTI_ptrCallBackFun[3]) (void) = {NULL_ptr};

void EXTI_Init(void)
{
    /* ------------ ENABLE PIE ------------ */
    //INITIAL STATE FOR INT0
    #if   INT0_INITIAL_STATE== EXTI_ENABLED
        SET_BIT(GICR_REG , GICR_INT0); 
    #elif INT0_INITIAL_STATE== EXTI_DISABLED
        CLR_BIT(GICR_REG , GICR_INT0); 
    #else
        #error "Wrong INITAL STATE FOR INT0"    
    #endif

    //INITIAL STATE FOR INT1
    #if   INT1_INITIAL_STATE== EXTI_ENABLED
        SET_BIT(GICR_REG , GICR_INT1); 
    #elif INT1_INITIAL_STATE== EXTI_DISABLED
        CLR_BIT(GICR_REG , GICR_INT1); 
    #else
        #error "Wrong INITAL STATE FOR INT1"    
    #endif

    //INITIAL STATE FOR INT2
    #if   INT2_INITIAL_STATE== EXTI_ENABLED
        SET_BIT(GICR_REG , GICR_INT2); 
    #elif INT2_INITIAL_STATE== EXTI_DISABLED
        CLR_BIT(GICR_REG , GICR_INT2); 
    #else
        #error "Wrong INITAL STATE FOR INT1"    
    #endif

    /* --------- SET INTERRUPT SENSE CONTROL --------- */
    // SENSE CONTROL FOR  INT0
    #if INT0_SENSE_STATE == EXTI_LOW_LEVEL
        CLR_BIT(MCUCR_REG , MCUCR_ISC00); 
        CLR_BIT(MCUCR_REG , MCUCR_ISC01); 
    #elif INT0_SENSE_STATE == EXTI_ANY_CHANGE
        SET_BIT(MCUCR_REG , MCUCR_ISC00); 
        CLR_BIT(MCUCR_REG , MCUCR_ISC01); 
    #elif INT0_SENSE_STATE == EXTI_FALLING_EDGE
        CLR_BIT(MCUCR_REG , MCUCR_ISC00); 
        SET_BIT(MCUCR_REG , MCUCR_ISC01); 
    #elif INT0_SENSE_STATE == EXTI_RISING_EDGE
        SET_BIT(MCUCR_REG , MCUCR_ISC00); 
        SET_BIT(MCUCR_REG , MCUCR_ISC01); 
    #else
        #error "WRONG CONTROL STATE FOR INT0"    
    #endif

    // SENSE CONTROL FOR  INT1
    #if INT1_SENSE_STATE == EXTI_LOW_LEVEL
        CLR_BIT(MCUCR_REG , MCUCR_ISC10); 
        CLR_BIT(MCUCR_REG , MCUCR_ISC11); 
    #elif INT1_SENSE_STATE == EXTI_ANY_CHANGE
        SET_BIT(MCUCR_REG , MCUCR_ISC10); 
        CLR_BIT(MCUCR_REG , MCUCR_ISC11); 
    #elif INT1_SENSE_STATE == EXTI_FALLING_EDGE
        CLR_BIT(MCUCR_REG , MCUCR_ISC10); 
        SET_BIT(MCUCR_REG , MCUCR_ISC11); 
    #elif INT1_SENSE_STATE == EXTI_RISING_EDGE
        SET_BIT(MCUCR_REG , MCUCR_ISC10); 
        SET_BIT(MCUCR_REG , MCUCR_ISC11); 
    #else
        #error "WRONG CONTROL STATE FOR INT1"    
    #endif

    // SENSE CONTROL FOR  INT2
    #if INT2_SENSE_STATE == EXTI_FALLING_EDGE
        CLR_BIT(MCUCSR_REG , MCUCSR_ISC2); 
    #elif INT2_SENSE_STATE == EXTI_RISING_EDGE
        SET_BIT(MCUCSR_REG , MCUCSR_ISC2); 
    #else
        #error "WRONG CONTROL STATE FOR INT2"    
    #endif
}

Error_t EXTI_InterruptEnable (uint8_t copy_IntNum)
{
    Error_t LocErrorState = NoError ;
    switch (copy_IntNum)
    {
        case EXTI_INT0 : SET_BIT(GICR_REG , GICR_INT0); break;
        case EXTI_INT1 : SET_BIT(GICR_REG , GICR_INT1); break;
        case EXTI_INT2 : SET_BIT(GICR_REG , GICR_INT2); break;
        default        : LocErrorState = FunctioParameterError ; 
    }
    return LocErrorState ; 
}
Error_t EXTI_InterruptDisable(uint8_t copy_IntNum)
{
    Error_t LocErrorState = NoError ;
    switch (copy_IntNum)
    {
        case EXTI_INT0 : CLR_BIT(GICR_REG , GICR_INT0); break;
        case EXTI_INT1 : CLR_BIT(GICR_REG , GICR_INT1); break;
        case EXTI_INT2 : CLR_BIT(GICR_REG , GICR_INT2); break;
        default        : LocErrorState = FunctioParameterError ; 
    }
    return LocErrorState ; 
}

Error_t EXTI_SetSenseControl (uint8_t copy_IntNum ,uint8_t copy_SenceContol)
{
    Error_t LocErrorState = NoError ;
    if(copy_IntNum == EXTI_INT0  )
    {
        switch (copy_SenceContol)
        {
            case EXTI_LOW_LEVEL    : CLR_BIT(MCUCR_REG , MCUCR_ISC00); CLR_BIT(MCUCR_REG , MCUCR_ISC01); break;
            case EXTI_ANY_CHANGE   : SET_BIT(MCUCR_REG , MCUCR_ISC00); CLR_BIT(MCUCR_REG , MCUCR_ISC01); break;
            case EXTI_FALLING_EDGE : CLR_BIT(MCUCR_REG , MCUCR_ISC00); SET_BIT(MCUCR_REG , MCUCR_ISC01); break;
            case EXTI_RISING_EDGE  : SET_BIT(MCUCR_REG , MCUCR_ISC00); SET_BIT(MCUCR_REG , MCUCR_ISC01); break;
            default                : LocErrorState = FunctioParameterError ; 
        }
    }else if(copy_IntNum == EXTI_INT1  )
    {
        switch (copy_SenceContol)
        {
            case EXTI_LOW_LEVEL    : CLR_BIT(MCUCR_REG , MCUCR_ISC10); CLR_BIT(MCUCR_REG , MCUCR_ISC11); break;
            case EXTI_ANY_CHANGE   : SET_BIT(MCUCR_REG , MCUCR_ISC10); CLR_BIT(MCUCR_REG , MCUCR_ISC11); break;
            case EXTI_FALLING_EDGE : CLR_BIT(MCUCR_REG , MCUCR_ISC10); SET_BIT(MCUCR_REG , MCUCR_ISC11); break;
            case EXTI_RISING_EDGE  : SET_BIT(MCUCR_REG , MCUCR_ISC10); SET_BIT(MCUCR_REG , MCUCR_ISC11); break;
            default                : LocErrorState = FunctioParameterError ; 
        }
    }else if(copy_IntNum == EXTI_INT2  )
    {
        switch (copy_SenceContol)
        {
            case EXTI_FALLING_EDGE : CLR_BIT(MCUCSR_REG , MCUCSR_ISC2); break;
            case EXTI_RISING_EDGE  : SET_BIT(MCUCSR_REG , MCUCSR_ISC2); break;
            default                : LocErrorState = FunctioParameterError ; 
        }
    }else
    {
        LocErrorState = FunctioParameterError ;
    }
    return LocErrorState ; 
}
Error_t EXTI_SetCallBackFun  (uint8_t copy_IntNum , void (*pFun)(void))
{
    Error_t LocErrorState = NoError ;
    if(pFun != NULL_ptr)
    {
        switch (copy_IntNum)
        {
            case EXTI_INT0 : EXTI_ptrCallBackFun[0] = pFun; break;
            case EXTI_INT1 : EXTI_ptrCallBackFun[1] = pFun; break;
            case EXTI_INT2 : EXTI_ptrCallBackFun[2] = pFun; break;
            default        : LocErrorState = FunctioParameterError ; 
        }
    }else
    {
        LocErrorState = FunctioParameterError ;
    }
 
    return LocErrorState ;
}
/* ISR implemetaion  */
void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
    if(EXTI_ptrCallBackFun[0]!=NULL_ptr)
    {
        EXTI_ptrCallBackFun[0]();
    }
}
void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{
    if(EXTI_ptrCallBackFun[1]!=NULL_ptr)
    {
        EXTI_ptrCallBackFun[1]();
    }
}
void __vector_3(void) __attribute__((signal));
void __vector_3(void)
{
    if(EXTI_ptrCallBackFun[2]!=NULL_ptr)
    {
        EXTI_ptrCallBackFun[2]();
    }
}