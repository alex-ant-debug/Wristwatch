/*
 * stopwatch.h
 *
 *  Created on: Mar 8, 2023
 *      Author: user
 */

#ifndef SRC_WIDGETS_STOPWATCH_H_
#define SRC_WIDGETS_STOPWATCH_H_

#include "constants.h"

enum menuStopwatch
{
    START_STOP,
    RESET_STOPWATCH,
    EXIT_STOPWATCH
};

void drawStopwatch(encoderData_t *count, uint8_t secBubbles);

#endif /* SRC_WIDGETS_STOPWATCH_H_ */
