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

char start[] = "START";
char stop[] = "STOP";

void DrawStopwatch(encoderData_t *count, uint8_t secBubbles)
{
	uint8_t exit = 1;
	char state[6] = {0};
	strcpy(state, start);

	while(exit)
	{
		uint32_t seconds = 0;
		uint8_t sixtySeconds = 0;
		uint16_t firstColor, secondColor, thirdColor;
		uint16_t secArcColor = (bgColor == WHITE)? MAGENTA: GREEN;

		firstColor = secondColor = thirdColor = digitColor;

		switch (count->encoderPosition) {
		case START_STOP:
			firstColor = selectedText;
			if(count->isEnter)
			{
				count->isEnter = false;
				strcpy(state, stop);
			}
			else
			{
				count->isEnter = false;
				strcpy(state, start);
			}
			break;
		case RESET_STOPWATCH:
			secondColor = selectedText;
			if(count->isEnter)
			{
				count->isEnter = false;
				seconds = 0;
				sixtySeconds = 0;
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

		dispcolor_FillScreen(bgColor);

		dispcolor_printf(60, 55, FONTID_64F, digitColor, "%08d", seconds);
		dispcolor_printf(105, 130, FONTID_16F, firstColor, "%s", state);
		dispcolor_printf(95, 150, FONTID_16F, secondColor, "%s", "RESET");
		dispcolor_printf(105, 170, FONTID_16F, thirdColor, "%s", "EXIT");


		if (!sixtySeconds)
			sixtySeconds = 60;
		if (secBubbles) {
			int16_t startAngle = -90;
			int16_t endAngle = sixtySeconds * 6 - 90;

			for (int16_t angle = startAngle; angle <= endAngle; angle += 6)
			{
				float angleRad = (float) angle * PI / 180;
				int x = cos(angleRad) * 118 + xC;
				int y = sin(angleRad) * 118 + yC;

				if (angle == endAngle)
					dispcolor_FillCircleWu(x, y, 4, secArcColor);
				else
					dispcolor_FillCircleWu(x, y, 3, secArcColor);
			}
		} else
			dispcolor_DrawArc(xC, yC, 119, 0, sixtySeconds * 6, secArcColor, 5);

		dispcolor_Update();

		HAL_Delay(50);
	}
}
