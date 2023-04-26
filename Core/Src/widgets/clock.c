#include <stm32f4xx_hal.h>
#include <string.h>
#include <dispcolor.h>
#include <font.h>
#include <rtc.h>
#include <math.h>

#include "../widgets/constants.h"
#include "../widgets/clock.h"


static void DrawArrow(int16_t angle, uint8_t lineLen, uint8_t thick, uint16_t color)
{
	angle -= 90;
	float angleRad = (float) angle * PI / 180;
	int x = cos(angleRad) * lineLen + xC;
	int y = sin(angleRad) * lineLen + yC;

	dispcolor_DrawLine2(xC, yC, x, y, color, thick);
}

void DrawClock(void)
{
    RTC_TimeTypeDef time = { 0 };
    RTC_DateTypeDef date = { 0 };

    uint16_t secArcColor = (bgColor == WHITE)? MAGENTA: GREEN;

    RTC_GetTime(&time, &date);

    dispcolorFillScreen(bgColor);

    dispcolorPrintf(65, 45, FONTID_24F, digitColor, "%02d.%02d.20%02d", date.Date,
            date.Month, date.Year);

    dispcolorPrintf(55, 85, FONTID_64F, digitColor, "%02d : %02d : %02d", time.Hours,
            time.Minutes, time.Seconds);

    if(!time.Seconds)
    {
        time.Seconds = 60;
    }

    dispcolorDrawArc(xC, yC, 119, 0, time.Seconds * 6, secArcColor, 5);

    dispcolorUpdate();

    HAL_Delay(50);
}

void DrawAnalogClock(uint8_t secBubbles)
{
	uint16_t riskColor, arrowColor;

    RTC_TimeTypeDef time = { 0 };
    RTC_DateTypeDef date = { 0 };

    uint16_t secArcColor = (bgColor == WHITE)? MAGENTA: GREEN;

    RTC_GetTime(&time, &date);

	if(bgColor == WHITE)
	{
		riskColor = arrowColor = BLACK;
	}
	else
	{
		riskColor = arrowColor = WHITE;
	}

	dispcolor_FillScreen(bgColor);

	//Circumferential marks
	uint8_t radius1 = 119;
	for (uint16_t angle = 0; angle <= 360; angle += 6)
	{
		uint8_t riskSize;
		if (!(angle % 90))
			riskSize = 13;
		else if (!(angle % 30))
			riskSize = 10;
		else
			riskSize = 6;

		uint8_t radius2 = radius1 - riskSize;
		float angleRad = (float) angle * PI / 180;
		int x1 = cos(angleRad) * radius1 + xC;
		int y1 = sin(angleRad) * radius1 + yC;
		int x2 = cos(angleRad) * radius2 + xC;
		int y2 = sin(angleRad) * radius2 + yC;

		dispcolor_DrawLine_Wu(x1, y1, x2, y2, riskColor);
	}

	// Watch Signatures
	dispcolor_DrawString(165, 30, FONTID_16F, "1", digitColor);
	dispcolor_DrawString(200, 63, FONTID_16F, "2", digitColor);
	dispcolor_DrawString(207, 106, FONTID_32F, "3", digitColor);
	dispcolor_DrawString(200, 160, FONTID_16F, "4", digitColor);
	dispcolor_DrawString(165, 193, FONTID_16F, "5", digitColor);
	dispcolor_DrawString(112, 195, FONTID_32F, "6", digitColor);
	dispcolor_DrawString(65, 193, FONTID_16F, "7", digitColor);
	dispcolor_DrawString(32, 160, FONTID_16F, "8", digitColor);
	dispcolor_DrawString(17, 106, FONTID_32F, "9", digitColor);
	dispcolor_DrawString(32, 63, FONTID_16F, "10", digitColor);
	dispcolor_DrawString(65, 30, FONTID_16F, "11", digitColor);
	dispcolor_DrawString(106, 14, FONTID_32F, "12", digitColor);

//	dispcolor_printf(75, 80, FONTID_16F, digitColor, "%02d : %02d : %02d", time.Hours, time.Minutes, time.Seconds);
	dispcolor_DrawCircle_Wu(xC, yC, 60, riskColor);
	dispcolor_DrawCircle_Wu(xC, yC, 119, riskColor);

	// Minute hand
	DrawArrow(time.Minutes * 6 + time.Seconds / 10, 100, 2, arrowColor);
	// Hour hand
	DrawArrow(time.Hours * 30 + time.Minutes / 2, 50, 4, arrowColor);

	// second arc
	if (!time.Seconds)
		time.Seconds = 60;
	if (secBubbles) {
		int16_t startAngle = -90;
		int16_t endAngle = time.Seconds * 6 - 90;

		for (int16_t angle = startAngle; angle <= endAngle; angle += 6) {
			float angleRad = (float) angle * PI / 180;
			int x = cos(angleRad) * 118 + xC;
			int y = sin(angleRad) * 118 + yC;

			if (angle == endAngle)
				dispcolor_FillCircleWu(x, y, 4, secArcColor);
			else
				dispcolor_FillCircleWu(x, y, 3, secArcColor);
		}
	} else
		dispcolor_DrawArc(xC, yC, 119, 0, time.Seconds * 6, secArcColor, 2);

	dispcolor_Update();

	HAL_Delay(50);
}
