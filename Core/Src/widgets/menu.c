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
#include "../widgets/ChangBackground.h"


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

		dispcolor_FillScreen(bgColor);

		dispcolor_printf(85, 80, FONTID_16F, firstColor, "%s", "Stopwatch");
		dispcolor_printf(20, 110, FONTID_16F, secondColor, "%s", "Setting the time and date");
		dispcolor_printf(60, 140, FONTID_16F, thirdColor, "%s", "Background color");
		dispcolor_printf(105, 170, FONTID_16F, fourthColor, "%s", "Exit");

		dispcolor_Update();

		HAL_Delay(50);
	}
}
