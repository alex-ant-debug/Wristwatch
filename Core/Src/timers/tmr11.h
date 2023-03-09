#ifndef _TMR2_H
#define _TMR2_H

#include <stdint.h>


void tmr11_start(void);

void tmr11_stop(void);

void tmr11_PWM_init(uint16_t MaxValue, uint16_t Value);

void tmr11_PWM_set(uint16_t Value);

#endif
