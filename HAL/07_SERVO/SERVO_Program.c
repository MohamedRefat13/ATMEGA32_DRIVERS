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
        TIMER1_Init(TIMER_PWM_MODE, TIMER1_PRESCALER_64);
        SERVO_SetAngle(0,kChannel);
    }else
    {
        kErrorState = FunctioParameterError;

    }
    return kErrorState;
}
Error_t SERVO_SetAngle(sint8_t copyAngle, uint8_t kChannel)
{
    Error_t kErrorState = NoError;
    if ( copyAngle <= 90 || copyAngle >= -90 )
    {
        /**
         * Max Duty Cycle = 10  -> at angle  90
         * Max Duty Cycle = 5   -> at angle -90
         * mid Duty Cycle = 7.5 -> at angle  0
         *
         * So what is the 36??
         * 	since the mid duty cycle is 7.5 at angle 0
         * 		to reach the max duty cycle --> 10 at angle 90
         *		7.5 + 90/x = 10 --> x = 36
         * Example :
         *  		at angle 70 -->
         *  		duty cycle = 70/36 + 7.5 = 8.61111
         *  		and so on in the negative values
         *  		at angle -70 -->
         *  		duty cycle = -70/36 + 7.5 = 6.38889
         *
         */
        f32_t dutyCycle = (copyAngle/36.0) + 7.5;
       TIMER1_SetDutyCycle(dutyCycle,kChannel);
    }else 
    {
        kErrorState = FunctioParameterError;
    }
    return kErrorState;
}


