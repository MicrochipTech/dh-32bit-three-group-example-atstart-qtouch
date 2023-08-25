/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */

#include "driver_init.h"
#include <peripheral_clk_config.h>
#include <utils.h>
#include <hal_init.h>
#include <hpl_gclk_base.h>
#include <hpl_pm_base.h>

#include <hpl_rtc_base.h>

/*! The buffer size for USART */
#define USART_BUFFER_SIZE 16

struct usart_async_descriptor USART;
struct timer_descriptor       Timer;

static uint8_t USART_buffer[USART_BUFFER_SIZE];

/**
 * \brief USART Clock initialization function
 *
 * Enables register interface and peripheral clock
 */
void USART_CLOCK_init()
{

	_pm_enable_bus_clock(PM_BUS_APBC, SERCOM3);
	_gclk_enable_channel(SERCOM3_GCLK_ID_CORE, CONF_GCLK_SERCOM3_CORE_SRC);
}

/**
 * \brief USART pinmux initialization function
 *
 * Set each required pin to USART functionality
 */
void USART_PORT_init()
{

	gpio_set_pin_function(PA24, PINMUX_PA24C_SERCOM3_PAD2);

	gpio_set_pin_function(PA25, PINMUX_PA25C_SERCOM3_PAD3);
}

/**
 * \brief USART initialization function
 *
 * Enables USART peripheral, clocks and initializes USART driver
 */
void USART_init(void)
{
	USART_CLOCK_init();
	usart_async_init(&USART, SERCOM3, USART_buffer, USART_BUFFER_SIZE, (void *)NULL);
	USART_PORT_init();
}

/**
 * \brief Timer initialization function
 *
 * Enables Timer peripheral, clocks and initializes Timer driver
 */
static void Timer_init(void)
{
	_pm_enable_bus_clock(PM_BUS_APBA, RTC);
	_gclk_enable_channel(RTC_GCLK_ID, CONF_GCLK_RTC_SRC);
	timer_init(&Timer, RTC, _rtc_get_timer());
}

/**
 * \brief PTC initialization function
 *
 * Enables PTC peripheral, clocks and initializes PTC driver
 */
static void PTC_clock_init(void)
{
	_pm_enable_bus_clock(PM_BUS_APBC, PTC);
	_gclk_enable_channel(PTC_GCLK_ID, CONF_GCLK_PTC_SRC);
}

void system_init(void)
{
	init_mcu();

	// GPIO on PA07

	gpio_set_pin_level(LED_SLIDER7,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   true);

	// Set pin direction to output
	gpio_set_pin_direction(LED_SLIDER7, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(LED_SLIDER7, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PA22

	gpio_set_pin_level(LED_BTN0,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   true);

	// Set pin direction to output
	gpio_set_pin_direction(LED_BTN0, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(LED_BTN0, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PA23

	gpio_set_pin_level(LED_BTN1,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   true);

	// Set pin direction to output
	gpio_set_pin_direction(LED_BTN1, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(LED_BTN1, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PB00

	gpio_set_pin_level(LED_SLIDER0,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   true);

	// Set pin direction to output
	gpio_set_pin_direction(LED_SLIDER0, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(LED_SLIDER0, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PB14

	gpio_set_pin_level(LED_WHEEL0,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   true);

	// Set pin direction to output
	gpio_set_pin_direction(LED_WHEEL0, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(LED_WHEEL0, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PB15

	gpio_set_pin_level(LED_WHEEL1,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   true);

	// Set pin direction to output
	gpio_set_pin_direction(LED_WHEEL1, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(LED_WHEEL1, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PB16

	gpio_set_pin_level(TEST,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   false);

	// Set pin direction to output
	gpio_set_pin_direction(TEST, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(TEST, GPIO_PIN_FUNCTION_OFF);

	USART_init();

	Timer_init();

	PTC_clock_init();
}
