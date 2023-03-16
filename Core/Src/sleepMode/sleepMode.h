/*
 * sleepMode.h
 *
 *  Created on: Mar 13, 2023
 *      Author: user
 */

#ifndef SRC_SLEEPMODE_SLEEPMODE_H_
#define SRC_SLEEPMODE_SLEEPMODE_H_

#include <stdbool.h>
#include "sleepMode.h"

void sleepMode(void);
void setStateSleepMode(bool turnOnOff);
bool getStateSleepMode(void);
void awakening(void);

#endif /* SRC_SLEEPMODE_SLEEPMODE_H_ */
