/*
 * timeSetting.c
 *
 *  Created on: 10 бер. 2023 р.
 *      Author: user
 */
#include <stm32f4xx_hal.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#include "dispcolor.h"
#include "font.h"
#include "timeSetting.h"
#include "../timers/tmr2.h"
#include "../rtc/rtc.h"

#define DOUBLING(val)        (val)*2


static void parameterChange(encoderData_t *count,
                            uint8_t menuItem,
                            bool *isParameterChanges,
                            uint8_t maxParameterValue,
                            uint8_t *parameter,
                            bool isOnePlus)
{
    if(count->isEnter)
    {
        if(*isParameterChanges)
        {
            *isParameterChanges = false;
            resizeMenuCounter(DOUBLING(TIME_SETTING_SIZE), menuItem);
            count->encoderPosition = menuItem;
            TIM2->CNT = menuItem*2;
        }
        else
        {
            *isParameterChanges = true;
            resizeMenuCounter(DOUBLING(maxParameterValue), (*parameter)*2);
            count->encoderPosition = *parameter;
        }
        count->isEnter = false;
    }
    else
    {
        if(*isParameterChanges)
        {
            uint8_t one = (isOnePlus)? 1: 0;
            *parameter = (maxParameterValue < count->encoderPosition + one)? one: count->encoderPosition + one;
        }
    }
}

void drawTimeSetting(encoderData_t *count)
{
    RTC_TimeTypeDef time = { 0 };
    RTC_DateTypeDef date = { 0 };
    uint8_t menuPosition = 0;
    bool isParameterChanges = false;

    RTC_GetTime(&time, &date);

    uint8_t day = date.Date;
    uint8_t month = date.Month;
    uint8_t year = date.Year;
    uint8_t hours = time.Hours;
    uint8_t minutes = time.Minutes;
    uint8_t seconds = time.Seconds;
    uint8_t hourFormat = getHourFormat();
    uint8_t format = (hourFormat == RTC_HOURFORMAT_24)? 24: 12;


    resizeMenuCounter(TIME_SETTING_SIZE*2, START_MENU);
    count->encoderPosition = START_MENU;
    TIM2->CNT = START_MENU;

    uint8_t exit = 1;
    while(exit)
    {
        uint16_t colorParameter[TIME_SETTING_SIZE] = {digitColor, digitColor, digitColor, digitColor,
                                          digitColor, digitColor, digitColor, digitColor, digitColor};

        if(!isParameterChanges)
        {
            menuPosition = count->encoderPosition;
        }

        switch (menuPosition)
        {
        case DAYS:
            colorParameter[DAYS] = selectedText;
            parameterChange(count, DAYS, &isParameterChanges, AMOUNT_DAYS, &day, true);
            break;
        case MONTHS:
            colorParameter[MONTHS] = selectedText;
            parameterChange(count, MONTHS, &isParameterChanges, NUMBER_MONTHS, &month, true);
            break;
        case YEARS:
            colorParameter[YEARS] = selectedText;
            parameterChange(count, YEARS, &isParameterChanges, NUMBER_YEARS, &year, false);
            break;
        case HOURS:
            colorParameter[HOURS] = selectedText;
            uint32_t formatHours = (hourFormat == RTC_HOURFORMAT_24)? NUMBER_HOURS_24: NUMBER_HOURS_12;
            parameterChange(count, HOURS, &isParameterChanges, formatHours, &hours, false);
            break;
        case MINUTES:
            colorParameter[MINUTES] = selectedText;
            parameterChange(count, MINUTES, &isParameterChanges, NUMBER_MINUTES, &minutes, false);
            break;
        case SECONDS:
            colorParameter[SECONDS] = selectedText;
            parameterChange(count, SECONDS, &isParameterChanges, NUMBER_SECONDS, &seconds, false);
            break;
        case HOURFORMAT:
            colorParameter[HOURFORMAT] = selectedText;
            if(count->isEnter)
            {
                if(format == 12)
                {
                    format = 24;
                    hourFormat = RTC_HOURFORMAT_24;
                }
                else
                {
                    format = 12;
                    hourFormat = RTC_HOURFORMAT_12;
                }
                count->isEnter = false;
            }
            break;
        case SAVE:
            colorParameter[SAVE] = selectedText;
            if(count->isEnter)
            {
                count->isEnter = false;

                date.Date = day;
                date.Month = month;
                date.Year = year;

                time.Hours = hours;
                time.Minutes = minutes;
                time.Seconds = seconds;
                setHourFormat(hourFormat);

                RTC_SetTime(&time, &date);
            }
            break;
        case EXIT_SETUP:
            colorParameter[EXIT_SETUP] = selectedText;
            if(count->isEnter)
            {
                count->isEnter = false;
                resizeMenuCounter(DOUBLING(MENU_ZIZE), START_MENU);
                count->encoderPosition = START_MENU;
                TIM2->CNT = START_MENU;
                exit = 0;
            }
            break;
        default: break;
        }

        dispcolorFillScreen(bgColor);

        dispcolorPrintf(65, 45, FONTID_24F, digitColor, "   .   .");
        dispcolorPrintf(65, 45, FONTID_24F, colorParameter[DAYS], "%02d", day);
        dispcolorPrintf(65+35, 45, FONTID_24F, colorParameter[MONTHS], "%02d", month);
        dispcolorPrintf(65+70, 45, FONTID_24F, colorParameter[YEARS], "20%02d", year);

        dispcolorPrintf(55, 85, FONTID_64F, digitColor, "    :     :");
        dispcolorPrintf(55, 85, FONTID_64F, colorParameter[HOURS], "%02d", hours);
        dispcolorPrintf(55+45, 85, FONTID_64F, colorParameter[MINUTES], "%02d", minutes);
        dispcolorPrintf(55+95, 85, FONTID_64F, colorParameter[SECONDS], "%02d", seconds);

        dispcolorPrintf(45, 160, FONTID_16F, digitColor, "HOUR FORMAT:");
        dispcolorPrintf(180, 160, FONTID_16F, colorParameter[HOURFORMAT], "%d", format);

        dispcolorPrintf(100, 187, FONTID_16F, colorParameter[SAVE], "%s", "SAVE");
        dispcolorPrintf(105, 212, FONTID_16F, colorParameter[EXIT_SETUP], "%s", "EXIT");


        dispcolorUpdate();

        HAL_Delay(50);
    }
}
