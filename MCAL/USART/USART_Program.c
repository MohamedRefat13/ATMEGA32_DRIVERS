/**
 * @file USART_Program.c
 * @author Mohamed Refat
 * @brief
 * @version 0.1
 * @date 2023-11-10
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../../HAL/04_CLCD/CLCD_Interface.h"
#include "USART_Config.h"
#include "USART_Interface.h"
#include "USART_Private.h"

char *pReceivedChar = NULL_ptr;
void (*pRx_CallBackFunction)(char *pChar) = NULL_ptr;
void (*pTx_CallBackFunction)(char *pChar) = NULL_ptr;
char *pGlobalTransmittedStr = NULL_ptr;
char *pGlobalReceivedStr = NULL_ptr;
uint16_tt strIterator = 0;
uint16_tt dataLength = 0;
void USART_Init(unsigned short int copyBaudRate)
{
    /* 1--> Calculate Baud Rate */
    uint16_tt UBRR_Value = 0;

    /* Set URSEL bit to 1 to Access UCSRC */
    SET_BIT(UCSRC, UCSRC_URSEL);

/* Select USART Mode And Calculate UBRR for baud rate */
#if USART_MODE == USART_SYNCHRONOUS_MODE

    /* Calculate UBRR value  */
    UBRR_Value = (F_CPU / (2 * copyBaudRate)) -1;

    /* Select Mode */
    SET_BIT(UCSRC, UCSRC_UMSEL);


#elif (USART_MODE == USART_ASYNCHRONOUS_MODE && \
       USART_ASYN_SPEED == USART_ASYN_DOUBLE_SPEED)

    /* Calculate UBRR value  */
    UBRR_Value = (F_CPU / (8 * copyBaudRate)) -1;

    /* Select  Asynchronous Mode */
    CLR_BIT(UCSRC, UCSRC_UMSEL);

    /* Set USART Speed to double speed */
    SET_BIT(UCSRA, UCSRA_U2X);


#elif (USART_MODE == USART_ASYNCHRONOUS_MODE && \
       USART_ASYN_SPEED == USART_ASYN_NORMAL_SPEED)

    /* Calculate UBRR value  */
    UBRR_Value = (uint16_tt)(F_CPU / (16U * copyBaudRate)) - 1;

    /* Select  Synchronous Mode */
    CLR_BIT(UCSRC, UCSRC_UMSEL);

    /* Set USART Speed to Normal speed */
    CLR_BIT(UCSRA, UCSRA_U2X);

#endif


    /* Set Data Size */
#if USART_DATA_SEIZE == USART_DATA_SIZE_5_BIT

    CLR_BIT(UCSRC, UCSRC_UCSZ0);
    CLR_BIT(UCSRC, UCSRC_UCSZ1);
    CLR_BIT(UCSRB, UCSRB_UCSZ2);
    
#elif USART_DATA_SEIZE == USART_DATA_SIZE_6_BIT

    SET_BIT(UCSRC, UCSRC_UCSZ0);
    CLR_BIT(UCSRC, UCSRC_UCSZ1);
    CLR_BIT(UCSRB, UCSRB_UCSZ2);

#elif USART_DATA_SEIZE == USART_DATA_SIZE_7_BIT

    CLR_BIT(UCSRC, UCSRC_UCSZ0);
    SET_BIT(UCSRC, UCSRC_UCSZ1);
    CLR_BIT(UCSRB, UCSRB_UCSZ2);

#elif USART_DATA_SEIZE == USART_DATA_SIZE_8_BIT

    SET_BIT(UCSRC, UCSRC_UCSZ0);
    SET_BIT(UCSRC, UCSRC_UCSZ1);
    CLR_BIT(UCSRB, UCSRB_UCSZ2);

#endif


    /* Set Parity Check Type */
#if USART_PARITY_TYPE == USART_NO_PARITY

    CLR_BIT(UCSRC, UCSRC_UPM0);
    CLR_BIT(UCSRC, UCSRC_UPM1);

#elif USART_PARITY_TYPE == USART_EVEN_PARITY

    CLR_BIT(UCSRC, UCSRC_UPM0);
    SET(UCSRC, UCSRC_UPM1);

#elif USART_PARITY_TYPE == USART_ODD_PARITY

    SET(UCSRC, UCSRC_UPM0);
    SET(UCSRC, UCSRC_UPM1);

#endif


    /* Set Number of Stop bits */
#if USART_STOP_BITS == USART_STOP_BITS_ONE

    CLR_BIT(UCSRC,UCSRC_USBS);

#elif USART_STOP_BITS == USART_STOP_BITS_TWO
    SET_BIT(UCSRC,UCSRC_USBS);

#endif

    /* Clear URSEL bit to 0
        to Access UBRRH register to set the value of baud rate
    */
    CLR_BIT(UBRRH, UBRRH_URSEL);

    
/* Note : The calculated Value wont be accurate using these equation
    // Set upper 4 bits first
    UBRR_Value &= 0X0FFF;
    //UBRRH = (uint8_t)(UBRR_Value>>8);
    //UBRRH |= ( (UBRR_Value>>8) & UBRRH_MASK );

    // Set Lower byte of UBRR
    //UBRRL = (uint8_t)UBRR_Value;
*/
#if USART_BAUD_RATE == USART_BAUD_RATE_2400
    UBRRH = 0;
    UBRRL = 207;
