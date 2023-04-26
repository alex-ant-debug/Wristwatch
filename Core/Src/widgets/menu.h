/*
 * menu.h
 *
 *  Created on: Mar 9, 2023
 *      Author: user
 */

#ifndef SRC_WIDGETS_MENU_H_
#define SRC_WIDGETS_MENU_H_

#include "constants.h"

enum menuStructure
{
    STOPWATCH,
    TIME_SETTING,
    CHANG_BACKGROUND,
	BRIGHTNESS_CHANGE,
    EXIT
};

void DrawMenu(encoderData_t *count);

#endif /* SRC_WIDGETS_MENU_H_ */
