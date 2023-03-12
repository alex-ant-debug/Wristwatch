/*
 * stopwatch.c
 *
 *  Created on: Mar 8, 2023
 *      Author: user
 */
#include <stm32f4xx_hal.h>
#include <string.h>
#include <dispcolor.h>
#include <font.h>
#include <math.h>

#include "../widgets/constants.h"
#include "../widgets/stopwatch.h"
#include "../timers/timers.h"


static bool isStarted = false;
char start[] = "START";
char stop[] = "STOP";

static uint32_t seconds = 0;
static uint16_t milliseconds = 0;
static uint8_t sixtySeconds = 0;

void DrawStopwatch(encoderData_t *count, uint8_t secBubbles)
{
	uint8_t exit = 1;
	static char stateBtn[6] = {0};

	if(!stateBtn[0])
	{
		strcpy(stateBtn, start);
	}

	resizeMenuCounter(STOPWATCH_MENU_SIZE*2, 0);

	while(exit)
	{
		uint16_t firstColor, secondColor, thirdColor;
		uint16_t secArcColor = (bgColor == WHITE)? MAGENTA: GREEN;

		firstColor = secondColor = thirdColor = digitColor;

		switch (count->encoderPosition) {
		case START_STOP:
			firstColor = selectedText;
			if((count->isEnter) && (!isStarted))
			{
				count->isEnter = false;
				startTim3();
				strcpy(stateBtn, stop);
				isStarted = true;
			}
			if((count->isEnter) && (isStarted))
			{
				count->isEnter = false;
				stopTim3();
				strcpy(stateBtn, start);
				isStarted = false;
			}
			break;
		case RESET_STOPWATCH:
			secondColor = selectedText;
			if(count->isEnter)
			{
				count->isEnter = false;
				seconds = 0;
				sixtySeconds = 0;
				milliseconds = 0;
			}
			break;
		case EXIT_STOPWATCH:
			thirdColor = selectedText;
			if(count->isEnter)
			{
				count->isEnter = false;
				exit = 0;
			}

			break;
		default: break;
		}

		dispcolorFillScreen(bgColor);

		dispcolorPrintf(45, 55, FONTID_64F, digitColor, "%07d.%03d", seconds, milliseconds);
		dispcolorPrintf((isStarted)? 105: 95, 130, FONTID_16F, firstColor, "%s", stateBtn);
		dispcolorPrintf(95, 150, FONTID_16F, secondColor, "%s", "RESET");
		dispcolorPrintf(105, 170, FONTID_16F, thirdColor, "%s", "EXIT");

		if (sixtySeconds == 60)
		{
			sixtySeconds = 0;
		}

		int16_t startAngle = -90;
		int16_t endAngle = sixtySeconds * 6 - 90;

		for (int16_t angle = startAngle; angle <= endAngle; angle += 6)
		{
			float angleRad = (float) angle * PI / 180;
			int x = cos(angleRad) * 118 + xC;
			int y = sin(angleRad) * 118 + yC;

			if (angle == endAngle)
				dispcolorFillCircleWu(x, y, 4, secArcColor);
			else
				dispcolorFillCircleWu(x, y, 3, secArcColor);
		}

		dispcolorUpdate();

		HAL_Delay(50);
	}
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef* htim)
{
	if(htim->Instance == TIM3)
	{
		if(milliseconds == 1000)
		{
			seconds++;
			sixtySeconds++;
			milliseconds = 0;
		}
		else
		{
			milliseconds++;
		}
	}
}
