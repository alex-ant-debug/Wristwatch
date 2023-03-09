/*
 * tmr2.h
 *
 *  Created on: Mar 9, 2023
 *      Author: user
 */

#ifndef SRC_TIMERS_TMR2_H_
#define SRC_TIMERS_TMR2_H_

#include <stdint.h>

void TIM2_Init(uint32_t period);
void TIM2_DeInit(void);

#endif /* SRC_TIMERS_TMR2_H_ */