#elif USART_BAUD_RATE == USART_BAUD_RATE_4800
    UBRRH = 0;
    UBRRL = 103;
#elif USART_BAUD_RATE == USART_BAUD_RATE_9600
    UBRRH = 0;
    UBRRL = 51;
#endif
    
}

void USART_EnableTransmitter(void)
{
    SET_BIT(UCSRB, UCSRB_TXEN);
}

void USART_EnableReceiver(void)
{
    SET_BIT(UCSRB, UCSRB_RXEN);
}
void USART_RxInterruptControl(uint8_t ControlStatue)
{
    switch (ControlStatue)
    {
        case USART_RX_INTERRUPT_ENABLE:
            SET_BIT(UCSRB, UCSRB_RXCIE);
            break;

        case USART_RX_INTERRUPT_DISABLE:
            CLR_BIT(UCSRB, UCSRB_RXCIE);
            break;
    }
}
void USART_TxInterruptControl(uint8_t ControlStatue)
{
    switch (ControlStatue)
    {
        case USART_TX_INTERRUPT_ENABLE:
            SET_BIT(UCSRB, UCSRB_TXCIE);
            break;

        case USART_TX_INTERRUPT_DISABLE:
            CLR_BIT(UCSRB, UCSRB_TXCIE);
            break;
    }
}
void USART_SendChar(uint8_t copyChar)
{
    /* Wait for the transmit buffer to be empty */ 
    while ( (GET_BIT(UCSRA, UCSRA_UDRE )) == 0 );
    UDR = copyChar;
    /* Wait until the transmit is complete */ 
    while ( (GET_BIT(UCSRA, UCSRA_TXC )) == 1 );

}
void USART_ReceiveCharSyn(char *pChar)
{
    /* Wait until the receive is complete */ 
    while ( (GET_BIT(UCSRA, UCSRA_RXC ) )== 0 );
    *pChar = UDR;
}

void USART_SendStringSyn(char *pString)
{
    uint16_tt iterator = 0;
    while ( pString[iterator] != '\0')
    {
        USART_SendChar( pString[iterator]);
        iterator++;
    }

    USART_SendChar('\0');

}

void USART_ReceiveStringSyn(char pString[], uint16_tt strLength)
{

    uint16_tt iterator = 0;
    char temp = 0 ;
    USART_ReceiveCharSyn(&temp);
    while ( temp != 0 &&   iterator < strLength-1)
    {
        pString[ iterator ] = temp;
        USART_ReceiveCharSyn(&temp);
        iterator++;
    }
    pString[ iterator ] = 0;
}

void USART_ReceiveCharAsyn(char *pChar, void (*pFun)(char *pChar) )
{
    if (pFun != NULL_ptr)
    {
        pGlobalReceivedStr = pChar;
        pRx_CallBackFunction = pFun;
        dataLength = 1;
        /* Enable Transmit Complete Interrupt  */
        SET_BIT(UCSRB, UCSRB_TXCIE);
    }
}
void USART_SendStringAsyn(char *pString, void (*pFun)(char *pString) )
{
    if ( pString != NULL_ptr && pFun != NULL_ptr)
    {
        pGlobalTransmittedStr = pString;
        pTx_CallBackFunction = pFun;
        /* Send First Char in the string */
        UDR = pGlobalTransmittedStr[0];

        /* Enable Transmit Complete Interrupt  */
        SET_BIT(UCSRB, UCSRB_TXCIE);
    }
}
void USART_ReceiveStringAsyn(char *pString, uint16_tt strLength, void (*pFun)(char *pString))
{
    if ( pString != NULL_ptr && pFun != NULL_ptr)
    {
        pRx_CallBackFunction = pFun;
        pGlobalReceivedStr = pString;

        dataLength = strLength;
        /* Enable Receive Complete Interrupt  */
        SET_BIT(UCSRB, UCSRB_RXCIE);
    }
}

/* Transmit Complete ISR  */
void __vector_15(void) __attribute__ ((signal));
void __vector_15(void)
{
    strIterator++;
    if (pGlobalTransmittedStr[ strIterator ] != '\0')
    {
        UDR = pGlobalTransmittedStr[strIterator];

    }else 
    {
        /* End of String */
        strIterator = 0;
        pTx_CallBackFunction(pGlobalTransmittedStr);

        /* Disable Transmit Complete Interrupt */
        CLR_BIT(UCSRB, UCSRB_TXCIE);
        /*Send Null After Disable the Interrupt to make sure that the
         Tx interrupt flag wont fire again */
        UDR = '\0';
    }
}

/* Receive Complete ISR  */
void __vector_13(void) __attribute__ ((signal));
void __vector_13(void)
{

    pGlobalReceivedStr[strIterator] = UDR;
    if (pGlobalReceivedStr[strIterator] == '\0' || strIterator == dataLength-1 )
    {
        /* USART Received all the data[string] */
        strIterator = 0;
        pRx_CallBackFunction(pGlobalReceivedStr);

    }else if ( pGlobalReceivedStr[strIterator] != '\0' )
    {
        strIterator++;
    }

}
