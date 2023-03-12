/*
 * menu.c
 *
 *  Created on: Mar 9, 2023
 *      Author: user
 */
#include <stm32f4xx_hal.h>
#include <string.h>
#include <math.h>

#include "menu.h"
#include "dispcolor.h"
#include "font.h"
#include "../widgets/stopwatch.h"
#include "../widgets/timeSetting.h"
#include "../widgets/ChangBackground.h"
#include "../rtc/rtc.h"


void DrawMenu(encoderData_t *count)
{
    uint8_t exit = 1;
    while(exit)
    {
        uint16_t colorText[MENU_ZIZE] = {digitColor, digitColor, digitColor, digitColor};

        switch (count->encoderPosition) {
        case STOPWATCH:
            colorText[STOPWATCH] = selectedText;
            if(count->isEnter)
            {
                count->isEnter = false;
                drawStopwatch(count, 0);
            }
            break;
        case TIME_SETTING:
            colorText[TIME_SETTING] = selectedText;
            if(count->isEnter)
            {
                count->isEnter = false;
                drawTimeSetting(count);
            }
            break;
        case CHANG_BACKGROUND:
            colorText[CHANG_BACKGROUND] = selectedText;
            if(count->isEnter)
            {
                count->isEnter = false;
                drawChangBackground(count);
            }
            break;
        case EXIT:
            colorText[EXIT] = selectedText;
            if(count->isEnter)
            {
                count->isEnter = false;
                exit = 0;
            }
            break;
        default: break;
        }

        dispcolorFillScreen(bgColor);

        dispcolorPrintf(85, 80, FONTID_16F, colorText[STOPWATCH], "%s", "Stopwatch");
        dispcolorPrintf(20, 110, FONTID_16F, colorText[TIME_SETTING], "%s", "Setting the time and date");
        dispcolorPrintf(60, 140, FONTID_16F, colorText[CHANG_BACKGROUND], "%s", "Background color");
        dispcolorPrintf(105, 170, FONTID_16F, colorText[EXIT], "%s", "Exit");

        dispcolorUpdate();

        HAL_Delay(50);
    }
}
