/*
 * ChangBackground.c
 *
 *  Created on: Mar 9, 2023
 *      Author: user
 */
#include <stm32f4xx_hal.h>
#include <string.h>

#include "dispcolor.h"
#include "font.h"
#include "../widgets/ChangBackground.h"


void drawChangBackground(encoderData_t *count)
{
    uint8_t exit = 1;

    while(exit)
    {
        uint16_t colorText[BACKGROUND_SIZE] = {digitColor, digitColor, digitColor, digitColor};

        selectedText = GREEN;

        switch (bgColor)
        {
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

        switch (count->encoderPosition)
        {
        case COLOR_WHITE:
            colorText[COLOR_WHITE] = selectedText;
            if(count->isEnter)
            {
                count->isEnter = false;
                bgColor = WHITE;
            }
            break;
        case COLOR_BLACK:
            colorText[COLOR_BLACK] = selectedText;
            if(count->isEnter)
            {
                count->isEnter = false;
                bgColor = BLACK;
            }
            break;
        case COLOR_BLUE:
            colorText[COLOR_BLUE] = selectedText;
            if(count->isEnter)
            {
                count->isEnter = false;
                bgColor = BLUE;
            }
            break;
        case COLOR_EXIT:
            colorText[COLOR_EXIT] = selectedText;
            if(count->isEnter)
            {
                count->isEnter = false;
                exit = 0;
            }

            break;
        default: break;
        }

        dispcolorFillScreen(bgColor);

        dispcolorPrintf(95, 80, FONTID_16F, colorText[COLOR_WHITE], "%s", "WHITE");
        dispcolorPrintf(95, 110, FONTID_16F, colorText[COLOR_BLACK], "%s", "BLACK");
        dispcolorPrintf(100, 140, FONTID_16F, colorText[COLOR_BLUE], "%s", "BLUE");
        dispcolorPrintf(105, 170, FONTID_16F, colorText[COLOR_EXIT], "%s", "EXIT");

        dispcolorUpdate();

        HAL_Delay(50);
    }
}
