/*
 * TIMER_Program.c
 *
 *  Created on: Oct 26, 2023
 *      Author: Mohamed Refat
 */

#ifndef MCAL_TIMER_TIMER_PROGRAM_C_
#define MCAL_TIMER_TIMER_PROGRAM_C_

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/Error.h"

#include "../../MCAL/DIO/DIO_interface.h"
#include "TIMER_Interface.h"
#include "TIMER_Private.h"

void(*pOVF_CallBackFunctions[3])(void) = {NULL_ptr};
void(*pCTC_CallBackFunctions[4])(void) = {NULL_ptr};
//void(*pICU_CallBackFunction)(void) = NULL_ptr;


Error_t TIMER0_Init(uint8_t kMode, uint8_t kClock)
{
    Error_t kErrorState = NoError;
    /* Set Timer0 Mode */
    switch (kMode)
    {
        case TIMER_NORMAL_MODE:
            CLR_BIT(TCCR0, TCCR0_WGM00);
            CLR_BIT(TCCR0, TCCR0_WGM01);
            break;

        case TIMER_CTC_MODE:
            CLR_BIT(TCCR0, TCCR0_WGM00);
            SET_BIT(TCCR0, TCCR0_WGM01);
            break;

        case TIMER_PWM_MODE:
            /* Set Timer Mode To Fast PWM */
            SET_BIT(TCCR0, TCCR0_WGM00);
            SET_BIT(TCCR0, TCCR0_WGM01);
            /* Set PWM Output To Inverting 
                Clear on Top Set On Compare 
            */
            SET_BIT(TCCR0, TCCR0_COMM00);
            SET_BIT(TCCR0, TCCR0_COMM01);
            break; 
        default: kErrorState = FunctioParameterError; 
    }
    /* Set Timer0 Clock Source */
    TCCR0 &= ~(TIMER_CLOCK_MASK);
    kClock &= (TIMER_CLOCK_MASK);
    TCCR0 |= kClock;
    
    /* Enable Timer0 Overflow Interrupt */
    SET_BIT(TIMSK, TIMSK_TOIE0);
    /* Enable Timer0 CTC  Interrupt */
    SET_BIT(TIMSK, TIMSK_OCIE0);

    return kErrorState;
}

void TIMER0_SetPreload(uint8_t preloadValue)
{
    TCNT0 = preloadValue;
}

void TIMER0_SetCTC(uint8_t OCR_Value)
{
    OCR0 = OCR_Value;
}

Error_t TIMER0_SetOCPinMode(uint8_t OCPinMode)
{
    Error_t kErrorState = NoError;
    switch (OCPinMode)
    {
        case TIMER_OC_TURN_OFF: 
            CLR_BIT(TCCR0, TCCR0_COMM00);
            CLR_BIT(TCCR0, TCCR0_COMM01);
            break;

        case TIMER_OC_TOGGLE:
            SET_BIT(TCCR0, TCCR0_COMM00);
            CLR_BIT(TCCR0, TCCR0_COMM01);
            break;

        case TIMER_OC_CLEAR:
            CLR_BIT(TCCR0, TCCR0_COMM00);
            SET_BIT(TCCR0, TCCR0_COMM01);
            break;

        case TIMER_OC_SET:
            CLR_BIT(TCCR0, TCCR0_COMM00);
            SET_BIT(TCCR0, TCCR0_COMM01);
            break;
    }
    return kErrorState;
}

Error_t TIMER0_SetDutyCycle(uint8_t DutyCycle)
{
    Error_t kErrorState = NoError;
    if (DutyCycle <= 100)
    {
        uint8_t OCR_Value = 255 -((DutyCycle/100.0) * 255.0);
        OCR0 = OCR_Value;
    }else 
    {
        kErrorState = FunctioParameterError;
    }
    return kErrorState;
}

Error_t TIMER0_SetCallBackFun(uint8_t interruptSource, void (*pTimer_ISR)(void))
{
    Error_t kErrorState = NoError;
    if ( pTimer_ISR != NULL_ptr )
    {

        switch (interruptSource)
        {
            case TIMER0_INTERRUPT_OVERFLOW :
                pOVF_CallBackFunctions[0] = pTimer_ISR;
                break;

            case TIMER0_INTERRUPT_CTC :
                pCTC_CallBackFunctions[0] = pTimer_ISR;
                break;

            default: kErrorState = FunctioParameterError;
        }
        
    }else
    {
        kErrorState = FunctioParameterError;
    }
    return kErrorState;
}


