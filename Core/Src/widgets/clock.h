#ifndef SRC_WIDGETS_CLOCK_H_
#define SRC_WIDGETS_CLOCK_H_

#include "../rtc/rtc.h"


void DrawClock(RTC_TimeTypeDef *time,
		       RTC_DateTypeDef *date,
		       uint8_t light,
			   uint8_t secBubbles);


#endif /* SRC_WIDGETS_CLOCK_H_ */
