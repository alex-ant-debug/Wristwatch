/*
 * timeSetting.c
 *
 *  Created on: 10 бер. 2023 р.
 *      Author: user
 */
#include <stm32f4xx_hal.h>
#include <string.h>
#include <dispcolor.h>
#include <font.h>
#include <math.h>

#include "../timers/tmr2.h"
#include "timeSetting.h"
#include "../rtc/rtc.h"

#define DOUBLING(val)		(val)*2


void DrawTimeSetting(encoderData_t *count,
		             RTC_TimeTypeDef *time,
				     RTC_DateTypeDef *date)
{
	uint8_t day = date->Date;
	uint8_t month = date->Month;
	uint8_t year = date->Year;
	uint8_t hours = time->Hours;
	uint8_t minutes = time->Minutes;
	uint8_t seconds = time->Seconds;
	uint8_t hourFormat = getHourFormat();
	uint8_t format = (hourFormat == RTC_HOURFORMAT_24)? 24: 12;

	uint8_t menuPosition = 0;
	bool isParameterChanges = false;


	resizeMenuCounter(TIME_SETTING_SIZE*2, 0);

	uint8_t exit = 1;
	while(exit)
	{
		uint16_t colorParameter[TIME_SETTING_SIZE] = {digitColor, digitColor, digitColor, digitColor,
				                          digitColor, digitColor, digitColor, digitColor, digitColor};

		if(!isParameterChanges)
		{
			menuPosition = count->encoderPosition;
		}

		switch (menuPosition) {
		case DAYS:
			colorParameter[DAYS] = selectedText;
			if(count->isEnter)
			{
				if(isParameterChanges)
				{
					isParameterChanges = false;
					resizeMenuCounter(DOUBLING(TIME_SETTING_SIZE), DAYS);
					count->encoderPosition = menuPosition = DAYS;
				}
				else
				{
					isParameterChanges = true;
					resizeMenuCounter(DOUBLING(AMOUNT_DAYS), DOUBLING(day));
					count->encoderPosition = day;
				}
				count->isEnter = false;
			}
			else
			{
				if(isParameterChanges)
				{
					day = (AMOUNT_DAYS < count->encoderPosition + 1)? 1: count->encoderPosition + 1;
				}
			}
			break;
		case MONTHS:
			colorParameter[MONTHS] = selectedText;
			if(count->isEnter)
			{
				if(isParameterChanges)
				{
					isParameterChanges = false;
					resizeMenuCounter(DOUBLING(TIME_SETTING_SIZE), DOUBLING(MONTHS));
					count->encoderPosition = menuPosition = MONTHS;
				}
				else
				{
					isParameterChanges = true;
					resizeMenuCounter(DOUBLING(NUMBER_MONTHS), DOUBLING(month));
					count->encoderPosition = month;
				}
				count->isEnter = false;
			}
			else
			{
				if(isParameterChanges)
				{
					month = (NUMBER_MONTHS < count->encoderPosition + 1)? 1: count->encoderPosition + 1;
				}
			}
			break;
		case YEARS:
			colorParameter[YEARS] = selectedText;
			if(count->isEnter)
			{
				if(isParameterChanges)
				{
					isParameterChanges = false;
					resizeMenuCounter(DOUBLING(TIME_SETTING_SIZE), DOUBLING(YEARS));
					count->encoderPosition = menuPosition = YEARS;
				}
				else
				{
					isParameterChanges = true;
					resizeMenuCounter(DOUBLING(NUMBER_YEARS), DOUBLING(year));
					count->encoderPosition = year;
				}
				count->isEnter = false;
			}
			else
			{
				if(isParameterChanges)
				{
					year = (NUMBER_YEARS < count->encoderPosition + 1)? 1: count->encoderPosition + 1;
				}
			}
			break;
		case HOURS:
			colorParameter[HOURS] = selectedText;
			uint32_t formatHours = (hourFormat == RTC_HOURFORMAT_24)? NUMBER_HOURS_24: NUMBER_HOURS_12;
			if(count->isEnter)
			{
				if(isParameterChanges)
				{
					isParameterChanges = false;
					resizeMenuCounter(DOUBLING(TIME_SETTING_SIZE), DOUBLING(HOURS));
					count->encoderPosition = menuPosition = HOURS;
				}
				else
				{
					isParameterChanges = true;
					resizeMenuCounter(DOUBLING(formatHours), DOUBLING(hours));
					count->encoderPosition = hours;
				}
				count->isEnter = false;
			}
			else
			{
				if(isParameterChanges)
				{
//					hours = (count->encoderPosition > formatHours)? 0: count->encoderPosition;
					if(count->encoderPosition > formatHours)
					{
						hours = 0;
						count->encoderPosition = 0;
					}
					else
					{
						hours = count->encoderPosition;
					}
				}
			}
			break;
		case MINUTES:
			colorParameter[MINUTES] = selectedText;
			if(count->isEnter)
			{
				if(isParameterChanges)
				{
					isParameterChanges = false;
					resizeMenuCounter(DOUBLING(TIME_SETTING_SIZE), DOUBLING(MINUTES));
					count->encoderPosition = menuPosition = MINUTES;
				}
				else
				{
					isParameterChanges = true;
					resizeMenuCounter(DOUBLING(NUMBER_MINUTES), DOUBLING(minutes));
					count->encoderPosition = minutes;
				}
				count->isEnter = false;
			}
			else
			{
				if(isParameterChanges)
				{
					minutes = (NUMBER_MINUTES < count->encoderPosition + 1)? 0: count->encoderPosition + 1;
				}
			}
			break;
		case SECONDS:
			colorParameter[SECONDS] = selectedText;
			if(count->isEnter)
			{
				if(isParameterChanges)
				{
					isParameterChanges = false;
					resizeMenuCounter(DOUBLING(TIME_SETTING_SIZE), DOUBLING(SECONDS));
					count->encoderPosition = menuPosition = SECONDS;
				}
				else
				{
					isParameterChanges = true;
					resizeMenuCounter(DOUBLING(NUMBER_SECONDS), DOUBLING(seconds));
					count->encoderPosition = seconds;
				}
				count->isEnter = false;
			}
			else
			{
				if(isParameterChanges)
				{
					seconds = (NUMBER_SECONDS < count->encoderPosition + 1)? 0: count->encoderPosition + 1;
				}
			}
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
			count->isEnter = false;
			break;
		case SAVE:
			colorParameter[SAVE] = selectedText;
			if(count->isEnter)
			{
				count->isEnter = false;

				todayDate.Date = day;
				todayDate.Month = month;
				todayDate.Year = year;

				timeNow.Hours = hours;
				timeNow.Minutes = minutes;
				timeNow.Seconds = seconds;
				setHourFormat(hourFormat);

				RTC_SetTime(&timeNow, &todayDate);
			}
			break;
		case EXIT_SETUP:
			colorParameter[EXIT_SETUP] = selectedText;
			if(count->isEnter)
			{
				count->isEnter = false;
				resizeMenuCounter(DOUBLING(4), 0);
				exit = 0;
			}

			break;
		default: break;
		}


		dispcolor_FillScreen(bgColor);

		dispcolor_printf(65, 45, FONTID_24F, digitColor, "   .   .");
		dispcolor_printf(65, 45, FONTID_24F, colorParameter[DAYS], "%02d", day);
		dispcolor_printf(65+35, 45, FONTID_24F, colorParameter[MONTHS], "%02d", month);
		dispcolor_printf(65+70, 45, FONTID_24F, colorParameter[YEARS], "20%02d", year);

		dispcolor_printf(55, 85, FONTID_64F, digitColor, "    :     :");
		dispcolor_printf(55, 85, FONTID_64F, colorParameter[HOURS], "%02d", hours);
		dispcolor_printf(55+45, 85, FONTID_64F, colorParameter[MINUTES], "%02d", minutes);
		dispcolor_printf(55+95, 85, FONTID_64F, colorParameter[SECONDS], "%02d", seconds);

		//dispcolor_DrawRectangle(55-1, 85, 55+30, 85+60, selectedText);

		dispcolor_printf(45, 160, FONTID_16F, digitColor, "HOUR FORMAT:");
		dispcolor_printf(180, 160, FONTID_16F, colorParameter[HOURFORMAT], "%d", format);

		dispcolor_printf(100, 187, FONTID_16F, colorParameter[SAVE], "%s", "SAVE");
		dispcolor_printf(105, 212, FONTID_16F, colorParameter[EXIT_SETUP], "%s", "EXIT");


		dispcolor_Update();

		HAL_Delay(50);
	}
}