Error_t TIMER1_Init(uint8_t kMode, uint8_t kClock)
{
    Error_t kErrorState = NoError;
    /* Set Timer0 Mode */
    switch (kMode)
    {
        case TIMER_NORMAL_MODE:
            CLR_BIT(TCCR1A, TCCR1A_WGM10);
            CLR_BIT(TCCR1A, TCCR1A_WGM11);
            CLR_BIT(TCCR1B, TCCR1B_WGM12);
            CLR_BIT(TCCR1B, TCCR1B_WGM13);
            break;

        case TIMER_CTC_MODE:
            CLR_BIT(TCCR1A, TCCR1A_WGM10);
            CLR_BIT(TCCR1A, TCCR1A_WGM11);
            SET_BIT(TCCR1B, TCCR1B_WGM12);
            CLR_BIT(TCCR1B, TCCR1B_WGM13);
            break;

        case TIMER_PWM_MODE:
            /* Set Timer Mode To Fast PWM and the top value is ICR1 */
            CLR_BIT(TCCR1A, TCCR1A_WGM10);
            SET_BIT(TCCR1A, TCCR1A_WGM11);
            SET_BIT(TCCR1B, TCCR1B_WGM12);
            SET_BIT(TCCR1B, TCCR1B_WGM13);

            break; 
        default: kErrorState = FunctioParameterError; 
    }

    /* Set Timer1 Clock Source */
    TCCR1B &= ~(TIMER_CLOCK_MASK);
    kClock &= (TIMER_CLOCK_MASK);
    TCCR1B |= kClock;
    
    /* Enable Timer1 Overflow Interrupt */
    SET_BIT(TIMSK, TIMSK_TOIE1);
    /* Enable Timer1 CTC A Interrupt */
    SET_BIT(TIMSK, TIMSK_OCIE1A);
    /* Enable Timer1 CTC B Interrupt */
    SET_BIT(TIMSK, TIMSK_OCIE1B);
    /* Enable Timer1 Input Capture Interrupt */
    SET_BIT(TIMSK, TIMSK_ICIE1);

    return kErrorState;
}

void TIMER1_SetPreload(unsigned short  preloadValue)
{
    TCNT1 = preloadValue;
}

void TIMER1_SetCTCA(uint16_tt OCRA_Value)
{
    OCR1A = OCRA_Value;
}

void TIMER1_SetCTCB(uint16_tt OCRB_Value)
{
    OCR1B = OCRB_Value;
}

Error_t TIMER1_SetOCAPinMode(uint8_t OCPinMode)
{
    Error_t kErrorState = NoError;
    switch (OCPinMode)
    {
        case TIMER_OC_TURN_OFF: 
            CLR_BIT(TCCR1A, TCCR1A_COM1A0);
            CLR_BIT(TCCR1A, TCCR1A_COM1A1);
            break;
        case TIMER_OC_TOGGLE:
            SET_BIT(TCCR1A, TCCR1A_COM1A0);
            CLR_BIT(TCCR1A, TCCR1A_COM1A1);
            break;
        case TIMER_OC_CLEAR:
            CLR_BIT(TCCR1A, TCCR1A_COM1A0);
            SET_BIT(TCCR1A, TCCR1A_COM1A1);
            break;
        case TIMER_OC_SET:
            CLR_BIT(TCCR1A, TCCR1A_COM1A0);
            SET_BIT(TCCR1A, TCCR1A_COM1A1);
            break;
    }
    return kErrorState;
}

Error_t TIMER1_SetOCBPinMode(uint8_t OCPinMode){
    Error_t kErrorState = NoError;
    switch (OCPinMode)
    {
        case TIMER_OC_TURN_OFF: 
            CLR_BIT(TCCR1A, TCCR1A_COM1B0);
            CLR_BIT(TCCR1A, TCCR1A_COM1B1);
            break;
        case TIMER_OC_TOGGLE:
            SET_BIT(TCCR1A, TCCR1A_COM1B0);
            CLR_BIT(TCCR1A, TCCR1A_COM1B1);
            break;
        case TIMER_OC_CLEAR:
            CLR_BIT(TCCR1A, TCCR1A_COM1B0);
            SET_BIT(TCCR1A, TCCR1A_COM1B1);
            break;
        case TIMER_OC_SET:
            CLR_BIT(TCCR1A, TCCR1A_COM1B0);
            SET_BIT(TCCR1A, TCCR1A_COM1B1);
            break;
    }
    return kErrorState;
}

