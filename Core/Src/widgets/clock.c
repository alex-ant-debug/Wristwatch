#include <stm32f4xx_hal.h>
#include <string.h>
#include <dispcolor.h>
#include <font.h>
#include <math.h>

#include "../widgets/constants.h"
#include "../widgets/clock.h"

static void DrawArrow(int16_t angle, uint8_t lineLen, uint8_t thick,
		uint16_t color) {
	angle -= 90;
	float angleRad = (float) angle * PI / 180;
	int x = cos(angleRad) * lineLen + xC;
	int y = sin(angleRad) * lineLen + yC;

	//dispcolor_DrawLine_Wu(xC, yC, x, y, color);
	dispcolor_DrawLine2(xC, yC, x, y, color, thick);
}

void DrawClock(RTC_TimeTypeDef *time,
		       RTC_DateTypeDef *date,
			   uint8_t secBubbles)
{
	uint16_t secArcColor = (bgColor == WHITE)? MAGENTA: GREEN;

	dispcolor_FillScreen(bgColor);

	dispcolor_printf(65, 45, FONTID_24F, digitColor, "%02d.%02d.20%02d", date->Date,
			date->Month, date->Year);

	dispcolor_printf(55, 85, FONTID_64F, digitColor, "%02d : %02d : %02d", time->Hours,
			time->Minutes, time->Seconds);


	if (!time->Seconds)
		time->Seconds = 60;
	if (secBubbles) {
		int16_t startAngle = -90;
		int16_t endAngle = time->Seconds * 6 - 90;

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
		dispcolor_DrawArc(xC, yC, 119, 0, time->Seconds * 6, secArcColor, 5);

	dispcolor_Update();

	HAL_Delay(50);
}

