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

void drawTimeSetting(encoderData_t *count);

#endif /* SRC_WIDGETS_TIMESETTING_H_ */
