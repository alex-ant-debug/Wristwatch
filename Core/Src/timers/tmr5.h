/*
 * tmr5.h
 *
 *  Created on: Mar 11, 2023
 *      Author: user
 */

#ifndef SRC_TIMERS_TMR5_H_
#define SRC_TIMERS_TMR5_H_

#include <stdint.h>

void TIM5_Init(void);
void startTim5(void);
void stopTim5(void);
void restartTim5(void);

#endif /* SRC_TIMERS_TMR5_H_ */
