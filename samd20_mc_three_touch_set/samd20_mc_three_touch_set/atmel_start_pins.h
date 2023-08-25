/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */
#ifndef ATMEL_START_PINS_H_INCLUDED
#define ATMEL_START_PINS_H_INCLUDED

#include <hal_gpio.h>

// SAMD20 has 8 pin functions

#define GPIO_PIN_FUNCTION_A 0
#define GPIO_PIN_FUNCTION_B 1
#define GPIO_PIN_FUNCTION_C 2
#define GPIO_PIN_FUNCTION_D 3
#define GPIO_PIN_FUNCTION_E 4
#define GPIO_PIN_FUNCTION_F 5
#define GPIO_PIN_FUNCTION_G 6
#define GPIO_PIN_FUNCTION_H 7

#define LED_SLIDER7 GPIO(GPIO_PORTA, 7)
#define PA20 GPIO(GPIO_PORTA, 20)
#define PA21 GPIO(GPIO_PORTA, 21)
#define LED_BTN0 GPIO(GPIO_PORTA, 22)
#define LED_BTN1 GPIO(GPIO_PORTA, 23)
#define PA24 GPIO(GPIO_PORTA, 24)
#define PA25 GPIO(GPIO_PORTA, 25)
#define LED_SLIDER0 GPIO(GPIO_PORTB, 0)
#define PB04 GPIO(GPIO_PORTB, 4)
#define LED_WHEEL0 GPIO(GPIO_PORTB, 14)
#define LED_WHEEL1 GPIO(GPIO_PORTB, 15)
#define TEST GPIO(GPIO_PORTB, 16)

#endif // ATMEL_START_PINS_H_INCLUDED
