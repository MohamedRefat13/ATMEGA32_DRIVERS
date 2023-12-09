/**
 * @file USART_Private.h
 * @author Mohamed Refat 
 * @brief 
 * @version 0.1
 * @date 2023-11-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef USART_PRIVATE_H
#define USART_PRIVATE_H

/* Registers */
#define UBRRH *((volatile uint8_t *)0x40)
#define UCSRC *((volatile uint8_t *)0x40)  /* USART Control and Status Register C */
#define UDR   *((volatile char *)0x2C)
#define UCSRA *((volatile uint8_t *)0x2B)  /* USART Control and Status Register A */
#define UCSRB *((volatile uint8_t *)0x2A)  /* USART Control and Status Register B */
#define UBRRL *((volatile uint8_t *)0x29)


/* Register Bits */
#define UBRRH_URSEL (7) /* Register Select */
#define UCSRC_URSEL (7) /* Register Select */
#define UCSRC_UMSEL (6) /* USART Mode Select */
#define UCSRC_UPM1  (5)
#define UCSRC_UPM0  (4)
#define UCSRC_USBS  (3)
#define UCSRC_UCSZ1 (2) /* Character Size */
#define UCSRC_UCSZ0 (1) /* Character Size */
#define UCSRC_UCPOL (0)

#define UCSRB_RXCIE (7)  /* RX Complete Interrupt Enable */
#define UCSRB_TXCIE (6)  /* TX Complete Interrupt Enable */
#define UCSRB_UCSZ2 (2)  /* Character Size */
#define UCSRB_RXEN  (4)  /* Receiver Enable */
#define UCSRB_TXEN  (3)  /* Transmit Enable */


#define UCSRA_RXC   (7)  /* USART Receive Complete */
#define UCSRA_TXC   (6)  /* USART Transmit Complete */
#define UCSRA_UDRE  (5)  /* USART Data Register Empty */
#define UCSRA_U2X   (1)  /* U2X: Double the USART Transmission Speed */


/* Bit Mask */
#define UBRRH_MASK (0X0F)

#endif /* USART_PRIVATE_H */
