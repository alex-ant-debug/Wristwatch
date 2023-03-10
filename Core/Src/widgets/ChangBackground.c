/*
 * ChangBackground.c
 *
 *  Created on: Mar 9, 2023
 *      Author: user
 */
#include <stm32f4xx_hal.h>
#include <string.h>
#include <dispcolor.h>
#include <font.h>

#include "../widgets/ChangBackground.h"


void DrawChangBackground(encoderData_t *count)
{
	uint8_t exit = 1;

	while(exit)
	{
		uint16_t firstColor, secondColor, thirdColor, fourthColor;

		selectedText = GREEN;

		switch (bgColor) {
		case BLACK:
			digitColor = WHITE;
			break;
		case BLUE:
			digitColor = BLACK;
			break;
		case WHITE:
			digitColor = BLACK;
			break;
		default: break;
		}

		firstColor = secondColor = thirdColor = fourthColor = digitColor;

		switch (count->encoderPosition) {
		case COLOR_WHITE:
			firstColor = selectedText;
			if(count->isEnter)
			{
				count->isEnter = false;
				bgColor = WHITE;
			}
			break;
		case COLOR_BLACK:
			secondColor = selectedText;
			if(count->isEnter)
			{
				count->isEnter = false;
				bgColor = BLACK;
			}
			break;
		case COLOR_BLUE:
			thirdColor = selectedText;
			if(count->isEnter)
			{
				count->isEnter = false;
				bgColor = BLUE;
			}
			break;
		case COLOR_EXIT:
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

		dispcolor_printf(95, 80, FONTID_16F, firstColor, "%s", "WHITE");
		dispcolor_printf(95, 110, FONTID_16F, secondColor, "%s", "BLACK");
		dispcolor_printf(100, 140, FONTID_16F, thirdColor, "%s", "BLUE");
		dispcolor_printf(105, 170, FONTID_16F, fourthColor, "%s", "EXIT");

		dispcolor_Update();

		HAL_Delay(50);
	}
}
