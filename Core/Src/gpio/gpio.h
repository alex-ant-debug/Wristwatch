#ifndef _GPIO_H
#define _GPIO_H

#include <stm32f4xx_hal_gpio.h>

#define gpio_NoPull     0
#define gpio_PullUp     1
#define gpio_PullDown   2


void gpioSetGPIOmodeIn(GPIO_TypeDef* GPIOx, uint16_t Mask, uint8_t PullMode);
void gpioSetGPIOmodeOut(GPIO_TypeDef* GPIOx, uint16_t Mask);
void gpioPortClockStart(GPIO_TypeDef *GPIOx);

#endif
