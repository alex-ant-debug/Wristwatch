/*
 * brightness.h
 *
 *  Created on: Mar 21, 2023
 *      Author: user
 */

#ifndef SRC_WIDGETS_BRIGHTNESS_H_
#define SRC_WIDGETS_BRIGHTNESS_H_

#include "constants.h"

enum menuBrightness
{
    BRIGHTNESS_VALUE,
    EXIT_BRIGHTNESS
};

void drawMenuBrightness(encoderData_t *count);

#endif /* SRC_WIDGETS_BRIGHTNESS_H_ */
