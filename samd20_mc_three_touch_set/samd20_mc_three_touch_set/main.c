#include <atmel_start.h>
#include <touch.h>
#include "touch_example.h"

int main(void)
{
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();
	
	/* Replace with your application code */
	while (1) {
		touch_example();
	}
}
