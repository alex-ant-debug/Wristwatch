#include <stdlib.h>
#include "dispcolor.h"
#include "timers.h"
#include "main.h"
#include "widgets/clock.h"
#include "widgets/menu.h"
#include "sleepMode/sleepMode.h"
#include "systemClock/systemClock.h"


static void MX_GPIO_Init(void);


static encoderData_t encoder;
static uint16_t encoderCounter = 0;
bool isEncSecondOperation = false;


int main(void) {
    HAL_Init();
    SystemClock_Config();

    RTC_Init();
    TIM2_Init(MENU_ZIZE*2);
    TIM3_Init();
    TIM5_Init();
    MX_GPIO_Init();

    dispcolorInit(240, 240);
    startTim5();

    while(1)
    {
        if(encoder.isEnter)
        {
            encoder.isEnter = false;
            DrawMenu(&encoder);
        }
        else
        {
        	//DrawAnalogClock(0);//
        	DrawClock();
        }
        sleepMode();
    }
}

static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin : PB8 */
  GPIO_InitStruct.Pin = GPIO_PIN_8;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI9_5_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);
}



void HAL_TIM_TriggerCallback(TIM_HandleTypeDef *htim)
{
    if(htim->Instance == TIM2)
    {
        if(isEncSecondOperation)
        {
            encoderCounter = getTIM2Counter();

            if(encoderCounter != 0)
            {
                uint32_t maxCountTIM2 = getTIM2AutoReload();
                // encoder count failure prevention
                if((encoderCounter == maxCountTIM2)&&(encoder.encoderPosition == 0))
                {
                    setTIM2Counter(maxCountTIM2 - 2);
                    encoderCounter = encoder.encoderPosition = (maxCountTIM2/2) - 1;
                }
                else if((encoderCounter == maxCountTIM2)&&(encoder.encoderPosition == (maxCountTIM2/2) - 1))
                {
                    encoderCounter = encoder.encoderPosition = 0;
                    setTIM2Counter(0);
                }
                else
                {
                    encoder.encoderPosition = encoderCounter/2;
                }
            }
            else
            {
                encoder.encoderPosition = 0;
            }

            isEncSecondOperation = false;
        }
        else
        {
            isEncSecondOperation = true;
        }
        // sleep timer reset
        restartTim5();
    }
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
   if(GPIO_Pin == GPIO_PIN_8)
   {
       if(!getStateSleepMode())
       {
           encoder.isEnter = true;
       }
       else
       {
           // device woke up
           setStateSleepMode(false);
           MX_GPIO_Init();

           awakening();
       }
       // sleep timer reset
       restartTim5();
   }
}

/**
 * @brief  This function is executed in case of error occurrence.
 * @retval None
 */
void Error_Handler(void) {
    /* USER CODE BEGIN Error_Handler_Debug */
    /* User can add his own implementation to report the HAL error return state */

    /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
