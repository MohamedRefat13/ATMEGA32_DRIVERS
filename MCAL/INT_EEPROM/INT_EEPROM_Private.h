/*
 * INT_EEPROM_Private.h
 *
 *  Created on: Aug 11, 2023
 *      Author: Mohamed Refat
 */

#ifndef MCAL_INT_EEPROM_INT_EEPROM_PRIVATE_H_
#define MCAL_INT_EEPROM_INT_EEPROM_PRIVATE_H_


#define EEARH_REG  (*((volatile uint8_t  *) 0x3F))
#define EEARL_REG  (*((volatile uint8_t  *) 0x3E))
#define EEDR_REG   (*((volatile uint8_t  *) 0x3D))
#define EECR_REG   (*((volatile uint8_t  *) 0x3C))

#define EECR_EERIE  (3) 
#define EECR_EEMWE  (2) 
#define EECR_EEWE   (1)
#define EECR_EERE   (0)

#define EEPROM_MAX_ADDRESS (1023)

#endif /* MCAL_INT_EEPROM_INT_EEPROM_PRIVATE_H_ */