Error_t TIMER1_SetPWM_Channel_Mode(uint8_t kChannel, uint8_t kMode)
{
    Error_t kErrorState = NoError;
    if ( kChannel == PWM1_OC1A )
    {
        DIO_SetPinDirection(DIO_PORTD, DIO_PIN5, DIO_OUTPUT_PIN);
        switch (kMode)
        {
            case PWM1_INVERTING:
                SET_BIT(TCCR1A, TCCR1A_COM1A0);
                SET_BIT(TCCR1A, TCCR1A_COM1A1);
                break;
            case PWM1_NON_INVERTING:
                CLR_BIT(TCCR1A, TCCR1A_COM1A0);
                SET_BIT(TCCR1A, TCCR1A_COM1A1);
                break;
            default : kErrorState = FunctioParameterError;
        }
    }else if ( kChannel == PWM1_OC1B)
    {
        DIO_SetPinDirection(DIO_PORTD, DIO_PIN4, DIO_OUTPUT_PIN);
        switch (kMode)
        {
            case PWM1_INVERTING:
                SET_BIT(TCCR1A, TCCR1A_COM1B0);
                SET_BIT(TCCR1A, TCCR1A_COM1B1);
                break;
            case PWM1_NON_INVERTING:
                CLR_BIT(TCCR1A, TCCR1A_COM1B0);
                SET_BIT(TCCR1A, TCCR1A_COM1B1);
                break;
            default : kErrorState = FunctioParameterError;
        }
    }else
    {
    	kErrorState = FunctioParameterError;
    }
    return kErrorState;
}
Error_t TIMER1_SetPWM_Freq(uint32_t Frequency, uint32_t Prescaler)
{
    Error_t kErrorState = NoError;
    if ( Frequency <= F_CPU )
    {
            /**
             * F_PWM = F_CPU/(Prescaler * (1 + TOP ))
             */

            ICR1 = ( ( F_CPU ) / ( Prescaler * Frequency ) ) - 1;
    }else
    {
        kErrorState = FunctioParameterError;
    }
    return kErrorState;
}
Error_t TIMER1_SetDutyCycle(f32_t DutyCycle, uint8_t Channel)
{
    Error_t kErrorState = NoError;
    if (DutyCycle <= 100 )
    {
        /* ICR1 --> Top value of timer1 */
        uint16_tt OCR_Value =  ICR1 -((DutyCycle/100.0) * ICR1);
        if (Channel == PWM1_OC1A)
        {
            OCR1A = OCR_Value;
        }else if (Channel == PWM1_OC1B)
        {
            OCR1B = OCR_Value;
        }else 
        {
            kErrorState = FunctioParameterError;
        }
    }else 
    {
        kErrorState = FunctioParameterError;
    }
    return kErrorState;
}

Error_t TIMER1_SetCallBackFun(uint8_t interruptSource, void (*pTimer_ISR)(void))
{
    Error_t kErrorState = NoError;
    if ( pTimer_ISR != NULL_ptr )
    {

        switch (interruptSource)
        {
            case TIMER1_INTERRUPT_OVERFLOW :
                pOVF_CallBackFunctions[1] = pTimer_ISR;
                break;

            case TIMER1_INTERRUPT_CTCA :
                pCTC_CallBackFunctions[1] = pTimer_ISR;
                break;

            case TIMER1_INTERRUPT_CTCB :
                pCTC_CallBackFunctions[3] = pTimer_ISR;
                break;

            case TIMER1_INTERRUPT_ICU1 :
                //pICU_CallBackFunction = pTimer_ISR;
                break;

            default: kErrorState = FunctioParameterError;
        }
        
    }else
    {
        kErrorState = FunctioParameterError;
    }
    return kErrorState;
}





Error_t TIMER2_Init(uint8_t kMode, uint8_t kClock)
{
    Error_t kErrorState = NoError;
    /* Set Timer2 Mode */
    switch (kMode)
    {
        case TIMER_NORMAL_MODE:
            CLR_BIT(TCCR2, TCCR2_WGM20);
            CLR_BIT(TCCR2, TCCR2_WGM21);
            break;
        case TIMER_CTC_MODE:
            CLR_BIT(TCCR2, TCCR2_WGM20);
            SET_BIT(TCCR2, TCCR2_WGM21);
            break;
        case TIMER_PWM_MODE:
            /* Set Timer Mode To Fast PWM */
            SET_BIT(TCCR2, TCCR2_WGM20);
            SET_BIT(TCCR2, TCCR2_WGM21);
            /* Set PWM Output To Inverting 
                Clear on Top Set On Compare 
            */
            SET_BIT(TCCR2, TCCR2_COMM20);
            SET_BIT(TCCR2, TCCR2_COMM21);
            break;
        default: kErrorState = FunctioParameterError;    
    }

    /* Set Timer2 Clock Source */
    TCCR2 &= ~(TIMER_CLOCK_MASK);
    kClock &= (TIMER_CLOCK_MASK);
    TCCR2 |= kClock;

    /* Enable Timer2 Overflow Interrupt */
    SET_BIT(TIMSK, TIMSK_TOIE2);
    /* Enable Timer2 CTC  Interrupt */
    SET_BIT(TIMSK, TIMSK_OCIE2);

    return kErrorState;

}

