/*
 * brightness.c
 *
 *  Created on: Mar 21, 2023
 *      Author: user
 */
#include <stm32f4xx_hal.h>
#include <string.h>
#include <math.h>

#include "brightness.h"
#include "../display/dispcolor.h"
#include "../display/fonts/font.h"
#include "../sleepMode/sleepMode.h"
#include "../timers/tmr2.h"


#define MAX_BRIGHTNESS	200


void drawMenuBrightness(encoderData_t *count)
{
	uint8_t exit = 1;
	uint16_t value = 100;
	uint8_t menuPosition = 0;
	bool isChangBrightness = false;
	resizeMenuCounter(BRIGHTNESS_MENU_SIZE*2, START_MENU);
	count->encoderPosition = START_MENU;

	while(exit)
	{
		uint16_t colorText[BRIGHTNESS_MENU_SIZE] = {digitColor, digitColor};

        if(!isChangBrightness)
        {
            menuPosition = count->encoderPosition;
        }

		switch (menuPosition)
		{
		case BRIGHTNESS_VALUE:
			colorText[BRIGHTNESS_VALUE] = selectedText;
			if(count->isEnter)
			{
				if(isChangBrightness)
				{
					isChangBrightness = false;
					resizeMenuCounter(BRIGHTNESS_MENU_SIZE*2, BRIGHTNESS_VALUE);
					count->encoderPosition = BRIGHTNESS_VALUE;
				}
				else
				{
					value = (value > MAX_BRIGHTNESS)? 0: value;
		        	isChangBrightness = true;
		            resizeMenuCounter(MAX_BRIGHTNESS*2, value*2);
		            count->encoderPosition = value;
				}
				count->isEnter = false;
			}
		    else
		    {
		        if(isChangBrightness)
		        {
		        	value = (MAX_BRIGHTNESS < count->encoderPosition)? 0: count->encoderPosition;
		        }
		    }
			break;
		case EXIT_BRIGHTNESS:
			colorText[EXIT_BRIGHTNESS] = selectedText;
			if(count->isEnter)
			{
				count->isEnter = false;
				resizeMenuCounter(MENU_ZIZE*2, START_MENU);
				count->encoderPosition = START_MENU;
				exit = 0;
			}
			break;
		default: break;
		}

        dispcolorFillScreen(bgColor);

        dispcolorDrawLine(30, 80, 200, 80, WHITE);
        dispcolor_FillCircleWu(value, 80, 8, colorText[BRIGHTNESS_VALUE]);

        dispcolorPrintf(105, 140, FONTID_16F, colorText[BRIGHTNESS_VALUE], "%d", value);
        dispcolorPrintf(105, 170, FONTID_16F, colorText[EXIT_BRIGHTNESS], "%s", "Exit");

        dispcolorUpdate();

        HAL_Delay(50);
	}
}
