/*
 * SWITCH_Interface.h
 *
 *  Created on: Mar 1, 2023
 *      Author: Mohamed Refat
 */

#ifndef HAL_03_SWITCH_SWITCH_INTERFACE_H_
#define HAL_03_SWITCH_SWITCH_INTERFACE_H_

typedef struct
{
	uint8_t SW_PortNum ;
	uint8_t SW_PinNum ;
	uint8_t SW_State ; 
}SWITCH_t;

enum SWITCH_MODE
{
	SW_PULL_UP ,
	SW_PULL_DOWN 
};
typedef enum 
{

	SW_NOT_PRESSED ,
	SW_PRESSED
}SWITCH_STATE_t;
/**
 * @brief                   :This function use ti initialize the switch
 * 
 * @param  pSwitch_Config   : is a pointer that is point to --> [SWITCH_t] -->  the configeration of the switch  
 * @return Std_ReturnType   : This function returns E_OK if it success (Parameter is correct)
 *                            and it returns E_NOT_OK if it failed (Parameter is Not correct)
 */
Error_t SWITCH_Init(SWITCH_t Switch_Config );
/**
 * @brief                     : This fuiction is used to get whether  the switch is pressed or not 
 * 
 * @param pSwitch_Config      : is a pointer that is point to --> [SWITCH_t] -->  the configeration of the switch  
 * @param pPressed_Value      : Pointer to the pressed value --> which could be [SW_NOT_PRESSED or SW_PRESSED]  
 * @return Std_ReturnType 
 */
Error_t SWITCH_GetPressed(SWITCH_t Switch_Config , SWITCH_STATE_t *pPressedValue);

#endif /* HAL_03_SWITCH_SWITCH_INTERFACE_H_ */
