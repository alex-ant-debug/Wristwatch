/*
 * tmr5.c
 *
 *  Created on: Mar 11, 2023
 *      Author: user
 */
#include <stm32f4xx_hal_rcc.h>
#include <stm32f4xx_hal_tim.h>
#include <stm32f4xx_hal_gpio.h>
#include "tmr5.h"
#include "timers.h"

TIM_HandleTypeDef htim5;


void TIM5_Init(void)
{

  /* USER CODE BEGIN TIM5_Init 0 */

  /* USER CODE END TIM5_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM5_Init 1 */

  /* USER CODE END TIM5_Init 1 */
  htim5.Instance = TIM5;
  htim5.Init.Prescaler = 10000;
  htim5.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim5.Init.Period = 300000;
  htim5.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim5.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
  if (HAL_TIM_Base_Init(&htim5) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim5, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim5, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM5_Init 2 */

  /* USER CODE END TIM5_Init 2 */
}

void startTim5(void)
{
    //clear the flag so that the interrupt does not work immediately after initialization
    __HAL_TIM_CLEAR_FLAG(&htim5, TIM_SR_UIF);
    HAL_TIM_Base_Start_IT(&htim5);
}
void stopTim5(void)
{
    HAL_TIM_Base_Stop_IT(&htim5);
}

void restartTim5(void)
{
    HAL_TIM_Base_Stop_IT(&htim5);
    TIM5->CNT = 0;
    HAL_TIM_Base_Start_IT(&htim5);
}
