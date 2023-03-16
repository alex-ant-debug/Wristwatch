/*
 * systemClock.h
 *
 *  Created on: Mar 14, 2023
 *      Author: user
 */

#ifndef SRC_SYSTEMCLOCK_SYSTEMCLOCK_H_
#define SRC_SYSTEMCLOCK_SYSTEMCLOCK_H_

#include <stdint.h>

void SystemClock_Config(void);
void SystemClock_Config_HSI(void);
void stopHSE(void);
void stopHSI(void);

#endif /* SRC_SYSTEMCLOCK_SYSTEMCLOCK_H_ */
