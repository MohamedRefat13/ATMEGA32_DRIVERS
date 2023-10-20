/*
 * INT_EEPROM_Interface.h
 *
 *  Created on: Aug 11, 2023
 *      Author: Mohamed Refat
 */

#ifndef MCAL_INT_EEPROM_INT_EEPROM_INTERFACE_H_
#define MCAL_INT_EEPROM_INT_EEPROM_INTERFACE_H_

/* This Driver doesn't work correctly  */

/**
 * @brief          : This function is used to Write on a specific byte in the EEPROM
 * 
 * @param address  : The Address of the byte [0 --> 1023] [0x00 --> 0xFF]
 * @param kData    : Copy from the data you want to write on the EEPROM
 * @return Error_t :   NoError               --> if function passed parameter is Correct
 * 					   FunctioParameterError --> if function passed parameter is wrong
 */
Error_t INT_EEPROM_WriteByte(uint16_tt address, uint8_t kData);




/**
 * @brief          : This function is used to Read on a specific byte in the EEPROM
 *
 * @param address  : The Address of the byte [0 --> 1023] [0x00 --> 0xFF]
 * @param pData    : Pionter to the data to hold it from the EEPROM
 * @return Error_t :   NoError               --> if function passed parameter is Correct
 * 					   FunctioParameterError --> if function passed parameter is wrong
 */
Error_t INT_EEPROM_ReadByte(uint16_tt address, uint8_t *pData);

#endif /* MCAL_INT_EEPROM_INT_EEPROM_INTERFACE_H_ */
