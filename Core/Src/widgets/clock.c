#include <stm32f4xx_hal.h>
#include <string.h>
#include <dispcolor.h>
#include <font.h>
#include <rtc.h>
#include <math.h>

#include "../widgets/constants.h"
#include "../widgets/clock.h"



void DrawClock(void)
{
    RTC_TimeTypeDef time = { 0 };
    RTC_DateTypeDef date = { 0 };

    uint16_t secArcColor = (bgColor == WHITE)? MAGENTA: GREEN;

    RTC_GetTime(&time, &date);

    dispcolorFillScreen(bgColor);

    dispcolorPrintf(65, 45, FONTID_24F, digitColor, "%02d.%02d.20%02d", date.Date,
            date.Month, date.Year);

    dispcolorPrintf(55, 85, FONTID_64F, digitColor, "%02d : %02d : %02d", time.Hours,
            time.Minutes, time.Seconds);

    if(!time.Seconds)
    {
        time.Seconds = 60;
    }

    dispcolorDrawArc(xC, yC, 119, 0, time.Seconds * 6, secArcColor, 5);

    dispcolorUpdate();

    HAL_Delay(50);
}

