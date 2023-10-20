/*
 * INT_EEPROM.c
 *
 *  Created on: Aug 11, 2023
 *      Author: Mohamed Refat
 */

#include <Util/delay.h>
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/Error.h"
#include "INT_EEPROM_Private.h"
#include "INT_EEPROM_Interface.h"

Error_t INT_EEPROM_WriteByte(uint16_tt address  , uint8_t kData)
{
    Error_t kErrorState = NoError ;
    if(address > EEPROM_MAX_ADDRESS)
    {
        kErrorState = FunctioParameterError ;
    }else
    {
        /* 1) Wait until the previews write operation is done */
        while ( (GET_BIT(EECR_REG , EECR_EEWE)) );
        /* 2) Write Address */
        EEARH_REG = (address>>8) ;
        EEARL_REG = address ;

        /* 3) Write Data */
        EEDR_REG = kData ;

        /* 4) Write 1 to EEPROM master write enable (EEMWE) to enable write operation option */
        SET_BIT(EECR_REG , EECR_EEMWE);
        /* 5) Write 1 to EEPROM master write enable (EEWE) to enable write operation*/
        SET_BIT(EECR_REG , EECR_EEWE);
        /* NOTE : EEWE is clear by HW after the write is done */

    }
    return kErrorState ;
}

Error_t INT_EEPROM_ReadByte(uint16_tt address  , uint8_t *pData)
{
    Error_t kErrorState = NoError ;
    if(address > EEPROM_MAX_ADDRESS || pData == NULL_ptr)
    {
        kErrorState = FunctioParameterError ;
    }else
    {
        /* 1) Wait until the previews write operation is done */
        //while ( (GET_BIT(EECR_REG , EECR_EEWE)) == DIO_HIGH_PIN );

        /* 2) Write Address */
    	EEARH_REG = (address>>8) ;
    	EEARL_REG = (uint8_t)address ;
        /* 3) Write 1 to EERE to start Read */
        SET_BIT(EECR_REG , EECR_EERE);

        *pData = EEDR_REG ;

        /* NOTE : EEWE is clear by HW after the read is done */

    }
    return kErrorState ;
}
