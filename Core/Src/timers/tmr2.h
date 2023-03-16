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
void resizeMenuCounter(uint32_t period, uint32_t startPosition);
uint32_t getTIM2Counter(void);
void setTIM2Counter(uint32_t counter);
uint32_t getTIM2AutoReload(void);

#endif /* SRC_TIMERS_TMR2_H_ */
