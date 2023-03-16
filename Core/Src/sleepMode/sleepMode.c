/*
 * sleepMode.c
 *
 *  Created on: Mar 13, 2023
 *      Author: user
 */
#include <stm32f4xx_hal.h>
#include "sleepMode.h"
#include "../systemClock/systemClock.h"
#include "../timers/timers.h"

bool isSleepModeStart = false;

void sleepMode(void)
{
    if(isSleepModeStart)
    {
        stopTim5();
        tmr11_PWM_set(0);

        SystemClock_Config_HSI();
        stopHSE();

        GC9A01A_DisplayPower(0);

        HAL_SuspendTick();
        __HAL_RCC_PWR_CLK_ENABLE();
        /* Request to enter SLEEP mode */
        HAL_PWR_EnterSLEEPMode(PWR_MAINREGULATOR_ON, PWR_SLEEPENTRY_WFI);
        /* Resume Tick interrupt if disabled prior to sleep mode entry*/
        HAL_ResumeTick();
    }
}

void setStateSleepMode(bool turnOnOff)
{
    isSleepModeStart = turnOnOff;
}

bool getStateSleepMode(void)
{
    return isSleepModeStart;
}

void awakening(void)
{
    SystemClock_Config();
    stopHSI();

    GPIO_init();
    GC9A01A_DisplayPower(1);

   startTim5();
   tmr11_PWM_set(100);
}
