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

	uint8_t menuPosition = 0;
	bool isParameterChanges = false;

	resizeMenuCounter(TIME_SETTING_SIZE*2, 0);

	uint8_t exit = 1;
	while(exit)
	{
		uint16_t firstColor, secondColor, thirdColor, fourthColor, fifthColor;
		uint16_t sixthColor, seventhColor, eighthColor, ninthColor;

		firstColor = secondColor = thirdColor = fourthColor = fifthColor = digitColor;
		sixthColor = seventhColor = eighthColor = ninthColor = digitColor;

		if(!isParameterChanges)
		{
			menuPosition = count->encoderPosition;
		}

		switch (menuPosition) {
		case DAYS:
			firstColor = selectedText;
			if(count->isEnter)
			{
				if(isParameterChanges)
				{
					isParameterChanges = false;
					resizeMenuCounter(TIME_SETTING_SIZE*2, 0);
				}
				else
				{
					isParameterChanges = true;
					resizeMenuCounter(30*2, day);
					count->encoderPosition = day;
				}
				count->isEnter = false;
			}
			else
			{
				if(isParameterChanges)
				{
					day = count->encoderPosition;
				}
			}
			break;
		case MONTHS:
			secondColor = selectedText;
			if(count->isEnter)
			{
				count->isEnter = false;

			}
			break;
		case YEARS:
			thirdColor = selectedText;
			if(count->isEnter)
			{
				count->isEnter = false;

			}
			break;
		case HOURS:
			fourthColor = selectedText;
			if(count->isEnter)
			{
				count->isEnter = false;

			}
			break;
		case MINUTES:
			fifthColor = selectedText;
			if(count->isEnter)
			{
				count->isEnter = false;

			}
			break;
		case SECONDS:
			sixthColor = selectedText;
			if(count->isEnter)
			{
				count->isEnter = false;

			}
			break;
		case HOURFORMAT:
			seventhColor = selectedText;
			if(count->isEnter)
			{
				count->isEnter = false;
				//setHourFormat(uint32_t format);
			}
			break;
		case SAVE:
			eighthColor = selectedText;
			if(count->isEnter)
			{
				count->isEnter = false;

				todayDate.Date = day;
				todayDate.Month = month;
				todayDate.Year = year;

				timeNow.Hours = hours;
				timeNow.Minutes = minutes;
				timeNow.Seconds = seconds;
				RTC_SetTime(&timeNow, &todayDate);
			}
			break;
		case EXIT_SETUP:
			ninthColor = selectedText;
			if(count->isEnter)
			{
				count->isEnter = false;
				resizeMenuCounter(4*2, 0);
				exit = 0;
			}

			break;
		default: break;
		}


		dispcolor_FillScreen(bgColor);

		dispcolor_printf(65, 45, FONTID_24F, digitColor, "   .   .");
		dispcolor_printf(65, 45, FONTID_24F, firstColor, "%02d", day);
		dispcolor_printf(65+35, 45, FONTID_24F, secondColor, "%02d", month);
		dispcolor_printf(65+70, 45, FONTID_24F, thirdColor, "20%02d", year);

		dispcolor_printf(55, 85, FONTID_64F, digitColor, "    :     :");
		dispcolor_printf(55, 85, FONTID_64F, fourthColor, "%02d", hours);
		dispcolor_printf(55+45, 85, FONTID_64F, fifthColor, "%02d", minutes);
		dispcolor_printf(55+95, 85, FONTID_64F, sixthColor, "%02d", seconds);

		//dispcolor_DrawRectangle(55-1, 85, 55+30, 85+60, selectedText);

		dispcolor_printf(45, 160, FONTID_16F, digitColor, "HOUR FORMAT:");
		dispcolor_printf(180, 160, FONTID_16F, seventhColor, "%s", "12");

		dispcolor_printf(100, 187, FONTID_16F, eighthColor, "%s", "SAVE");
		dispcolor_printf(105, 212, FONTID_16F, ninthColor, "%s", "EXIT");


		dispcolor_Update();

		HAL_Delay(50);
	}
}
