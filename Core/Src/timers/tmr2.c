/*
 * tmr2.c
 *
 *  Created on: Mar 9, 2023
 *      Author: user
 */
#include <stm32f4xx_hal_rcc.h>
#include <stm32f4xx_hal_tim.h>
#include <stm32f4xx_hal_gpio.h>
#include <tmr2.h>
#include "timers.h"
#include "gpio.h"


TIM_HandleTypeDef htim2;
TIM_Encoder_InitTypeDef sConfig = {0};
TIM_MasterConfigTypeDef sMasterConfig = {0};


void TIM2_Init(uint32_t period)
{
    htim2.Instance = TIM2;
    htim2.Init.Prescaler = 0;
    htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
    htim2.Init.Period = period;
    htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
    sConfig.EncoderMode = TIM_ENCODERMODE_TI1;
    sConfig.IC1Polarity = TIM_ICPOLARITY_RISING;
    sConfig.IC1Selection = TIM_ICSELECTION_DIRECTTI;
    sConfig.IC1Prescaler = TIM_ICPSC_DIV1;
    sConfig.IC1Filter = 0xF;
    sConfig.IC2Polarity = TIM_ICPOLARITY_RISING;
    sConfig.IC2Selection = TIM_ICSELECTION_DIRECTTI;
    sConfig.IC2Prescaler = TIM_ICPSC_DIV1;
    sConfig.IC2Filter = 0xF;
    if (HAL_TIM_Encoder_Init(&htim2, &sConfig) != HAL_OK)
    {
        Error_Handler();
    }
    sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
    sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
    if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
    {
        Error_Handler();
    }

    /* Trigger Edge Detector */
    /* 100: TI1 Edge Detector (TI1F_ED) */
    TIM2->SMCR &= ~(TIM_SMCR_TS_0 | TIM_SMCR_TS_1);
    TIM2->SMCR |= TIM_SMCR_TS_2;
    /* 1: Trigger interrupt enabled. */
    TIM2->DIER |= TIM_DIER_TIE;
    NVIC_EnableIRQ(TIM2_IRQn);

    HAL_TIM_Encoder_Start(&htim2, TIM_CHANNEL_ALL);
}

void resizeMenuCounter(uint32_t period, uint32_t startPosition)
{
    HAL_TIM_Encoder_Stop(&htim2, TIM_CHANNEL_ALL);
    TIM2->ARR = period;
    TIM2->CNT = startPosition;
    HAL_TIM_Encoder_Start(&htim2, TIM_CHANNEL_ALL);
}

uint32_t getTIM2Counter(void)
{
    return TIM2->CNT;
}

void setTIM2Counter(uint32_t counter)
{
    TIM2->CNT = counter;
}

uint32_t getTIM2AutoReload(void)
{
    return TIM2->ARR;
}
