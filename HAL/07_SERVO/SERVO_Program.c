/**
 * @file SERVO_Program.c
 * @author Mohamed Refat 
 * @brief 
 * @version 0.1
 * @date 2024-02-11
 * 
 */

 #include "../../LIB/STD_TYPES.h"
#include "../../LIB/Error.h"
#include "../../MCAL/TIMER/TIMER_Interface.h"
#include "SERVO_Interface.h"

Error_t SERVO_Init(uint8_t kChannel)
{
    Error_t kErrorState = NoError;
    if (kChannel == PWM1_OC1A || kChannel == PWM1_OC1B )
    {
        TIMER1_SetPWM_Channel_Mode(kChannel, PWM1_INVERTING);
        TIMER1_SetPWM_Freq(50, PWM1_PRESCALER_64);
        SERVO_SetAngle(0,kChannel);
        TIMER1_Init(TIMER_PWM_MODE, TIMER1_PRESCALER_64);
    }else
    {
        kErrorState = FunctioParameterError;

    }
    return kErrorState;
}
Error_t SERVO_SetAngle(uint8_t copyAngle, uint8_t kChannel)
{
    Error_t kErrorState = NoError;
    if ( copyAngle <= 180 &&
    	   (kChannel == PWM1_OC1A || kChannel == PWM1_OC1B))
    {
    	 /**
    	 * At freq = 50 Hz
    	 * The max Control Pulse = 2ms   --> Max Duty Cycle = 10  -> at angle   180
    	 * The max Control Pulse = 1ms   --> Min Duty Cycle = 5   -> at angle   0
    	 * The max Control Pulse = 1.5ms --> Mid Duty Cycle = 7.5 -> at angle   90
    	 *
         *
         * So what is the 36??
         * 	since the min duty cycle is 5 at angle 0
         * 		to reach the max duty cycle --> 10 at angle 180
         *		180/x + (5) = 10 --> x = 36
         */
        f32_t dutyCycle = (copyAngle/36.0) + 5;
       TIMER1_SetDutyCycle(dutyCycle,kChannel);
    }else 
    {
        kErrorState = FunctioParameterError;
    }
    return kErrorState;
}


