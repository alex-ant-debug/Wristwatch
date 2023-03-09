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

void DrawStopwatch(uint32_t seconds, uint8_t sixtySeconds, uint8_t light, uint8_t secBubbles)
{
	uint8_t exit = 1;

	while(exit)
	{

		uint16_t bgColor, digitColor, secArcColor;

		bgColor = (light)? WHITE: BLACK;
		digitColor = (light)? BLACK: WHITE;
		secArcColor = (light)? MAGENTA: GREEN;

		dispcolor_FillScreen(bgColor);

		dispcolor_printf(60, 55, FONTID_64F, digitColor, "%08d", seconds);
		dispcolor_printf(100, 130, FONTID_16F, digitColor, "%s", "Start");
		dispcolor_printf(100, 150, FONTID_16F, BLUE, "%s", "Reset");
		dispcolor_printf(100, 170, FONTID_16F, digitColor, "%s", "Exit");

		// ��������� ����
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
