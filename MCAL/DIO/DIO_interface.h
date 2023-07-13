/*
 * @file  : DIO_intrfacr.h
 * @brief : This header file hase DIO Data types and DIO functions prototype
 * @date  : Feb 9, 2023
 * @author: Mohamed Refat
 */

#ifndef MCAL_DIO_DIO_INTERFACE_H_
#define MCAL_DIO_DIO_INTERFACE_H_

#include "../../LIB/Error.h"

/* Define Microcontroller PORTS */
enum PORT
{
	DIO_PORTA ,
	DIO_PORTB ,
	DIO_PORTC ,
	DIO_PORTD 
};


/* Define Microcontroller Pins */
enum PIN
{
	DIO_PIN0  ,
	DIO_PIN1  ,
	DIO_PIN2  ,
	DIO_PIN3  ,
	DIO_PIN4  ,
	DIO_PIN5  ,
	DIO_PIN6  ,
	DIO_PIN7 
};
/*Define direction of ports*/
#define DIO_OUTPUT_PORT 0XFF
#define DIO_INPUT_PORT  0X00

/*Define direction of ports*/
enum PIN_DIRECTION
{
	DIO_INPUT_PIN   ,
	DIO_OUTPUT_PIN   
};

/*Define Pin Voltage Level*/
enum VoltageLevels
{
	DIO_LOW_PIN  ,
	DIO_HIGH_PIN 
};

//#include "../../LIB/Error.h"

#define DIO_HIGH_PORT (0XFF) 
#define DIO_LOW_PORT  (0X00) 

/**
 * @brief 				: This function is used to set Data Direction of the Pin [OUTPUT , INPUT] 
 * @param  Port 		: Port --> [DIO_PORTA , DIO_PORTB , DIO_PORTC ,   DIO_PORTD ]
 * @param  PinNumber 	: PinNumber --> [DIO_PIN1  , DIO_PIN2  , DIO_PIN3 .... DIO_PIN7  ]
 * @param  Direction 	: Direction --> [DIO_INPUT_PIN , DIO_OUTPUT_PIN]
 * @return Error_t 		: DIO_OK --> if function passed parameter is Correct
 * 						  DIO_OK --> if function passed parameter is wrong
 */
Error_t DIO_SetPinDirection(uint8_t PortNumber , uint8_t PinNumber , uint8_t Direction);

/**
* @brief 				: This function is used to set the pin volage level [High , Low] 
* @param PortNumber		: Port --> [DIO_PORTA , DIO_PORTB , DIO_PORTC ,   DIO_PORTD ]
* @param PinNumber		: PinNumber --> [DIO_PIN1  , DIO_PIN2  , DIO_PIN3 .... DIO_PIN7  ]
* @param VoltageLevel	: VoltageLevel --> [DIO_HIGH_PIN , DIO_LOW_PIN]
* @return Error_t		: DIO_OK --> if function passed parameter is Correct
*					      DIO_OK --> if function passed parameter is wrong
 */
Error_t DIO_SetPinValue(uint8_t PortNumber , uint8_t PinNumber , uint8_t VoltageLevel);

/**
* @brief 				: This function is get the pin voltage value 
* @param PortNumber		: Port --> [DIO_PORTA , DIO_PORTB , DIO_PORTC ,   DIO_PORTD ]
* @param PinNumber		: PinNumber --> [DIO_PIN1  , DIO_PIN2  , DIO_PIN3 .... DIO_PIN7  ]
* @param PinVal			: VoltageLevel --> Pointer to recieve pinn value
* @return Error_t		: DIO_OK --> if function passed parameter is Correct
*					      DIO_OK --> if function passed parameter is wrong
 */
Error_t DIO_GetPinValue(uint8_t PortNumber , uint8_t PinNumber , uint8_t *PinVal);

/**
 * @brief 				: This function is used to set Data Direction of the PORT [OUTPUT , INPUT] 
 * @param  Port 		: Port --> [DIO_PORTA , DIO_PORTB , DIO_PORTC ,   DIO_PORTD
 * @param  Direction 	: Direction --> [DIO_INPUT_PIN , DIO_OUTPUT_PIN]
 * @return Error_t 		: DIO_OK --> if function passed parameter is Correct
 * 						  DIO_OK --> if function passed parameter is wrong
 */
Error_t DIO_SetPortDirection(uint8_t PortNumber , uint8_t Direction);



/**
* @brief 				: This function is used to set the Port value
* @param PortNumber		: Port --> [DIO_PORTA , DIO_PORTB , DIO_PORTC ,   DIO_PORTD ]
* @param VoltageLevel	: VoltageLevel --> [DIO_HIGH_PORT , DIO_HIGH_PORT] 
* @return Error_t		: DIO_OK --> if function passed parameter is Correct
*					      DIO_OK --> if function passed parameter is wrong
 */
Error_t DIO_SetPortValue(uint8_t PortNumber , uint8_t PortValue );



/**
* @brief 				: This function is Toggle  pin voltage 
* @param PortNumber		: Port --> [DIO_PORTA , DIO_PORTB , DIO_PORTC ,   DIO_PORTD ]
* @param PinNumber		: PinNumber --> [DIO_PIN1  , DIO_PIN2  , DIO_PIN3 .... DIO_PIN7  ]
* @return Error_t		: DIO_OK --> if function passed parameter is Correct
*					      DIO_OK --> if function passed parameter is wrong
 */
Error_t DIO_TogglePinValue(uint8_t PortNumber , uint8_t PinNumber);
/**
* @brief 				: This function is used to set value of Low Nibble Value pins in Port 
* @param PortNumber		: Port   --> [DIO_PORTA , DIO_PORTB , DIO_PORTC ,   DIO_PORTD ]
* @param Value			: Value  --> Port Val
* @return Error_t		: DIO_OK --> if function passed parameter is Correct
*					      DIO_OK --> if function passed parameter is wrong
 */
Error_t DIO_SetLowNibbleValue(uint8_t PortNumber , uint8_t Value);
/**
* @brief 				: This function is used to set value of Hight Nibble Value pins in Port 
* @param PortNumber		: Port   --> [DIO_PORTA , DIO_PORTB , DIO_PORTC ,   DIO_PORTD ]
* @param Value			: Value  --> Port Val
* @return Error_t		: DIO_OK --> if function passed parameter is Correct
*					      DIO_OK --> if function passed parameter is wrong
*/
Error_t DIO_SetHighNibbleValue(uint8_t PortNumber , uint8_t Value);

#endif /* MCAL_DIO_DIO_INTERFACE_H_ */


