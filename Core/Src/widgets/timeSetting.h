/*
 * timeSetting.h
 *
 *  Created on: 10 бер. 2023 р.
 *      Author: user
 */

#ifndef SRC_WIDGETS_TIMESETTING_H_
#define SRC_WIDGETS_TIMESETTING_H_

#include "constants.h"


enum menuMeaningful
{
	DAYS,
	MONTHS,
	YEARS,
	HOURS,
	MINUTES,
	SECONDS,
	HOURFORMAT,
	SAVE,
	EXIT_SETUP
};

void DrawTimeSetting(encoderData_t *count,
		             RTC_TimeTypeDef *time,
				     RTC_DateTypeDef *date);

#endif /* SRC_WIDGETS_TIMESETTING_H_ */
