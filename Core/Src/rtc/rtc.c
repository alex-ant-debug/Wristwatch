#include <stm32f4xx_hal_rtc.h>
#include <rtc.h>

RTC_HandleTypeDef hrtc;
RTC_TimeTypeDef sTime = { 0 };
RTC_DateTypeDef sDate = { 0 };

void RTC_Init(void) {
	__HAL_RCC_RTC_ENABLE();

	hrtc.Instance = RTC;
	hrtc.Init.HourFormat = RTC_HOURFORMAT_24;
	hrtc.Init.AsynchPrediv = 127;
	hrtc.Init.SynchPrediv = 255;
	hrtc.Init.OutPut = RTC_OUTPUT_DISABLE;
	hrtc.Init.OutPutPolarity = RTC_OUTPUT_POLARITY_HIGH;
	hrtc.Init.OutPutType = RTC_OUTPUT_TYPE_OPENDRAIN;
	HAL_RTC_Init(&hrtc);

	sTime.Hours = 0x0;
	sTime.Minutes = 0x0;
	sTime.Seconds = 0x0;
	sTime.DayLightSaving = RTC_DAYLIGHTSAVING_NONE;
	sTime.StoreOperation = RTC_STOREOPERATION_RESET;
	HAL_RTC_SetTime(&hrtc, &sTime, RTC_FORMAT_BCD);

	sDate.WeekDay = 3;
	sDate.Month = 10;
	sDate.Date = 21;
	sDate.Year = 20;
	HAL_RTC_SetDate(&hrtc, &sDate, RTC_FORMAT_BCD);
}

void RTC_GetTime(RTC_TimeTypeDef *sTime) {
	HAL_RTC_GetTime(&hrtc, sTime, RTC_FORMAT_BIN);
	HAL_RTC_GetDate(&hrtc, &sDate, RTC_FORMAT_BIN);
}

void RTC_SetTime(RTC_TimeTypeDef *sTime, RTC_DateTypeDef *sDate) {
	HAL_RTC_SetTime(&hrtc, sTime, RTC_FORMAT_BIN);
	HAL_RTC_SetDate(&hrtc, sDate, RTC_FORMAT_BCD);
}

RTC_DateTypeDef *RTC_GetTodayDate(void)
{
	return &sDate;
}

void setHourFormat(uint32_t format)
{
	hrtc.Init.HourFormat = format;
	HAL_RTC_Init(&hrtc);
}

uint32_t getHourFormat(void)
{
	return hrtc.Init.HourFormat;
}
