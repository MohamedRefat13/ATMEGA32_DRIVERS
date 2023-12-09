/**
 * @file USART_Interface.h
 * @author Mohamed Refat 
 * @brief 
 * @version 0.1
 * @date 2023-11-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef USART_INTERFACE_H
#define USART_INTERFACE_H

/* USART Modes */
#define USART_ASYNCHRONOUS_MODE (0)
#define USART_SYNCHRONOUS_MODE  (1)

/* USART Asynchronous Mode Speed */
#define USART_ASYN_NORMAL_SPEED (3)
#define USART_ASYN_DOUBLE_SPEED (4)

/* USART Stop Bit Types */
#define USART_STOP_BITS_ONE     (5)
#define USART_STOP_BITS_TWO     (6)

/* USART Baud Rate  */
#define USART_BAUD_RATE_2400 (0)
#define USART_BAUD_RATE_4800 (1)
#define USART_BAUD_RATE_9600 (2)

/* USART parity check Types */
#define USART_EVEN_PARITY       (7)
#define USART_ODD_PARITY        (8)
#define USART_NO_PARITY         (9)

/* USART Data Size */
#define USART_DATA_SIZE_5_BIT   (0)
#define USART_DATA_SIZE_6_BIT   (1)
#define USART_DATA_SIZE_7_BIT   (2)
#define USART_DATA_SIZE_8_BIT   (3)
#define USART_DATA_SIZE_9_BIT   (4)


/* USART Clock Polarity */
#define USART_POLARITY_RISING_EDGE  (5)
#define USART_POLARITY_FALLING_EDGE (6)

/* USART Interrupt State */
#define USART_RX_INTERRUPT_ENABLE  (1)
#define USART_RX_INTERRUPT_DISABLE (2)
#define USART_TX_INTERRUPT_ENABLE  (3)
#define USART_TX_INTERRUPT_DISABLE (4)

void USART_Init(unsigned short int copyBaudRate);
void USART_EnableTransmitter(void);
void USART_EnableReceiver(void);
void USART_RxInterruptControl(uint8_t ControlStatue);
void USART_TxInterruptControl(uint8_t ControlStatue);

void USART_SendChar(uint8_t copyChar);

void USART_ReceiveCharSyn(char *pChar);
void USART_SendStringSyn(char *pString);
void USART_ReceiveStringSyn(char *pString, unsigned short int strLength);

void USART_ReceiveCharAsyn(char *pChar, void (*pFun)(char *pChar) );
void USART_SendStringAsyn(char *pString, void (*pFun)(char *pString) );
void USART_ReceiveStringAsyn(char *pString, unsigned short int strLength,
                                                    void (*pFun)(char *pString));

#endif /* USART_INTERFACE_H */