void TIMER2_SetPreload(uint8_t preloadValue)
{
    TCNT2 = preloadValue;
}

void TIMER2_SetCTC(uint8_t OCR_Value)
{
    OCR2 = OCR_Value;
}

Error_t TIMER2_SetOCPinMode(uint8_t OCPinMode)
{
    Error_t kErrorState = NoError;
    switch (OCPinMode)
    {
        case TIMER_OC_TURN_OFF: 
            CLR_BIT(TCCR2, TCCR2_COMM20);
            CLR_BIT(TCCR2, TCCR2_COMM21);
            break;
        case TIMER_OC_TOGGLE:
            SET_BIT(TCCR2, TCCR2_COMM20);
            CLR_BIT(TCCR2, TCCR2_COMM21);
            break;
        case TIMER_OC_CLEAR:
            CLR_BIT(TCCR2, TCCR2_COMM20);
            SET_BIT(TCCR2, TCCR2_COMM21);
            break;
        case TIMER_OC_SET:
            CLR_BIT(TCCR2, TCCR2_COMM20);
            SET_BIT(TCCR2, TCCR2_COMM21);
            break;
    }
    return kErrorState;
}

Error_t TIMER2_SetDutyCycle(uint8_t DutyCycle)
{
    Error_t kErrorState = NoError;
    if (DutyCycle <= 100)
    {
        uint8_t OCR_Value = RESOLUTION_8BIT -((DutyCycle/100.0) * RESOLUTION_8BIT);
        OCR2 = OCR_Value;
    }else 
    {
        kErrorState = FunctioParameterError;
    }
    return kErrorState;
}


Error_t TIMER2_SetCallBackFun(uint8_t interruptSource, void (*pTimer_ISR)(void))
{
    Error_t kErrorState = NoError;
    if ( pTimer_ISR != NULL_ptr )
    {

        switch (interruptSource)
        {
            case TIMER2_INTERRUPT_OVERFLOW :
                pOVF_CallBackFunctions[2] = pTimer_ISR;
                break;

            case TIMER2_INTERRUPT_CTC :
                pCTC_CallBackFunctions[2] = pTimer_ISR;
                break;

            default: kErrorState = FunctioParameterError;
        }
        
    }else
    {
        kErrorState = FunctioParameterError;
    }
    return kErrorState;
}



/*TIMER0 Normal Mode ISR*/
void __vector_11(void) __attribute__((signal));
void __vector_11(void)
{
    if(pOVF_CallBackFunctions[0]!=NULL_ptr)
    {
        pOVF_CallBackFunctions[0]();
    }
}
/*TIMER0 CTC  Mode ISR*/
void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
    if(pCTC_CallBackFunctions[0]!=NULL_ptr)
    {
        pCTC_CallBackFunctions[0]();
    }
}


/*TIMER1 Normal Mode ISR*/
void __vector_9(void) __attribute__((signal));
void __vector_9(void)
{
    if(pOVF_CallBackFunctions[1]!=NULL_ptr)
    {
        pOVF_CallBackFunctions[1]();
    }
}
/*TIMER1 CTC A Mode ISR*/
void __vector_7(void) __attribute__((signal));
void __vector_7(void)
{
    if(pCTC_CallBackFunctions[1]!=NULL_ptr)
    {
        pCTC_CallBackFunctions[1]();
    }
}
/*TIMER1 CTC B Mode ISR*/
void __vector_8(void) __attribute__((signal));
void __vector_8(void)
{
    if(pCTC_CallBackFunctions[3]!=NULL_ptr)
    {
        pCTC_CallBackFunctions[3]();
    }
}
// /*TIMER1 ICU Mode ISR*/
// void __vector_6(void) __attribute__((signal));
// void __vector_6(void)
// {
//     if(pICU_CallBackFunction!=NULL_ptr)
//     {
//         pICU_CallBackFunction();
//     }
// }

/*TIMER2 Normal Mode ISR*/
void __vector_5(void) __attribute__((signal));
void __vector_5(void)
{
    if(pOVF_CallBackFunctions[2]!=NULL_ptr)
    {
        pOVF_CallBackFunctions[2]();
    }
}

/*TIMER2 CTC Mode ISR*/
void __vector_4(void) __attribute__((signal));
void __vector_4(void)
{
    if(pCTC_CallBackFunctions[2]!=NULL_ptr)
    {
        pCTC_CallBackFunctions[2]();
    }
}

#endif /* MCAL_TIMER_TIMER_PROGRAM_C_ */
