/*
 * ChangBackground.h
 *
 *  Created on: Mar 9, 2023
 *      Author: user
 */

#ifndef SRC_WIDGETS_CHANGBACKGROUND_H_
#define SRC_WIDGETS_CHANGBACKGROUND_H_

#include "constants.h"

enum colorStructure
{
	COLOR_WHITE,
	COLOR_BLACK,
	COLOR_BLUE,
	COLOR_EXIT
};

void DrawChangBackground(encoderData_t *count, uint8_t light);

#endif /* SRC_WIDGETS_CHANGBACKGROUND_H_ */
