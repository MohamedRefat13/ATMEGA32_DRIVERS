/*
 * GIE_Interface.h
 *
 *  Created on: 17 Aug 2022
 *      Author: mo7am
 */

#ifndef MCAL_GIE_GIE_INTERFACE_H_
#define MCAL_GIE_GIE_INTERFACE_H_

#define GLOBAL_INTERRUPT_ENABLE   1
#define GLOBAL_INTERRUPT_DISABLE  0


/*
 * brief :Control Global Interrupt enable or disable
 * @para: copy_u8Control options:
 *						 GLOBAL_INTERRUPT_ENABLE
 *						 GLOBAL_INTERRUPT_DISABLE
 *
 *
 * return: Non
 * */

void GIE_voidGlobalInterruptControl(uint8_t copy_u8Control);

#endif /* MCAL_GIE_GIE_INTERFACE_H_ */
