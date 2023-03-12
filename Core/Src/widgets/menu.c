/*
 * menu.c
 *
 *  Created on: Mar 9, 2023
 *      Author: user
 */
#include <stm32f4xx_hal.h>
#include <string.h>
#include <dispcolor.h>
#include <font.h>
#include <math.h>

#include "menu.h"
#include "../widgets/stopwatch.h"
#include "../widgets/timeSetting.h"
#include "../widgets/ChangBackground.h"
#include "../rtc/rtc.h"


void DrawMenu(encoderData_t *count)
{
	uint8_t exit = 1;
	while(exit)
	{
		uint16_t firstColor, secondColor, thirdColor, fourthColor;

		firstColor = secondColor = thirdColor = fourthColor = digitColor;

		switch (count->encoderPosition) {
		case STOPWATCH:
			firstColor = selectedText;
			if(count->isEnter)
			{
				count->isEnter = false;
				DrawStopwatch(count, 0);
			}
			break;
		case TIME_SETTING:
			secondColor = selectedText;
			if(count->isEnter)
			{
				count->isEnter = false;
				RTC_TimeTypeDef timeNow = { 0 };
				RTC_DateTypeDef todayDate = { 0 };
				RTC_GetTime(&timeNow, &todayDate);
				DrawTimeSetting(count, &timeNow, &todayDate);
			}
			break;
		case CHANG_BACKGROUND:
			thirdColor = selectedText;
			if(count->isEnter)
			{
				count->isEnter = false;
				DrawChangBackground(count);
			}
			break;
		case EXIT:
			fourthColor = selectedText;
			if(count->isEnter)
			{
				count->isEnter = false;
				exit = 0;
			}

			break;
		default: break;
		}

		dispcolorFillScreen(bgColor);

		dispcolorPrintf(85, 80, FONTID_16F, firstColor, "%s", "Stopwatch");
		dispcolorPrintf(20, 110, FONTID_16F, secondColor, "%s", "Setting the time and date");
		dispcolorPrintf(60, 140, FONTID_16F, thirdColor, "%s", "Background color");
		dispcolorPrintf(105, 170, FONTID_16F, fourthColor, "%s", "Exit");

		dispcolorUpdate();

		HAL_Delay(50);
	}
}
