#ifndef _RTC_H
#define _RTC_H

#include <stm32f4xx_hal_rtc.h>


void RTC_Init(void);
void RTC_GetTime(RTC_TimeTypeDef *sTime);
void RTC_SetTime(RTC_TimeTypeDef *sTime, RTC_DateTypeDef *sDate);
RTC_DateTypeDef *RTC_GetTodayDate(void);

#endif